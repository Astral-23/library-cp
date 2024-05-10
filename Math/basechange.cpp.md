---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "10\u9032\u21D4n\u9032"
    links: []
  bundledCode: "#line 1 \"Math/basechange.cpp\"\nll nto10(string S, ll base) { //O(|S|)\
    \ 16\u65B0\u6570\u307E\u3067\u5BFE\u5FDC\n  ll res = 0;\n  reverse(all0(S));\n\
    \  while(!S.empty()) {\n    ll num = S.back() - '0';\n    if(num < 0 || num >\
    \ 9) num = 9 + S.back() - 'a' + 1;\n    res = res * base + num;\n    S.pop_back();\n\
    \  }\n  return res;\n}\nstring toN(ll N, ll base) { //O(log_(base)(N)\uFF09\u7A0B\
    \u3000base\u304C\u8CA0\u306E\u6642\u306F\u77E5\u3089\u306A\u3044\n  if(N == 0)\
    \ return \"0\";\n  string ans =\"\";\n  ll MOD = abs(base);\n  while(N != 0) {\n\
    \    ll first = N % MOD;\n    while(first < 0) first += MOD;\n    ans += to_string(first);\n\
    \    N -= first;\n    N /= base;\n  }\n  reverse(all0(ans));\n  return ans;\n\
    }\n\n/*\n@brief 10\u9032\u21D4n\u9032\n*/\n"
  code: "ll nto10(string S, ll base) { //O(|S|) 16\u65B0\u6570\u307E\u3067\u5BFE\u5FDC\
    \n  ll res = 0;\n  reverse(all0(S));\n  while(!S.empty()) {\n    ll num = S.back()\
    \ - '0';\n    if(num < 0 || num > 9) num = 9 + S.back() - 'a' + 1;\n    res =\
    \ res * base + num;\n    S.pop_back();\n  }\n  return res;\n}\nstring toN(ll N,\
    \ ll base) { //O(log_(base)(N)\uFF09\u7A0B\u3000base\u304C\u8CA0\u306E\u6642\u306F\
    \u77E5\u3089\u306A\u3044\n  if(N == 0) return \"0\";\n  string ans =\"\";\n  ll\
    \ MOD = abs(base);\n  while(N != 0) {\n    ll first = N % MOD;\n    while(first\
    \ < 0) first += MOD;\n    ans += to_string(first);\n    N -= first;\n    N /=\
    \ base;\n  }\n  reverse(all0(ans));\n  return ans;\n}\n\n/*\n@brief 10\u9032\u21D4\
    n\u9032\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Math/basechange.cpp
  requiredBy: []
  timestamp: '2024-05-10 23:19:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/basechange.cpp
layout: document
redirect_from:
- /library/Math/basechange.cpp
- /library/Math/basechange.cpp.html
title: "10\u9032\u21D4n\u9032"
---
