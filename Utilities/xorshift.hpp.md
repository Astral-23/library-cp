---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: xorshift
    links: []
  bundledCode: "#line 1 \"Utilities/xorshift.hpp\"\nclass xorshift {\n    uint64_t\
    \ x;\n    public:\n        xorshift() {\n            mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());\n\
    \            x = rnd();\n            for (int i = 0; i < 100; i++) {\n       \
    \         random();\n            }\n        }\n        uint64_t random() {\n \
    \           x = x ^ (x << 7);\n            return x = x ^ (x >> 9);\n    }\n};\
    \ xorshift rng;\n/*\n@brief xorshift\n*/\n"
  code: "class xorshift {\n    uint64_t x;\n    public:\n        xorshift() {\n  \
    \          mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());\n\
    \            x = rnd();\n            for (int i = 0; i < 100; i++) {\n       \
    \         random();\n            }\n        }\n        uint64_t random() {\n \
    \           x = x ^ (x << 7);\n            return x = x ^ (x >> 9);\n    }\n};\
    \ xorshift rng;\n/*\n@brief xorshift\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: Utilities/xorshift.hpp
  requiredBy: []
  timestamp: '2024-05-11 00:52:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utilities/xorshift.hpp
layout: document
redirect_from:
- /library/Utilities/xorshift.hpp
- /library/Utilities/xorshift.hpp.html
title: xorshift
---
