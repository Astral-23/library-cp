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
  bundledCode: "#line 1 \"DetaStructures/D2BIT.cpp\"\ntemplate<typename T>\nstruct\
    \ D2BIT {\n    int H, W;\n    vector<vector<T>> dat;\n\n    D2BIT(int _H, int\
    \ _W) : H(_H), W(_W){\n        dat.resize(H+1);\n        for(int i = 1; i <= H;\
    \ i++)dat[i].resize(W+1, 0);\n    }\n    \n\n    private:\n\n        void change__(int\
    \ y, int x, T val) {\n            while(x <= W) {\n                dat[y][x] +=\
    \ val;\n                x += (x & -x);\n            }\n        }\n\n        T\
    \ get__(int y, int x) {\n            T res = 0;\n            while(x > 0) {\n\
    \                res += dat[y][x];\n                x -= (x & -x);\n         \
    \   }\n            return res;\n        }\n\n\n    public:\n        void change(int\
    \ y, int x, T val) {\n            if(1 > y || y > H || 1 > x || x > W) return;\n\
    \            while(y <= H) {\n                change__(y, x, val);\n         \
    \       y += (y & -y);\n            }\n        }\n\n        T get(int y, int x)\
    \ {\n            if(1 > y || y > H || 1 > x || x > W) return 0;\n            T\
    \ res = 0;\n            while(y > 0) {\n                res += get__(y, x);\n\
    \                y -= (y & -y);\n            }\n            return res;\n    \
    \    }\n\n        T rec(int sy, int ty, int sx, int tx) {\n            T res =\
    \ 0;\n            res += get(ty, tx);\n            res += get(sy-1, sx-1);\n \
    \           res -= get(ty, sx-1);\n            res -= get(sy-1, tx);\n       \
    \     return res;\n        }\n};\n\n/*\nBrief : 2DBIT\n\n*/\n"
  code: "template<typename T>\nstruct D2BIT {\n    int H, W;\n    vector<vector<T>>\
    \ dat;\n\n    D2BIT(int _H, int _W) : H(_H), W(_W){\n        dat.resize(H+1);\n\
    \        for(int i = 1; i <= H; i++)dat[i].resize(W+1, 0);\n    }\n    \n\n  \
    \  private:\n\n        void change__(int y, int x, T val) {\n            while(x\
    \ <= W) {\n                dat[y][x] += val;\n                x += (x & -x);\n\
    \            }\n        }\n\n        T get__(int y, int x) {\n            T res\
    \ = 0;\n            while(x > 0) {\n                res += dat[y][x];\n      \
    \          x -= (x & -x);\n            }\n            return res;\n        }\n\
    \n\n    public:\n        void change(int y, int x, T val) {\n            if(1\
    \ > y || y > H || 1 > x || x > W) return;\n            while(y <= H) {\n     \
    \           change__(y, x, val);\n                y += (y & -y);\n           \
    \ }\n        }\n\n        T get(int y, int x) {\n            if(1 > y || y > H\
    \ || 1 > x || x > W) return 0;\n            T res = 0;\n            while(y >\
    \ 0) {\n                res += get__(y, x);\n                y -= (y & -y);\n\
    \            }\n            return res;\n        }\n\n        T rec(int sy, int\
    \ ty, int sx, int tx) {\n            T res = 0;\n            res += get(ty, tx);\n\
    \            res += get(sy-1, sx-1);\n            res -= get(ty, sx-1);\n    \
    \        res -= get(sy-1, tx);\n            return res;\n        }\n};\n\n/*\n\
    Brief : 2DBIT\n\n*/"
  dependsOn: []
  isVerificationFile: false
  path: DetaStructures/D2BIT.cpp
  requiredBy: []
  timestamp: '2024-05-10 22:34:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DetaStructures/D2BIT.cpp
layout: document
redirect_from:
- /library/DetaStructures/D2BIT.cpp
- /library/DetaStructures/D2BIT.cpp.html
title: DetaStructures/D2BIT.cpp
---
