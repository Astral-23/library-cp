---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/lichao.test.cpp
    title: Li chao tree
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Li chao tree
    links: []
  bundledCode: "#line 1 \"DataStructures/li_chao_tree.hpp\"\ntemplate<typename T>\n\
    struct li_chao_tree {\n    struct line {\n        T a, b; // y = ax + b\n    \
    \    line (T _a, T _b) : a(_a), b(_b) {}\n        bool operator==(const line &c)\
    \ {return a == c.a && b == c.b;}\n        bool operator!=(const line& c) {return\
    \ !(a == *this);}\n        T operator()(T x) const {return a * x + b;}\n    };\n\
    \n    int siz = 1;\n    vector<line> dat;\n    vector<T> X;//\u30AF\u30A8\u30EA\
    \u3067\u805E\u304B\u308C\u308Bx\u5EA7\u6A19 sorted && unique\u6E08\u307F\u524D\
    \u63D0\n    T M = numeric_limits<T>::max();\n\n  \n    li_chao_tree (vector<T>\
    \ &xs) { \n        while(siz < xs.size()) siz <<= 1;\n        dat.resize(siz<<1,\
    \ line(0, M));\n\t\tT Mx = -M;\n\t\tT mx = M;\n\t\tfor(auto x : xs) {\n\t\t\t\
    if(Mx < x) Mx = x;\n\t\t\tif(mx > x) mx = x;\n\t\t}\n        X.resize(siz+1, Mx+1);\n\
    \        X[0] = mx-1;\n        for(int i = 1; i <= int(xs.size()); i++) X[i] =\
    \ xs[i-1];\n    }\n  \n    void add_line_query(line nw, long long l, long long\
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
    \ x) - X.begin();\n        return get_query(id);\n    }\n\n};\n\n/*\n@brief Li\
    \ chao tree\n*/\n"
  code: "template<typename T>\nstruct li_chao_tree {\n    struct line {\n        T\
    \ a, b; // y = ax + b\n        line (T _a, T _b) : a(_a), b(_b) {}\n        bool\
    \ operator==(const line &c) {return a == c.a && b == c.b;}\n        bool operator!=(const\
    \ line& c) {return !(a == *this);}\n        T operator()(T x) const {return a\
    \ * x + b;}\n    };\n\n    int siz = 1;\n    vector<line> dat;\n    vector<T>\
    \ X;//\u30AF\u30A8\u30EA\u3067\u805E\u304B\u308C\u308Bx\u5EA7\u6A19 sorted &&\
    \ unique\u6E08\u307F\u524D\u63D0\n    T M = numeric_limits<T>::max();\n\n  \n\
    \    li_chao_tree (vector<T> &xs) { \n        while(siz < xs.size()) siz <<= 1;\n\
    \        dat.resize(siz<<1, line(0, M));\n\t\tT Mx = -M;\n\t\tT mx = M;\n\t\t\
    for(auto x : xs) {\n\t\t\tif(Mx < x) Mx = x;\n\t\t\tif(mx > x) mx = x;\n\t\t}\n\
    \        X.resize(siz+1, Mx+1);\n        X[0] = mx-1;\n        for(int i = 1;\
    \ i <= int(xs.size()); i++) X[i] = xs[i-1];\n    }\n  \n    void add_line_query(line\
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
    \    }\n\n};\n\n/*\n@brief Li chao tree\n*/"
  dependsOn: []
  isVerificationFile: false
  path: DataStructures/li_chao_tree.hpp
  requiredBy: []
  timestamp: '2024-05-11 04:03:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/lichao.test.cpp
documentation_of: DataStructures/li_chao_tree.hpp
layout: document
redirect_from:
- /library/DataStructures/li_chao_tree.hpp
- /library/DataStructures/li_chao_tree.hpp.html
title: Li chao tree
---
