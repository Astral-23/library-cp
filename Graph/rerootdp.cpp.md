---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u5168\u65B9\u4F4D\u6728DP"
    links: []
  bundledCode: "#line 1 \"Graph/rerootdp.cpp\"\ntemplate<typename tdp>\nstruct TDP_MAIN\
    \ {\n    int N;\n    vector<vector<pair<int, int>>> G;\n    vector<vector<tdp>>\
    \ dp;//dp[now][i] :=  \u5168\u4F53\u306E\u6839\u3092now\u3068\u3057\u305F\u6642\
    \u3001 G[now][i]\u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306E\u7D50\u679C\
    \n    vector<tdp> ans;\n  \n    TDP_MAIN (int _N) : N(_N) {G.resize(N+1), dp.resize(N+1),\
    \ ans.resize(N+1);}\n\n\n    private:\n        tdp dfs(int now, int prev) {\n\
    \            tdp res = tdp();\n            int deg = G[now].size();\n        \
    \    dp[now].resize(deg);\n            for(int i = 0; i < deg; i++) {\n      \
    \          int to = G[now][i].first;\n                if(to == prev) continue;\n\
    \                dp[now][i] = dfs(to, now);\n                res = op(res, E(dp[now][i],\
    \ G[now][i].second));\n            }\n            return res.addRoot(now);\n \
    \       }\n\n\n        void bfs(int now, const tdp& dpPar, int prev) {\n     \
    \       int deg = G[now].size();\n            for(int i = 0; i < deg; i++) if(G[now][i].first\
    \ == prev) dp[now][i] = dpPar;\n            \n            vector<tdp> dpsumL(deg+1,\
    \ tdp()); //dpsumL[i] := [0, i-1]\n            vector<tdp> dpsumR(deg+1, tdp());\
    \ //dpsumR[i] := [i, deg-1]\n\n\n            for(int i = 0; i < deg; i++) dpsumL[i+1]\
    \ = op(dpsumL[i], E(dp[now][i], G[now][i].second));\n            for(int i = deg-1;\
    \ i >= 0; i--) dpsumR[i] = op(dpsumR[i+1], E(dp[now][i], G[now][i].second));\n\
    \            \n            reflect(now, dpsumL[deg].addRoot(now));\n\n       \
    \     for(int i = 0; i < deg; i++) {\n                int to = G[now][i].first;\n\
    \                if(to == prev) continue;\n                tdp d = op(dpsumL[i],\
    \ dpsumR[i+1]);\n                bfs(to, d.addRoot(now), now);\n\n           \
    \ }\n        }\n\n\t\tvoid reflect(int now, const tdp& res) {\n\t\t    ans[now]\
    \ = res;    \n            return;        \n        }\n\n    public:\n\n\t    void\
    \ add_edge(int u, int v, int id) {\n\t\t\tG[u].emplace_back(v, id);\n\t\t\tG[v].emplace_back(u,\
    \ id);\n\t    } \n        \n        vector<tdp> exe() {\n            dfs(1, -1);\
    \ tdp tmp = tdp();\n            bfs(1, tmp, -1);\n            return ans;\n  \
    \      }\n\n\t\t/*\n\t\t  TDP_MAIN<tdp> (N, G)\n\t\t  @brief \u5168\u65B9\u4F4D\
    \u6728DP\n\t\t  add_edge(u, v, id) ... (u, v)\u9593\u306B\u8FBA\u756A\u53F7\u304C\
    id\u306E\u8FBA\u3092\u8FFD\u52A0\u3059\u308B\u3002\n\t\t  exe()...\u5B9F\u884C\
    \n\t\t\n\t\t  \u8AF8\u6CE8\u610F\uFF1A\n\t\t    \u30FB\u6728DP\u3067\u4E00\u6642\
    \u5909\u6570\u306B\u4EFB\u305B\u3066\u305F\u7269\u306F\u3001\u5168\u65B9\u4F4D\
    \u6728DP\u3067\u306F\u660E\u793A\u7684\u306B\u6301\u3064\u5FC5\u8981\u304C\u3042\
    \u308B\u3002\n\t\t\tE...\u8FBA\u91CD\u307F\u3092\u8FFD\u52A0\u3002\u4E00\u69D8\
    \u306A\u3089addRoot\u306E\u6642\u3067\u826F\u3044\u3002\n\t\t\top...\u96C6\u7D04\
    \u3002\n\t\t\t\n\t\t*/\n};\n\n\nstruct TDP {\n\n\tll val;\n\n\tTDP (ll _val =\
    \ 0) :  val(_val) {}\n    \n\tfriend TDP E (const TDP& l, int id) {\n\t\n\n\t\
    }\n\n    friend TDP op (const TDP& l, const TDP& r)  {\n\t\t\n    }\n\n\t\n  \
    \  TDP addRoot (int now)  { //*this\u304C\u5B50\u306E\u96C6\u7D04\u7D50\u679C\n\
    \t\n    }\n\n};\n"
  code: "template<typename tdp>\nstruct TDP_MAIN {\n    int N;\n    vector<vector<pair<int,\
    \ int>>> G;\n    vector<vector<tdp>> dp;//dp[now][i] :=  \u5168\u4F53\u306E\u6839\
    \u3092now\u3068\u3057\u305F\u6642\u3001 G[now][i]\u3092\u6839\u3068\u3059\u308B\
    \u90E8\u5206\u6728\u306E\u7D50\u679C\n    vector<tdp> ans;\n  \n    TDP_MAIN (int\
    \ _N) : N(_N) {G.resize(N+1), dp.resize(N+1), ans.resize(N+1);}\n\n\n    private:\n\
    \        tdp dfs(int now, int prev) {\n            tdp res = tdp();\n        \
    \    int deg = G[now].size();\n            dp[now].resize(deg);\n            for(int\
    \ i = 0; i < deg; i++) {\n                int to = G[now][i].first;\n        \
    \        if(to == prev) continue;\n                dp[now][i] = dfs(to, now);\n\
    \                res = op(res, E(dp[now][i], G[now][i].second));\n           \
    \ }\n            return res.addRoot(now);\n        }\n\n\n        void bfs(int\
    \ now, const tdp& dpPar, int prev) {\n            int deg = G[now].size();\n \
    \           for(int i = 0; i < deg; i++) if(G[now][i].first == prev) dp[now][i]\
    \ = dpPar;\n            \n            vector<tdp> dpsumL(deg+1, tdp()); //dpsumL[i]\
    \ := [0, i-1]\n            vector<tdp> dpsumR(deg+1, tdp()); //dpsumR[i] := [i,\
    \ deg-1]\n\n\n            for(int i = 0; i < deg; i++) dpsumL[i+1] = op(dpsumL[i],\
    \ E(dp[now][i], G[now][i].second));\n            for(int i = deg-1; i >= 0; i--)\
    \ dpsumR[i] = op(dpsumR[i+1], E(dp[now][i], G[now][i].second));\n            \n\
    \            reflect(now, dpsumL[deg].addRoot(now));\n\n            for(int i\
    \ = 0; i < deg; i++) {\n                int to = G[now][i].first;\n          \
    \      if(to == prev) continue;\n                tdp d = op(dpsumL[i], dpsumR[i+1]);\n\
    \                bfs(to, d.addRoot(now), now);\n\n            }\n        }\n\n\
    \t\tvoid reflect(int now, const tdp& res) {\n\t\t    ans[now] = res;    \n   \
    \         return;        \n        }\n\n    public:\n\n\t    void add_edge(int\
    \ u, int v, int id) {\n\t\t\tG[u].emplace_back(v, id);\n\t\t\tG[v].emplace_back(u,\
    \ id);\n\t    } \n        \n        vector<tdp> exe() {\n            dfs(1, -1);\
    \ tdp tmp = tdp();\n            bfs(1, tmp, -1);\n            return ans;\n  \
    \      }\n\n\t\t/*\n\t\t  TDP_MAIN<tdp> (N, G)\n\t\t  @brief \u5168\u65B9\u4F4D\
    \u6728DP\n\t\t  add_edge(u, v, id) ... (u, v)\u9593\u306B\u8FBA\u756A\u53F7\u304C\
    id\u306E\u8FBA\u3092\u8FFD\u52A0\u3059\u308B\u3002\n\t\t  exe()...\u5B9F\u884C\
    \n\t\t\n\t\t  \u8AF8\u6CE8\u610F\uFF1A\n\t\t    \u30FB\u6728DP\u3067\u4E00\u6642\
    \u5909\u6570\u306B\u4EFB\u305B\u3066\u305F\u7269\u306F\u3001\u5168\u65B9\u4F4D\
    \u6728DP\u3067\u306F\u660E\u793A\u7684\u306B\u6301\u3064\u5FC5\u8981\u304C\u3042\
    \u308B\u3002\n\t\t\tE...\u8FBA\u91CD\u307F\u3092\u8FFD\u52A0\u3002\u4E00\u69D8\
    \u306A\u3089addRoot\u306E\u6642\u3067\u826F\u3044\u3002\n\t\t\top...\u96C6\u7D04\
    \u3002\n\t\t\t\n\t\t*/\n};\n\n\nstruct TDP {\n\n\tll val;\n\n\tTDP (ll _val =\
    \ 0) :  val(_val) {}\n    \n\tfriend TDP E (const TDP& l, int id) {\n\t\n\n\t\
    }\n\n    friend TDP op (const TDP& l, const TDP& r)  {\n\t\t\n    }\n\n\t\n  \
    \  TDP addRoot (int now)  { //*this\u304C\u5B50\u306E\u96C6\u7D04\u7D50\u679C\n\
    \t\n    }\n\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/rerootdp.cpp
  requiredBy: []
  timestamp: '2024-05-10 23:04:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/rerootdp.cpp
layout: document
redirect_from:
- /library/Graph/rerootdp.cpp
- /library/Graph/rerootdp.cpp.html
title: "\u5168\u65B9\u4F4D\u6728DP"
---
