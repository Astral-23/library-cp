---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: ": \u30BB\u30B0\u6728"
    links: []
  bundledCode: "#line 1 \"DetaStructures/SegTree.cpp\"\ntemplate<typename T>\nstruct\
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
    \    }\n         \n};\n\n\n\nstruct Monoid {\n    long long a;\n   \n    Monoid(){}\n\
    \      \n    Monoid(long long _a) : a(_a) {\n      \n    }\n\n    friend Monoid\
    \ op(const Monoid& l, const Monoid& r) {\n      return l.a + r.a;\n    }\n\n \
    \   friend Monoid update(const Monoid& l, const Monoid& r) {\n   \n    }\n\n \
    \   static Monoid ide() {\n       return 0LL;\n    }\n    \n};\n\n/*\n@brief :\
    \ \u30BB\u30B0\u6728\n*/\n"
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
    \nstruct Monoid {\n    long long a;\n   \n    Monoid(){}\n      \n    Monoid(long\
    \ long _a) : a(_a) {\n      \n    }\n\n    friend Monoid op(const Monoid& l, const\
    \ Monoid& r) {\n      return l.a + r.a;\n    }\n\n    friend Monoid update(const\
    \ Monoid& l, const Monoid& r) {\n   \n    }\n\n    static Monoid ide() {\n   \
    \    return 0LL;\n    }\n    \n};\n\n/*\n@brief : \u30BB\u30B0\u6728\n*/"
  dependsOn: []
  isVerificationFile: false
  path: DetaStructures/SegTree.cpp
  requiredBy: []
  timestamp: '2024-05-10 22:30:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DetaStructures/SegTree.cpp
layout: document
redirect_from:
- /library/DetaStructures/SegTree.cpp
- /library/DetaStructures/SegTree.cpp.html
title: ": \u30BB\u30B0\u6728"
---
