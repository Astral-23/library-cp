---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Maxflow
    links: []
  bundledCode: "#line 1 \"Algorithms/maxflow.cpp\"\nstruct Edge {\n    int to;\n \
    \   ll cap;\n    int rev;//\u5BFE\u5FDC\u3059\u308B\u8FBA\u306E\u3001G[\u76F8\u624B\
    ]\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\n};\n\nstruct Maxflow {\n\n  \n\t\
    vector<vector<Edge>> G;\n   \n  int siz;\n  vector<pair<int, Edge>> es;//\u8FBA\
    \u306E\u60C5\u5831 [from, EDGE]\n  vector<unordered_map<int, int>> getid;\n  vector<int>\
    \ level;\n  vector<int> iter; //dfs\u306B\u304A\u3044\u3066\u3001\u65E2\u306B\u8A2A\
    \u308C\u305F\u8FBA\u306E\u672C\u6570\n  \n\tMaxflow(int N) {\n     siz = N;\n\t\
    \t G.resize(N+1);\n     level.assign(N+1, -1);\n     iter.assign(N+1, 0);\n  \
    \   getid.resize(N+1);\n     es.resize(1);\n\t}\n  \n\n  void bfs(int s) {//\u30B0\
    \u30E9\u30D5\u306E\u30EC\u30D9\u30EB\u3092\u5272\u308A\u632F\u308B\n    rep(i,\
    \ 0, siz) level.at(i) = -1;\n    queue<int>  que;\n    level.at(s) = 0;\n    que.push(s);\n\
    \    while(!que.empty()) {\n      int now = que.front(); que.pop();\n      for(auto\
    \ [TO, CAP, REV] : G[now]) {\n        if(CAP > 0 && level[TO] < 0) {\n       \
    \   level[TO] = level[now] + 1;\n          que.push(TO);\n        }\n      }\n\
    \    }\n  }\n \n\tll dfs(int now, int goal, ll F) {// pos\u304B\u3089goal\u307E\
    \u3067\u306E\uFF11\u30D1\u30B9\u5206\u306E\u6700\u5927\u6D41\u91CF\u3092\u8FD4\
    \u3059 F = \u66AB\u5B9A\u6D41\u305B\u308B\u6C34\u91CF \n\t\tif (now == goal) {\n\
    \          return F;\n        }\n\t\tfor (int &i = iter[now]; i < int(G[now].size());\
    \ i++) {//\u884C\u304D\u5148\u306A\u304F\u306A\u3063\u305F\u3089\u3053\u3053\u7121\
    \u8996\u3055\u308C\u308B\u3088\u3046\u306B\u306A\u3063\u3066\u3001\u305D\u3053\
    \u304C\u30B4\u30FC\u30EB\u3067\u306A\u3044\u306A\u3089\u30700\u304C\u8FD4\u3055\
    \u308C\u308B\u3002\u3088\u3063\u3066flow >= 1\u3092\u6E80\u305F\u3055\u306A\u3044\
    \u306E\u3067\u305D\u306E\u9053\u7B4B\u306F\u7121\u8996\u3055\u308C\u308B\u3002\
    \u30B4\u30FC\u30EB\u306A\u3089\u3070F\u304C\u5E30\u308B\u3002\n\t\t  auto &e =\
    \ G[now][i]; \n\t\t\tif(e.cap > 0 && level[now] < level[e.to]) {\n        ll d\
    \ = dfs(e.to, goal, min(F, e.cap));\n        if(d > 0) {\n          e.cap -= d;\n\
    \          G[e.to][e.rev].cap += d;\n          return d;\n        }\n\t\t  }\n\
    \    }\n\t\treturn 0;\n\t}\n\n\n\n  void add_edge(int s, int t, ll c) {//\u6709\
    \u52B9\u8FBAO(1) //\u7121\u5411\u8FBA\u3092\u8CBC\u308A\u305F\u3044\u6642\u306F\
    2\u56DE\u3001a\u3068b\u3092\u9006\u306B\u547C\u3076\n\t\tint Current_Ga_idx =\
    \ G.at(s).size(); \n\t\tint Current_Gb_idx = G.at(t).size(); \n\t\tG.at(s).push_back(Edge{t,\
    \ c, Current_Gb_idx});\n\t\tG.at(t).push_back(Edge{s, 0, Current_Ga_idx});//rev\u306F\
    \u3001\u9006\u5411\u304D\u306E\u8FBA\u306E\u6DFB\u3048\u5B57\u3000\u6D41\u3057\
    \u305F\u6642\u3001\u6B8B\u4F59\u30B0\u30E9\u30D5\u306E\u5BB9\u91CF\u3092\u5897\
    \u3084\u3059\u70BA\n    es.emplace_back(s, Edge{t, c, Current_Gb_idx});\n    getid[s][t]\
    \ = es.size() - 1;\n\t}\n\n  int get_edgecount() {return es.size() - 1;}\n  \n\
    \  int get_id(int s, int t) {return getid[s][t];}\n\n  ll get_flow(int id) {//\u73FE\
    \u72B6\u306E\u6D41\u91CF\u3092\u8FD4\u3059\u3002O(1)\n    auto [_, e] = es[id];\n\
    \    return G[e.to][e.rev].cap;\n  }\n\n  pair<int, int> get_st(int id) {\n  \
    \  auto [s, e] = es[id];\n    return make_pair(s, e.to);\n  }\n\n  void change_edge(int\
    \ id, ll new_cap, ll new_flow) {//O(1)//\u6D41\u91CF\u5909\u3048\u305F\u304F\u306A\
    \u3044\u306A\u3089\u3001new_flow = get_flow(id)\n    assert(new_cap >= new_flow);\n\
    \    auto[a, e] = es[id];\n    G[a][G[e.to][e.rev].rev] = Edge{e.to, new_cap-new_flow,\
    \ e.rev};\n    G[e.to][e.rev] = Edge{a, new_flow, G[e.to][e.rev].rev};\n  }\n\n\
    \n\tll max_flow(int s, int t) {//1\u30D1\u30B9\u5206\u306E\u6700\u5927\u6D41\u91CF\
    \u3092\u5408\u8A08\u3059\u308B O(\u8FBA * (\u6D41\u91CF))\n\t\tll Total_Flow =\
    \ 0;\n\t\twhile (true) {\n            bfs(s);\n\t\t    if(level[t] < 0) return\
    \ Total_Flow;\n            rep(i, 0, siz) iter.at(i) = 0;\n\t\t    ll F = 0;\n\
    \            while((F = dfs(s, t, BIG)) > 0) {\n              Total_Flow += F;\n\
    \            }\n\t\t}\n\t}\n};\n\n\n/*\n@brief Maxflow\n*/\n"
  code: "struct Edge {\n    int to;\n    ll cap;\n    int rev;//\u5BFE\u5FDC\u3059\
    \u308B\u8FBA\u306E\u3001G[\u76F8\u624B]\u306E\u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\
    \n};\n\nstruct Maxflow {\n\n  \n\tvector<vector<Edge>> G;\n   \n  int siz;\n \
    \ vector<pair<int, Edge>> es;//\u8FBA\u306E\u60C5\u5831 [from, EDGE]\n  vector<unordered_map<int,\
    \ int>> getid;\n  vector<int> level;\n  vector<int> iter; //dfs\u306B\u304A\u3044\
    \u3066\u3001\u65E2\u306B\u8A2A\u308C\u305F\u8FBA\u306E\u672C\u6570\n  \n\tMaxflow(int\
    \ N) {\n     siz = N;\n\t\t G.resize(N+1);\n     level.assign(N+1, -1);\n    \
    \ iter.assign(N+1, 0);\n     getid.resize(N+1);\n     es.resize(1);\n\t}\n  \n\
    \n  void bfs(int s) {//\u30B0\u30E9\u30D5\u306E\u30EC\u30D9\u30EB\u3092\u5272\u308A\
    \u632F\u308B\n    rep(i, 0, siz) level.at(i) = -1;\n    queue<int>  que;\n   \
    \ level.at(s) = 0;\n    que.push(s);\n    while(!que.empty()) {\n      int now\
    \ = que.front(); que.pop();\n      for(auto [TO, CAP, REV] : G[now]) {\n     \
    \   if(CAP > 0 && level[TO] < 0) {\n          level[TO] = level[now] + 1;\n  \
    \        que.push(TO);\n        }\n      }\n    }\n  }\n \n\tll dfs(int now, int\
    \ goal, ll F) {// pos\u304B\u3089goal\u307E\u3067\u306E\uFF11\u30D1\u30B9\u5206\
    \u306E\u6700\u5927\u6D41\u91CF\u3092\u8FD4\u3059 F = \u66AB\u5B9A\u6D41\u305B\u308B\
    \u6C34\u91CF \n\t\tif (now == goal) {\n          return F;\n        }\n\t\tfor\
    \ (int &i = iter[now]; i < int(G[now].size()); i++) {//\u884C\u304D\u5148\u306A\
    \u304F\u306A\u3063\u305F\u3089\u3053\u3053\u7121\u8996\u3055\u308C\u308B\u3088\
    \u3046\u306B\u306A\u3063\u3066\u3001\u305D\u3053\u304C\u30B4\u30FC\u30EB\u3067\
    \u306A\u3044\u306A\u3089\u30700\u304C\u8FD4\u3055\u308C\u308B\u3002\u3088\u3063\
    \u3066flow >= 1\u3092\u6E80\u305F\u3055\u306A\u3044\u306E\u3067\u305D\u306E\u9053\
    \u7B4B\u306F\u7121\u8996\u3055\u308C\u308B\u3002\u30B4\u30FC\u30EB\u306A\u3089\
    \u3070F\u304C\u5E30\u308B\u3002\n\t\t  auto &e = G[now][i]; \n\t\t\tif(e.cap >\
    \ 0 && level[now] < level[e.to]) {\n        ll d = dfs(e.to, goal, min(F, e.cap));\n\
    \        if(d > 0) {\n          e.cap -= d;\n          G[e.to][e.rev].cap += d;\n\
    \          return d;\n        }\n\t\t  }\n    }\n\t\treturn 0;\n\t}\n\n\n\n  void\
    \ add_edge(int s, int t, ll c) {//\u6709\u52B9\u8FBAO(1) //\u7121\u5411\u8FBA\u3092\
    \u8CBC\u308A\u305F\u3044\u6642\u306F2\u56DE\u3001a\u3068b\u3092\u9006\u306B\u547C\
    \u3076\n\t\tint Current_Ga_idx = G.at(s).size(); \n\t\tint Current_Gb_idx = G.at(t).size();\
    \ \n\t\tG.at(s).push_back(Edge{t, c, Current_Gb_idx});\n\t\tG.at(t).push_back(Edge{s,\
    \ 0, Current_Ga_idx});//rev\u306F\u3001\u9006\u5411\u304D\u306E\u8FBA\u306E\u6DFB\
    \u3048\u5B57\u3000\u6D41\u3057\u305F\u6642\u3001\u6B8B\u4F59\u30B0\u30E9\u30D5\
    \u306E\u5BB9\u91CF\u3092\u5897\u3084\u3059\u70BA\n    es.emplace_back(s, Edge{t,\
    \ c, Current_Gb_idx});\n    getid[s][t] = es.size() - 1;\n\t}\n\n  int get_edgecount()\
    \ {return es.size() - 1;}\n  \n  int get_id(int s, int t) {return getid[s][t];}\n\
    \n  ll get_flow(int id) {//\u73FE\u72B6\u306E\u6D41\u91CF\u3092\u8FD4\u3059\u3002\
    O(1)\n    auto [_, e] = es[id];\n    return G[e.to][e.rev].cap;\n  }\n\n  pair<int,\
    \ int> get_st(int id) {\n    auto [s, e] = es[id];\n    return make_pair(s, e.to);\n\
    \  }\n\n  void change_edge(int id, ll new_cap, ll new_flow) {//O(1)//\u6D41\u91CF\
    \u5909\u3048\u305F\u304F\u306A\u3044\u306A\u3089\u3001new_flow = get_flow(id)\n\
    \    assert(new_cap >= new_flow);\n    auto[a, e] = es[id];\n    G[a][G[e.to][e.rev].rev]\
    \ = Edge{e.to, new_cap-new_flow, e.rev};\n    G[e.to][e.rev] = Edge{a, new_flow,\
    \ G[e.to][e.rev].rev};\n  }\n\n\n\tll max_flow(int s, int t) {//1\u30D1\u30B9\u5206\
    \u306E\u6700\u5927\u6D41\u91CF\u3092\u5408\u8A08\u3059\u308B O(\u8FBA * (\u6D41\
    \u91CF))\n\t\tll Total_Flow = 0;\n\t\twhile (true) {\n            bfs(s);\n\t\t\
    \    if(level[t] < 0) return Total_Flow;\n            rep(i, 0, siz) iter.at(i)\
    \ = 0;\n\t\t    ll F = 0;\n            while((F = dfs(s, t, BIG)) > 0) {\n   \
    \           Total_Flow += F;\n            }\n\t\t}\n\t}\n};\n\n\n/*\n@brief Maxflow\n\
    */"
  dependsOn: []
  isVerificationFile: false
  path: Algorithms/maxflow.cpp
  requiredBy: []
  timestamp: '2024-05-10 23:04:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Algorithms/maxflow.cpp
layout: document
redirect_from:
- /library/Algorithms/maxflow.cpp
- /library/Algorithms/maxflow.cpp.html
title: Maxflow
---
