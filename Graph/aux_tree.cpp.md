---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u5727\u7E2E\u6728"
    links: []
  bundledCode: "#line 1 \"Graph/aux_tree.cpp\"\nstruct lca_getter {\n    lca_getter(){}\n\
    \n    lca_getter(int _N, int _root) : N(_N), root(_root){\n        G.resize(N+1);\n\
    \        siz.resize(N+1);\n        num.resize(N+1, -1);\n        nrev.resize(N+1);\n\
    \        par.resize(N+1);\n        head.resize(N+1);\n\n    }\n    \n    bool\
    \ initialized = false;\n    int N=1;\n    int root=1;\n    vector<vector<int>>\
    \ G;\n    vector<int> siz;\n    vector<int> num;\n    vector<int> nrev;\n    vector<int>\
    \ par;\n    vector<int> head;\n\n    private:\n\n        int dfs_siz(int now,\
    \ int prev) {\n            siz[now] = 1;\n            for(int to : G[now]) {\n\
    \                if(to == prev) continue;\n                siz[now] += dfs_siz(to,\
    \ now);\n            }\n            return siz[now];\n        }\n\n        void\
    \ dfs_bunkai(int now, int prev, int hed, int& idx) {\n            num[now] = idx;\n\
    \            nrev[idx] = now;\n            idx++;\n            par[num[now]] =\
    \ prev;\n            if(hed == -1) hed = num[now];\n            head[num[now]]\
    \ = hed;\n\n            bool f = true;\n            for(int i = 0; i < int(G[now].size());\
    \ i++) {\n                if(num[G[now][i]] != -1) continue;\n               \
    \ if(f) dfs_bunkai(G[now][i], num[now], hed, idx), f = false;\n              \
    \  else dfs_bunkai(G[now][i], num[now], -1, idx);\n            }\n        }\n\n\
    \        void init__() {\n            dfs_siz(root, -1);\n            for(int\
    \ i = 1; i <= N; i++) {\n                sort(G[i].begin(), G[i].end(), [&](int\
    \ a, int b) {\n                  return siz[a] > siz[b];\n                });\n\
    \            }\n            int id = 1;\n            dfs_bunkai(root, root, -1,\
    \ id);\n        }\n            \n\n        \n    \n    public:\n        void add_edge(int\
    \ u, int v) {\n            G[u].push_back(v);\n            G[v].push_back(u);\n\
    \        }\n\n        void init() {\n            initialized = true;\n       \
    \     init__();\n        }\n\n\n        int getLCA(int a, int b) {\n         \
    \   if(!initialized) init();\n            a = num[a];\n            b = num[b];\n\
    \            while(true) {\n               if(a > b) swap(a, b);\n           \
    \    if(head[a] == head[b]) return nrev[a];\n               b = par[head[b]];\n\
    \            }\n        }\n};\n\nstruct axis_tree {\n    axis_tree(int _N, int\
    \ _root) : N(_N), root(_root){\n        G.resize(N+1);\n        in.resize(N+1);\n\
    \        out.resize(N+1);\n        lca = lca_getter(N, root);\n    }\n   \n\n\
    \    private:\n        int N;\n        int root;\n        vector<vector<int>>\
    \ G;\n        vector<int> in;\n        vector<int> out;\n        vector<int> pre_vs;\n\
    \        lca_getter lca;\n\n    public:\n        void add_edge(int u, int v) {\n\
    \            lca.add_edge(u, v);\n            G[u].push_back(v);\n           \
    \ G[v].push_back(u);\n        }\n\n        void init() {\n            lca.init();\n\
    \            int t = 1;\n            auto dfs = [&](auto f, int now, int prev)\
    \ -> void {\n                in[now] = t;\n                t++;\n            \
    \    for(auto to : G[now]) if(to != prev) f(f, to, now);\n                out[now]\
    \ = t;\n                return;\n            };\n            dfs(dfs, root, -1);\n\
    \        }\n\n        int make_tree(vector<int>& V, vector<vector<int>>& G2) {\n\
    \            if(V.empty()) return -1;\n            auto cmp = [&](int i, int j)\
    \ {\n                return in[i] < in[j];\n            };\n            sort(all0(V),\
    \ cmp);\n            int m = V.size();\n            rep(j, 0, m-2) {\n       \
    \         V.push_back(lca.getLCA(V[j], V[j+1]));\n            }\n    \n      \
    \      sort(all0(V), cmp);\n            V.erase(unique(V.begin(), V.end()), V.end());\n\
    \    \n            vector<int> st;\n            for(auto v : V) {\n          \
    \      while(st.size()) {\n                    int p = st.back();\n          \
    \          if(in[p] < in[v] && in[v] < out[p]) break;\n                    st.pop_back();\n\
    \                }\n                if(st.size()) {\n                    G2[st.back()].push_back(v);\n\
    \                    G2[v].push_back(st.back());\n                }\n        \
    \        st.push_back(v);\n            }\n            pre_vs = V;\n          \
    \  return V[0];\n        }\n\n        void clean(vector<vector<int>> &G2) {\n\
    \            for(auto v : pre_vs) G2[v] = vector<int>();\n            pre_vs =\
    \ vector<int>();\n            return;\n        }\n\n        /*\n        @brief\
    \ \u5727\u7E2E\u6728\n        \u9802\u70B9\u96C6\u5408V\u3092\u6E21\u3059\u3068\
    \u3001O(|V|log|V|)\u3067\u3001\u30B5\u30A4\u30BA\u304CO(|V|)\u306E\u5727\u7E2E\
    \u6728\u3092\u8FD4\u3059\u3002\n\n        G2 ... \u30B5\u30A4\u30BAN\u306E\u3001\
    \u7A7A\u306Evvi\u3092\u6E21\u3059\u3002\n        \u4F7F\u7528\u5F8C\u3001\u6B21\
    \u306E\u5727\u7E2E\u6728\u3092\u4F5C\u6210\u3059\u308B\u524D\u306Bclean(G2)\u3092\
    \u547C\u3076\u3002\n        make_tree\u306E\u8FD4\u308A\u5024\u306F\u4EEE\u60F3\
    \u306E\u6839\u3067\u3042\u308B\u3002\u3053\u306E\u5024\u304C-1\u306E\u6642\u3001\
    \u5727\u7E2E\u6728\u306F\u7A7A\u306E\u6728\u3067\u3042\u308B\u3002\n        */\n\
    \n};\n"
  code: "struct lca_getter {\n    lca_getter(){}\n\n    lca_getter(int _N, int _root)\
    \ : N(_N), root(_root){\n        G.resize(N+1);\n        siz.resize(N+1);\n  \
    \      num.resize(N+1, -1);\n        nrev.resize(N+1);\n        par.resize(N+1);\n\
    \        head.resize(N+1);\n\n    }\n    \n    bool initialized = false;\n   \
    \ int N=1;\n    int root=1;\n    vector<vector<int>> G;\n    vector<int> siz;\n\
    \    vector<int> num;\n    vector<int> nrev;\n    vector<int> par;\n    vector<int>\
    \ head;\n\n    private:\n\n        int dfs_siz(int now, int prev) {\n        \
    \    siz[now] = 1;\n            for(int to : G[now]) {\n                if(to\
    \ == prev) continue;\n                siz[now] += dfs_siz(to, now);\n        \
    \    }\n            return siz[now];\n        }\n\n        void dfs_bunkai(int\
    \ now, int prev, int hed, int& idx) {\n            num[now] = idx;\n         \
    \   nrev[idx] = now;\n            idx++;\n            par[num[now]] = prev;\n\
    \            if(hed == -1) hed = num[now];\n            head[num[now]] = hed;\n\
    \n            bool f = true;\n            for(int i = 0; i < int(G[now].size());\
    \ i++) {\n                if(num[G[now][i]] != -1) continue;\n               \
    \ if(f) dfs_bunkai(G[now][i], num[now], hed, idx), f = false;\n              \
    \  else dfs_bunkai(G[now][i], num[now], -1, idx);\n            }\n        }\n\n\
    \        void init__() {\n            dfs_siz(root, -1);\n            for(int\
    \ i = 1; i <= N; i++) {\n                sort(G[i].begin(), G[i].end(), [&](int\
    \ a, int b) {\n                  return siz[a] > siz[b];\n                });\n\
    \            }\n            int id = 1;\n            dfs_bunkai(root, root, -1,\
    \ id);\n        }\n            \n\n        \n    \n    public:\n        void add_edge(int\
    \ u, int v) {\n            G[u].push_back(v);\n            G[v].push_back(u);\n\
    \        }\n\n        void init() {\n            initialized = true;\n       \
    \     init__();\n        }\n\n\n        int getLCA(int a, int b) {\n         \
    \   if(!initialized) init();\n            a = num[a];\n            b = num[b];\n\
    \            while(true) {\n               if(a > b) swap(a, b);\n           \
    \    if(head[a] == head[b]) return nrev[a];\n               b = par[head[b]];\n\
    \            }\n        }\n};\n\nstruct axis_tree {\n    axis_tree(int _N, int\
    \ _root) : N(_N), root(_root){\n        G.resize(N+1);\n        in.resize(N+1);\n\
    \        out.resize(N+1);\n        lca = lca_getter(N, root);\n    }\n   \n\n\
    \    private:\n        int N;\n        int root;\n        vector<vector<int>>\
    \ G;\n        vector<int> in;\n        vector<int> out;\n        vector<int> pre_vs;\n\
    \        lca_getter lca;\n\n    public:\n        void add_edge(int u, int v) {\n\
    \            lca.add_edge(u, v);\n            G[u].push_back(v);\n           \
    \ G[v].push_back(u);\n        }\n\n        void init() {\n            lca.init();\n\
    \            int t = 1;\n            auto dfs = [&](auto f, int now, int prev)\
    \ -> void {\n                in[now] = t;\n                t++;\n            \
    \    for(auto to : G[now]) if(to != prev) f(f, to, now);\n                out[now]\
    \ = t;\n                return;\n            };\n            dfs(dfs, root, -1);\n\
    \        }\n\n        int make_tree(vector<int>& V, vector<vector<int>>& G2) {\n\
    \            if(V.empty()) return -1;\n            auto cmp = [&](int i, int j)\
    \ {\n                return in[i] < in[j];\n            };\n            sort(all0(V),\
    \ cmp);\n            int m = V.size();\n            rep(j, 0, m-2) {\n       \
    \         V.push_back(lca.getLCA(V[j], V[j+1]));\n            }\n    \n      \
    \      sort(all0(V), cmp);\n            V.erase(unique(V.begin(), V.end()), V.end());\n\
    \    \n            vector<int> st;\n            for(auto v : V) {\n          \
    \      while(st.size()) {\n                    int p = st.back();\n          \
    \          if(in[p] < in[v] && in[v] < out[p]) break;\n                    st.pop_back();\n\
    \                }\n                if(st.size()) {\n                    G2[st.back()].push_back(v);\n\
    \                    G2[v].push_back(st.back());\n                }\n        \
    \        st.push_back(v);\n            }\n            pre_vs = V;\n          \
    \  return V[0];\n        }\n\n        void clean(vector<vector<int>> &G2) {\n\
    \            for(auto v : pre_vs) G2[v] = vector<int>();\n            pre_vs =\
    \ vector<int>();\n            return;\n        }\n\n        /*\n        @brief\
    \ \u5727\u7E2E\u6728\n        \u9802\u70B9\u96C6\u5408V\u3092\u6E21\u3059\u3068\
    \u3001O(|V|log|V|)\u3067\u3001\u30B5\u30A4\u30BA\u304CO(|V|)\u306E\u5727\u7E2E\
    \u6728\u3092\u8FD4\u3059\u3002\n\n        G2 ... \u30B5\u30A4\u30BAN\u306E\u3001\
    \u7A7A\u306Evvi\u3092\u6E21\u3059\u3002\n        \u4F7F\u7528\u5F8C\u3001\u6B21\
    \u306E\u5727\u7E2E\u6728\u3092\u4F5C\u6210\u3059\u308B\u524D\u306Bclean(G2)\u3092\
    \u547C\u3076\u3002\n        make_tree\u306E\u8FD4\u308A\u5024\u306F\u4EEE\u60F3\
    \u306E\u6839\u3067\u3042\u308B\u3002\u3053\u306E\u5024\u304C-1\u306E\u6642\u3001\
    \u5727\u7E2E\u6728\u306F\u7A7A\u306E\u6728\u3067\u3042\u308B\u3002\n        */\n\
    \n};"
  dependsOn: []
  isVerificationFile: false
  path: Graph/aux_tree.cpp
  requiredBy: []
  timestamp: '2024-05-10 23:04:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/aux_tree.cpp
layout: document
redirect_from:
- /library/Graph/aux_tree.cpp
- /library/Graph/aux_tree.cpp.html
title: "\u5727\u7E2E\u6728"
---
