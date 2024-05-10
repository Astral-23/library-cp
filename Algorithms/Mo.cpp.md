---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Mo
    links: []
  bundledCode: "#line 1 \"Algorithms/Mo.cpp\"\nstruct Mo {\n  int N;\n  int Q;\n \
    \ vector<pair<int, int>> lr;\n  vector<int> querynum;\n  int width;\n  int nowl\
    \ = 0;\n  int nowr = 0;\n  //\u7B54\u3048\u3092\u8A18\u9332\u3059\u308B\u914D\u5217\
    \u3068\u4E00\u6642\u7684\u306A\u7B54\u3048\u3092\u8A18\u9332\u3059\u308B\u5909\
    \u6570\n  vl answer;\n  long long ans = 0;\n  //\u578B\u306F\u554F\u984C\u306B\
    \u3088\u3063\u3066\u5909\u308F\u308B\u304B\u3082\n\n\n  Mo (int n, int q, vector<pair<int,int>>\
    \ &query) {\n    N = n;\n    Q = q;\n    lr.resize(Q+1);\n    answer.resize(Q+1);\n\
    \    querynum.resize(Q+1);\n    rep(i, 1, Q) {\n      querynum[i] = i;\n    }\n\
    \    //width = max(1, int(N/sqrt(Q)));\n    width = max<int>(1, 1.0 * N / max<double>(1.0,\
    \ sqrt(Q * 2.0 / 3.0)));\n    rep(i, 1, Q) {\n      lr[i] = query[i];\n    }\n\
    \n    sort(querynum.begin()+1, querynum.end(), [&](int i, int j) {\n      if(lr[i].first/width\
    \ != lr[j].first/width) {\n        return lr[i].first < lr[j].first;\n      }\n\
    \      else {\n        int group = lr[i].first/width;\n        if(group%2==0)\
    \ {\n          return lr[i].second < lr[j].second;\n        }\n        else {\n\
    \          return lr[i].second > lr[j].second;\n        }\n      }\n    });\n\
    \  }\n\n  void add(int id) {\n \n\n  }\n\n  void del(int id) {\n\n  }\n\n\n  void\
    \ excute() {\n    for(int i = 1; i <= Q; i++) {\n      while(nowl > lr[querynum[i]].first)\
    \ nowl--, add(nowl);\n      while(nowr < lr[querynum[i]].second) nowr++, add(nowr);\n\
    \      while(nowl < lr[querynum[i]].first) del(nowl), nowl++;\n      while(nowr\
    \ > lr[querynum[i]].second) del(nowr), nowr--;\n      answer[querynum[i]] = ans;\n\
    \    }\n  }\n};\n\n/*\n@brief Mo \n*/\n"
  code: "struct Mo {\n  int N;\n  int Q;\n  vector<pair<int, int>> lr;\n  vector<int>\
    \ querynum;\n  int width;\n  int nowl = 0;\n  int nowr = 0;\n  //\u7B54\u3048\u3092\
    \u8A18\u9332\u3059\u308B\u914D\u5217\u3068\u4E00\u6642\u7684\u306A\u7B54\u3048\
    \u3092\u8A18\u9332\u3059\u308B\u5909\u6570\n  vl answer;\n  long long ans = 0;\n\
    \  //\u578B\u306F\u554F\u984C\u306B\u3088\u3063\u3066\u5909\u308F\u308B\u304B\u3082\
    \n\n\n  Mo (int n, int q, vector<pair<int,int>> &query) {\n    N = n;\n    Q =\
    \ q;\n    lr.resize(Q+1);\n    answer.resize(Q+1);\n    querynum.resize(Q+1);\n\
    \    rep(i, 1, Q) {\n      querynum[i] = i;\n    }\n    //width = max(1, int(N/sqrt(Q)));\n\
    \    width = max<int>(1, 1.0 * N / max<double>(1.0, sqrt(Q * 2.0 / 3.0)));\n \
    \   rep(i, 1, Q) {\n      lr[i] = query[i];\n    }\n\n    sort(querynum.begin()+1,\
    \ querynum.end(), [&](int i, int j) {\n      if(lr[i].first/width != lr[j].first/width)\
    \ {\n        return lr[i].first < lr[j].first;\n      }\n      else {\n      \
    \  int group = lr[i].first/width;\n        if(group%2==0) {\n          return\
    \ lr[i].second < lr[j].second;\n        }\n        else {\n          return lr[i].second\
    \ > lr[j].second;\n        }\n      }\n    });\n  }\n\n  void add(int id) {\n\
    \ \n\n  }\n\n  void del(int id) {\n\n  }\n\n\n  void excute() {\n    for(int i\
    \ = 1; i <= Q; i++) {\n      while(nowl > lr[querynum[i]].first) nowl--, add(nowl);\n\
    \      while(nowr < lr[querynum[i]].second) nowr++, add(nowr);\n      while(nowl\
    \ < lr[querynum[i]].first) del(nowl), nowl++;\n      while(nowr > lr[querynum[i]].second)\
    \ del(nowr), nowr--;\n      answer[querynum[i]] = ans;\n    }\n  }\n};\n\n/*\n\
    @brief Mo \n*/"
  dependsOn: []
  isVerificationFile: false
  path: Algorithms/Mo.cpp
  requiredBy: []
  timestamp: '2024-05-10 23:04:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Algorithms/Mo.cpp
layout: document
redirect_from:
- /library/Algorithms/Mo.cpp
- /library/Algorithms/Mo.cpp.html
title: Mo
---
