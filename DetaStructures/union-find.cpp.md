---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Union-find
    links: []
  bundledCode: "#line 1 \"DetaStructures/union-find.cpp\"\nstruct Union {   \n   \
    \ vector<int> Par;\n    vector<int> size;\n \n\n    Union(int N) {\n        Par.resize(N+1);\n\
    \        size.resize(N+1, 1);\n        for (int i = 1; i <= N; i++) {\n      \
    \      Par[i] = i;\n            \n        }\n    }\n  \n    int root(int u) {\n\
    \        if (Par[u] != u) {\n            return Par[u] = root(Par[u]);\n     \
    \   }    \n         return u;\n    }\n    \n    bool same(int a, int b) {\n  \
    \      return root(a) == root(b);\n    }\n    \n    bool unit(int a, int b) {\n\
    \        a = root(a), b = root(b);\n        if(size[a] < size[b]) swap(a, b);\n\
    \n        if(a == b) return false;\n        else {\n            Par[b] = root(a);\n\
    \            size[a] += size[b];\n\t\t\treturn true;\n        }\n\n    }\nint\
    \ getsize(int u) {//u\u304C\u542B\u307E\u308C\u308B\u9023\u7D50\u6210\u5206\u306E\
    \u30B5\u30A4\u30BA\u3092\u8FD4\u3059\n        return size[root(u)];\n    }//O(1)(\u5927\
    \u4F53)\n};\n\n/*\n@brief Union-find\n*/\n\n/*\n struct Union {   \n\tusing vi\
    \ = vector<int>;\n\tusing vvi = vector<vector<int>>;\n    vi par;\n    vi size;\n\
    \    vi edge;\n\tvector<bool> visited;\n    vvi G;\n    \n    Union(int N) {\n\
    \        par.resize(N+1);\n        iota(par.begin(), par.end(), 0);\n        size.assign(N+1,\
    \ 1);\n        edge.assign(N+1, 0);\n        G.resize(N+1);\n\t\tvisited.resize(N+1);\n\
    \    }\n  \n    int root(int u) {\n        if(par[u] != u) return par[u] = root(par[u]);\n\
    \         return u;\n    }\n    \n    bool same(int a, int b) {\n        return\
    \ root(a) == root(b);\n    }\n    \n    void unit(int a, int b) {\n        a =\
    \ root(a), b = root(b);\n        if(size[a] < size[b]) swap(a, b);\n \n      \
    \  if(a == b) {\n            ++edge[a];\n            return;\n        }\n    \
    \    else {\n            G[a].push_back(b);\n            G[b].push_back(a);\n\
    \            par[b] = a;\n            size[a] += size[b];\n            edge[a]\
    \ += edge[b];\n            edge[a]++;\n        }\n    }\n  \n    int getsize(int\
    \ u) {//u\u304C\u542B\u307E\u308C\u308B\u9023\u7D50\u6210\u5206\u306E\u30B5\u30A4\
    \u30BA\u3092\u8FD4\u3059\n        return size[root(u)];\n    }//O(1)(\u5927\u4F53\
    )\n  \n    vector<int> members(int u) {\n        vi res;\n        queue<int> que;\n\
    \        visited[u] = true;\n        que.push(u);\n        res.push_back(u);\n\
    \        while(!que.empty()) {\n            int now = que.front();\n         \
    \   que.pop();\n            for(int to : G[now]) {\n                if(!visited[to])\
    \ {\n                    visited[to] = true;\n                    que.push(to);\n\
    \                    res.push_back(to);\n                }\n            }\n  \
    \      }\n \n\t\tfor(auto v : res) visited[v] = false;\n        return res;\n\
    \    }  \n};\n*/\n"
  code: "struct Union {   \n    vector<int> Par;\n    vector<int> size;\n \n\n   \
    \ Union(int N) {\n        Par.resize(N+1);\n        size.resize(N+1, 1);\n   \
    \     for (int i = 1; i <= N; i++) {\n            Par[i] = i;\n            \n\
    \        }\n    }\n  \n    int root(int u) {\n        if (Par[u] != u) {\n   \
    \         return Par[u] = root(Par[u]);\n        }    \n         return u;\n \
    \   }\n    \n    bool same(int a, int b) {\n        return root(a) == root(b);\n\
    \    }\n    \n    bool unit(int a, int b) {\n        a = root(a), b = root(b);\n\
    \        if(size[a] < size[b]) swap(a, b);\n\n        if(a == b) return false;\n\
    \        else {\n            Par[b] = root(a);\n            size[a] += size[b];\n\
    \t\t\treturn true;\n        }\n\n    }\nint getsize(int u) {//u\u304C\u542B\u307E\
    \u308C\u308B\u9023\u7D50\u6210\u5206\u306E\u30B5\u30A4\u30BA\u3092\u8FD4\u3059\
    \n        return size[root(u)];\n    }//O(1)(\u5927\u4F53)\n};\n\n/*\n@brief Union-find\n\
    */\n\n/*\n struct Union {   \n\tusing vi = vector<int>;\n\tusing vvi = vector<vector<int>>;\n\
    \    vi par;\n    vi size;\n    vi edge;\n\tvector<bool> visited;\n    vvi G;\n\
    \    \n    Union(int N) {\n        par.resize(N+1);\n        iota(par.begin(),\
    \ par.end(), 0);\n        size.assign(N+1, 1);\n        edge.assign(N+1, 0);\n\
    \        G.resize(N+1);\n\t\tvisited.resize(N+1);\n    }\n  \n    int root(int\
    \ u) {\n        if(par[u] != u) return par[u] = root(par[u]);\n         return\
    \ u;\n    }\n    \n    bool same(int a, int b) {\n        return root(a) == root(b);\n\
    \    }\n    \n    void unit(int a, int b) {\n        a = root(a), b = root(b);\n\
    \        if(size[a] < size[b]) swap(a, b);\n \n        if(a == b) {\n        \
    \    ++edge[a];\n            return;\n        }\n        else {\n            G[a].push_back(b);\n\
    \            G[b].push_back(a);\n            par[b] = a;\n            size[a]\
    \ += size[b];\n            edge[a] += edge[b];\n            edge[a]++;\n     \
    \   }\n    }\n  \n    int getsize(int u) {//u\u304C\u542B\u307E\u308C\u308B\u9023\
    \u7D50\u6210\u5206\u306E\u30B5\u30A4\u30BA\u3092\u8FD4\u3059\n        return size[root(u)];\n\
    \    }//O(1)(\u5927\u4F53)\n  \n    vector<int> members(int u) {\n        vi res;\n\
    \        queue<int> que;\n        visited[u] = true;\n        que.push(u);\n \
    \       res.push_back(u);\n        while(!que.empty()) {\n            int now\
    \ = que.front();\n            que.pop();\n            for(int to : G[now]) {\n\
    \                if(!visited[to]) {\n                    visited[to] = true;\n\
    \                    que.push(to);\n                    res.push_back(to);\n \
    \               }\n            }\n        }\n \n\t\tfor(auto v : res) visited[v]\
    \ = false;\n        return res;\n    }  \n};\n*/"
  dependsOn: []
  isVerificationFile: false
  path: DetaStructures/union-find.cpp
  requiredBy: []
  timestamp: '2024-05-10 22:44:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DetaStructures/union-find.cpp
layout: document
redirect_from:
- /library/DetaStructures/union-find.cpp
- /library/DetaStructures/union-find.cpp.html
title: Union-find
---
