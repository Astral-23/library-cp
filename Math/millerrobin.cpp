class MillerRabin {
    vector<long long> A1 = {2, 7, 61};
    vector<long long> A2 = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};

    private:
        template<typename T>
        T pow_mod(T x, T y, T m) {
            T res = 1;
            x %= m;
            while(y) {
                if(y&1) res = (res * x)%m;
                x = (x*x)%m;            
                y >>= 1;
            }
            return res;
        }

        bool MR(long long x, vector<long long>& A) {
            long long s = 0, d = x-1;
            while(!(d&1)) {
                ++s;
                d >>= 1;
            }

            for(auto a : A) {
                if(x <= a) return true;
                long long t = 0;
                long long v = pow_mod<__int128_t>(a, d, x);
                if(v != 1) {
                    for(t = 0; t < s; ++t) {
                        if(v == x-1)break;
                        v = __int128_t(v)*v%x;
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
/*
@brief 素数判定(Miller Robin)
*/