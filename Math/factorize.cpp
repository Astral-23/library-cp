//ref:https://drken1215.hatenablog.com/entry/2023/05/24/003724
// montgomery modint (MOD < 2^62, MOD is odd)
struct MontgomeryModInt64 {
    using mint = MontgomeryModInt64;
    using u64 = uint64_t;
    using u128 = __uint128_t;
    
    // static menber
    static u64 MOD;
    static u64 INV_MOD;  // INV_MOD * MOD ≡ 1 (mod 2^64)
    static u64 T128;  // 2^128 (mod MOD)
    
    // inner value
    u64 val;
    
    // constructor
    MontgomeryModInt64() : val(0) { }
    MontgomeryModInt64(long long v) : val(reduce((u128(v) + MOD) * T128)) { }
    u64 get() const {
        u64 res = reduce(val);
        return res >= MOD ? res - MOD : res;
    }
    
    // mod getter and setter
    static u64 get_mod() { return MOD; }
    static void set_mod(u64 mod) {
        assert(mod < (1LL << 62));
        assert((mod & 1));
        MOD = mod;
        T128 = -u128(mod) % mod;
        INV_MOD = get_inv_mod();
    }
    static u64 get_inv_mod() {
        u64 res = MOD;
        for (int i = 0; i < 5; ++i) res *= 2 - MOD * res;
        return res;
    }
    static u64 reduce(const u128 &v) {
        return (v + u128(u64(v) * u64(-INV_MOD)) * MOD) >> 64;
    }
    
    // arithmetic operators
    mint operator - () const { return mint() - mint(*this); }
    mint operator + (const mint &r) const { return mint(*this) += r; }
    mint operator - (const mint &r) const { return mint(*this) -= r; }
    mint operator * (const mint &r) const { return mint(*this) *= r; }
    mint operator / (const mint &r) const { return mint(*this) /= r; }
    mint& operator += (const mint &r) {
        if ((val += r.val) >= 2 * MOD) val -= 2 * MOD;
        return *this;
    }
    mint& operator -= (const mint &r) {
        if ((val += 2 * MOD - r.val) >= 2 * MOD) val -= 2 * MOD;
        return *this;
    }
    mint& operator *= (const mint &r) {
        val = reduce(u128(val) * r.val);
        return *this;
    }
    mint& operator /= (const mint &r) {
        *this *= r.inv();
        return *this;
    }
    mint inv() const { return pow(MOD - 2); }
    mint pow(u128 n) const {
        mint res(1), mul(*this);
        while (n > 0) {
            if (n & 1) res *= mul;
            mul *= mul;
            n >>= 1;
        }
        return res;
    }

    // other operators
    bool operator == (const mint &r) const {
        return (val >= MOD ? val - MOD : val) == (r.val >= MOD ? r.val - MOD : r.val);
    }
    bool operator != (const mint &r) const {
        return (val >= MOD ? val - MOD : val) != (r.val >= MOD ? r.val - MOD : r.val);
    }
    friend istream& operator >> (istream &is, mint &x) {
        long long t;
        is >> t;
        x = mint(t);
        return is;
    }
    friend ostream& operator << (ostream &os, const mint &x) {
        return os << x.get();
    }
    friend mint modpow(const mint &r, long long n) {
        return r.pow(n);
    }
    friend mint modinv(const mint &r) {
        return r.inv();
    }
};

typename MontgomeryModInt64::u64
MontgomeryModInt64::MOD, MontgomeryModInt64::INV_MOD, MontgomeryModInt64::T128;



class MillerRabin {
    vector<long long> A1 = {2, 7, 61};
    vector<long long> A2 = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};

    private:
        bool MR(long long x, vector<long long>& A) {
			using PMINT = MontgomeryModInt64;
			PMINT::set_mod(x);

            long long s = 0, d = x-1;
            while(!(d&1)) {
                ++s;
                d >>= 1;
            }

            for(auto a : A) {
                if(x <= a) return true;
                long long t = 0;
                PMINT v = PMINT(a).pow(d);
                if(v != 1) {
                    for(t = 0; t < s; ++t) {
                        if(v == x-1)break;
                        v = v*v;
                    }
                    if(t == s) return false;//一つも通らなかった。
                }
            }
            return true;
        }

    public:
        bool isprime(long long x) {
            if(x <= 1) return false;
            if(x == 2) return true;
            if(!(x&1)) return false;
            if(x < 4759123141LL) return MR(x, A1);
            else return MR(x, A2);
        }
};MillerRabin MR;


struct Pollard_rho {

	long long prime_factor(long long n) { 
		if(!(n&1)) return 2LL;
		using PMINT = MontgomeryModInt64;
		PMINT::set_mod(n);

		for(int i = 1; i < n; i++) {
			auto f = [&](long long x) {
				return(PMINT(x)*x+i).val;
			};
			long long x = 0, y = 0;
			long long d = 1;
			while(d==1) {
				x = f(x);
				y = f(f(y));
				d = gcd(abs(x-y), n);
			}

			if(d==n) continue;
			if(MR.isprime(d))return d;
			else if(MR.isprime(n/d)) return n/d;
			else return prime_factor(d);
		}
	}

	vector<pair<long long, int>> factorize(long long x) {
		vector<pair<long long, int>> res;
		while(!MR.isprime(x) && x > 1) {
			long long p = prime_factor(x);
			int c = 0;
			while(x%p==0) {
				c++;
				x /= p;
			}
			res.emplace_back(p, c);
		}
		if(x > 1) res.emplace_back(x, 1);
		sort(res.begin(), res.end());
		return res;
	}

}; Pollard_rho POL;
/*
@brief 素因数分解（Pollard_rho) N^(1/4)logN
*/