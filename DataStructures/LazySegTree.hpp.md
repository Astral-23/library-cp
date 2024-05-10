---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/lazyseg.test.cpp
    title: verify/lazyseg.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
    links: []
  bundledCode: "#line 1 \"DataStructures/LazySegTree.hpp\"\n\ntemplate<typename X,\
    \ typename E>\nstruct LazySegTree {\n    using FX = function<X(X, E, long long)>;//X\u306B\
    \u4F5C\u7528\u7D20M\u3092\u4F5C\u7528\u3055\u305B\u308B\n    \n    int n;\n  \
    \  int siz;\n    FX fx; \n    vector<X> dat;\n    vector<E> lazy;\n    LazySegTree(int\
    \ _siz, FX _fx) : siz(_siz),  fx(_fx) {\n        n = 1;\n        while(n < siz)\
    \ n <<= 1;\n        dat.assign(n * 2, X::ide());\n        lazy.assign(n * 2, E::ide());\n\
    \    }\n\n    private:\n        void eval(int k, int len) {\n            if(lazy[k]\
    \ == E::ide()) return;\n            if(k < n) {\n              lazy[k<<1] = op(lazy[k<<1],\
    \ lazy[k]);\n              lazy[k<<1|1] = op(lazy[k<<1|1], lazy[k]);\n       \
    \     }\n            dat[k] = fx(dat[k], lazy[k], len);\n            lazy[k] =\
    \ E::ide();\n        }    \n\n        X query(int a, int b, int l, int r, int\
    \ k) {\n            eval(k,r-l);\n            if(r <= a || b <= l) return X::ide();\n\
    \            if(a <= l && r <= b) return dat[k];\n            int mid = (l + r)>>1;\n\
    \            X L = query(a, b, l, mid, k<<1);\n            X R = query(a, b, mid,\
    \ r, k<<1|1);\n            return op(L, R);\n        }  \n\n        void update(int\
    \ a, int b, E m, int l, int r,  int k) {//[a, b) := \u30AF\u30A8\u30EA\u533A\u9593\
    \  [l, r) := \u4ECA\u898B\u3066\u3044\u308B\u533A\u9593\n            eval(k, r-l);\n\
    \            if(r <= a || b <= l) return;\n            if(a <= l && r <= b) {\n\
    \                lazy[k] = op(lazy[k], m);\n                eval(k, r-l);\n  \
    \          }\n            else {\n                int mid = (l + r)>>1;\n    \
    \            update(a, b, m, l, mid, k<<1);\n                update(a, b, m, mid,\
    \ r, k<<1|1);\n                dat[k] = op(dat[k<<1], dat[k<<1|1]);\n        \
    \    }\n        }   \n    \n    public:\n\n        void set(int i, X x) {\n  \
    \          dat[i + n - 1] =  x;\n        }    \n\n        void init() {\n    \
    \        for(int i = n-1; i >= 1; i--) {\n                dat[i] = op(dat[i<<1],\
    \ dat[i<<1|1]);\n            }\n        }    \n    \n        void change(int l,\
    \ int r, E m) {\n            update(l, r + 1, m, 1, n + 1, 1);\n        }\n\n\
    \        X get(int l, int r) {\n          return query(l, r + 1, 1, n + 1, 1);\n\
    \        }\n\n        void dump() {\n            for(int i = 1; i <= siz; i++)\
    \ {\n                cout << get(i, i) << \" \";//\u9069\u5B9C\u76F4\u3059\u3002\
    \n            }\n            cout << endl;\n        }\n};    \n/*\n@brief \u9045\
    \u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n*/\n"
  code: "\ntemplate<typename X, typename E>\nstruct LazySegTree {\n    using FX =\
    \ function<X(X, E, long long)>;//X\u306B\u4F5C\u7528\u7D20M\u3092\u4F5C\u7528\u3055\
    \u305B\u308B\n    \n    int n;\n    int siz;\n    FX fx; \n    vector<X> dat;\n\
    \    vector<E> lazy;\n    LazySegTree(int _siz, FX _fx) : siz(_siz),  fx(_fx)\
    \ {\n        n = 1;\n        while(n < siz) n <<= 1;\n        dat.assign(n * 2,\
    \ X::ide());\n        lazy.assign(n * 2, E::ide());\n    }\n\n    private:\n \
    \       void eval(int k, int len) {\n            if(lazy[k] == E::ide()) return;\n\
    \            if(k < n) {\n              lazy[k<<1] = op(lazy[k<<1], lazy[k]);\n\
    \              lazy[k<<1|1] = op(lazy[k<<1|1], lazy[k]);\n            }\n    \
    \        dat[k] = fx(dat[k], lazy[k], len);\n            lazy[k] = E::ide();\n\
    \        }    \n\n        X query(int a, int b, int l, int r, int k) {\n     \
    \       eval(k,r-l);\n            if(r <= a || b <= l) return X::ide();\n    \
    \        if(a <= l && r <= b) return dat[k];\n            int mid = (l + r)>>1;\n\
    \            X L = query(a, b, l, mid, k<<1);\n            X R = query(a, b, mid,\
    \ r, k<<1|1);\n            return op(L, R);\n        }  \n\n        void update(int\
    \ a, int b, E m, int l, int r,  int k) {//[a, b) := \u30AF\u30A8\u30EA\u533A\u9593\
    \  [l, r) := \u4ECA\u898B\u3066\u3044\u308B\u533A\u9593\n            eval(k, r-l);\n\
    \            if(r <= a || b <= l) return;\n            if(a <= l && r <= b) {\n\
    \                lazy[k] = op(lazy[k], m);\n                eval(k, r-l);\n  \
    \          }\n            else {\n                int mid = (l + r)>>1;\n    \
    \            update(a, b, m, l, mid, k<<1);\n                update(a, b, m, mid,\
    \ r, k<<1|1);\n                dat[k] = op(dat[k<<1], dat[k<<1|1]);\n        \
    \    }\n        }   \n    \n    public:\n\n        void set(int i, X x) {\n  \
    \          dat[i + n - 1] =  x;\n        }    \n\n        void init() {\n    \
    \        for(int i = n-1; i >= 1; i--) {\n                dat[i] = op(dat[i<<1],\
    \ dat[i<<1|1]);\n            }\n        }    \n    \n        void change(int l,\
    \ int r, E m) {\n            update(l, r + 1, m, 1, n + 1, 1);\n        }\n\n\
    \        X get(int l, int r) {\n          return query(l, r + 1, 1, n + 1, 1);\n\
    \        }\n\n        void dump() {\n            for(int i = 1; i <= siz; i++)\
    \ {\n                cout << get(i, i) << \" \";//\u9069\u5B9C\u76F4\u3059\u3002\
    \n            }\n            cout << endl;\n        }\n};    \n/*\n@brief \u9045\
    \u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n*/"
  dependsOn: []
  isVerificationFile: false
  path: DataStructures/LazySegTree.hpp
  requiredBy: []
  timestamp: '2024-05-11 03:22:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/lazyseg.test.cpp
documentation_of: DataStructures/LazySegTree.hpp
layout: document
redirect_from:
- /library/DataStructures/LazySegTree.hpp
- /library/DataStructures/LazySegTree.hpp.html
title: "\u9045\u5EF6\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---
