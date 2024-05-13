---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/SegTree.test.cpp
    title: verify/SegTree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/segtree.md
    document_title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
    links: []
  bundledCode: "#line 1 \"DataStructures/SegTree.hpp\"\ntemplate<typename T>\nstruct\
    \ SegTree {\n    int n;\n    vector<T> dat;\n\n         \n    SegTree(int siz)\
    \ {\n        n = 1;\n        while(n < siz) n <<= 1;\n        dat.resize(n * 2,\
    \ T::ide());\n    }\n\n    private:\n         \n        T query(int l, int r)\
    \ {\n            T L = T::ide(), R = T::ide();\n            l += n - 1, r += n\
    \ - 1;\n            while(l < r) {\n                if(l & 1) L = op(L, dat[l++]);\n\
    \                if(r & 1) R = op(dat[--r], R);\n                l >>= 1, r >>=\
    \ 1;\n            }  \n            return  op(L, R);\n        }\n\n    \n    public:\n\
    \n        void set(int pos, T x) {\n            pos += n-1;\n            dat[pos]\
    \ = x;\n        }\n          \n        void init() {\n            for(int i =\
    \ n-1; i >= 1; i--)  dat[i] = op(dat[i<<1], dat[i<<1|1]);\n        }\n       \
    \   \n        void change(int pos, T x) {\n            pos += n - 1;\n       \
    \     dat[pos] = update(dat[pos], x);\n            while(pos >= 2) {\n       \
    \         pos >>= 1;\n                dat[pos] = op(dat[pos<<1], dat[pos<<1|1]);\n\
    \            }\n        }\n         \n        T get(int l, int r) {// [l, r]\u306E\
    \u6F14\u7B97\u7D50\u679C\u3002\n            return query(l, r+1);\n        }\n\
    \n        T operator[](int pos) {\n            return dat[pos + n - 1];\n    \
    \    }\n         \n};\n\n\n/*\n@brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n@docs\
    \ docs/segtree.md\n*/\n"
  code: "template<typename T>\nstruct SegTree {\n    int n;\n    vector<T> dat;\n\n\
    \         \n    SegTree(int siz) {\n        n = 1;\n        while(n < siz) n <<=\
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
    /*\n@brief \u30BB\u30B0\u30E1\u30F3\u30C8\u6728\n@docs docs/segtree.md\n*/"
  dependsOn: []
  isVerificationFile: false
  path: DataStructures/SegTree.hpp
  requiredBy: []
  timestamp: '2024-05-11 03:22:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/SegTree.test.cpp
documentation_of: DataStructures/SegTree.hpp
layout: document
redirect_from:
- /library/DataStructures/SegTree.hpp
- /library/DataStructures/SegTree.hpp.html
title: "\u30BB\u30B0\u30E1\u30F3\u30C8\u6728"
---
## テスト