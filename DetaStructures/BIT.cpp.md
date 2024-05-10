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
  bundledCode: "#line 1 \"DetaStructures/BIT.cpp\"\n\ntemplate<typename T>\nstruct\
    \ BIT {\n    int N;\n    vector<T> dat;\n\tBIT(){}\n    BIT(int _N) : N(_N) {\n\
    \        dat.resize(N+1, 0);\n    }\n\n\tvoid set(int pos, T val) {dat[pos] =\
    \ val;}\n\n\tvoid init() {\n\t\tfor(int x = 1; x < N; ++x) if(x + (x & -x) <=\
    \ N) dat[x + (x&-x)] += dat[x];\n\t}\n\n    void add(int pos, T val) {\n     \
    \   for(int x = pos; x <= N; x += x & -x) dat[x] += val;\n    }\n\n    T get(int\
    \ r) {\n        T res = 0;\n        for(int x = r; x > 0; x -= x & -x) res +=\
    \ dat[x];\n        return res;\n    }\n    \n    T get(int l, int r) {\n\t\tT\
    \ res = get(r);\n\t\tif(l!=1) res -= get(l-1);\n\t\treturn res;\n\t}\n\n};\n\n"
  code: "\ntemplate<typename T>\nstruct BIT {\n    int N;\n    vector<T> dat;\n\t\
    BIT(){}\n    BIT(int _N) : N(_N) {\n        dat.resize(N+1, 0);\n    }\n\n\tvoid\
    \ set(int pos, T val) {dat[pos] = val;}\n\n\tvoid init() {\n\t\tfor(int x = 1;\
    \ x < N; ++x) if(x + (x & -x) <= N) dat[x + (x&-x)] += dat[x];\n\t}\n\n    void\
    \ add(int pos, T val) {\n        for(int x = pos; x <= N; x += x & -x) dat[x]\
    \ += val;\n    }\n\n    T get(int r) {\n        T res = 0;\n        for(int x\
    \ = r; x > 0; x -= x & -x) res += dat[x];\n        return res;\n    }\n    \n\
    \    T get(int l, int r) {\n\t\tT res = get(r);\n\t\tif(l!=1) res -= get(l-1);\n\
    \t\treturn res;\n\t}\n\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: DetaStructures/BIT.cpp
  requiredBy: []
  timestamp: '2024-05-10 22:23:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DetaStructures/BIT.cpp
layout: document
redirect_from:
- /library/DetaStructures/BIT.cpp
- /library/DetaStructures/BIT.cpp.html
title: DetaStructures/BIT.cpp
---
