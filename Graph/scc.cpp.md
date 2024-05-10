---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
    links: []
  bundledCode: "#line 1 \"Graph/scc.cpp\"\ntemplate<typename EDGE>\nclass SCC {\n\
    \    private:\n        void sDFS(int now, vector<vector<EDGE>>& G, vector<bool>&\
    \ visited, vector<int>& vs) {\n            visited[now] = true;\n            for(auto&\
    \ e : G[now]) {\n                if(!visited[e.to]) sDFS(e.to, G, visited, vs);\n\
    \            }\n            vs.push_back(now);\n            return;\n        }\n\
    \n        void srDFS(int now, vector<vector<EDGE>>& rG, vector<bool>& rvisited,\
    \ vector<int>& cmp, int k) {\n            rvisited[now] = true;\n            cmp[now]\
    \ = k;\n            for(EDGE& e : rG[now]) {\n                if(!rvisited[e.to])\
    \ srDFS(e.to, rG, rvisited, cmp, k);\n            }\n        }\n    \n    public:\n\
    \        SCC(){}\n        vector<int> build_scc(int MAX_N, vector<vector<EDGE>>&G,\
    \ int indexed) {//indexed : \u9802\u70B9\u756A\u53F7\u306F\u4F55\u304B\u3089\u59CB\
    \u307E\u308B\u304B MAX_N : \u6700\u5927\u306E\u9802\u70B9\u756A\u53F7\n      \
    \      int t = indexed;\n            int N = MAX_N;\n            vector<vector<EDGE>>\
    \ rG(N+1);\n            vector<int> vs;\n            vector<bool> visited(N+1,\
    \ false);\n\n            for(int i = t; i <= N; i++) {\n                for(EDGE&\
    \ e : G[i]) {\n                    EDGE ne = e;\n                    ne.to = i;\n\
    \                    rG[e.to].push_back(ne);\n                }\n            }\n\
    \n            for(int i = t; i <= N; i++) {\n                if(!visited[i])sDFS(i,\
    \ G, visited, vs);\n            }\n        \n            vector<int> cmp(N+1,\
    \ -1);\n            vector<bool> rvisited(N+1, false);\n            int k = 1;\n\
    \            for(int i = vs.size(); i >= 1; i--) {\n                if(!rvisited[vs[i-1]])\
    \ srDFS(vs[i-1], rG, rvisited, cmp, k++);\n            }\n            return cmp;\n\
    \        }\n};\nstruct edge {\n    int to;\n};\nSCC<edge> scc;//1\u304B\u3089\u59CB\
    \u307E\u308B\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u9806\u5E8F\u3092\u8FD4\u3059\
    \u3002\u9802\u70B9\u306Eindexed\u3092bulid_scc\u306B\u6E21\u3059\u3002\n\n/*\n\
    @brief \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\n*/\n"
  code: "template<typename EDGE>\nclass SCC {\n    private:\n        void sDFS(int\
    \ now, vector<vector<EDGE>>& G, vector<bool>& visited, vector<int>& vs) {\n  \
    \          visited[now] = true;\n            for(auto& e : G[now]) {\n       \
    \         if(!visited[e.to]) sDFS(e.to, G, visited, vs);\n            }\n    \
    \        vs.push_back(now);\n            return;\n        }\n\n        void srDFS(int\
    \ now, vector<vector<EDGE>>& rG, vector<bool>& rvisited, vector<int>& cmp, int\
    \ k) {\n            rvisited[now] = true;\n            cmp[now] = k;\n       \
    \     for(EDGE& e : rG[now]) {\n                if(!rvisited[e.to]) srDFS(e.to,\
    \ rG, rvisited, cmp, k);\n            }\n        }\n    \n    public:\n      \
    \  SCC(){}\n        vector<int> build_scc(int MAX_N, vector<vector<EDGE>>&G, int\
    \ indexed) {//indexed : \u9802\u70B9\u756A\u53F7\u306F\u4F55\u304B\u3089\u59CB\
    \u307E\u308B\u304B MAX_N : \u6700\u5927\u306E\u9802\u70B9\u756A\u53F7\n      \
    \      int t = indexed;\n            int N = MAX_N;\n            vector<vector<EDGE>>\
    \ rG(N+1);\n            vector<int> vs;\n            vector<bool> visited(N+1,\
    \ false);\n\n            for(int i = t; i <= N; i++) {\n                for(EDGE&\
    \ e : G[i]) {\n                    EDGE ne = e;\n                    ne.to = i;\n\
    \                    rG[e.to].push_back(ne);\n                }\n            }\n\
    \n            for(int i = t; i <= N; i++) {\n                if(!visited[i])sDFS(i,\
    \ G, visited, vs);\n            }\n        \n            vector<int> cmp(N+1,\
    \ -1);\n            vector<bool> rvisited(N+1, false);\n            int k = 1;\n\
    \            for(int i = vs.size(); i >= 1; i--) {\n                if(!rvisited[vs[i-1]])\
    \ srDFS(vs[i-1], rG, rvisited, cmp, k++);\n            }\n            return cmp;\n\
    \        }\n};\nstruct edge {\n    int to;\n};\nSCC<edge> scc;//1\u304B\u3089\u59CB\
    \u307E\u308B\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u9806\u5E8F\u3092\u8FD4\u3059\
    \u3002\u9802\u70B9\u306Eindexed\u3092bulid_scc\u306B\u6E21\u3059\u3002\n\n/*\n\
    @brief \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Graph/scc.cpp
  requiredBy: []
  timestamp: '2024-05-10 23:04:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/scc.cpp
layout: document
redirect_from:
- /library/Graph/scc.cpp
- /library/Graph/scc.cpp.html
title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
---
