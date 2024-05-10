---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: LIS/LDS
    links: []
  bundledCode: "#line 1 \"Algorithms/lislds.cpp\"\ntemplate<typename T>\nint LIS(vector<T>\
    \ A, int N, int indexed) {\n    vector<int> dp(N+1, 0);\n    vector<long long>\
    \ L(N+1, LLONG_MAX);\n    L[0] = -LLONG_MAX;\n  \n    for (int i = indexed; i\
    \ <=N; i++) {\n        auto temp = lower_bound(L.begin(), L.end(), A[i]);\n  \
    \      int index = distance(L.begin(), temp - 1);\n        dp[i] = index + 1;\n\
    \        L[index+1] = min<long long>(L[index + 1], A[i]);    \n    }\n \n    int\
    \ answer = 0;\n    for(int i = indexed; i <= N; i++) {\n        answer = max(answer,\
    \ dp[i]);\n    }\n    return answer;\n}\n\ntemplate<class T>\nint LDS(vector<T>\
    \ A, int N, int indexed) {//1-indexed\n\tvector<int> dp(N+1, 0);\n    vector<long\
    \ long> L(N+1, -LLONG_MAX);\n    L[0] = LLONG_MAX;\n  \n    for (int i = indexed;\
    \ i <= N; i++) {\n    \tint li = 0;\n    \tint ri = N-indexed;\n        while(li\
    \ < ri) {\n    \t\tint mi = (li+ri+1)>>1;\n    \t\tif(L[mi] > A[i]) li = mi;\n\
    \    \t\telse ri = mi-1;\n    \t}\n          dp[i] = li + 1;\n          L[li+1]\
    \ = max<long long>(L[li + 1], A[i]);\n      }\n     \n      int answer = 0;\n\
    \      for  (int i = indexed; i <= N; i++) {\n        answer = max(answer, dp[i]);\n\
    \      }\n      return answer;\n}\n\n/*\n@brief LIS/LDS\n*/\n"
  code: "template<typename T>\nint LIS(vector<T> A, int N, int indexed) {\n    vector<int>\
    \ dp(N+1, 0);\n    vector<long long> L(N+1, LLONG_MAX);\n    L[0] = -LLONG_MAX;\n\
    \  \n    for (int i = indexed; i <=N; i++) {\n        auto temp = lower_bound(L.begin(),\
    \ L.end(), A[i]);\n        int index = distance(L.begin(), temp - 1);\n      \
    \  dp[i] = index + 1;\n        L[index+1] = min<long long>(L[index + 1], A[i]);\
    \    \n    }\n \n    int answer = 0;\n    for(int i = indexed; i <= N; i++) {\n\
    \        answer = max(answer, dp[i]);\n    }\n    return answer;\n}\n\ntemplate<class\
    \ T>\nint LDS(vector<T> A, int N, int indexed) {//1-indexed\n\tvector<int> dp(N+1,\
    \ 0);\n    vector<long long> L(N+1, -LLONG_MAX);\n    L[0] = LLONG_MAX;\n  \n\
    \    for (int i = indexed; i <= N; i++) {\n    \tint li = 0;\n    \tint ri = N-indexed;\n\
    \        while(li < ri) {\n    \t\tint mi = (li+ri+1)>>1;\n    \t\tif(L[mi] >\
    \ A[i]) li = mi;\n    \t\telse ri = mi-1;\n    \t}\n          dp[i] = li + 1;\n\
    \          L[li+1] = max<long long>(L[li + 1], A[i]);\n      }\n     \n      int\
    \ answer = 0;\n      for  (int i = indexed; i <= N; i++) {\n        answer = max(answer,\
    \ dp[i]);\n      }\n      return answer;\n}\n\n/*\n@brief LIS/LDS\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Algorithms/lislds.cpp
  requiredBy: []
  timestamp: '2024-05-10 23:25:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Algorithms/lislds.cpp
layout: document
redirect_from:
- /library/Algorithms/lislds.cpp
- /library/Algorithms/lislds.cpp.html
title: LIS/LDS
---
