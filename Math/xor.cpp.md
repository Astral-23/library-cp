---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "xor\u57FA\u5E95"
    links: []
  bundledCode: "#line 1 \"Math/xor.cpp\"\nconst int K = 60;\nstruct bitbase { //xor\u57FA\
    \u5E95\u3092\u4F5C\u6210\u3059\u308B \u30AA\u30FC\u30C0\u30FC\uFF1A60 * N    NlogN\u3068\
    \u8A00\u3048\u3070\u6B63\u78BA\u304B\n  vector<ll> d;\n\n  bitbase() : d(K) {}\n\
    \  void add(ll x) {\n    x = tomin(x);\n    if(x == 0)return ;//x\u306F\u306A\u3093\
    \u306E\u4EE3\u8868\u306B\u3082\u306A\u308C\u306A\u3044\n    per(i, K-1, 0) { //i\u6841\
    \u76EE\u306E\u4EE3\u8868\u306B\u306A\u308B\n      if(x >> i & 1) {\n        rep(j,\
    \ 0, K-1) {\n          if(d.at(j) >> i & 1) d.at(j) ^= x; //\u5143\u3042\u3063\
    \u305F\u57FA\u5E95\u3068xor\u3092\u3068\u3063\u3066\u304A\u304F\uFF08\u6383\u304D\
    \u51FA\u3059\uFF09\n        }\n        d.at(i) = x;\n        return ;\n      }\n\
    \    }\n  }\n  ll tomin(ll x) { //\u307E\u3060\u57FA\u5E95\u304C\u5B58\u5728\u3057\
    \u306A\u3044 && x\u306F\u305D\u306E\u57FA\u5E95\u306B\u306A\u308C\u308B\u3000\u3088\
    \u3046\u306Abit\u3092\u6C42\u3081\u308B\u70BA\u306E\u524D\u51E6\u7406\n    per(i,\
    \ K-1, 0) {\n      if(x >> i & 1) x ^= d.at(i);\n    }\n    return x;\n  }\n \
    \ ll operator[](int i) const {return d[i-1];}\n  ll& operator[](int i) {return\
    \ d[i-1];}\n};\n\n/*\n@brief xor\u57FA\u5E95\n*/\n"
  code: "const int K = 60;\nstruct bitbase { //xor\u57FA\u5E95\u3092\u4F5C\u6210\u3059\
    \u308B \u30AA\u30FC\u30C0\u30FC\uFF1A60 * N    NlogN\u3068\u8A00\u3048\u3070\u6B63\
    \u78BA\u304B\n  vector<ll> d;\n\n  bitbase() : d(K) {}\n  void add(ll x) {\n \
    \   x = tomin(x);\n    if(x == 0)return ;//x\u306F\u306A\u3093\u306E\u4EE3\u8868\
    \u306B\u3082\u306A\u308C\u306A\u3044\n    per(i, K-1, 0) { //i\u6841\u76EE\u306E\
    \u4EE3\u8868\u306B\u306A\u308B\n      if(x >> i & 1) {\n        rep(j, 0, K-1)\
    \ {\n          if(d.at(j) >> i & 1) d.at(j) ^= x; //\u5143\u3042\u3063\u305F\u57FA\
    \u5E95\u3068xor\u3092\u3068\u3063\u3066\u304A\u304F\uFF08\u6383\u304D\u51FA\u3059\
    \uFF09\n        }\n        d.at(i) = x;\n        return ;\n      }\n    }\n  }\n\
    \  ll tomin(ll x) { //\u307E\u3060\u57FA\u5E95\u304C\u5B58\u5728\u3057\u306A\u3044\
    \ && x\u306F\u305D\u306E\u57FA\u5E95\u306B\u306A\u308C\u308B\u3000\u3088\u3046\
    \u306Abit\u3092\u6C42\u3081\u308B\u70BA\u306E\u524D\u51E6\u7406\n    per(i, K-1,\
    \ 0) {\n      if(x >> i & 1) x ^= d.at(i);\n    }\n    return x;\n  }\n  ll operator[](int\
    \ i) const {return d[i-1];}\n  ll& operator[](int i) {return d[i-1];}\n};\n\n\
    /*\n@brief xor\u57FA\u5E95\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Math/xor.cpp
  requiredBy: []
  timestamp: '2024-05-10 23:19:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/xor.cpp
layout: document
redirect_from:
- /library/Math/xor.cpp
- /library/Math/xor.cpp.html
title: "xor\u57FA\u5E95"
---
