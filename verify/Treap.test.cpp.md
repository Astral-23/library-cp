---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructures/Treap.hpp
    title: Treap
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
    PROBLEM: https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum
  bundledCode: "#line 1 \"verify/Treap.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
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
    using mint = modint<998244353>;\n/*\n@brief modint998244353\n*/\n#line 1 \"DataStructures/Treap.hpp\"\
    \nclass xorshift {\n    uint64_t x;\n    public:\n        xorshift() {\n     \
    \       mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());\n\
    \            x = rnd();\n            for (int i = 0; i < 100; i++) {\n       \
    \         random();\n            }\n        }\n        uint64_t random() {\n \
    \           x = x ^ (x << 7);\n            return x = x ^ (x >> 9);\n    }\n};\n\
    \n\ntemplate<typename T1, typename T2>\nstruct Treap {\n    xorshift rnd;\n  \
    \  public:\n        Treap(function<T1(T1, T2, long long)> _fx) : fx(_fx) {}\n\
    \    private:\n        struct node_t{\n            node_t* lch;\n            node_t*\
    \ rch;\n            int pri, cnt;\n            T1 val, acc;\n            T2 lazy;\n\
    \            bool rev;\n \n            node_t(T1 v, int p) : val(v), pri(p), acc(v)\
    \ , lch(nullptr), rch(nullptr), rev(false), cnt(1) {\n                lazy = T2::ide();\n\
    \            }\n        };\n\n        function<T1(T1, T2, long long)> fx;\n\n\
    \ \n        node_t* root = nullptr;\n\n        long long count(node_t* t) {return\
    \ !t ? 0 : t -> cnt;}\n        \n        T1 acc(node_t* t) {return !t ? T1::ide()\
    \ : t -> acc; }\n\n        \n\n        node_t* pushup(node_t* t) {\n         \
    \   if(t) {\n                t -> cnt = count(t -> lch) + count(t -> rch) + 1;\n\
    \                t -> acc = op(op(acc(t -> lch), t -> val),  acc(t -> rch));\n\
    \            }\n            return t;\n        }\n \n \n        void pushdown(node_t\
    \ *t) {\n            if(t && t -> rev) {\n                swap(t -> lch, t ->\
    \ rch);\n                if(t -> lch) t -> lch -> rev ^= 1;\n                if(t\
    \ -> rch) t -> rch -> rev ^= 1;\n                t -> rev = false;\n         \
    \   }\n\n            if(t && t -> lazy != T2::ide()) {\n                if(t ->\
    \ lch) {\n                    t -> lch-> lazy = op(t -> lch -> lazy, t -> lazy);\n\
    \                    t -> lch -> acc = fx(t -> lch -> acc, t -> lazy, count(t\
    \ -> lch));\n                }\n\n                if(t -> rch) {\n           \
    \         t -> rch -> lazy = op(t -> rch -> lazy, t -> lazy);\n              \
    \      t -> rch -> acc = fx(t -> rch -> acc, t -> lazy, count(t -> rch));\n  \
    \              }\n\n                t -> val = fx(t -> val, t -> lazy, 1LL);\n\
    \                t -> lazy = T2::ide();\n            }\n            pushup(t);\n\
    \        }\n \n \n            \n        \n \n        \n \n        void merge(node_t*&\
    \ t, node_t* l, node_t* r) {\n            pushdown(l), pushdown(r);\n        \
    \    if(!l || !r) t =  !l ? r : l;\n            else if(l -> pri > r -> pri) {\n\
    \                merge(l -> rch, l -> rch, r);\n                t = l;\n     \
    \       } else {\n               merge(r -> lch, l,r -> lch);\n              \
    \ t = r;\n            }\n            pushup(t);\n        }\n\n\n \n        void\
    \ split(node_t* t, int k, node_t*& tl, node_t*& tr) {// [0, k) [k, n)\n      \
    \      if(!t) {\n                tl = nullptr, tr = nullptr;\n               \
    \ return;\n            }\n            pushdown(t);\n \n            if(k <= count(t\
    \ -> lch)) {\n                split(t -> lch, k, tl, t -> lch);\n            \
    \    tr = t;\n            }else {\n                split(t -> rch, k - count(t\
    \ -> lch) - 1, t -> rch, tr);\n                tl = t;\n            }\n      \
    \      pushup(t);\n        }\n\n\n        //k+1\u500B\u76EE\u3001\u3064\u307E\u308A\
    k\u756A\u76EE\u306B\u306A\u308B\u3002\n        void insert__(node_t*& t, int k,\
    \  node_t* item) {\n            node_t* tl; node_t* tr;\n            split(t,\
    \ k, tl, tr);\n            merge(tl, tl, item);\n            merge(t, tl, tr);\n\
    \        }\n        \n        void erase__(node_t*& t, int k) {\n            node_t*\
    \ tl; node_t* tm; node_t* tr;\n            split(t, k+1, tl, tm);\n          \
    \  split(tl, k, tl, tr);\n            merge(t, tl, tm);\n        }\n \n      \
    \  void reverse__(node_t* t, int l, int r) {//[l, r)\n            if(l >= r) return;\n\
    \            node_t* tl; node_t* tm; node_t* tr;\n            split(t, l, tl,\
    \ tm);\n            split(tm, r - l, tm, tr);\n            tm -> rev ^= 1;\n \
    \           merge(tm, tm, tr);\n            merge(t, tl, tm);\n        }\n   \
    \     \n        void change__(node_t* t, int l, int r, T2 x) {\n            if(l\
    \ >= r) return;\n            node_t* tl; node_t* tm; node_t* tr;\n           \
    \ split(t, l, tl, tm);\n            split(tm, r - l, tm, tr);\n            tm\
    \ -> lazy = op(tm -> lazy, x);\n            tm -> acc = fx(tm -> acc, x, count(tm));\n\
    \            merge(tm, tm, tr);\n            merge(t, tl, tm);\n\n        }\n\n\
    \        T1 query(int l, int r) {\n            if(l >= r) return T1::ide();\n\
    \            node_t* tl; node_t* tm; node_t* tr;\n            split(root, l, tl,\
    \ tm);\n            split(tm, r-l, tm, tr);\n            T1 res = acc(tm);\n \
    \           merge(tm, tm, tr);\n            merge(root, tl, tm);\n           \
    \ return res;\n        }\n\n\n\n\n        void dump__(node_t* t) {\n         \
    \   if(!t) return;\n            pushdown(t);\n            dump__(t -> lch);\n\
    \            cout << t -> val.a << \" \";\n            dump__(t -> rch);\n   \
    \     }\n\n\n      \n\n \n\n    public:\n        void insert(int pos, T1 val)\
    \ {\n            insert__(root, pos, new node_t(val,rnd.random()));\n        }\n\
    \ \n        void erase(int pos) {\n            erase__(root, pos);\n        }\n\
    \ \n \n        void reverse(int l, int r) {//[l, r]\u3092reverse\n           \
    \ if(l > r) return;\n            reverse__(root, l, r+1);\n        }\n \n    \
    \    void rotate(int l, int m, int r) {//[l, r] \u3092 m\u304C\u5148\u982D\u306B\
    \u6765\u308B\u69D8\u306Breverse\n            r++;\n            if(l > r) return;\n\
    \            reverse__(root, l, r);\n            reverse__(root, l, l + r - m);\n\
    \            reverse__(root, l + r - m, r);\n        }\n        \n        T1 ith\
    \ (int pos) {\n            return query(pos, pos+1);\n        }\n\n        T1\
    \ get(int l, int r) {return query(l, r + 1);}\n\n        \n\n        void change(int\
    \ l,int r, T2 val) {\n            change__(root, l, r+1, val);\n        }\n\n\
    \        void dump() {\n            dump__(root);\n            cout << endl;\n\
    \        }\n \n        \n  \n};\n\n\n\n/*\n@brief Treap\n*/\n#line 6 \"verify/Treap.test.cpp\"\
    \nusing ll = long long;\nusing vvl = vector<vector<ll>>;\nusing vl = vector<ll>;\n\
    #define rep(i, s, f) for(long long i = s; i <= f; i++)\n#define ENDL '\\n'\n\n\
    \ struct Monoid {\n\n    mint a;\n   \n     Monoid(){}\n       \n     Monoid(mint\
    \ _a) : a(_a) {}\n   \n     friend Monoid op(const Monoid& l, const Monoid& r)\
    \ {\n       return l.a + r.a;\n     }\n\n     static Monoid ide() {\n        return\
    \ mint(0);\n    }\n   \n\n};\n\nstruct E {\n    mint p, b;\n   \n     E(){}\n\
    \       \n     E(mint _p, mint _x) {\n       p = _p;\n       b = _x;\n     }\n\
    \   \n     friend E op(const E& l, const E& r) {\n       E res;\n       res.p\
    \ = l.p * r.p;\n       res.b = r.p * l.b + r.b;\n       return res;\n     }\n\
    \   \n    static E ide() {\n        return E(1, 0);\n    }\n\n    bool operator==(const\
    \ E& x) const {return (p == x.p) && (b == x.b);}\n    bool operator!=(const E&\
    \ x) const {return (p != x.p) || (b != x.b);}\n};\n\n\nMonoid fx(const Monoid&\
    \ l, const E& r, long long len) {\n     return r.p * l.a + r.b * len;\n}\n\nint\
    \ main() {\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n   \
    \ cout << fixed << setprecision(15);\n    Treap<Monoid, E> tr(fx);\n    ll N,\
    \ Q;\n    cin >> N >> Q;\n    for(int i = 0; i <= N-1; i++) {\n        mint a;\n\
    \        cin >> a;\n        tr.insert(i, a);\n    }\n\n    \n\n    while(Q--)\
    \ {\n        int type;\n        cin >> type;\n        if(type == 0) {\n      \
    \      ll i, x;\n            cin >> i >> x;\n           tr.insert(i, Monoid(x));\n\
    \            N++;\n        }\n        else if(type==1) {\n            int i;\n\
    \            cin >> i;\n            tr.erase(i);\n            N--;\n        }\n\
    \        else if(type==2) {\n            ll l, r;\n            cin >> l >> r;\n\
    \            r--;\n            tr.reverse(l,r);\n        }\n        else if(type==3)\
    \ {\n            ll l, r;\n            mint b, c;\n            cin >> l >> r >>\
    \ b >> c;\n            r--;\n            tr.change(l, r, E(b, c));\n        }\n\
    \        else {\n            ll l, r;\n            cin >> l >> r;\n          \
    \  r--;\n            cout << tr.get(l, r).a << \" \";\n        }\n    }\n\n  /*\n\
    \n    while(Q--) {\n        ll type;\n        cin >> type;\n        if(type ==\
    \ 0) {\n            ll l, r, b, c;\n            cin >> l >> r >> b >> c;\n   \
    \         tr.change(l, r-1, E(b, c));\n        }\n        else {\n           \
    \ ll l, r;\n            cin >> l >> r;\n            cout << tr.get(l, r-1).a <<\
    \ \" \";\n        }\n    }*/\n\n\n    \n    \n    \n    \n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/dynamic_sequence_range_affine_range_sum\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\n#include \"../Utilities/modint998.hpp\"\
    \n#include \"../DataStructures/Treap.hpp\"\nusing ll = long long;\nusing vvl =\
    \ vector<vector<ll>>;\nusing vl = vector<ll>;\n#define rep(i, s, f) for(long long\
    \ i = s; i <= f; i++)\n#define ENDL '\\n'\n\n struct Monoid {\n\n    mint a;\n\
    \   \n     Monoid(){}\n       \n     Monoid(mint _a) : a(_a) {}\n   \n     friend\
    \ Monoid op(const Monoid& l, const Monoid& r) {\n       return l.a + r.a;\n  \
    \   }\n\n     static Monoid ide() {\n        return mint(0);\n    }\n   \n\n};\n\
    \nstruct E {\n    mint p, b;\n   \n     E(){}\n       \n     E(mint _p, mint _x)\
    \ {\n       p = _p;\n       b = _x;\n     }\n   \n     friend E op(const E& l,\
    \ const E& r) {\n       E res;\n       res.p = l.p * r.p;\n       res.b = r.p\
    \ * l.b + r.b;\n       return res;\n     }\n   \n    static E ide() {\n      \
    \  return E(1, 0);\n    }\n\n    bool operator==(const E& x) const {return (p\
    \ == x.p) && (b == x.b);}\n    bool operator!=(const E& x) const {return (p !=\
    \ x.p) || (b != x.b);}\n};\n\n\nMonoid fx(const Monoid& l, const E& r, long long\
    \ len) {\n     return r.p * l.a + r.b * len;\n}\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    cout << fixed << setprecision(15);\n    Treap<Monoid,\
    \ E> tr(fx);\n    ll N, Q;\n    cin >> N >> Q;\n    for(int i = 0; i <= N-1; i++)\
    \ {\n        mint a;\n        cin >> a;\n        tr.insert(i, a);\n    }\n\n \
    \   \n\n    while(Q--) {\n        int type;\n        cin >> type;\n        if(type\
    \ == 0) {\n            ll i, x;\n            cin >> i >> x;\n           tr.insert(i,\
    \ Monoid(x));\n            N++;\n        }\n        else if(type==1) {\n     \
    \       int i;\n            cin >> i;\n            tr.erase(i);\n            N--;\n\
    \        }\n        else if(type==2) {\n            ll l, r;\n            cin\
    \ >> l >> r;\n            r--;\n            tr.reverse(l,r);\n        }\n    \
    \    else if(type==3) {\n            ll l, r;\n            mint b, c;\n      \
    \      cin >> l >> r >> b >> c;\n            r--;\n            tr.change(l, r,\
    \ E(b, c));\n        }\n        else {\n            ll l, r;\n            cin\
    \ >> l >> r;\n            r--;\n            cout << tr.get(l, r).a << \" \";\n\
    \        }\n    }\n\n  /*\n\n    while(Q--) {\n        ll type;\n        cin >>\
    \ type;\n        if(type == 0) {\n            ll l, r, b, c;\n            cin\
    \ >> l >> r >> b >> c;\n            tr.change(l, r-1, E(b, c));\n        }\n \
    \       else {\n            ll l, r;\n            cin >> l >> r;\n           \
    \ cout << tr.get(l, r-1).a << \" \";\n        }\n    }*/\n\n\n    \n    \n   \
    \ \n    \n}"
  dependsOn:
  - Utilities/modint998.hpp
  - DataStructures/Treap.hpp
  isVerificationFile: true
  path: verify/Treap.test.cpp
  requiredBy: []
  timestamp: '2024-05-11 03:35:55+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/Treap.test.cpp
layout: document
redirect_from:
- /verify/verify/Treap.test.cpp
- /verify/verify/Treap.test.cpp.html
title: verify/Treap.test.cpp
---
