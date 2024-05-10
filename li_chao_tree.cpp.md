---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"li_chao_tree.cpp\"\ntemplate<typename T>\nstruct li_chao_tree\
    \ {\n    struct line {\n        T a, b; // y = ax + b\n        line (T _a, T _b)\
    \ : a(_a), b(_b) {}\n        bool operator==(const line &c) {return a == c.a &&\
    \ b == c.b;}\n        bool operator!=(const line& c) {return !(a == *this);}\n\
    \        T operator()(T x) const {return a * x + b;}\n    };\n\n    int siz =\
    \ 1;\n    vector<line> dat;\n    vector<T> X;//\u30AF\u30A8\u30EA\u3067\u805E\u304B\
    \u308C\u308Bx\u5EA7\u6A19 sorted && unique\u6E08\u307F\u524D\u63D0\n    T M =\
    \ numeric_limits<T>::max();\n\n  \n    li_chao_tree (vector<T> &xs) { \n     \
    \   while(siz < xs.size()) siz <<= 1;\n        dat.resize(siz<<1, line(0, M));\n\
    \        X.resize(siz+1, int_max);\n        X[0] = -int_max;\n        for(int\
    \ i = 1; i <= int(xs.size()); i++) X[i] = xs[i-1];\n    }\n  \n    void add_line_query(line\
    \ nw, long long l, long long r, int idx) {\n        int m = (l + r)/2;\n     \
    \   if(dat[idx] == line(0, M)) {\n            dat[idx] = nw;\n            return\
    \ ; \n        }    \n\n        T lx = X[l], mx = X[m], rx = X[r-1];\n        bool\
    \ lef = (nw(lx) < dat[idx](lx));\n        bool mid = (nw(mx) < dat[idx](mx));\n\
    \        bool rig = (nw(rx) < dat[idx](rx));\n  \n        if(lef && rig) {\n \
    \           dat[idx] = nw;\n            return;\n        }\n        if(!lef &&\
    \ !rig) return;\n        if(mid)swap(dat[idx], nw);\n        if(lef != mid) add_line_query(nw,\
    \ l, m, idx<<1);\n        else add_line_query(nw, m, r, idx<<1|1);\n        \n\
    \    }\n  \n    T get_query(T id) {\n        T x = X[id];\n        id += siz-1;\n\
    \        T res = numeric_limits<T>::max();\n        while(id >= 1) {\n       \
    \     res = min(res, dat[id](x));\n            id >>= 1;\n        }\n        return\
    \ res;\n    }\n  \n    void add_line(T a, T b) {\n        line nw(a, b);\n   \
    \     add_line_query(nw, 1, siz + 1, 1);\n     }\n\n    T get(T x) {\n       \
    \ int id = lower_bound(X.begin(), X.end(), x) - X.begin();\n        return get_query(id);\n\
    \    }\n\n};\n"
  code: "template<typename T>\nstruct li_chao_tree {\n    struct line {\n        T\
    \ a, b; // y = ax + b\n        line (T _a, T _b) : a(_a), b(_b) {}\n        bool\
    \ operator==(const line &c) {return a == c.a && b == c.b;}\n        bool operator!=(const\
    \ line& c) {return !(a == *this);}\n        T operator()(T x) const {return a\
    \ * x + b;}\n    };\n\n    int siz = 1;\n    vector<line> dat;\n    vector<T>\
    \ X;//\u30AF\u30A8\u30EA\u3067\u805E\u304B\u308C\u308Bx\u5EA7\u6A19 sorted &&\
    \ unique\u6E08\u307F\u524D\u63D0\n    T M = numeric_limits<T>::max();\n\n  \n\
    \    li_chao_tree (vector<T> &xs) { \n        while(siz < xs.size()) siz <<= 1;\n\
    \        dat.resize(siz<<1, line(0, M));\n        X.resize(siz+1, int_max);\n\
    \        X[0] = -int_max;\n        for(int i = 1; i <= int(xs.size()); i++) X[i]\
    \ = xs[i-1];\n    }\n  \n    void add_line_query(line nw, long long l, long long\
    \ r, int idx) {\n        int m = (l + r)/2;\n        if(dat[idx] == line(0, M))\
    \ {\n            dat[idx] = nw;\n            return ; \n        }    \n\n    \
    \    T lx = X[l], mx = X[m], rx = X[r-1];\n        bool lef = (nw(lx) < dat[idx](lx));\n\
    \        bool mid = (nw(mx) < dat[idx](mx));\n        bool rig = (nw(rx) < dat[idx](rx));\n\
    \  \n        if(lef && rig) {\n            dat[idx] = nw;\n            return;\n\
    \        }\n        if(!lef && !rig) return;\n        if(mid)swap(dat[idx], nw);\n\
    \        if(lef != mid) add_line_query(nw, l, m, idx<<1);\n        else add_line_query(nw,\
    \ m, r, idx<<1|1);\n        \n    }\n  \n    T get_query(T id) {\n        T x\
    \ = X[id];\n        id += siz-1;\n        T res = numeric_limits<T>::max();\n\
    \        while(id >= 1) {\n            res = min(res, dat[id](x));\n         \
    \   id >>= 1;\n        }\n        return res;\n    }\n  \n    void add_line(T\
    \ a, T b) {\n        line nw(a, b);\n        add_line_query(nw, 1, siz + 1, 1);\n\
    \     }\n\n    T get(T x) {\n        int id = lower_bound(X.begin(), X.end(),\
    \ x) - X.begin();\n        return get_query(id);\n    }\n\n};"
  dependsOn: []
  isVerificationFile: false
  path: li_chao_tree.cpp
  requiredBy: []
  timestamp: '2024-05-10 22:30:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: li_chao_tree.cpp
layout: document
redirect_from:
- /library/li_chao_tree.cpp
- /library/li_chao_tree.cpp.html
title: li_chao_tree.cpp
---
