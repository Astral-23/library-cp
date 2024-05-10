---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Z_algorithm
    links: []
  bundledCode: "#line 1 \"String/Zalgo.cpp\"\nvl Z_algorithm(string S) {\n  ll N =\
    \ S.size();\n  ll c = 0;\n  vl res(N+1, 0);\n  rep(i, 2, N) {\n    ll l = i -\
    \ c; //\u5BFE\u5FDC\u3059\u308B\u9ED2\u70B9\u7DDA\u306E\u5DE6\u7AEF\u306E\u5EA7\
    \u6A19\n    if(i + res.at(l) < c + res.at(c)) {\n      res.at(i) = res.at(l);\n\
    \    }\n    else {\n      ll j = max(0LL, c + res.at(c) - i);//\u4F55\u6587\u5B57\
    \u88AB\u3063\u3066\u305F\u304B \u6B21\u306Fj + 1\u6587\u5B57\u76EE\u4EE5\u964D\
    \u3092\u8ABF\u3079\u308C\u3070\u826F\u3044\u3002\n      while(i + j <= N && S.at(j)\
    \ == S.at(i + j))j++;\n      res.at(i) = j;\n      c = i;\n    }\n  }\n  return\
    \ res;\n}\n/*\n@brief Z_algorithm\nres[i] := [1:]\u3068[i:]\u306E\u6700\u9577\u5171\
    \u901A\u90E8\u306E\u9577\u3055\n*/\n"
  code: "vl Z_algorithm(string S) {\n  ll N = S.size();\n  ll c = 0;\n  vl res(N+1,\
    \ 0);\n  rep(i, 2, N) {\n    ll l = i - c; //\u5BFE\u5FDC\u3059\u308B\u9ED2\u70B9\
    \u7DDA\u306E\u5DE6\u7AEF\u306E\u5EA7\u6A19\n    if(i + res.at(l) < c + res.at(c))\
    \ {\n      res.at(i) = res.at(l);\n    }\n    else {\n      ll j = max(0LL, c\
    \ + res.at(c) - i);//\u4F55\u6587\u5B57\u88AB\u3063\u3066\u305F\u304B \u6B21\u306F\
    j + 1\u6587\u5B57\u76EE\u4EE5\u964D\u3092\u8ABF\u3079\u308C\u3070\u826F\u3044\u3002\
    \n      while(i + j <= N && S.at(j) == S.at(i + j))j++;\n      res.at(i) = j;\n\
    \      c = i;\n    }\n  }\n  return res;\n}\n/*\n@brief Z_algorithm\nres[i] :=\
    \ [1:]\u3068[i:]\u306E\u6700\u9577\u5171\u901A\u90E8\u306E\u9577\u3055\n*/"
  dependsOn: []
  isVerificationFile: false
  path: String/Zalgo.cpp
  requiredBy: []
  timestamp: '2024-05-10 23:14:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/Zalgo.cpp
layout: document
redirect_from:
- /library/String/Zalgo.cpp
- /library/String/Zalgo.cpp.html
title: Z_algorithm
---
