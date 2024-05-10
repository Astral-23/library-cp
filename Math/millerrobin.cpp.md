---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u7D20\u6570\u5224\u5B9A(Miller Robin)"
    links: []
  bundledCode: "#line 1 \"Math/millerrobin.cpp\"\nclass MillerRabin {\n    vector<long\
    \ long> A1 = {2, 7, 61};\n    vector<long long> A2 = {2, 325, 9375, 28178, 450775,\
    \ 9780504, 1795265022};\n\n    private:\n        template<typename T>\n      \
    \  T pow_mod(T x, T y, T m) {\n            T res = 1;\n            x %= m;\n \
    \           while(y) {\n                if(y&1) res = (res * x)%m;\n         \
    \       x = (x*x)%m;            \n                y >>= 1;\n            }\n  \
    \          return res;\n        }\n\n        bool MR(long long x, vector<long\
    \ long>& A) {\n            long long s = 0, d = x-1;\n            while(!(d&1))\
    \ {\n                ++s;\n                d >>= 1;\n            }\n\n       \
    \     for(auto a : A) {\n                if(x <= a) return true;\n           \
    \     long long t = 0;\n                long long v = pow_mod<__int128_t>(a, d,\
    \ x);\n                if(v != 1) {\n                    for(t = 0; t < s; ++t)\
    \ {\n                        if(v == x-1)break;\n                        v = __int128_t(v)*v%x;\n\
    \                    }\n                    if(t == s) return false;//\u4E00\u3064\
    \u3082\u901A\u3089\u306A\u304B\u3063\u305F\u3002\n                }\n        \
    \    }\n            return true;\n        }\n\n    public:\n        bool isprime(long\
    \ long x) {\n            if(x <= 1) return false;\n            if(x == 2) return\
    \ true;\n            if(!(x&1)) return false;\n            if(x < 4759123141LL)\
    \ return MR(x, A1);\n            else return MR(x, A2);\n        }\n\n\n};MillerRabin\
    \ MR;\n/*\n@brief \u7D20\u6570\u5224\u5B9A(Miller Robin)\n*/\n"
  code: "class MillerRabin {\n    vector<long long> A1 = {2, 7, 61};\n    vector<long\
    \ long> A2 = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};\n\n    private:\n\
    \        template<typename T>\n        T pow_mod(T x, T y, T m) {\n          \
    \  T res = 1;\n            x %= m;\n            while(y) {\n                if(y&1)\
    \ res = (res * x)%m;\n                x = (x*x)%m;            \n             \
    \   y >>= 1;\n            }\n            return res;\n        }\n\n        bool\
    \ MR(long long x, vector<long long>& A) {\n            long long s = 0, d = x-1;\n\
    \            while(!(d&1)) {\n                ++s;\n                d >>= 1;\n\
    \            }\n\n            for(auto a : A) {\n                if(x <= a) return\
    \ true;\n                long long t = 0;\n                long long v = pow_mod<__int128_t>(a,\
    \ d, x);\n                if(v != 1) {\n                    for(t = 0; t < s;\
    \ ++t) {\n                        if(v == x-1)break;\n                       \
    \ v = __int128_t(v)*v%x;\n                    }\n                    if(t == s)\
    \ return false;//\u4E00\u3064\u3082\u901A\u3089\u306A\u304B\u3063\u305F\u3002\n\
    \                }\n            }\n            return true;\n        }\n\n   \
    \ public:\n        bool isprime(long long x) {\n            if(x <= 1) return\
    \ false;\n            if(x == 2) return true;\n            if(!(x&1)) return false;\n\
    \            if(x < 4759123141LL) return MR(x, A1);\n            else return MR(x,\
    \ A2);\n        }\n\n\n};MillerRabin MR;\n/*\n@brief \u7D20\u6570\u5224\u5B9A\
    (Miller Robin)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Math/millerrobin.cpp
  requiredBy: []
  timestamp: '2024-05-10 23:19:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/millerrobin.cpp
layout: document
redirect_from:
- /library/Math/millerrobin.cpp
- /library/Math/millerrobin.cpp.html
title: "\u7D20\u6570\u5224\u5B9A(Miller Robin)"
---
