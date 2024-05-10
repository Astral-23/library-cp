---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "MP\u65B9"
    links: []
  bundledCode: "#line 1 \"String/MP.cpp\"\nvl MP(string S) {\n  int N = S.size();\n\
    \  vl res(N+1, -1);\n  int j = -1;\n  rep(i, 0, N-1) {\n    while(j >= 0 && S.at(i)\
    \ != S.at(j)) j = res.at(j);\n    j++;\n    res.at(i+1) = j;\n  }\n  return res;//\u7D50\
    \u679C\u306F1-indexed \u3064\u307E\u308A res[i] := [1, i]\u306B\u3064\u3044\u3066\
    \u3002\n}\n/*\n@brief MP\u65B9\nres[i] := S\u306E[1, i]\u306B\u3064\u3044\u3066\
    \u3001prefix\u3068suffix\u306E\u5171\u901A\u6587\u5B57\u5217\u9577\u3092\u8FD4\
    \u3059(\u4F46\u3057\u3001\u9577\u3055i\u672A\u6E80\u3068\u3059\u308B)\n*/\n"
  code: "vl MP(string S) {\n  int N = S.size();\n  vl res(N+1, -1);\n  int j = -1;\n\
    \  rep(i, 0, N-1) {\n    while(j >= 0 && S.at(i) != S.at(j)) j = res.at(j);\n\
    \    j++;\n    res.at(i+1) = j;\n  }\n  return res;//\u7D50\u679C\u306F1-indexed\
    \ \u3064\u307E\u308A res[i] := [1, i]\u306B\u3064\u3044\u3066\u3002\n}\n/*\n@brief\
    \ MP\u65B9\nres[i] := S\u306E[1, i]\u306B\u3064\u3044\u3066\u3001prefix\u3068\
    suffix\u306E\u5171\u901A\u6587\u5B57\u5217\u9577\u3092\u8FD4\u3059(\u4F46\u3057\
    \u3001\u9577\u3055i\u672A\u6E80\u3068\u3059\u308B)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: String/MP.cpp
  requiredBy: []
  timestamp: '2024-05-10 23:14:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/MP.cpp
layout: document
redirect_from:
- /library/String/MP.cpp
- /library/String/MP.cpp.html
title: "MP\u65B9"
---
