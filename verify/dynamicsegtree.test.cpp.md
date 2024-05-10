---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructures/DynamicSegTree.hpp
    title: "\u52D5\u7684\u30BB\u30B0\u6728"
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
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "#line 1 \"verify/dynamicsegtree.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
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
    using mint = modint<998244353>;\n/*\n@brief modint998244353\n*/\n#line 1 \"DataStructures/DynamicSegTree.hpp\"\
    \ntemplate<typename X, typename W>\nstruct DynamicSegTree {// max_pos < LLONG_MAX(\u958B\
    \u533A\u9593\u306E\u5F0A\u5BB3)\n    \n\n    W  min_pos;\n    W  max_pos;//\u6E21\
    \u3059\u6642\u306F\u9589\u533A\u9593\u3060\u304C\u3001\u958B\u533A\u9593\u3067\
    \u6271\u3046\u3002\n    DynamicSegTree(){} \n    DynamicSegTree(W _min_pos, W\
    \ _max_pos) :  min_pos(_min_pos), max_pos(_max_pos) {\n        assert(min_pos\
    \ <= max_pos);//\u9069\u5207\u306A\u533A\u9593\u304C\u6307\u5B9A\u3055\u308C\u3066\
    \u3044\u308B\u304B\n        assert(max_pos < LLONG_MAX);\n\t\tmax_pos++;\n\n \
    \   };\n\n\n    private:\n        struct Node {\n            W pos;\n        \
    \    X val;\n            X prod;\n            Node* lch;\n\t\t\tNode* rch;\n \
    \       \n            Node(W p, X v, X pro) : pos(p), val(v), prod(pro) {\n  \
    \              lch = nullptr;\n\t\t\t\trch = nullptr;\n            }\n       \
    \ };\n        \n        Node* root = nullptr;\n\n \n       \n        X value(Node*\
    \ now) {\n            return now!=nullptr ? now -> prod : X::ide(); \n       \
    \ }\n\n        Node* change__(Node* now, W& a, W& b, W& p, X& x) {\n         \
    \   if(now == nullptr) {\n                now = new Node(p, x, x);\n         \
    \       return now;\n            }\n            if(now -> pos == p) {\n      \
    \          now -> val = update(now -> val, x);\n                now -> prod =\
    \ op(value(now -> lch), op(now -> val, value(now -> rch)));//\u533A\u9593\u3092\
    \u7BA1\u7406\u3059\u308B\u30CE\u30FC\u30C9\u306E\u7B54\u3048\u3092\u8FD4\u3059\
    (\u5DE6\u5B50\u30FB\u3053\u306E\u30CE\u30FC\u30C9\u306B\u5165\u3063\u3066\u308B\
    \u5206(\u5E38\u306B1\u30CE\u30FC\u30C9\u5206\uFF09\u30FB\u53F3\u5B50)\n      \
    \          return now;\n            }\n            \n            W mid = (a+b)>>1;\n\
    \            if(p < mid) {\n                if(now -> pos < p) swap(p, now ->\
    \ pos), swap(x, now -> val);//\u5B50\u306E\u65B9\u304C\u9806\u5E8F\u304C\u5DE6\
    \u306B\u306A\u308B\u3088\u3046\u306B\n                now -> lch = change__(now\
    \ -> lch, a, mid, p, x);\n            }\n            else {\n                if(now\
    \ -> pos > p) swap(p, now -> pos), swap(x, now -> val);//\u5B50\u306E\u65B9\u304C\
    \u9806\u5E8F\u304C\u53F3\u306B\u306A\u308B\u3088\u3046\u306B\n               \
    \ now -> rch = change__(now -> rch, mid, b, p, x);\n            }\n          \
    \  now -> prod = op(value(now -> lch), op(now -> val, value(now -> rch)));\n \
    \           return now;\n        }\n\n        X get__(Node* now, W& a, W& b, W\
    \ l, W r) {// [l, r) := \u30AF\u30A8\u30EA\u533A\u9593  [a, b) := \u4ECA\u898B\
    \u3066\u3044\u308B\u533A\u9593   [a, b]\u3067\u306E\u7D50\u679C\u3092\u8FD4\u3059\
    \u3002\n            if(b <= l || r <= a) return X::ide();//\u7BC4\u56F2\u5916\u306A\
    \u3089\u5358\u4F4D\u5143\n            if(now == nullptr) return X::ide();//\u7BC4\
    \u56F2\u5185\u306B\u3064\u3044\u3066\u3001\u30C7\u30FC\u30BF\u304C\u5B58\u5728\
    \u3057\u306A\u3044\u306A\u3089\u5358\u4F4D\u5143\n            if(l <= a && b <=\
    \ r) return now -> prod;//\u5B8C\u5168\u306B\u542B\u307E\u308C\u3066\u3044\u308B\
    \u306A\u3089\u8FD4\u3059\u3002\n            W mid = (a+b)>>1;\n            X res\
    \ = get__(now -> lch, a, mid, l, r);\n            if(l <= now -> pos && now ->\
    \ pos < r) res = op(res, now -> val);//[a , b)\u306E\u5024\u306E\u5C45\u5834\u6240\
    \ : \u4ECA\u898B\u3066\u3044\u308B\u30CE\u30FC\u30C9\u304C\u6301\u3063\u3066\u3044\
    \u308B\u5024\u306E\u6DFB\u3048\u5B57\u3092id\u3068\u3057\u3066 [a, id)\u3092\u5DE6\
    \u306E\u5B50\u304C\u3001id\u3092\u3053\u308C\u304C\u3001(id, b)\u3092\u53F3\u306E\
    \u5B50\u304C\u6301\u3063\u3066\u3044\u308B\u3002\n            return op(res, get__(now\
    \ -> rch, mid, b, l, r));//\u4ECA\u898B\u3066\u3044\u308B\u30CE\u30FC\u30C9\u304C\
    \u6301\u3064\u7BC4\u56F2\u306E\u5206\u304C\u8A08\u7B97\u3057\u7D42\u308F\u3063\
    \u305F\u306E\u3067\u3001\u8FD4\u3059\u3002\n\n        }\n\n\n\n    public:\n \
    \       void change(W pos, X x) {\n           root = change__(root, min_pos, max_pos,\
    \ pos, x);\n        }\n\n        X  get(W l, W r) {\n            return get__(root,\
    \ min_pos, max_pos, l, r+1);\n        }\n\n\t\t/*\n\t\t    DynamicSegTree<X, W>\
    \ seg(minpos, maxpos)  X...\u30C7\u30FC\u30BF W...\u6DFB\u5B57\u306E\u578B  O(1)\n\
    \t\t\t@brief \u52D5\u7684\u30BB\u30B0\u6728\n\t\t\n\t\t*/\n\n};\n\n#line 6 \"\
    verify/dynamicsegtree.test.cpp\"\nusing ll = long long;\nusing vvl = vector<vector<ll>>;\n\
    using vl = vector<ll>;\n#define rep(i, s, f) for(long long i = s; i <= f; i++)\n\
    #define ENDL '\\n'\n\nstruct Monoid {\n    mint a, b;\n    \n    Monoid(){}\n\
    \    Monoid(mint _a, mint _b) : a(_a), b(_b){};\n\n    friend Monoid op(const\
    \ Monoid& l, const Monoid& r) {\n        Monoid res;\n        res.a = l.a * r.a;\n\
    \        res.b = r.a * l.b + r.b;\n        return res;\n    } \n    friend Monoid\
    \ update(const Monoid& l, const Monoid& x) {\n        return x;\n    }\n\n\n\t\
    static Monoid ide() {\n\t\treturn Monoid(1, 0);\n\n\t}\n};\n\n\n\n\n\nint main()\
    \ {\n\tios::sync_with_stdio(false);\n  std::cin.tie(nullptr);\n    int N, Q;\n\
    \    cin >> N >> Q;\n    DynamicSegTree<Monoid, int> seg(-250000, 250000);\n \
    \   for(int i = 0; i < N; i++) {\n        mint a, b;\n        cin >> a >> b;\n\
    \        seg.change(i-250000, Monoid(a, b));\n    }\n\n    while(Q--) {\n    \
    \    int type;\n        cin >> type;\n        int x, y, z;\n        cin >> x >>\
    \ y >> z;\n        x -= 250000;\n        if(type == 0) {\n            seg.change(x,\
    \ Monoid(y, z));\n        }\n        else {\n            y -= 250000;\n      \
    \      auto [a, b] = seg.get(x, y-1);\n            cout << a * z + b << '\\n';\n\
    \        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\n#include \"../Utilities/modint998.hpp\"\
    \n#include \"../DataStructures/DynamicSegTree.hpp\"\nusing ll = long long;\nusing\
    \ vvl = vector<vector<ll>>;\nusing vl = vector<ll>;\n#define rep(i, s, f) for(long\
    \ long i = s; i <= f; i++)\n#define ENDL '\\n'\n\nstruct Monoid {\n    mint a,\
    \ b;\n    \n    Monoid(){}\n    Monoid(mint _a, mint _b) : a(_a), b(_b){};\n\n\
    \    friend Monoid op(const Monoid& l, const Monoid& r) {\n        Monoid res;\n\
    \        res.a = l.a * r.a;\n        res.b = r.a * l.b + r.b;\n        return\
    \ res;\n    } \n    friend Monoid update(const Monoid& l, const Monoid& x) {\n\
    \        return x;\n    }\n\n\n\tstatic Monoid ide() {\n\t\treturn Monoid(1, 0);\n\
    \n\t}\n};\n\n\n\n\n\nint main() {\n\tios::sync_with_stdio(false);\n  std::cin.tie(nullptr);\n\
    \    int N, Q;\n    cin >> N >> Q;\n    DynamicSegTree<Monoid, int> seg(-250000,\
    \ 250000);\n    for(int i = 0; i < N; i++) {\n        mint a, b;\n        cin\
    \ >> a >> b;\n        seg.change(i-250000, Monoid(a, b));\n    }\n\n    while(Q--)\
    \ {\n        int type;\n        cin >> type;\n        int x, y, z;\n        cin\
    \ >> x >> y >> z;\n        x -= 250000;\n        if(type == 0) {\n           \
    \ seg.change(x, Monoid(y, z));\n        }\n        else {\n            y -= 250000;\n\
    \            auto [a, b] = seg.get(x, y-1);\n            cout << a * z + b <<\
    \ '\\n';\n        }\n    }\n}"
  dependsOn:
  - Utilities/modint998.hpp
  - DataStructures/DynamicSegTree.hpp
  isVerificationFile: true
  path: verify/dynamicsegtree.test.cpp
  requiredBy: []
  timestamp: '2024-05-11 03:28:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/dynamicsegtree.test.cpp
layout: document
redirect_from:
- /verify/verify/dynamicsegtree.test.cpp
- /verify/verify/dynamicsegtree.test.cpp.html
title: verify/dynamicsegtree.test.cpp
---
