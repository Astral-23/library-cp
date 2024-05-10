---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u6728\u306B\u95A2\u3059\u308Butility by HLD(lca,jump,ances)"
    links: []
  bundledCode: "#line 1 \"Graph/hld_utiliry.cpp\"\nstruct LCA {\n\n    LCA(vector<vector<int>>&\
    \ _G, int _root) : root(_root), G(_G){\n\t\tN = int(G.size()) - 1;\n        siz.resize(N+1);\n\
    \        in.resize(N+1, -1);\n        rev.resize(N+1);\n        par.resize(N+1);\n\
    \        head.resize(N+1);\n\t\tdep.resize(N+1);\n\t\tinit__();\n    }\n\n\n \
    \   private:\n        int N=1;\n        int root=1;\n        vector<vector<int>>\
    \ G;\n        vector<int> siz;\n\t\tvector<int> in;\n\t\tvector<int> rev;\n\t\t\
    vector<int> dep;\n        vector<int> par;\n        vector<int> head;\n\t\n\n\
    \        int dfs_siz(int now, int prev) {\n            siz[now] = 1;\n       \
    \     for(int to : G[now]) {\n                if(to == prev) continue;\n\t\t\t\
    \tdep[to] = dep[now] + 1;\n                siz[now] += dfs_siz(to, now);\n   \
    \         }\n            return siz[now];\n        }\n\n        void dfs_bunkai(int\
    \ now, int prev, int hed, int& idx) {\n            in[now] = idx;\n\t\t\trev[idx]\
    \ = now;\n            idx++;\n            par[now] = prev;\n            if(hed\
    \ == -1) hed = now;\n            head[now] = hed;\n\n            bool f = true;\n\
    \            for(int i = 0; i < int(G[now].size()); i++) {\n                if(in[G[now][i]]\
    \ != -1) continue;\n                if(f) dfs_bunkai(G[now][i], now, hed, idx),\
    \ f = false;\n                else dfs_bunkai(G[now][i], now, -1, idx);\n    \
    \        }\n        }\n\n        void init__() {\n\t\t\tdep[root] = 0;\n     \
    \       dfs_siz(root, -1);\n            for(int i = 1; i <= N; i++) {\n      \
    \          sort(G[i].begin(), G[i].end(), [&](int a, int b) {\n              \
    \    return siz[a] > siz[b];\n                });\n            }\n           \
    \ int id = 1;\n            dfs_bunkai(root, root, -1, id);\n        }\n      \
    \      \n\n        \n    \n    public:\n\n        int getLCA(int a, int b) {\n\
    \            while(true) {\n               if(in[a] > in[b]) swap(a, b);\n   \
    \            if(head[a] == head[b]) return a;\n               b = par[head[b]];\n\
    \            }\n        }\n\n\t\tint dist(int u, int v) {\n\t\t\tint lca = getLCA(u,\
    \ v);\n\t\t\treturn dep[u] + dep[v] - 2 * dep[lca];\n\t\t}\n\n\t\tint depth(int\
    \ v) {\n\t\t\treturn dep[v];\n\t\t}\n\n\t\tint kth_ances(int v, int k) {\n\t\t\
    \tif(k > dep[v]) return -1;\n\t\t\twhile(v >= 0) {\n\t\t\t\tint r = head[v];\n\
    \t\t\t\tif(k <= dep[v] - dep[r]) {\n\t\t\t\t\treturn rev[in[v] - k];\n\t\t\t\t\
    }\n\t\t\t\telse {\n\t\t\t\t\tk -= dep[v] - dep[r] + 1;\n\t\t\t\t\tv = par[r];\n\
    \t\t\t\t}\n\t\t\t}\n\t\t\treturn v;\n\t\t}\n\n\t\tint kth_path(int s, int t, int\
    \ k) {\n\t\t\tint lca = getLCA(s, t);\n\t\t\tint left = dep[s] - dep[lca];\n\t\
    \t\tint right = dep[t] - dep[lca];\n\t\t\tif(0 <= k && k <= left + right) {\n\t\
    \t\t\tif(k < left) return kth_ances(s, k);\n\t\t\t\telse return kth_ances(t, left+right-k);\n\
    \t\t\t}\n\t\t\treturn -1;\n\t\t}\n\n\t\t/*\n\t\tLCA(G, root)  \u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF: O(N)  \u7A7A\u9593 : O(N)\n\t\t@brief \u6728\u306B\u95A2\
    \u3059\u308Butility by HLD(lca,jump,ances)\n\t\t\n\t\tgetLCA(u, v) ... lca(u,\
    \ v)\u3092\u8FD4\u3059\u3002 O(logN)\n\t\tdist(u, v) ... (u, v)\u306E\u9593\u306E\
    \u8FBA\u306E\u672C\u6570\u3092\u8FD4\u3059\u3002 O(logN)\n\t\tdepth(v) ... v\u306E\
    0-indexed\u306E\u6DF1\u3055\u3092\u8FD4\u3059\u3002O(1)\n\t\tkth_ances(v, k) ...\
    \ v\u304B\u3089k\u672C\u306E\u8FBA\u3092\u6839\u306E\u65B9\u5411\u306B\u8FBF\u3063\
    \u305F\u672B\u306E\u9802\u70B9\u3092\u8FD4\u3059\u3002\u5B58\u5728\u3057\u306A\
    \u3044\u306A\u3089-1\u3002 O(logN)\n\t\tkth_path(s, t, k) ... s\u304B\u3089t\u306E\
    \u65B9\u5411\u306Bk\u672C\u306E\u8FBA\u3092\u8FBF\u3063\u305F\u672B\u306E\u9802\
    \u70B9\u3092\u8FD4\u3059\u3002\u5B58\u5728\u3057\u306A\u3044\u306A\u3089-1\u3002\
    \ O(logN)\n\t\t\n\t\t*/\n};\n"
  code: "struct LCA {\n\n    LCA(vector<vector<int>>& _G, int _root) : root(_root),\
    \ G(_G){\n\t\tN = int(G.size()) - 1;\n        siz.resize(N+1);\n        in.resize(N+1,\
    \ -1);\n        rev.resize(N+1);\n        par.resize(N+1);\n        head.resize(N+1);\n\
    \t\tdep.resize(N+1);\n\t\tinit__();\n    }\n\n\n    private:\n        int N=1;\n\
    \        int root=1;\n        vector<vector<int>> G;\n        vector<int> siz;\n\
    \t\tvector<int> in;\n\t\tvector<int> rev;\n\t\tvector<int> dep;\n        vector<int>\
    \ par;\n        vector<int> head;\n\t\n\n        int dfs_siz(int now, int prev)\
    \ {\n            siz[now] = 1;\n            for(int to : G[now]) {\n         \
    \       if(to == prev) continue;\n\t\t\t\tdep[to] = dep[now] + 1;\n          \
    \      siz[now] += dfs_siz(to, now);\n            }\n            return siz[now];\n\
    \        }\n\n        void dfs_bunkai(int now, int prev, int hed, int& idx) {\n\
    \            in[now] = idx;\n\t\t\trev[idx] = now;\n            idx++;\n     \
    \       par[now] = prev;\n            if(hed == -1) hed = now;\n            head[now]\
    \ = hed;\n\n            bool f = true;\n            for(int i = 0; i < int(G[now].size());\
    \ i++) {\n                if(in[G[now][i]] != -1) continue;\n                if(f)\
    \ dfs_bunkai(G[now][i], now, hed, idx), f = false;\n                else dfs_bunkai(G[now][i],\
    \ now, -1, idx);\n            }\n        }\n\n        void init__() {\n\t\t\t\
    dep[root] = 0;\n            dfs_siz(root, -1);\n            for(int i = 1; i <=\
    \ N; i++) {\n                sort(G[i].begin(), G[i].end(), [&](int a, int b)\
    \ {\n                  return siz[a] > siz[b];\n                });\n        \
    \    }\n            int id = 1;\n            dfs_bunkai(root, root, -1, id);\n\
    \        }\n            \n\n        \n    \n    public:\n\n        int getLCA(int\
    \ a, int b) {\n            while(true) {\n               if(in[a] > in[b]) swap(a,\
    \ b);\n               if(head[a] == head[b]) return a;\n               b = par[head[b]];\n\
    \            }\n        }\n\n\t\tint dist(int u, int v) {\n\t\t\tint lca = getLCA(u,\
    \ v);\n\t\t\treturn dep[u] + dep[v] - 2 * dep[lca];\n\t\t}\n\n\t\tint depth(int\
    \ v) {\n\t\t\treturn dep[v];\n\t\t}\n\n\t\tint kth_ances(int v, int k) {\n\t\t\
    \tif(k > dep[v]) return -1;\n\t\t\twhile(v >= 0) {\n\t\t\t\tint r = head[v];\n\
    \t\t\t\tif(k <= dep[v] - dep[r]) {\n\t\t\t\t\treturn rev[in[v] - k];\n\t\t\t\t\
    }\n\t\t\t\telse {\n\t\t\t\t\tk -= dep[v] - dep[r] + 1;\n\t\t\t\t\tv = par[r];\n\
    \t\t\t\t}\n\t\t\t}\n\t\t\treturn v;\n\t\t}\n\n\t\tint kth_path(int s, int t, int\
    \ k) {\n\t\t\tint lca = getLCA(s, t);\n\t\t\tint left = dep[s] - dep[lca];\n\t\
    \t\tint right = dep[t] - dep[lca];\n\t\t\tif(0 <= k && k <= left + right) {\n\t\
    \t\t\tif(k < left) return kth_ances(s, k);\n\t\t\t\telse return kth_ances(t, left+right-k);\n\
    \t\t\t}\n\t\t\treturn -1;\n\t\t}\n\n\t\t/*\n\t\tLCA(G, root)  \u30B3\u30F3\u30B9\
    \u30C8\u30E9\u30AF\u30BF: O(N)  \u7A7A\u9593 : O(N)\n\t\t@brief \u6728\u306B\u95A2\
    \u3059\u308Butility by HLD(lca,jump,ances)\n\t\t\n\t\tgetLCA(u, v) ... lca(u,\
    \ v)\u3092\u8FD4\u3059\u3002 O(logN)\n\t\tdist(u, v) ... (u, v)\u306E\u9593\u306E\
    \u8FBA\u306E\u672C\u6570\u3092\u8FD4\u3059\u3002 O(logN)\n\t\tdepth(v) ... v\u306E\
    0-indexed\u306E\u6DF1\u3055\u3092\u8FD4\u3059\u3002O(1)\n\t\tkth_ances(v, k) ...\
    \ v\u304B\u3089k\u672C\u306E\u8FBA\u3092\u6839\u306E\u65B9\u5411\u306B\u8FBF\u3063\
    \u305F\u672B\u306E\u9802\u70B9\u3092\u8FD4\u3059\u3002\u5B58\u5728\u3057\u306A\
    \u3044\u306A\u3089-1\u3002 O(logN)\n\t\tkth_path(s, t, k) ... s\u304B\u3089t\u306E\
    \u65B9\u5411\u306Bk\u672C\u306E\u8FBA\u3092\u8FBF\u3063\u305F\u672B\u306E\u9802\
    \u70B9\u3092\u8FD4\u3059\u3002\u5B58\u5728\u3057\u306A\u3044\u306A\u3089-1\u3002\
    \ O(logN)\n\t\t\n\t\t*/\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Graph/hld_utiliry.cpp
  requiredBy: []
  timestamp: '2024-05-10 23:14:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/hld_utiliry.cpp
layout: document
redirect_from:
- /library/Graph/hld_utiliry.cpp
- /library/Graph/hld_utiliry.cpp.html
title: "\u6728\u306B\u95A2\u3059\u308Butility by HLD(lca,jump,ances)"
---
