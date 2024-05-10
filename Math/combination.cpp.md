---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u30B3\u30F3\u30D3\u30CD\u30FC\u30B7\u30E7\u30F3"
    links: []
  bundledCode: "#line 1 \"Math/combination.cpp\"\nstruct CMB {//must\u7D20\u6570\n\
    \  vector<long long> fac;\n  vector<long long> facinv;\n  vector<long long> inv;\n\
    \  long long mod_comb = 0;\n  int siz = 1;//\u534A\u958B\u533A\u9593[0, siz)\u306B\
    \u5BFE\u5FDC\n\n  CMB (ll _mod) : mod_comb(_mod) {resize(1);}\n  void set(long\
    \ long _mod_comb) {mod_comb = _mod_comb; resize(1); return;} // \u6700\u521D\u306B\
    resize(1)\u3057\u306A\u3044\u3068 C(0, 0)\u3067\u30D0\u30B0\u308B\n  void resize(int\
    \ n) {\n    if(n < siz) return;\n    int ns = siz;\n    while(ns <= n) ns <<=\
    \ 1;\n    fac.resize(ns, 1);\n    facinv.resize(ns, 1);\n    inv.resize(ns, 1);\n\
    \    for(int i = max(2, siz); i < ns; i++) {\n      fac[i] = fac[i-1] * i % mod_comb;\n\
    \      inv[i] = mod_comb - inv[mod_comb%i] * (mod_comb/i)%mod_comb;\n      facinv[i]\
    \ = facinv[i-1] * inv[i] % mod_comb;\n    }\n    siz = ns;//\u5FD8\u308C\u306A\
    \u3044\u3002\n    return ;\n  }\n  \n\n  long long B(int n) { //\u968E\u4E57\n\
    \    resize(n);\n    return fac[n];\n  }\n\n  long long invB(int n) {//\u968E\u4E57\
    \u306E\u9006\u5143\n    resize(n);\n    return facinv[n];\n  }\n\n  long long\
    \ C(int n, int k) { //n\u7A2E\u985E\u304B\u3089\u91CD\u8907\u306A\u3057k\u500B\
    \u9078\u3076\u6642\u306E\u96C6\u5408\u306E\u7DCF\u6570\n    if(n < k) return 0LL;\n\
    \    if(n < 0 || k < 0) return 0LL;\n    resize(n);\n    return fac[n] * (facinv[k]\
    \ * facinv[n-k]%mod_comb)%mod_comb;\n  }\n\n  long long H(int n, int k) { //n\u7A2E\
    \u985E\u306E\u7269\u304B\u3089\u91CD\u8907\u3092\u8A31\u3057\u3066k\u500B\u9078\
    \u3076\u6642\u306E\u96C6\u5408\u306E\u7DCF\u6570\n    resize(n+k-1);\n    return\
    \ C(n+k-1, k);\n  }\n\n  long long Cn(int n) { //\u30AB\u30BF\u30E9\u30F3\u6570\
    \n    resize(2 * n);\n    return C(2*n, n) * inv[n+1] % mod_comb;\n  }\n};\nCMB\
    \ cmb(mod);\n\n/*\n@brief \u30B3\u30F3\u30D3\u30CD\u30FC\u30B7\u30E7\u30F3\n*/\n"
  code: "struct CMB {//must\u7D20\u6570\n  vector<long long> fac;\n  vector<long long>\
    \ facinv;\n  vector<long long> inv;\n  long long mod_comb = 0;\n  int siz = 1;//\u534A\
    \u958B\u533A\u9593[0, siz)\u306B\u5BFE\u5FDC\n\n  CMB (ll _mod) : mod_comb(_mod)\
    \ {resize(1);}\n  void set(long long _mod_comb) {mod_comb = _mod_comb; resize(1);\
    \ return;} // \u6700\u521D\u306Bresize(1)\u3057\u306A\u3044\u3068 C(0, 0)\u3067\
    \u30D0\u30B0\u308B\n  void resize(int n) {\n    if(n < siz) return;\n    int ns\
    \ = siz;\n    while(ns <= n) ns <<= 1;\n    fac.resize(ns, 1);\n    facinv.resize(ns,\
    \ 1);\n    inv.resize(ns, 1);\n    for(int i = max(2, siz); i < ns; i++) {\n \
    \     fac[i] = fac[i-1] * i % mod_comb;\n      inv[i] = mod_comb - inv[mod_comb%i]\
    \ * (mod_comb/i)%mod_comb;\n      facinv[i] = facinv[i-1] * inv[i] % mod_comb;\n\
    \    }\n    siz = ns;//\u5FD8\u308C\u306A\u3044\u3002\n    return ;\n  }\n  \n\
    \n  long long B(int n) { //\u968E\u4E57\n    resize(n);\n    return fac[n];\n\
    \  }\n\n  long long invB(int n) {//\u968E\u4E57\u306E\u9006\u5143\n    resize(n);\n\
    \    return facinv[n];\n  }\n\n  long long C(int n, int k) { //n\u7A2E\u985E\u304B\
    \u3089\u91CD\u8907\u306A\u3057k\u500B\u9078\u3076\u6642\u306E\u96C6\u5408\u306E\
    \u7DCF\u6570\n    if(n < k) return 0LL;\n    if(n < 0 || k < 0) return 0LL;\n\
    \    resize(n);\n    return fac[n] * (facinv[k] * facinv[n-k]%mod_comb)%mod_comb;\n\
    \  }\n\n  long long H(int n, int k) { //n\u7A2E\u985E\u306E\u7269\u304B\u3089\u91CD\
    \u8907\u3092\u8A31\u3057\u3066k\u500B\u9078\u3076\u6642\u306E\u96C6\u5408\u306E\
    \u7DCF\u6570\n    resize(n+k-1);\n    return C(n+k-1, k);\n  }\n\n  long long\
    \ Cn(int n) { //\u30AB\u30BF\u30E9\u30F3\u6570\n    resize(2 * n);\n    return\
    \ C(2*n, n) * inv[n+1] % mod_comb;\n  }\n};\nCMB cmb(mod);\n\n/*\n@brief \u30B3\
    \u30F3\u30D3\u30CD\u30FC\u30B7\u30E7\u30F3\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Math/combination.cpp
  requiredBy: []
  timestamp: '2024-05-10 23:19:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/combination.cpp
layout: document
redirect_from:
- /library/Math/combination.cpp
- /library/Math/combination.cpp.html
title: "\u30B3\u30F3\u30D3\u30CD\u30FC\u30B7\u30E7\u30F3"
---
