---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "MP\u65B9\u6CD5"
    links: []
  bundledCode: "#line 1 \"String/MP.hpp\"\nvector<int> MP(string S) {\n  int N = S.size();\n\
    \  vector<int> res(N+1, -1);\n  int j = -1;\n  for(int i = 0; i <= N-1; i++) {\n\
    \    while(j >= 0 && S.at(i) != S.at(j)) j = res.at(j);\n    j++;\n    res.at(i+1)\
    \ = j;\n  }\n  return res;//\u7D50\u679C\u306F1-indexed \u3064\u307E\u308A res[i]\
    \ := [1, i]\u306B\u3064\u3044\u3066\u3002\n}\n/*\n@brief MP\u65B9\u6CD5\nres[i]\
    \ := S\u306E[1, i]\u306B\u3064\u3044\u3066\u3001prefix\u3068suffix\u306E\u5171\
    \u901A\u6587\u5B57\u5217\u9577\u3092\u8FD4\u3059(\u4F46\u3057\u3001\u9577\u3055\
    i\u672A\u6E80\u3068\u3059\u308B)\n*/\n"
  code: "vector<int> MP(string S) {\n  int N = S.size();\n  vector<int> res(N+1, -1);\n\
    \  int j = -1;\n  for(int i = 0; i <= N-1; i++) {\n    while(j >= 0 && S.at(i)\
    \ != S.at(j)) j = res.at(j);\n    j++;\n    res.at(i+1) = j;\n  }\n  return res;//\u7D50\
    \u679C\u306F1-indexed \u3064\u307E\u308A res[i] := [1, i]\u306B\u3064\u3044\u3066\
    \u3002\n}\n/*\n@brief MP\u65B9\u6CD5\nres[i] := S\u306E[1, i]\u306B\u3064\u3044\
    \u3066\u3001prefix\u3068suffix\u306E\u5171\u901A\u6587\u5B57\u5217\u9577\u3092\
    \u8FD4\u3059(\u4F46\u3057\u3001\u9577\u3055i\u672A\u6E80\u3068\u3059\u308B)\n\
    */"
  dependsOn: []
  isVerificationFile: false
  path: String/MP.hpp
  requiredBy: []
  timestamp: '2024-05-11 01:13:57+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/MP.hpp
layout: document
redirect_from:
- /library/String/MP.hpp
- /library/String/MP.hpp.html
title: "MP\u65B9\u6CD5"
---
