---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Manacher
    links: []
  bundledCode: "#line 1 \"String/Manacher.cpp\"\nstruct Manacher {\n  string S;\n\
    \  int N;\n  int nn;\n  vi R;\n  Manacher(string &T) {\n    S = T;\n    N = S.size();\n\
    \    string temp = \"\";\n    rep(i, 0, N-1) {\n      temp += S[i];\n      if(i\
    \ != N-1)temp += \"$\";\n    }\n    nn = temp.size();\n    R.resize(nn);\n\n \
    \   int c = 0;\n    for(int i = 0; i < nn; i++) {\n      int l = 2 * c - i;\n\
    \      if(i + R[l] < c + R[c]) {\n        R[i] = R[l];\n      }\n      else {\n\
    \        int j = c+R[c] - i;//\u3068\u308A\u3042\u3048\u305A\u4FDD\u8A3C\u3055\
    \u308C\u3066\u3044\u308B\u534A\u5F84\n        while(i - j >= 0 && i + j < nn &&\
    \ temp[i-j] == temp[i+j]) j++;//i\u6587\u5B57\u76EE\u3092\u542B\u3081\u3066\u5DE6\
    \u306B\u3042\u308B\u306E\u306F i + 1\u6587\u5B57\u3000\u3088\u3063\u3066\u3001\
    \ (i + 1) - j >= 0\u304C\u5B88\u3089\u308C\u308B\u5FC5\u8981\u304C\u3042\u308B\
    \ i\u6587\u5B57\u76EE\u3092\u542B\u3081\u3066\u53F3\u306B\u306Fnn - i\u6587\u5B57\
    \u3042\u308B\u3088\u3063\u3066nn - i >= j\n        R[i] = j;\n        c = i;\n\
    \      }\n    }\n  }\n\n  int get(int idx) {//\u5947\u6570\u9577\n    return (R[2\
    \ * (idx-1)]+1)/2;\n  }\n\n  int get(int idx, int tuginosoezi) {//\u5076\u6570\
    \u9577\n    int m = 2 * (idx-1) + 1;\n    return R[m]/2;\n  }\n};\n/*\n@brief\
    \ Manacher\n\u56DE\u6587\u306E\u534A\u5F84\u3092\u8FD4\u3059\n*/\n"
  code: "struct Manacher {\n  string S;\n  int N;\n  int nn;\n  vi R;\n  Manacher(string\
    \ &T) {\n    S = T;\n    N = S.size();\n    string temp = \"\";\n    rep(i, 0,\
    \ N-1) {\n      temp += S[i];\n      if(i != N-1)temp += \"$\";\n    }\n    nn\
    \ = temp.size();\n    R.resize(nn);\n\n    int c = 0;\n    for(int i = 0; i <\
    \ nn; i++) {\n      int l = 2 * c - i;\n      if(i + R[l] < c + R[c]) {\n    \
    \    R[i] = R[l];\n      }\n      else {\n        int j = c+R[c] - i;//\u3068\u308A\
    \u3042\u3048\u305A\u4FDD\u8A3C\u3055\u308C\u3066\u3044\u308B\u534A\u5F84\n   \
    \     while(i - j >= 0 && i + j < nn && temp[i-j] == temp[i+j]) j++;//i\u6587\u5B57\
    \u76EE\u3092\u542B\u3081\u3066\u5DE6\u306B\u3042\u308B\u306E\u306F i + 1\u6587\
    \u5B57\u3000\u3088\u3063\u3066\u3001 (i + 1) - j >= 0\u304C\u5B88\u3089\u308C\u308B\
    \u5FC5\u8981\u304C\u3042\u308B i\u6587\u5B57\u76EE\u3092\u542B\u3081\u3066\u53F3\
    \u306B\u306Fnn - i\u6587\u5B57\u3042\u308B\u3088\u3063\u3066nn - i >= j\n    \
    \    R[i] = j;\n        c = i;\n      }\n    }\n  }\n\n  int get(int idx) {//\u5947\
    \u6570\u9577\n    return (R[2 * (idx-1)]+1)/2;\n  }\n\n  int get(int idx, int\
    \ tuginosoezi) {//\u5076\u6570\u9577\n    int m = 2 * (idx-1) + 1;\n    return\
    \ R[m]/2;\n  }\n};\n/*\n@brief Manacher\n\u56DE\u6587\u306E\u534A\u5F84\u3092\u8FD4\
    \u3059\n*/"
  dependsOn: []
  isVerificationFile: false
  path: String/Manacher.cpp
  requiredBy: []
  timestamp: '2024-05-10 23:14:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/Manacher.cpp
layout: document
redirect_from:
- /library/String/Manacher.cpp
- /library/String/Manacher.cpp.html
title: Manacher
---
