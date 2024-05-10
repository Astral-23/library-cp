---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u7D20\u56E0\u6570\u5206\u89E3\uFF08Pollard_rho) N^(1/4)logN"
    links:
    - https://drken1215.hatenablog.com/entry/2023/05/24/003724
  bundledCode: "#line 1 \"Math/factorize.cpp\"\n//ref:https://drken1215.hatenablog.com/entry/2023/05/24/003724\n\
    // montgomery modint (MOD < 2^62, MOD is odd)\nstruct MontgomeryModInt64 {\n \
    \   using mint = MontgomeryModInt64;\n    using u64 = uint64_t;\n    using u128\
    \ = __uint128_t;\n    \n    // static menber\n    static u64 MOD;\n    static\
    \ u64 INV_MOD;  // INV_MOD * MOD \u2261 1 (mod 2^64)\n    static u64 T128;  //\
    \ 2^128 (mod MOD)\n    \n    // inner value\n    u64 val;\n    \n    // constructor\n\
    \    MontgomeryModInt64() : val(0) { }\n    MontgomeryModInt64(long long v) :\
    \ val(reduce((u128(v) + MOD) * T128)) { }\n    u64 get() const {\n        u64\
    \ res = reduce(val);\n        return res >= MOD ? res - MOD : res;\n    }\n  \
    \  \n    // mod getter and setter\n    static u64 get_mod() { return MOD; }\n\
    \    static void set_mod(u64 mod) {\n        assert(mod < (1LL << 62));\n    \
    \    assert((mod & 1));\n        MOD = mod;\n        T128 = -u128(mod) % mod;\n\
    \        INV_MOD = get_inv_mod();\n    }\n    static u64 get_inv_mod() {\n   \
    \     u64 res = MOD;\n        for (int i = 0; i < 5; ++i) res *= 2 - MOD * res;\n\
    \        return res;\n    }\n    static u64 reduce(const u128 &v) {\n        return\
    \ (v + u128(u64(v) * u64(-INV_MOD)) * MOD) >> 64;\n    }\n    \n    // arithmetic\
    \ operators\n    mint operator - () const { return mint() - mint(*this); }\n \
    \   mint operator + (const mint &r) const { return mint(*this) += r; }\n    mint\
    \ operator - (const mint &r) const { return mint(*this) -= r; }\n    mint operator\
    \ * (const mint &r) const { return mint(*this) *= r; }\n    mint operator / (const\
    \ mint &r) const { return mint(*this) /= r; }\n    mint& operator += (const mint\
    \ &r) {\n        if ((val += r.val) >= 2 * MOD) val -= 2 * MOD;\n        return\
    \ *this;\n    }\n    mint& operator -= (const mint &r) {\n        if ((val +=\
    \ 2 * MOD - r.val) >= 2 * MOD) val -= 2 * MOD;\n        return *this;\n    }\n\
    \    mint& operator *= (const mint &r) {\n        val = reduce(u128(val) * r.val);\n\
    \        return *this;\n    }\n    mint& operator /= (const mint &r) {\n     \
    \   *this *= r.inv();\n        return *this;\n    }\n    mint inv() const { return\
    \ pow(MOD - 2); }\n    mint pow(u128 n) const {\n        mint res(1), mul(*this);\n\
    \        while (n > 0) {\n            if (n & 1) res *= mul;\n            mul\
    \ *= mul;\n            n >>= 1;\n        }\n        return res;\n    }\n\n   \
    \ // other operators\n    bool operator == (const mint &r) const {\n        return\
    \ (val >= MOD ? val - MOD : val) == (r.val >= MOD ? r.val - MOD : r.val);\n  \
    \  }\n    bool operator != (const mint &r) const {\n        return (val >= MOD\
    \ ? val - MOD : val) != (r.val >= MOD ? r.val - MOD : r.val);\n    }\n    friend\
    \ istream& operator >> (istream &is, mint &x) {\n        long long t;\n      \
    \  is >> t;\n        x = mint(t);\n        return is;\n    }\n    friend ostream&\
    \ operator << (ostream &os, const mint &x) {\n        return os << x.get();\n\
    \    }\n    friend mint modpow(const mint &r, long long n) {\n        return r.pow(n);\n\
    \    }\n    friend mint modinv(const mint &r) {\n        return r.inv();\n   \
    \ }\n};\n\ntypename MontgomeryModInt64::u64\nMontgomeryModInt64::MOD, MontgomeryModInt64::INV_MOD,\
    \ MontgomeryModInt64::T128;\n\n\n\nclass MillerRabin {\n    vector<long long>\
    \ A1 = {2, 7, 61};\n    vector<long long> A2 = {2, 325, 9375, 28178, 450775, 9780504,\
    \ 1795265022};\n\n    private:\n        bool MR(long long x, vector<long long>&\
    \ A) {\n\t\t\tusing PMINT = MontgomeryModInt64;\n\t\t\tPMINT::set_mod(x);\n\n\
    \            long long s = 0, d = x-1;\n            while(!(d&1)) {\n        \
    \        ++s;\n                d >>= 1;\n            }\n\n            for(auto\
    \ a : A) {\n                if(x <= a) return true;\n                long long\
    \ t = 0;\n                PMINT v = PMINT(a).pow(d);\n                if(v !=\
    \ 1) {\n                    for(t = 0; t < s; ++t) {\n                       \
    \ if(v == x-1)break;\n                        v = v*v;\n                    }\n\
    \                    if(t == s) return false;//\u4E00\u3064\u3082\u901A\u3089\u306A\
    \u304B\u3063\u305F\u3002\n                }\n            }\n            return\
    \ true;\n        }\n\n    public:\n        bool isprime(long long x) {\n     \
    \       if(x <= 1) return false;\n            if(x == 2) return true;\n      \
    \      if(!(x&1)) return false;\n            if(x < 4759123141LL) return MR(x,\
    \ A1);\n            else return MR(x, A2);\n        }\n};MillerRabin MR;\n\n\n\
    struct Pollard_rho {\n\n\tlong long prime_factor(long long n) { \n\t\tif(!(n&1))\
    \ return 2LL;\n\t\tusing PMINT = MontgomeryModInt64;\n\t\tPMINT::set_mod(n);\n\
    \n\t\tfor(int i = 1; i < n; i++) {\n\t\t\tauto f = [&](long long x) {\n\t\t\t\t\
    return(PMINT(x)*x+i).val;\n\t\t\t};\n\t\t\tlong long x = 0, y = 0;\n\t\t\tlong\
    \ long d = 1;\n\t\t\twhile(d==1) {\n\t\t\t\tx = f(x);\n\t\t\t\ty = f(f(y));\n\t\
    \t\t\td = gcd(abs(x-y), n);\n\t\t\t}\n\n\t\t\tif(d==n) continue;\n\t\t\tif(MR.isprime(d))return\
    \ d;\n\t\t\telse if(MR.isprime(n/d)) return n/d;\n\t\t\telse return prime_factor(d);\n\
    \t\t}\n\t}\n\n\tvector<pair<long long, int>> factorize(long long x) {\n\t\tvector<pair<long\
    \ long, int>> res;\n\t\twhile(!MR.isprime(x) && x > 1) {\n\t\t\tlong long p =\
    \ prime_factor(x);\n\t\t\tint c = 0;\n\t\t\twhile(x%p==0) {\n\t\t\t\tc++;\n\t\t\
    \t\tx /= p;\n\t\t\t}\n\t\t\tres.emplace_back(p, c);\n\t\t}\n\t\tif(x > 1) res.emplace_back(x,\
    \ 1);\n\t\tsort(res.begin(), res.end());\n\t\treturn res;\n\t}\n\n}; Pollard_rho\
    \ POL;\n/*\n@brief \u7D20\u56E0\u6570\u5206\u89E3\uFF08Pollard_rho) N^(1/4)logN\n\
    */\n"
  code: "//ref:https://drken1215.hatenablog.com/entry/2023/05/24/003724\n// montgomery\
    \ modint (MOD < 2^62, MOD is odd)\nstruct MontgomeryModInt64 {\n    using mint\
    \ = MontgomeryModInt64;\n    using u64 = uint64_t;\n    using u128 = __uint128_t;\n\
    \    \n    // static menber\n    static u64 MOD;\n    static u64 INV_MOD;  //\
    \ INV_MOD * MOD \u2261 1 (mod 2^64)\n    static u64 T128;  // 2^128 (mod MOD)\n\
    \    \n    // inner value\n    u64 val;\n    \n    // constructor\n    MontgomeryModInt64()\
    \ : val(0) { }\n    MontgomeryModInt64(long long v) : val(reduce((u128(v) + MOD)\
    \ * T128)) { }\n    u64 get() const {\n        u64 res = reduce(val);\n      \
    \  return res >= MOD ? res - MOD : res;\n    }\n    \n    // mod getter and setter\n\
    \    static u64 get_mod() { return MOD; }\n    static void set_mod(u64 mod) {\n\
    \        assert(mod < (1LL << 62));\n        assert((mod & 1));\n        MOD =\
    \ mod;\n        T128 = -u128(mod) % mod;\n        INV_MOD = get_inv_mod();\n \
    \   }\n    static u64 get_inv_mod() {\n        u64 res = MOD;\n        for (int\
    \ i = 0; i < 5; ++i) res *= 2 - MOD * res;\n        return res;\n    }\n    static\
    \ u64 reduce(const u128 &v) {\n        return (v + u128(u64(v) * u64(-INV_MOD))\
    \ * MOD) >> 64;\n    }\n    \n    // arithmetic operators\n    mint operator -\
    \ () const { return mint() - mint(*this); }\n    mint operator + (const mint &r)\
    \ const { return mint(*this) += r; }\n    mint operator - (const mint &r) const\
    \ { return mint(*this) -= r; }\n    mint operator * (const mint &r) const { return\
    \ mint(*this) *= r; }\n    mint operator / (const mint &r) const { return mint(*this)\
    \ /= r; }\n    mint& operator += (const mint &r) {\n        if ((val += r.val)\
    \ >= 2 * MOD) val -= 2 * MOD;\n        return *this;\n    }\n    mint& operator\
    \ -= (const mint &r) {\n        if ((val += 2 * MOD - r.val) >= 2 * MOD) val -=\
    \ 2 * MOD;\n        return *this;\n    }\n    mint& operator *= (const mint &r)\
    \ {\n        val = reduce(u128(val) * r.val);\n        return *this;\n    }\n\
    \    mint& operator /= (const mint &r) {\n        *this *= r.inv();\n        return\
    \ *this;\n    }\n    mint inv() const { return pow(MOD - 2); }\n    mint pow(u128\
    \ n) const {\n        mint res(1), mul(*this);\n        while (n > 0) {\n    \
    \        if (n & 1) res *= mul;\n            mul *= mul;\n            n >>= 1;\n\
    \        }\n        return res;\n    }\n\n    // other operators\n    bool operator\
    \ == (const mint &r) const {\n        return (val >= MOD ? val - MOD : val) ==\
    \ (r.val >= MOD ? r.val - MOD : r.val);\n    }\n    bool operator != (const mint\
    \ &r) const {\n        return (val >= MOD ? val - MOD : val) != (r.val >= MOD\
    \ ? r.val - MOD : r.val);\n    }\n    friend istream& operator >> (istream &is,\
    \ mint &x) {\n        long long t;\n        is >> t;\n        x = mint(t);\n \
    \       return is;\n    }\n    friend ostream& operator << (ostream &os, const\
    \ mint &x) {\n        return os << x.get();\n    }\n    friend mint modpow(const\
    \ mint &r, long long n) {\n        return r.pow(n);\n    }\n    friend mint modinv(const\
    \ mint &r) {\n        return r.inv();\n    }\n};\n\ntypename MontgomeryModInt64::u64\n\
    MontgomeryModInt64::MOD, MontgomeryModInt64::INV_MOD, MontgomeryModInt64::T128;\n\
    \n\n\nclass MillerRabin {\n    vector<long long> A1 = {2, 7, 61};\n    vector<long\
    \ long> A2 = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};\n\n    private:\n\
    \        bool MR(long long x, vector<long long>& A) {\n\t\t\tusing PMINT = MontgomeryModInt64;\n\
    \t\t\tPMINT::set_mod(x);\n\n            long long s = 0, d = x-1;\n          \
    \  while(!(d&1)) {\n                ++s;\n                d >>= 1;\n         \
    \   }\n\n            for(auto a : A) {\n                if(x <= a) return true;\n\
    \                long long t = 0;\n                PMINT v = PMINT(a).pow(d);\n\
    \                if(v != 1) {\n                    for(t = 0; t < s; ++t) {\n\
    \                        if(v == x-1)break;\n                        v = v*v;\n\
    \                    }\n                    if(t == s) return false;//\u4E00\u3064\
    \u3082\u901A\u3089\u306A\u304B\u3063\u305F\u3002\n                }\n        \
    \    }\n            return true;\n        }\n\n    public:\n        bool isprime(long\
    \ long x) {\n            if(x <= 1) return false;\n            if(x == 2) return\
    \ true;\n            if(!(x&1)) return false;\n            if(x < 4759123141LL)\
    \ return MR(x, A1);\n            else return MR(x, A2);\n        }\n};MillerRabin\
    \ MR;\n\n\nstruct Pollard_rho {\n\n\tlong long prime_factor(long long n) { \n\t\
    \tif(!(n&1)) return 2LL;\n\t\tusing PMINT = MontgomeryModInt64;\n\t\tPMINT::set_mod(n);\n\
    \n\t\tfor(int i = 1; i < n; i++) {\n\t\t\tauto f = [&](long long x) {\n\t\t\t\t\
    return(PMINT(x)*x+i).val;\n\t\t\t};\n\t\t\tlong long x = 0, y = 0;\n\t\t\tlong\
    \ long d = 1;\n\t\t\twhile(d==1) {\n\t\t\t\tx = f(x);\n\t\t\t\ty = f(f(y));\n\t\
    \t\t\td = gcd(abs(x-y), n);\n\t\t\t}\n\n\t\t\tif(d==n) continue;\n\t\t\tif(MR.isprime(d))return\
    \ d;\n\t\t\telse if(MR.isprime(n/d)) return n/d;\n\t\t\telse return prime_factor(d);\n\
    \t\t}\n\t}\n\n\tvector<pair<long long, int>> factorize(long long x) {\n\t\tvector<pair<long\
    \ long, int>> res;\n\t\twhile(!MR.isprime(x) && x > 1) {\n\t\t\tlong long p =\
    \ prime_factor(x);\n\t\t\tint c = 0;\n\t\t\twhile(x%p==0) {\n\t\t\t\tc++;\n\t\t\
    \t\tx /= p;\n\t\t\t}\n\t\t\tres.emplace_back(p, c);\n\t\t}\n\t\tif(x > 1) res.emplace_back(x,\
    \ 1);\n\t\tsort(res.begin(), res.end());\n\t\treturn res;\n\t}\n\n}; Pollard_rho\
    \ POL;\n/*\n@brief \u7D20\u56E0\u6570\u5206\u89E3\uFF08Pollard_rho) N^(1/4)logN\n\
    */"
  dependsOn: []
  isVerificationFile: false
  path: Math/factorize.cpp
  requiredBy: []
  timestamp: '2024-05-10 23:19:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/factorize.cpp
layout: document
redirect_from:
- /library/Math/factorize.cpp
- /library/Math/factorize.cpp.html
title: "\u7D20\u56E0\u6570\u5206\u89E3\uFF08Pollard_rho) N^(1/4)logN"
---
