---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u5165\u529B\u304C\u5358\u8ABF\u306ACHT"
    links: []
  bundledCode: "#line 1 \"DataStructures/monotone_CHT.cpp\"\nstruct CHT { //\u6700\
    \u5927\u5024ver//\u6700\u5C0F\u5024\u306A\u3089-1\u304B\u3051\u308B\u3068\u304B\
    \u3057\u3066\n  struct linear {\n    ll a, b;\n    linear(ll a = 0, ll b = 0)\
    \ : a(a), b(b){}\n    ll operator()(ll x) const {return a * x + b;}\n  };\n\n\
    \  deque<linear> ls;\n  void add(ll a, ll b) {//\u524D\u63D0\uFF1A\u50BE\u304D\
    \u304C\u5927\u304D\u304F\u306A\u3063\u3066\u3044\u304F\u3088\u3046\u306B\u8FFD\
    \u52A0 \n    linear l(a,b);\n    assert(ls.size() == 0 || ls.back().a <= l.a);\n\
    \    while(ls.size() >= 2) {\n      const linear& l1 = ls[ls.size() - 2];\n  \
    \    const linear& l2 = ls.back();\n      if((l1.b - l2.b) * (l.a - l2.a) < (l2.a\
    \ - l1.a) * (l2.b - l.b)) break;\n      ls.pop_back();\n    }\n    ls.push_back(l);\n\
    \  }\n\n  ll operator()(ll x) {//\u524D\u63D0 : \u30AF\u30A8\u30EA\u3067\u805E\
    \u304Fx\u5EA7\u6A19\u306F\u6607\u9806 && \u4EE5\u964D\u306E\u76F4\u7DDA\u306E\u8FFD\
    \u52A0\u7121\u3057\n    ll res = ls[0](x);\n    while(ls.size() >= 2) {\n    \
    \  ll now = ls[1](x);\n      if(now < res)break;\n      res = now;\n      ls.pop_front();\n\
    \    }\n    return res;\n  }\n};\n\n/*\n@brief \u5165\u529B\u304C\u5358\u8ABF\u306A\
    CHT\n*/\n"
  code: "struct CHT { //\u6700\u5927\u5024ver//\u6700\u5C0F\u5024\u306A\u3089-1\u304B\
    \u3051\u308B\u3068\u304B\u3057\u3066\n  struct linear {\n    ll a, b;\n    linear(ll\
    \ a = 0, ll b = 0) : a(a), b(b){}\n    ll operator()(ll x) const {return a * x\
    \ + b;}\n  };\n\n  deque<linear> ls;\n  void add(ll a, ll b) {//\u524D\u63D0\uFF1A\
    \u50BE\u304D\u304C\u5927\u304D\u304F\u306A\u3063\u3066\u3044\u304F\u3088\u3046\
    \u306B\u8FFD\u52A0 \n    linear l(a,b);\n    assert(ls.size() == 0 || ls.back().a\
    \ <= l.a);\n    while(ls.size() >= 2) {\n      const linear& l1 = ls[ls.size()\
    \ - 2];\n      const linear& l2 = ls.back();\n      if((l1.b - l2.b) * (l.a -\
    \ l2.a) < (l2.a - l1.a) * (l2.b - l.b)) break;\n      ls.pop_back();\n    }\n\
    \    ls.push_back(l);\n  }\n\n  ll operator()(ll x) {//\u524D\u63D0 : \u30AF\u30A8\
    \u30EA\u3067\u805E\u304Fx\u5EA7\u6A19\u306F\u6607\u9806 && \u4EE5\u964D\u306E\u76F4\
    \u7DDA\u306E\u8FFD\u52A0\u7121\u3057\n    ll res = ls[0](x);\n    while(ls.size()\
    \ >= 2) {\n      ll now = ls[1](x);\n      if(now < res)break;\n      res = now;\n\
    \      ls.pop_front();\n    }\n    return res;\n  }\n};\n\n/*\n@brief \u5165\u529B\
    \u304C\u5358\u8ABF\u306ACHT\n*/"
  dependsOn: []
  isVerificationFile: false
  path: DataStructures/monotone_CHT.cpp
  requiredBy: []
  timestamp: '2024-05-11 03:22:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructures/monotone_CHT.cpp
layout: document
redirect_from:
- /library/DataStructures/monotone_CHT.cpp
- /library/DataStructures/monotone_CHT.cpp.html
title: "\u5165\u529B\u304C\u5358\u8ABF\u306ACHT"
---
