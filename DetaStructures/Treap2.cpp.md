---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Treap(\u5024\u96C6\u7D04\u306A\u3057)"
    links: []
  bundledCode: "#line 1 \"DetaStructures/Treap2.cpp\"\nclass xorshift {\n    uint64_t\
    \ x;\n    public:\n        xorshift() {\n            mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());\n\
    \            x = rnd();\n            for (int i = 0; i < 100; i++) {\n       \
    \         random();\n            }\n        }\n        uint64_t random() {\n \
    \           x = x ^ (x << 7);\n            return x = x ^ (x >> 9);\n    }\n};\n\
    \ntemplate<typename T>\nstruct Treap {\n    xorshift rnd;\n\n    private:\n  \
    \      struct node_t{\n            node_t* lch;\n            node_t* rch;\n  \
    \          int pri = 0, cnt = 1;\n            T val;\n            bool rev;\n\n\
    \            node_t(){}\n            node_t(T v, int p) : val(v), pri(p) {\n \
    \               lch = rch = nullptr;\n                rev = false;\n         \
    \   }\n        };\n\n        node_t* root = nullptr;\n\n            \n       \
    \ int count(node_t* t) {return !t ? 0 : t -> cnt;}\n        \n\n        node_t*\
    \ pushup(node_t* t) {\n           if(t) t -> cnt = count(t -> lch) + count(t ->\
    \ rch) + 1;\n            return t;\n        }\n\n        void pushdown(node_t\
    \ *t) {\n            if(t && t -> rev) {\n                swap(t -> lch, t ->\
    \ rch);\n                if(t -> lch) t -> lch -> rev ^= 1;\n                if(t\
    \ -> rch) t -> rch -> rev ^= 1;\n                t -> rev = false;\n         \
    \   }\n            pushup(t);\n        }\n\n\n\n        void merge(node_t*& t,\
    \ node_t* l, node_t* r) {\n            pushdown(l), pushdown(r);\n           \
    \ if(!l || !r) t =  !l ? r : l;\n            else if(l -> pri > r -> pri) {\n\
    \                merge(l -> rch, l -> rch, r);\n                t = l;\n     \
    \       } else {\n               merge(r -> lch, l,r -> lch);\n              \
    \ t = r;\n            }\n            pushup(t);\n        }\n\n        void split(node_t*\
    \ t, int k, node_t*& tl, node_t*& tr) {// [0, k) [k, n)\n            if(!t) {\n\
    \                tl = nullptr, tr = nullptr;\n                return;\n      \
    \      }\n            pushdown(t);\n \n            if(k <= count(t -> lch)) {\n\
    \                split(t -> lch, k, tl, t -> lch);\n                tr = t;\n\
    \            }else {\n                split(t -> rch, k - count(t -> lch) - 1,\
    \ t -> rch, tr);\n                tl = t;\n            }\n            pushup(t);\n\
    \        }\n\n         void insert__(node_t*& t, int k,  node_t* item) {\n   \
    \         node_t* tl; node_t* tr;\n            split(t, k, tl, tr);\n        \
    \    merge(tl, tl, item);\n            merge(t, tl, tr);\n        }\n        \n\
    \        \n        void erase__(node_t*& t, int k) {\n            node_t* tl;\
    \ node_t* tm; node_t* tr;\n            split(t, k+1, tl, tm);\n            split(tl,\
    \ k, tl, tr);\n            merge(t, tl, tm);\n        }\n\n        void reverse__(node_t*\
    \ t, int l, int r) {//[l, r)\n            if(l >= r) return;\n            node_t*\
    \ tl; node_t* tm; node_t* tr;\n            split(t, l, tl, tm);\n            split(tm,\
    \ r - l, tm, tr);\n            tm -> rev ^= 1;\n            merge(tm, tm, tr);\n\
    \            merge(t, tl, tm);\n        }\n\n        node_t* ith__(node_t* t,\
    \ int k) {\n            pushdown(t);\n            int c = count(t -> lch), b =\
    \ (k > c);\n            if(k == c) return t;\n            if(b) return ith__(t\
    \ -> rch, k - (c+1));\n            else return ith__(t -> lch, k);\n        }\n\
    \n\n        void dump__(node_t* t) {\n            if(!t) return;\n           \
    \ pushdown(t);\n            dump__(t -> lch);\n            cout << t -> val <<\
    \ \" \";\n            dump__(t -> rch);\n        }\n\n\n\n\n    \n\n    public:\n\
    \        void insert(int pos, T val) {\n            insert__(root, pos, new node_t(val,rnd.random()));\n\
    \        }\n\n        void erase(int pos) {\n             erase__(root, pos);\n\
    \        }\n\n\n        void reverse(int l, int r) {\n            reverse__(root,\
    \ l, r+1);\n        }\n        \n        T ith(int pos) {\n            return\
    \ ith__(root, pos) -> val;\n        }\n\n        int size() {\n            return\
    \ count(root);\n        }\n\n        void dump() {\n            dump__(root);\n\
    \            cout << endl;\n        }\n\n};\n\n/*\n@brief Treap(\u5024\u96C6\u7D04\
    \u306A\u3057)\n*/\n\n"
  code: "class xorshift {\n    uint64_t x;\n    public:\n        xorshift() {\n  \
    \          mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());\n\
    \            x = rnd();\n            for (int i = 0; i < 100; i++) {\n       \
    \         random();\n            }\n        }\n        uint64_t random() {\n \
    \           x = x ^ (x << 7);\n            return x = x ^ (x >> 9);\n    }\n};\n\
    \ntemplate<typename T>\nstruct Treap {\n    xorshift rnd;\n\n    private:\n  \
    \      struct node_t{\n            node_t* lch;\n            node_t* rch;\n  \
    \          int pri = 0, cnt = 1;\n            T val;\n            bool rev;\n\n\
    \            node_t(){}\n            node_t(T v, int p) : val(v), pri(p) {\n \
    \               lch = rch = nullptr;\n                rev = false;\n         \
    \   }\n        };\n\n        node_t* root = nullptr;\n\n            \n       \
    \ int count(node_t* t) {return !t ? 0 : t -> cnt;}\n        \n\n        node_t*\
    \ pushup(node_t* t) {\n           if(t) t -> cnt = count(t -> lch) + count(t ->\
    \ rch) + 1;\n            return t;\n        }\n\n        void pushdown(node_t\
    \ *t) {\n            if(t && t -> rev) {\n                swap(t -> lch, t ->\
    \ rch);\n                if(t -> lch) t -> lch -> rev ^= 1;\n                if(t\
    \ -> rch) t -> rch -> rev ^= 1;\n                t -> rev = false;\n         \
    \   }\n            pushup(t);\n        }\n\n\n\n        void merge(node_t*& t,\
    \ node_t* l, node_t* r) {\n            pushdown(l), pushdown(r);\n           \
    \ if(!l || !r) t =  !l ? r : l;\n            else if(l -> pri > r -> pri) {\n\
    \                merge(l -> rch, l -> rch, r);\n                t = l;\n     \
    \       } else {\n               merge(r -> lch, l,r -> lch);\n              \
    \ t = r;\n            }\n            pushup(t);\n        }\n\n        void split(node_t*\
    \ t, int k, node_t*& tl, node_t*& tr) {// [0, k) [k, n)\n            if(!t) {\n\
    \                tl = nullptr, tr = nullptr;\n                return;\n      \
    \      }\n            pushdown(t);\n \n            if(k <= count(t -> lch)) {\n\
    \                split(t -> lch, k, tl, t -> lch);\n                tr = t;\n\
    \            }else {\n                split(t -> rch, k - count(t -> lch) - 1,\
    \ t -> rch, tr);\n                tl = t;\n            }\n            pushup(t);\n\
    \        }\n\n         void insert__(node_t*& t, int k,  node_t* item) {\n   \
    \         node_t* tl; node_t* tr;\n            split(t, k, tl, tr);\n        \
    \    merge(tl, tl, item);\n            merge(t, tl, tr);\n        }\n        \n\
    \        \n        void erase__(node_t*& t, int k) {\n            node_t* tl;\
    \ node_t* tm; node_t* tr;\n            split(t, k+1, tl, tm);\n            split(tl,\
    \ k, tl, tr);\n            merge(t, tl, tm);\n        }\n\n        void reverse__(node_t*\
    \ t, int l, int r) {//[l, r)\n            if(l >= r) return;\n            node_t*\
    \ tl; node_t* tm; node_t* tr;\n            split(t, l, tl, tm);\n            split(tm,\
    \ r - l, tm, tr);\n            tm -> rev ^= 1;\n            merge(tm, tm, tr);\n\
    \            merge(t, tl, tm);\n        }\n\n        node_t* ith__(node_t* t,\
    \ int k) {\n            pushdown(t);\n            int c = count(t -> lch), b =\
    \ (k > c);\n            if(k == c) return t;\n            if(b) return ith__(t\
    \ -> rch, k - (c+1));\n            else return ith__(t -> lch, k);\n        }\n\
    \n\n        void dump__(node_t* t) {\n            if(!t) return;\n           \
    \ pushdown(t);\n            dump__(t -> lch);\n            cout << t -> val <<\
    \ \" \";\n            dump__(t -> rch);\n        }\n\n\n\n\n    \n\n    public:\n\
    \        void insert(int pos, T val) {\n            insert__(root, pos, new node_t(val,rnd.random()));\n\
    \        }\n\n        void erase(int pos) {\n             erase__(root, pos);\n\
    \        }\n\n\n        void reverse(int l, int r) {\n            reverse__(root,\
    \ l, r+1);\n        }\n        \n        T ith(int pos) {\n            return\
    \ ith__(root, pos) -> val;\n        }\n\n        int size() {\n            return\
    \ count(root);\n        }\n\n        void dump() {\n            dump__(root);\n\
    \            cout << endl;\n        }\n\n};\n\n/*\n@brief Treap(\u5024\u96C6\u7D04\
    \u306A\u3057)\n*/\n\n"
  dependsOn: []
  isVerificationFile: false
  path: DetaStructures/Treap2.cpp
  requiredBy: []
  timestamp: '2024-05-10 22:51:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DetaStructures/Treap2.cpp
layout: document
redirect_from:
- /library/DetaStructures/Treap2.cpp
- /library/DetaStructures/Treap2.cpp.html
title: "Treap(\u5024\u96C6\u7D04\u306A\u3057)"
---
