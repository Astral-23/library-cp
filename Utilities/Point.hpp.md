---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"Utilities/Point.hpp\"\nstruct P {\n\tusing ll = long long;\n\
    \tll x, y;\n\tP () {}\n\tP (ll _x, ll _y) : x(_x), y(_y) {}\n\tbool operator<(const\
    \ P& a) {\n\t\tif(x != a.x) return x < a.x;\n\t\telse return y < a.y;\n\t}\n};\n"
  code: "struct P {\n\tusing ll = long long;\n\tll x, y;\n\tP () {}\n\tP (ll _x, ll\
    \ _y) : x(_x), y(_y) {}\n\tbool operator<(const P& a) {\n\t\tif(x != a.x) return\
    \ x < a.x;\n\t\telse return y < a.y;\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Utilities/Point.hpp
  requiredBy: []
  timestamp: '2024-05-12 02:56:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utilities/Point.hpp
layout: document
redirect_from:
- /library/Utilities/Point.hpp
- /library/Utilities/Point.hpp.html
title: Utilities/Point.hpp
---
