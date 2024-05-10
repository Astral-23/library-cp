---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: suffix_array
    links: []
  bundledCode: "#line 1 \"String/suf_array.cpp\"\nvi Suffix_Array(string &S, vi &sa)\
    \ {\n  int n = S.size();\n  int k;\n// vi sa(n+1, -1);\u304C\u5165\u3063\u3066\
    \u3044\u305F\u304C\u3001\u3088\u304F\u308F\u304B\u3089\u306A\u3044\u306E\u3067\
    \u6D88\u3057\u305F(9/3)\u3000\u672A\u691C\u8A3C\n  vi temp(n+1, -1);\n  vi rank(n+1,\
    \ -1);\n  for(int i = 0; i <= n; i++) {\n    sa[i] = i;\n    rank[i] = i < n ?\
    \ S[i] : -1;\n  }\n\n  auto cmp_sa = [&](int i, int j) {\n    if(rank[i] != rank[j])\
    \ return rank[i] < rank[j];\n    else {\n      int ri = i + k <= n ? rank[i+k]\
    \ : -1;\n      int rj = j + k <= n ? rank[j+k] : -1;\n      return ri < rj;\n\
    \    }\n  };\n\n  for(k = 1; k <= n; k *= 2) {\n    sort(sa.begin(), sa.end(),\
    \ cmp_sa);\n    temp[sa[0]] = 0;\n    for(int i = 1; i <= n; i++) {\n      temp[sa[i]]\
    \ = temp[sa[i-1]] + (cmp_sa(sa[i-1], sa[i]) ? 1 : 0);\n    }\n    for(int i =\
    \ 0; i <= n; i++) {\n      rank[i] = temp[i];\n    }\n  }\n  \n  return rank;\n\
    }\n\nvi make_lcp(string &S, vi &sa) {\n  int n = S.size();\n  vi lcp(n, -1);\n\
    \  vi rank(n+1);\n  int h = 0;\n  lcp[0] = 0;\n\n  rep(i, 0, n) {\n    rank[sa[i]]\
    \ = i;\n  }\n  rep(i, 0, n-1) {\n    int j = sa[rank[i]-1];\n    if(h > 0)h--;\n\
    \    for( ; j + h < n && i + h < n; h++) {\n      if(S[j+h] != S[i+h])break;\n\
    \    }\n    lcp[rank[i]-1] = h;\n  }\n  return lcp;\n}\n\n/*\n@brief suffix_array\n\
    */\n"
  code: "vi Suffix_Array(string &S, vi &sa) {\n  int n = S.size();\n  int k;\n// vi\
    \ sa(n+1, -1);\u304C\u5165\u3063\u3066\u3044\u305F\u304C\u3001\u3088\u304F\u308F\
    \u304B\u3089\u306A\u3044\u306E\u3067\u6D88\u3057\u305F(9/3)\u3000\u672A\u691C\u8A3C\
    \n  vi temp(n+1, -1);\n  vi rank(n+1, -1);\n  for(int i = 0; i <= n; i++) {\n\
    \    sa[i] = i;\n    rank[i] = i < n ? S[i] : -1;\n  }\n\n  auto cmp_sa = [&](int\
    \ i, int j) {\n    if(rank[i] != rank[j]) return rank[i] < rank[j];\n    else\
    \ {\n      int ri = i + k <= n ? rank[i+k] : -1;\n      int rj = j + k <= n ?\
    \ rank[j+k] : -1;\n      return ri < rj;\n    }\n  };\n\n  for(k = 1; k <= n;\
    \ k *= 2) {\n    sort(sa.begin(), sa.end(), cmp_sa);\n    temp[sa[0]] = 0;\n \
    \   for(int i = 1; i <= n; i++) {\n      temp[sa[i]] = temp[sa[i-1]] + (cmp_sa(sa[i-1],\
    \ sa[i]) ? 1 : 0);\n    }\n    for(int i = 0; i <= n; i++) {\n      rank[i] =\
    \ temp[i];\n    }\n  }\n  \n  return rank;\n}\n\nvi make_lcp(string &S, vi &sa)\
    \ {\n  int n = S.size();\n  vi lcp(n, -1);\n  vi rank(n+1);\n  int h = 0;\n  lcp[0]\
    \ = 0;\n\n  rep(i, 0, n) {\n    rank[sa[i]] = i;\n  }\n  rep(i, 0, n-1) {\n  \
    \  int j = sa[rank[i]-1];\n    if(h > 0)h--;\n    for( ; j + h < n && i + h <\
    \ n; h++) {\n      if(S[j+h] != S[i+h])break;\n    }\n    lcp[rank[i]-1] = h;\n\
    \  }\n  return lcp;\n}\n\n/*\n@brief suffix_array\n*/"
  dependsOn: []
  isVerificationFile: false
  path: String/suf_array.cpp
  requiredBy: []
  timestamp: '2024-05-10 23:14:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/suf_array.cpp
layout: document
redirect_from:
- /library/String/suf_array.cpp
- /library/String/suf_array.cpp.html
title: suffix_array
---
