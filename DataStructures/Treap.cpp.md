---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Treap
    links: []
  bundledCode: "#line 1 \"DataStructures/Treap.cpp\"\nclass xorshift {\n    uint64_t\
    \ x;\n    public:\n        xorshift() {\n            mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());\n\
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
    \        }\n \n        \n  \n};\n\n\n\n struct Monoid {\n\n    ll a;\n   \n  \
    \   Monoid(){}\n       \n     Monoid(ll _a) : a(_a) {}\n   \n     friend Monoid\
    \ op(const Monoid& l, const Monoid& r) {\n       return l.a + r.a;\n     }\n\n\
    \     static Monoid ide() {\n        return 0LL;\n    }\n   \n    bool operator==(const\
    \ Monoid& x) const {return a == x.a;}\n    bool operator!=(const Monoid& x) const\
    \ {return a != x.a;}\n\n};\n\nstruct E {\n    ll a;\n   \n     E(){}\n       \n\
    \     E(ll _a) : a(_a) {\n       \n     }\n   \n     friend E op(const E& l, const\
    \ E& r) {\n       return l.a + r.a;\n     }\n   \n    static E ide() {\n     \
    \   return 0LL;\n    }\n\n    bool operator==(const E& x) const {return a == x.a;}\n\
    \    bool operator!=(const E& x) const {return a != x.a;}\n};\n\n\nMonoid fx(const\
    \ Monoid& l, const E& r, long long len) {\n     return l.a + r.a;\n} \n\n/*\n\
    @brief Treap\n*/\n"
  code: "class xorshift {\n    uint64_t x;\n    public:\n        xorshift() {\n  \
    \          mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());\n\
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
    \        }\n \n        \n  \n};\n\n\n\n struct Monoid {\n\n    ll a;\n   \n  \
    \   Monoid(){}\n       \n     Monoid(ll _a) : a(_a) {}\n   \n     friend Monoid\
    \ op(const Monoid& l, const Monoid& r) {\n       return l.a + r.a;\n     }\n\n\
    \     static Monoid ide() {\n        return 0LL;\n    }\n   \n    bool operator==(const\
    \ Monoid& x) const {return a == x.a;}\n    bool operator!=(const Monoid& x) const\
    \ {return a != x.a;}\n\n};\n\nstruct E {\n    ll a;\n   \n     E(){}\n       \n\
    \     E(ll _a) : a(_a) {\n       \n     }\n   \n     friend E op(const E& l, const\
    \ E& r) {\n       return l.a + r.a;\n     }\n   \n    static E ide() {\n     \
    \   return 0LL;\n    }\n\n    bool operator==(const E& x) const {return a == x.a;}\n\
    \    bool operator!=(const E& x) const {return a != x.a;}\n};\n\n\nMonoid fx(const\
    \ Monoid& l, const E& r, long long len) {\n     return l.a + r.a;\n} \n\n/*\n\
    @brief Treap\n*/"
  dependsOn: []
  isVerificationFile: false
  path: DataStructures/Treap.cpp
  requiredBy: []
  timestamp: '2024-05-11 03:22:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructures/Treap.cpp
layout: document
redirect_from:
- /library/DataStructures/Treap.cpp
- /library/DataStructures/Treap.cpp.html
title: Treap
---
