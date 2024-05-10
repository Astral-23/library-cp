---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DetaStructures/LazySegTree.hpp
    title: "\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  - icon: ':heavy_check_mark:'
    path: Utilities/modint998.hpp
    title: modint998244353
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "#line 1 \"verify/lazyseg.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\n#line 1 \"Utilities/modint998.hpp\"\
    \n\ntemplate<int mod>\nstruct modint{\n    long long x;\n    modint(long long\
    \ _x=0) noexcept : x((_x%mod+mod)%mod){}\n    long long val() const noexcept {return\
    \ x;}\n    modint& operator+=(const modint& a) noexcept {if((x += a.x) >= mod)\
    \ x -= mod;return *this;}\n    modint& operator-=(const modint& a) noexcept {if((x\
    \ += mod - a.x) >= mod) x -= mod;return *this;}\n    modint& operator*=(const\
    \ modint& a) noexcept {(x *= a.x) %= mod;return *this;}\n    modint& operator/=(const\
    \ modint& a) {return (*this) *= a.inv();}\n    modint& operator++() noexcept {return\
    \ *this += 1;}\n    modint& operator--() noexcept {return *this -= 1;}\n    modint\
    \ operator++(int) {modint tmp = *this; ++*this; return tmp;}\n    modint operator--(int)\
    \ {modint tmp = *this; --*this; return tmp;}\n    modint inv() const {return pow(mod-2);}\n\
    \    friend modint operator+(const modint&  t, const modint& a)  {modint tmp =\
    \ t; return tmp += a;}\n    friend modint operator-(const modint&  t, const modint&\
    \ a)  {modint tmp = t; return tmp += (a * -1);}\n    friend modint operator*(const\
    \ modint&  t, const modint& a)  {modint tmp = t; return tmp *= a;}\n    friend\
    \ modint operator/(const modint&  t, const modint& a)  {assert(a.x != 0) ; return\
    \ a.inv() *=  t;}\n    modint pow(const long long& y) const {\n        if(!y)\
    \ return 1;\n        modint res = pow(y >> 1);\n        res *= res;\n        if(y\
    \ & 1) res *= *this;\n        return res;\n    }\n    friend istream& operator>>(istream&\
    \ is, modint& a) { return is >> a.x;}\n    friend ostream& operator<<(ostream&\
    \ os, const modint& a) { return os << a.x;}\n    bool operator==(const modint&\
    \ a) const {return x == a.x;}\n    bool operator!=(const modint& a) const {return\
    \ x != a.x;}\n    bool operator<(const modint& a) const {return x < a.x;}\n};\n\
    using mint = modint<998244353>;\n/*\n@brief modint998244353\n*/\n#line 1 \"DetaStructures/LazySegTree.hpp\"\
    \n\ntemplate<typename X, typename E>\nstruct LazySegTree {\n    using FX = function<X(X,\
    \ E, long long)>;//X\u306B\u4F5C\u7528\u7D20M\u3092\u4F5C\u7528\u3055\u305B\u308B\
    \n    \n    int n;\n    int siz;\n    FX fx; \n    vector<X> dat;\n    vector<E>\
    \ lazy;\n    LazySegTree(int _siz, FX _fx) : siz(_siz),  fx(_fx) {\n        n\
    \ = 1;\n        while(n < siz) n <<= 1;\n        dat.assign(n * 2, X::ide());\n\
    \        lazy.assign(n * 2, E::ide());\n    }\n\n    private:\n        void eval(int\
    \ k, int len) {\n            if(lazy[k] == E::ide()) return;\n            if(k\
    \ < n) {\n              lazy[k<<1] = op(lazy[k<<1], lazy[k]);\n              lazy[k<<1|1]\
    \ = op(lazy[k<<1|1], lazy[k]);\n            }\n            dat[k] = fx(dat[k],\
    \ lazy[k], len);\n            lazy[k] = E::ide();\n        }    \n\n        X\
    \ query(int a, int b, int l, int r, int k) {\n            eval(k,r-l);\n     \
    \       if(r <= a || b <= l) return X::ide();\n            if(a <= l && r <= b)\
    \ return dat[k];\n            int mid = (l + r)>>1;\n            X L = query(a,\
    \ b, l, mid, k<<1);\n            X R = query(a, b, mid, r, k<<1|1);\n        \
    \    return op(L, R);\n        }  \n\n        void update(int a, int b, E m, int\
    \ l, int r,  int k) {//[a, b) := \u30AF\u30A8\u30EA\u533A\u9593  [l, r) := \u4ECA\
    \u898B\u3066\u3044\u308B\u533A\u9593\n            eval(k, r-l);\n            if(r\
    \ <= a || b <= l) return;\n            if(a <= l && r <= b) {\n              \
    \  lazy[k] = op(lazy[k], m);\n                eval(k, r-l);\n            }\n \
    \           else {\n                int mid = (l + r)>>1;\n                update(a,\
    \ b, m, l, mid, k<<1);\n                update(a, b, m, mid, r, k<<1|1);\n   \
    \             dat[k] = op(dat[k<<1], dat[k<<1|1]);\n            }\n        } \
    \  \n    \n    public:\n\n        void set(int i, X x) {\n            dat[i +\
    \ n - 1] =  x;\n        }    \n\n        void init() {\n            for(int i\
    \ = n-1; i >= 1; i--) {\n                dat[i] = op(dat[i<<1], dat[i<<1|1]);\n\
    \            }\n        }    \n    \n        void change(int l, int r, E m) {\n\
    \            update(l, r + 1, m, 1, n + 1, 1);\n        }\n\n        X get(int\
    \ l, int r) {\n          return query(l, r + 1, 1, n + 1, 1);\n        }\n\n \
    \       void dump() {\n            for(int i = 1; i <= siz; i++) {\n         \
    \       cout << get(i, i) << \" \";//\u9069\u5B9C\u76F4\u3059\u3002\n        \
    \    }\n            cout << endl;\n        }\n};    \n/*\n@brief \u9045\u5EF6\u30BB\
    \u30B0\u30E1\u30F3\u30C8\u6728\n*/\n#line 6 \"verify/lazyseg.test.cpp\"\nusing\
    \ ll = long long;\nusing vvl = vector<vector<ll>>;\nusing vl = vector<ll>;\n#define\
    \ rep(i, s, f) for(long long i = s; i <= f; i++)\n#define ENDL '\\n'\n\n\nstruct\
    \ Monoid {\n    mint a;\n   \n    Monoid(){}\n      \n    Monoid(mint _a) : a(_a)\
    \ {\n      \n    }\n\n    friend Monoid op(const Monoid& l, const Monoid& r) {\n\
    \      return l.a + r.a;\n    }\n\n    static Monoid ide() {\n       return mint(0);\n\
    \    }\n    \n};\n\n\nstruct E {    \n    mint a, b;\n   \n    E(){}\n      \n\
    \    E(mint _a, mint _b) : a(_a), b(_b) {}\n\n    friend E op(const E& l, const\
    \ E& r) {//r\u306E\u304C\u65B0\u3057\u3044\u3002(affine)\n        E res;\n   \
    \     res.a = l.a * r.a;\n        res.b = r.a * l.b + r.b;\n        return res;\n\
    \      \n    }\n    static E ide() {\n       return E(1, 0);\n    }\n   \n   \
    \ bool operator==(const E& x) const {return (a == x.a && b == x.b);}\n    bool\
    \ operator!=(const E& x) const {return !(*this == x);}\n\n};\n\n\nMonoid fx(const\
    \ Monoid& l, const E& r, long long len) {\n     return l.a * r.a + r.b * len;\n\
    }\n\nint main() {\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    int N, Q;\n    cin >> N >> Q;\n    vector<ll> A(N+1);\n    LazySegTree<Monoid,\
    \ E> seg(N, fx);\n\n    for(int i = 1; i <= N; i++) cin >> A[i];\n\n    for(int\
    \ i = 1; i <= N; i++) seg.set(i, mint(A[i]));\n    seg.init();\n    while(Q--)\
    \ {\n        int t;\n        cin >> t;\n        if(t == 0) {\n            int\
    \ l, r;\n            cin >> l >> r;\n            mint b, c;\n            cin >>\
    \ b >> c;\n            l++;\n            seg.change(l, r, E(b, c));\n        }\n\
    \        else {\n            int l, r;\n            cin >> l >> r;\n         \
    \   l++;\n            cout << seg.get(l,r).a << endl;\n\n        }\n    }\n\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\n#include \"../Utilities/modint998.hpp\"\
    \n#include \"../DetaStructures/LazySegTree.hpp\"\nusing ll = long long;\nusing\
    \ vvl = vector<vector<ll>>;\nusing vl = vector<ll>;\n#define rep(i, s, f) for(long\
    \ long i = s; i <= f; i++)\n#define ENDL '\\n'\n\n\nstruct Monoid {\n    mint\
    \ a;\n   \n    Monoid(){}\n      \n    Monoid(mint _a) : a(_a) {\n      \n   \
    \ }\n\n    friend Monoid op(const Monoid& l, const Monoid& r) {\n      return\
    \ l.a + r.a;\n    }\n\n    static Monoid ide() {\n       return mint(0);\n   \
    \ }\n    \n};\n\n\nstruct E {    \n    mint a, b;\n   \n    E(){}\n      \n  \
    \  E(mint _a, mint _b) : a(_a), b(_b) {}\n\n    friend E op(const E& l, const\
    \ E& r) {//r\u306E\u304C\u65B0\u3057\u3044\u3002(affine)\n        E res;\n   \
    \     res.a = l.a * r.a;\n        res.b = r.a * l.b + r.b;\n        return res;\n\
    \      \n    }\n    static E ide() {\n       return E(1, 0);\n    }\n   \n   \
    \ bool operator==(const E& x) const {return (a == x.a && b == x.b);}\n    bool\
    \ operator!=(const E& x) const {return !(*this == x);}\n\n};\n\n\nMonoid fx(const\
    \ Monoid& l, const E& r, long long len) {\n     return l.a * r.a + r.b * len;\n\
    }\n\nint main() {\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    int N, Q;\n    cin >> N >> Q;\n    vector<ll> A(N+1);\n    LazySegTree<Monoid,\
    \ E> seg(N, fx);\n\n    for(int i = 1; i <= N; i++) cin >> A[i];\n\n    for(int\
    \ i = 1; i <= N; i++) seg.set(i, mint(A[i]));\n    seg.init();\n    while(Q--)\
    \ {\n        int t;\n        cin >> t;\n        if(t == 0) {\n            int\
    \ l, r;\n            cin >> l >> r;\n            mint b, c;\n            cin >>\
    \ b >> c;\n            l++;\n            seg.change(l, r, E(b, c));\n        }\n\
    \        else {\n            int l, r;\n            cin >> l >> r;\n         \
    \   l++;\n            cout << seg.get(l,r).a << endl;\n\n        }\n    }\n\n}"
  dependsOn:
  - Utilities/modint998.hpp
  - DetaStructures/LazySegTree.hpp
  isVerificationFile: true
  path: verify/lazyseg.test.cpp
  requiredBy: []
  timestamp: '2024-05-11 02:53:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/lazyseg.test.cpp
layout: document
redirect_from:
- /verify/verify/lazyseg.test.cpp
- /verify/verify/lazyseg.test.cpp.html
title: verify/lazyseg.test.cpp
---
