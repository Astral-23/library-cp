---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u6728\u306B\u95A2\u3059\u308Butility"
    links: []
  bundledCode: "#line 1 \"Graph/treefuncs.cpp\"\nstruct TreeFuncs {\n    using vi\
    \ = vector<int>;\n    using vvi = vector<vector<int>>;\n    vvi G;\n    int N;\n\
    \    int MAX_DIST = 1001001001;\n    int u = -1; int v = -1; int d = -1;\n   \
    \ TreeFuncs(vvi _G) : G(_G) {N = int(G.size()) - 1;}\n\n\n    private:\n\n   \
    \     vi dist__(int s) {\n            vi res(N+1, MAX_DIST);\n               \
    \ res[s] = 0;\n                queue<int> que;\n                que.push(s);\n\
    \                while(!que.empty()) {\n                    int now = que.front();\n\
    \                    que.pop();\n                    for(int to : G[now]) if(res[to]\
    \ == MAX_DIST) {\n                        res[to] = res[now] + 1;\n          \
    \              que.push(to);\n                    }\n                }\n     \
    \       return res;\n        }\n\n        vi path__(int s, int t) {\n        \
    \    vi res;\n            auto dfs = [&](auto f, int now, int prev = -1) -> bool\
    \ {\n                if(now == t) {\n                    res.push_back(now);\n\
    \                    return true;\n                }\n\n                for(int\
    \ to : G[now]) if(to != prev) {\n                    if(f(f, to, now)) {\n   \
    \                     res.push_back(now);\n                        return true;\n\
    \                    }\n                }\n                return false;\n   \
    \         };\n\n            dfs(dfs, s);\n            return res;\n        }\n\
    \    \n        pair<int, pair<int, int>> diam__() {\n            {\n         \
    \       vi ds = dist__(1);\n                int tmp = -1;\n                for(int\
    \ i = 1; i <= N; i++) {\n                    if(tmp < ds[i]) {\n             \
    \           u = i;\n                        tmp = ds[i];\n                   \
    \ }\n                }\n            }\n            {\n                vi ds =\
    \ dist__(u);\n                for(int i = 1; i <= N; i++) {\n                \
    \    if(d < ds[i]) {\n                        v = i;\n                       \
    \ d = ds[i];\n                    }\n                }\n            }\n\n    \
    \        pair<int, pair<int, int>> res;\n            res.first = d;\n        \
    \    res.second.first = u;\n            res.second.second = v;\n            return\
    \ res;\n        }\n\n        pair<int, int> center__() {\n            pair<int,\
    \ int> res(-1, -1);\n            if(d == -1) {\n                auto [t, p] =\
    \ diam__();\n                d = t; u = p.first; v = p.second;\n            }\n\
    \            vi ps = path__(u, v);\n            res.first = ps[d/2];\n       \
    \     if(d/2+1 < int(ps.size()) && res.first != ps[d/2+1]) res.second = ps[d/2+1];\n\
    \            return res;\n        }\n    public:\n\n        void change(vvi _G)\
    \ { G = _G, N = int(G.size())-1; u = -1; v = -1; d = -1;};\n\n        vi dist(int\
    \ s) {\n            return dist__(s);\n        }\n\n        vi path(int s, int\
    \ t) {\n            return path__(s, t);\n        }\n\n\n        pair<int, pair<int,\
    \ int>> diam() {\n            return diam__();\n        }\n\n      \n        pair<int,\
    \ int> center() {\n            return center__();\n        }\n\n        /*  \n\
    \            TreeFuncs\n            @brief \u6728\u306B\u95A2\u3059\u308Butility\n\
    \            \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF(G)\u30FBchange(G) ...\
    \ \u6271\u3046\u6728\u3092G\u306B\u5909\u66F4\n            dist(s) ... s\u304B\
    \u3089\u306E\u8DDD\u96E2\u3092\u5165\u308C\u305F\u914D\u5217\u3002\n         \
    \   path(s, t) ... s\u304B\u3089t\u306E\u30D1\u30B9\u4E0A\u306E\u9802\u70B9\u3092\
    , {s, ....., t}\u306E\u914D\u5217\u3067\u8FD4\u3059\u3002\n            diam()\
    \ ...pair(\u76F4\u5F84, pair(\u76F4\u5F84\u306E\u7AEFu, \u76F4\u5F84\u306E\u7AEF\
    v))\n            center() .... pair(u\u306B\u8FD1\u3044\u65B9\u306E\u4E2D\u5FC3\
    \u3001\uFF08\u5B58\u5728\u3059\u308B\u306A\u3089)v\u306B\u8FD1\u3044\u65B9\u306E\
    \u4E2D\u5FC3 (\u5B58\u5728\u3057\u306A\u3044)-1)\n        */\n};\n"
  code: "struct TreeFuncs {\n    using vi = vector<int>;\n    using vvi = vector<vector<int>>;\n\
    \    vvi G;\n    int N;\n    int MAX_DIST = 1001001001;\n    int u = -1; int v\
    \ = -1; int d = -1;\n    TreeFuncs(vvi _G) : G(_G) {N = int(G.size()) - 1;}\n\n\
    \n    private:\n\n        vi dist__(int s) {\n            vi res(N+1, MAX_DIST);\n\
    \                res[s] = 0;\n                queue<int> que;\n              \
    \  que.push(s);\n                while(!que.empty()) {\n                    int\
    \ now = que.front();\n                    que.pop();\n                    for(int\
    \ to : G[now]) if(res[to] == MAX_DIST) {\n                        res[to] = res[now]\
    \ + 1;\n                        que.push(to);\n                    }\n       \
    \         }\n            return res;\n        }\n\n        vi path__(int s, int\
    \ t) {\n            vi res;\n            auto dfs = [&](auto f, int now, int prev\
    \ = -1) -> bool {\n                if(now == t) {\n                    res.push_back(now);\n\
    \                    return true;\n                }\n\n                for(int\
    \ to : G[now]) if(to != prev) {\n                    if(f(f, to, now)) {\n   \
    \                     res.push_back(now);\n                        return true;\n\
    \                    }\n                }\n                return false;\n   \
    \         };\n\n            dfs(dfs, s);\n            return res;\n        }\n\
    \    \n        pair<int, pair<int, int>> diam__() {\n            {\n         \
    \       vi ds = dist__(1);\n                int tmp = -1;\n                for(int\
    \ i = 1; i <= N; i++) {\n                    if(tmp < ds[i]) {\n             \
    \           u = i;\n                        tmp = ds[i];\n                   \
    \ }\n                }\n            }\n            {\n                vi ds =\
    \ dist__(u);\n                for(int i = 1; i <= N; i++) {\n                \
    \    if(d < ds[i]) {\n                        v = i;\n                       \
    \ d = ds[i];\n                    }\n                }\n            }\n\n    \
    \        pair<int, pair<int, int>> res;\n            res.first = d;\n        \
    \    res.second.first = u;\n            res.second.second = v;\n            return\
    \ res;\n        }\n\n        pair<int, int> center__() {\n            pair<int,\
    \ int> res(-1, -1);\n            if(d == -1) {\n                auto [t, p] =\
    \ diam__();\n                d = t; u = p.first; v = p.second;\n            }\n\
    \            vi ps = path__(u, v);\n            res.first = ps[d/2];\n       \
    \     if(d/2+1 < int(ps.size()) && res.first != ps[d/2+1]) res.second = ps[d/2+1];\n\
    \            return res;\n        }\n    public:\n\n        void change(vvi _G)\
    \ { G = _G, N = int(G.size())-1; u = -1; v = -1; d = -1;};\n\n        vi dist(int\
    \ s) {\n            return dist__(s);\n        }\n\n        vi path(int s, int\
    \ t) {\n            return path__(s, t);\n        }\n\n\n        pair<int, pair<int,\
    \ int>> diam() {\n            return diam__();\n        }\n\n      \n        pair<int,\
    \ int> center() {\n            return center__();\n        }\n\n        /*  \n\
    \            TreeFuncs\n            @brief \u6728\u306B\u95A2\u3059\u308Butility\n\
    \            \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF(G)\u30FBchange(G) ...\
    \ \u6271\u3046\u6728\u3092G\u306B\u5909\u66F4\n            dist(s) ... s\u304B\
    \u3089\u306E\u8DDD\u96E2\u3092\u5165\u308C\u305F\u914D\u5217\u3002\n         \
    \   path(s, t) ... s\u304B\u3089t\u306E\u30D1\u30B9\u4E0A\u306E\u9802\u70B9\u3092\
    , {s, ....., t}\u306E\u914D\u5217\u3067\u8FD4\u3059\u3002\n            diam()\
    \ ...pair(\u76F4\u5F84, pair(\u76F4\u5F84\u306E\u7AEFu, \u76F4\u5F84\u306E\u7AEF\
    v))\n            center() .... pair(u\u306B\u8FD1\u3044\u65B9\u306E\u4E2D\u5FC3\
    \u3001\uFF08\u5B58\u5728\u3059\u308B\u306A\u3089)v\u306B\u8FD1\u3044\u65B9\u306E\
    \u4E2D\u5FC3 (\u5B58\u5728\u3057\u306A\u3044)-1)\n        */\n};"
  dependsOn: []
  isVerificationFile: false
  path: Graph/treefuncs.cpp
  requiredBy: []
  timestamp: '2024-05-10 23:04:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/treefuncs.cpp
layout: document
redirect_from:
- /library/Graph/treefuncs.cpp
- /library/Graph/treefuncs.cpp.html
title: "\u6728\u306B\u95A2\u3059\u308Butility"
---
