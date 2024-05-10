---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DetaStructures/SegTree.hpp
    title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"SegTree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\n#line 1 \"DetaStructures/SegTree.hpp\"\
    \ntemplate<typename T>\nstruct SegTree {\n    int n;\n    vector<T> dat;\n\n \
    \        \n    SegTree(int siz) {\n        n = 1;\n        while(n < siz) n <<=\
    \ 1;\n        dat.resize(n * 2, T::ide());\n    }\n\n    private:\n         \n\
    \        T query(int l, int r) {\n            T L = T::ide(), R = T::ide();\n\
    \            l += n - 1, r += n - 1;\n            while(l < r) {\n           \
    \     if(l & 1) L = op(L, dat[l++]);\n                if(r & 1) R = op(dat[--r],\
    \ R);\n                l >>= 1, r >>= 1;\n            }  \n            return\
    \  op(L, R);\n        }\n\n    \n    public:\n\n        void set(int pos, T x)\
    \ {\n            pos += n-1;\n            dat[pos] = x;\n        }\n         \
    \ \n        void init() {\n            for(int i = n-1; i >= 1; i--)  dat[i] =\
    \ op(dat[i<<1], dat[i<<1|1]);\n        }\n          \n        void change(int\
    \ pos, T x) {\n            pos += n - 1;\n            dat[pos] = update(dat[pos],\
    \ x);\n            while(pos >= 2) {\n                pos >>= 1;\n           \
    \     dat[pos] = op(dat[pos<<1], dat[pos<<1|1]);\n            }\n        }\n \
    \        \n        T get(int l, int r) {// [l, r]\u306E\u6F14\u7B97\u7D50\u679C\
    \u3002\n            return query(l, r+1);\n        }\n\n        T operator[](int\
    \ pos) {\n            return dat[pos + n - 1];\n        }\n         \n};\n\n\n\
    /*\n@brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n@docs docs/segtree.md\n*/\n#line\
    \ 5 \"SegTree.test.cpp\"\nstruct mint{//998244353\n   long long x;\n   static\
    \ const long long mod = 998244353;\n   mint(long long _x=0) noexcept : x((_x%mod+mod)%mod){}\n\
    \   long long val() const noexcept {return x;}\n   mint& operator+=(const mint&\
    \ a) noexcept {if((x += a.x) >= mod) x -= mod;return *this;}\n   mint& operator-=(const\
    \ mint& a) noexcept {if((x += mod - a.x) >= mod) x -= mod;return *this;}\n   mint&\
    \ operator*=(const mint& a) noexcept {(x *= a.x) %= mod;return *this;}\n   mint&\
    \ operator/=(const mint& a) {return (*this) *= a.inv();}\n   mint& operator++()\
    \ noexcept {return *this += 1;}\n   mint& operator--() noexcept {return *this\
    \ -= 1;}\n   mint operator++(int) {mint tmp = *this; ++*this; return tmp;}\n \
    \  mint operator--(int) {mint tmp = *this; --*this; return tmp;}\n   mint inv()\
    \ const {return pow(mod-2);}\n   friend mint operator+(const mint&  t, const mint&\
    \ a)  {mint tmp = t; return tmp += a;}\n   friend mint operator-(const mint& \
    \ t, const mint& a)  {mint tmp = t; return tmp += (a * -1);}\n   friend mint operator*(const\
    \ mint&  t, const mint& a)  {mint tmp = t; return tmp *= a;}\n   friend mint operator/(const\
    \ mint&  t, const mint& a)  {return a.inv() *=  t;}\n   mint pow(const long long&\
    \ y) const {\n    if(!y) return 1;\n    mint res = pow(y >> 1);\n    res *= res;\n\
    \    if(y & 1) res *= *this;\n    return res;\n  }\n   friend istream& operator>>(istream&\
    \ is, mint& a) { return is >> a.x;}\n   friend ostream& operator<<(ostream& os,\
    \ const mint& a) { return os << a.x;}\n   bool operator==(const mint& a) const\
    \ {return x == a.x;}\n   bool operator!=(const mint& a) const {return x != a.x;}\n\
    };\n\n\n\nstruct Monoid {\n    mint a, b;\n    \n    Monoid(){}\n    Monoid(mint\
    \ _a, mint _b) : a(_a), b(_b){};\n\n    friend Monoid op(const Monoid& l, const\
    \ Monoid& r) {\n        Monoid res;\n        res.a = l.a * r.a;\n        res.b\
    \ = r.a * l.b + r.b;\n        return res;\n    } \n    friend Monoid update(const\
    \ Monoid& l, const Monoid& x) {\n        return x;\n    }\n\n\n\tstatic Monoid\
    \ ide() {\n\t\treturn Monoid(1, 0);\n\n\t}\n};\n\n\n\n\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \  std::cin.tie(nullptr);\n    int N, Q;\n    cin >> N >> Q;\n    int test = 100;\n\
    \     SegTree<Monoid> seg(N);\n    for(int i = 1; i <= N; i++) {\n        mint\
    \ a, b;\n        cin >> a >> b;\n        seg.set(i, Monoid(a, b));\n    }\n\t\
    seg.init();\n\n\n    while(Q--) {\n        int type;\n        cin >> type;\n \
    \       int x, y, z;\n        cin >> x >> y >> z;\n        x++;\n        if(type\
    \ == 0) {\n            seg.change(x, Monoid(y, z));\n        }\n        else {\n\
    \            \n            auto [a, b] = seg.get(x, y);\n            cout << a\
    \ * z + b << '\\n';\n        }\n    }\n    \n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\n#include \"DetaStructures/SegTree.hpp\"\
    \nstruct mint{//998244353\n   long long x;\n   static const long long mod = 998244353;\n\
    \   mint(long long _x=0) noexcept : x((_x%mod+mod)%mod){}\n   long long val()\
    \ const noexcept {return x;}\n   mint& operator+=(const mint& a) noexcept {if((x\
    \ += a.x) >= mod) x -= mod;return *this;}\n   mint& operator-=(const mint& a)\
    \ noexcept {if((x += mod - a.x) >= mod) x -= mod;return *this;}\n   mint& operator*=(const\
    \ mint& a) noexcept {(x *= a.x) %= mod;return *this;}\n   mint& operator/=(const\
    \ mint& a) {return (*this) *= a.inv();}\n   mint& operator++() noexcept {return\
    \ *this += 1;}\n   mint& operator--() noexcept {return *this -= 1;}\n   mint operator++(int)\
    \ {mint tmp = *this; ++*this; return tmp;}\n   mint operator--(int) {mint tmp\
    \ = *this; --*this; return tmp;}\n   mint inv() const {return pow(mod-2);}\n \
    \  friend mint operator+(const mint&  t, const mint& a)  {mint tmp = t; return\
    \ tmp += a;}\n   friend mint operator-(const mint&  t, const mint& a)  {mint tmp\
    \ = t; return tmp += (a * -1);}\n   friend mint operator*(const mint&  t, const\
    \ mint& a)  {mint tmp = t; return tmp *= a;}\n   friend mint operator/(const mint&\
    \  t, const mint& a)  {return a.inv() *=  t;}\n   mint pow(const long long& y)\
    \ const {\n    if(!y) return 1;\n    mint res = pow(y >> 1);\n    res *= res;\n\
    \    if(y & 1) res *= *this;\n    return res;\n  }\n   friend istream& operator>>(istream&\
    \ is, mint& a) { return is >> a.x;}\n   friend ostream& operator<<(ostream& os,\
    \ const mint& a) { return os << a.x;}\n   bool operator==(const mint& a) const\
    \ {return x == a.x;}\n   bool operator!=(const mint& a) const {return x != a.x;}\n\
    };\n\n\n\nstruct Monoid {\n    mint a, b;\n    \n    Monoid(){}\n    Monoid(mint\
    \ _a, mint _b) : a(_a), b(_b){};\n\n    friend Monoid op(const Monoid& l, const\
    \ Monoid& r) {\n        Monoid res;\n        res.a = l.a * r.a;\n        res.b\
    \ = r.a * l.b + r.b;\n        return res;\n    } \n    friend Monoid update(const\
    \ Monoid& l, const Monoid& x) {\n        return x;\n    }\n\n\n\tstatic Monoid\
    \ ide() {\n\t\treturn Monoid(1, 0);\n\n\t}\n};\n\n\n\n\n\nint main() {\n\tios::sync_with_stdio(false);\n\
    \  std::cin.tie(nullptr);\n    int N, Q;\n    cin >> N >> Q;\n    int test = 100;\n\
    \     SegTree<Monoid> seg(N);\n    for(int i = 1; i <= N; i++) {\n        mint\
    \ a, b;\n        cin >> a >> b;\n        seg.set(i, Monoid(a, b));\n    }\n\t\
    seg.init();\n\n\n    while(Q--) {\n        int type;\n        cin >> type;\n \
    \       int x, y, z;\n        cin >> x >> y >> z;\n        x++;\n        if(type\
    \ == 0) {\n            seg.change(x, Monoid(y, z));\n        }\n        else {\n\
    \            \n            auto [a, b] = seg.get(x, y);\n            cout << a\
    \ * z + b << '\\n';\n        }\n    }\n    \n}"
  dependsOn:
  - DetaStructures/SegTree.hpp
  isVerificationFile: true
  path: SegTree.test.cpp
  requiredBy: []
  timestamp: '2024-05-10 23:50:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: SegTree.test.cpp
layout: document
redirect_from:
- /verify/SegTree.test.cpp
- /verify/SegTree.test.cpp.html
title: SegTree.test.cpp
---
