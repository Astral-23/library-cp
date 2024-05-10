---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: 2sat
    links: []
  bundledCode: "#line 1 \"Algorithms/twosat.cpp\"\ntemplate<typename EDGE>\nclass\
    \ SCC {\n    private:\n        void sDFS(int now, vector<vector<EDGE>>& G, vector<bool>&\
    \ visited, vector<int>& vs) {\n            visited[now] = true;\n            for(auto&\
    \ e : G[now]) {\n                if(!visited[e.to]) sDFS(e.to, G, visited, vs);\n\
    \            }\n            vs.push_back(now);\n            return;\n        }\n\
    \n        void srDFS(int now, vector<vector<EDGE>>& rG, vector<bool>& rvisited,\
    \ vector<int>& cmp, int k) {\n            rvisited[now] = true;\n            cmp[now]\
    \ = k;\n            for(EDGE& e : rG[now]) {\n                if(!rvisited[e.to])\
    \ srDFS(e.to, rG, rvisited, cmp, k);\n            }\n        }\n    \n    public:\n\
    \        SCC(){}\n        vector<int> build_scc(int MAX_N, vector<vector<EDGE>>&\
    \ G, int indexed) {//indexed : \u9802\u70B9\u756A\u53F7\u306F\u4F55\u304B\u3089\
    \u59CB\u307E\u308B\u304B MAX_N : \u6700\u5927\u306E\u9802\u70B9\u756A\u53F7\n\
    \            int t = indexed;\n            int N = MAX_N;\n            vector<vector<EDGE>>\
    \ rG(N+1);\n            vector<int> vs;\n            vector<bool> visited(N+1,\
    \ false);\n\n            for(int i = t; i <= N; i++) {\n                for(EDGE&\
    \ e : G[i]) {\n                    EDGE ne = e;\n                    ne.to = i;\n\
    \                    rG[e.to].push_back(ne);\n                }\n            }\n\
    \n            for(int i = t; i <= N; i++) {\n                if(!visited[i])sDFS(i,\
    \ G, visited, vs);\n            }\n        \n            vector<int> cmp(N+1,\
    \ -1);\n            vector<bool> rvisited(N+1, false);\n            int k = 1;\n\
    \            for(int i = vs.size(); i >= 1; i--) {\n                if(!rvisited[vs[i-1]])\
    \ srDFS(vs[i-1], rG, rvisited, cmp, k++);\n            }\n            return cmp;\n\
    \        }\n};\n\nstruct edge {\n    int to;\n};\nSCC<edge> scc;//1\u304B\u3089\
    \u59CB\u307E\u308B\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u9806\u5E8F\u3092\u8FD4\
    \u3059\u3002\u9802\u70B9\u306Eindexed\u3092bulid_scc\u306B\u6E21\u3059\u3002\n\
    \ntemplate<typename EDGE>\nstruct two_sat {\n    int N;//\u547D\u984C\u5909\u6570\
    \u306E\u7A2E\u985E\u6570\u3092\u8868\u3059\u3002\n    int N2;//N\u306E2\u500D\u3092\
    \u8868\u3059\u3002\n    vector<bool> res;//\u7D50\u679C\u3002\n    bool pre_res;//answer\u95A2\
    \u6570\u3067\u8AAC\u660E\u3002\n    vector<vector<EDGE>> G; //i\u756A\u76EE\u306E\
    \u547D\u984C\u5909\u6570\u306B\u3064\u3044\u3066\u3001\u305D\u306E\u307E\u307E\
    \u3092i\u756A\u76EE\u306E\u9802\u70B9\u3001\u5426\u5B9A\u3092i+N\u756A\u76EE\u306E\
    \u9802\u70B9\u306B\u5272\u308A\u5F53\u3066\u308B\u3053\u3068\u306B\u3059\u308B\
    \u3002\n    two_sat(int _N) : N(_N){\n        N2 = N * 2;\n        G.resize(N2+1);\n\
    \        res.resize(N+1, false);\n    };\n    \n\n    void add_clause(int i, bool\
    \ f, int j, bool g) {//\u7BC0\u3092\u8FFD\u52A0\u3059\u308B\u3002f, g = true\u306A\
    \u3089\u3070\u80AF\u5B9A\u3067\u3042\u308B\u3053\u3068\u3001 f, g = false\u306A\
    \u3089\u3070\u5426\u5B9A\u304C\u3064\u3044\u3066\u3044\u308B\u4E8B\u3092\u8868\
    \u3059\u3002\n        int ni = i, nj = j;\n        if(!f) ni += N;\n        if(!g)\
    \ nj += N;\n        // not i  \u2192 j\n        if(!f) G[ni-N].emplace_back(nj);\n\
    \        else G[ni+N].emplace_back(nj);      \n        // not j \u2192 i\n   \
    \     if(!g)G[nj-N].emplace_back(ni);\n        else G[nj+N].emplace_back(ni);\n\
    \    }\n\n    bool satisfiable() {//\u73FE\u72B6\u306E\u547D\u984C\u8AD6\u7406\
    \u5F0F\u3092\u5145\u8DB3\u3059\u308B\u5272\u308A\u632F\u308A\u304C\u5B58\u5728\
    \u3059\u308B\u304B\u3092\u8FD4\u3059\u3002\n        for(int i = 1; i <= N; i++)\
    \ res[i] = false;//\u7D50\u679C\u3092\u683C\u7D0D\u3059\u308B\u914D\u5217\u306E\
    \u521D\u671F\u5316\u3002\n        vector<int> scc_res = scc.build_scc(N2, G, 1);\n\
    \        for(int i = 1; i <= N; i++) {\n            //i\u756A\u76EE\u306E\u547D\
    \u984C\u5909\u6570\u306B\u3064\u3044\u3066\u307F\u308B\u3002\n            if(scc_res[i]\
    \ == scc_res[i+N]) {\n                pre_res = false;\n                return\
    \ false;//i\u756A\u76EE\u306E\u547D\u984C\u5909\u6570\u306B\u3064\u3044\u3066\u3001\
    \u305D\u306E\u307E\u307E\u3068\u5426\u5B9A\u304C\u540C\u3058\u5F37\u9023\u7D50\
    \u6210\u5206\u306B\u5B58\u5728\u3002\u3053\u306E\u6642\u5272\u308A\u632F\u308A\
    \u306F\u5B58\u5728\u3057\u306A\u3044\u3002\n            }\n            if(scc_res[i]\
    \ > scc_res[i+N]) res[i] = true;// P[i] > P[not i]\u306A\u3089true\u3002 P[i]\
    \ < P[not i]\u306A\u3089false\u3002\n        }\n        pre_res = true;\n    \
    \    return true;//\u5168\u3066\u306B\u3064\u3044\u3066\u5272\u308A\u632F\u308C\
    \u305F\u306A\u3089\u5B58\u5728\u3059\u308B\u3002\n    }\n\n    pair<vector<bool>,\
    \ bool> answer() {//\u76F4\u8FD1\u3067satisfiable\u3092\u547C\u3093\u3060\u6642\
    \u306E\u5272\u308A\u5F53\u3066\u306E\u7D50\u679C\u3068\u3001\u5B58\u5728\u3057\
    \u305F\u306E\u304B\u3092\u8FD4\u3059\u3002\n        return make_pair(res, pre_res);\n\
    \    }\n};\n\n/*\n@brief 2sat\n*/\n"
  code: "template<typename EDGE>\nclass SCC {\n    private:\n        void sDFS(int\
    \ now, vector<vector<EDGE>>& G, vector<bool>& visited, vector<int>& vs) {\n  \
    \          visited[now] = true;\n            for(auto& e : G[now]) {\n       \
    \         if(!visited[e.to]) sDFS(e.to, G, visited, vs);\n            }\n    \
    \        vs.push_back(now);\n            return;\n        }\n\n        void srDFS(int\
    \ now, vector<vector<EDGE>>& rG, vector<bool>& rvisited, vector<int>& cmp, int\
    \ k) {\n            rvisited[now] = true;\n            cmp[now] = k;\n       \
    \     for(EDGE& e : rG[now]) {\n                if(!rvisited[e.to]) srDFS(e.to,\
    \ rG, rvisited, cmp, k);\n            }\n        }\n    \n    public:\n      \
    \  SCC(){}\n        vector<int> build_scc(int MAX_N, vector<vector<EDGE>>& G,\
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
    \        }\n};\n\nstruct edge {\n    int to;\n};\nSCC<edge> scc;//1\u304B\u3089\
    \u59CB\u307E\u308B\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u9806\u5E8F\u3092\u8FD4\
    \u3059\u3002\u9802\u70B9\u306Eindexed\u3092bulid_scc\u306B\u6E21\u3059\u3002\n\
    \ntemplate<typename EDGE>\nstruct two_sat {\n    int N;//\u547D\u984C\u5909\u6570\
    \u306E\u7A2E\u985E\u6570\u3092\u8868\u3059\u3002\n    int N2;//N\u306E2\u500D\u3092\
    \u8868\u3059\u3002\n    vector<bool> res;//\u7D50\u679C\u3002\n    bool pre_res;//answer\u95A2\
    \u6570\u3067\u8AAC\u660E\u3002\n    vector<vector<EDGE>> G; //i\u756A\u76EE\u306E\
    \u547D\u984C\u5909\u6570\u306B\u3064\u3044\u3066\u3001\u305D\u306E\u307E\u307E\
    \u3092i\u756A\u76EE\u306E\u9802\u70B9\u3001\u5426\u5B9A\u3092i+N\u756A\u76EE\u306E\
    \u9802\u70B9\u306B\u5272\u308A\u5F53\u3066\u308B\u3053\u3068\u306B\u3059\u308B\
    \u3002\n    two_sat(int _N) : N(_N){\n        N2 = N * 2;\n        G.resize(N2+1);\n\
    \        res.resize(N+1, false);\n    };\n    \n\n    void add_clause(int i, bool\
    \ f, int j, bool g) {//\u7BC0\u3092\u8FFD\u52A0\u3059\u308B\u3002f, g = true\u306A\
    \u3089\u3070\u80AF\u5B9A\u3067\u3042\u308B\u3053\u3068\u3001 f, g = false\u306A\
    \u3089\u3070\u5426\u5B9A\u304C\u3064\u3044\u3066\u3044\u308B\u4E8B\u3092\u8868\
    \u3059\u3002\n        int ni = i, nj = j;\n        if(!f) ni += N;\n        if(!g)\
    \ nj += N;\n        // not i  \u2192 j\n        if(!f) G[ni-N].emplace_back(nj);\n\
    \        else G[ni+N].emplace_back(nj);      \n        // not j \u2192 i\n   \
    \     if(!g)G[nj-N].emplace_back(ni);\n        else G[nj+N].emplace_back(ni);\n\
    \    }\n\n    bool satisfiable() {//\u73FE\u72B6\u306E\u547D\u984C\u8AD6\u7406\
    \u5F0F\u3092\u5145\u8DB3\u3059\u308B\u5272\u308A\u632F\u308A\u304C\u5B58\u5728\
    \u3059\u308B\u304B\u3092\u8FD4\u3059\u3002\n        for(int i = 1; i <= N; i++)\
    \ res[i] = false;//\u7D50\u679C\u3092\u683C\u7D0D\u3059\u308B\u914D\u5217\u306E\
    \u521D\u671F\u5316\u3002\n        vector<int> scc_res = scc.build_scc(N2, G, 1);\n\
    \        for(int i = 1; i <= N; i++) {\n            //i\u756A\u76EE\u306E\u547D\
    \u984C\u5909\u6570\u306B\u3064\u3044\u3066\u307F\u308B\u3002\n            if(scc_res[i]\
    \ == scc_res[i+N]) {\n                pre_res = false;\n                return\
    \ false;//i\u756A\u76EE\u306E\u547D\u984C\u5909\u6570\u306B\u3064\u3044\u3066\u3001\
    \u305D\u306E\u307E\u307E\u3068\u5426\u5B9A\u304C\u540C\u3058\u5F37\u9023\u7D50\
    \u6210\u5206\u306B\u5B58\u5728\u3002\u3053\u306E\u6642\u5272\u308A\u632F\u308A\
    \u306F\u5B58\u5728\u3057\u306A\u3044\u3002\n            }\n            if(scc_res[i]\
    \ > scc_res[i+N]) res[i] = true;// P[i] > P[not i]\u306A\u3089true\u3002 P[i]\
    \ < P[not i]\u306A\u3089false\u3002\n        }\n        pre_res = true;\n    \
    \    return true;//\u5168\u3066\u306B\u3064\u3044\u3066\u5272\u308A\u632F\u308C\
    \u305F\u306A\u3089\u5B58\u5728\u3059\u308B\u3002\n    }\n\n    pair<vector<bool>,\
    \ bool> answer() {//\u76F4\u8FD1\u3067satisfiable\u3092\u547C\u3093\u3060\u6642\
    \u306E\u5272\u308A\u5F53\u3066\u306E\u7D50\u679C\u3068\u3001\u5B58\u5728\u3057\
    \u305F\u306E\u304B\u3092\u8FD4\u3059\u3002\n        return make_pair(res, pre_res);\n\
    \    }\n};\n\n/*\n@brief 2sat\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Algorithms/twosat.cpp
  requiredBy: []
  timestamp: '2024-05-10 23:04:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Algorithms/twosat.cpp
layout: document
redirect_from:
- /library/Algorithms/twosat.cpp
- /library/Algorithms/twosat.cpp.html
title: 2sat
---
