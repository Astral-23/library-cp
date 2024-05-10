---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Mincostflow
    links: []
  bundledCode: "#line 1 \"Algorithms/mincostflow.cpp\"\nstruct MinCostFlow {\n\tusing\
    \ ll = long long;\n\tusing pli = pair<long long, int>;\n\tusing vl = vector<ll>;\n\
    \tusing vi = vector<int>;\n\n\tstruct Edge {\n\t\tint to, rev;\n\t\tll cap, cost;\n\
    \t\tEdge(){}\n\t\tEdge(int _to, int _rev, ll _cap, ll _cost) : to(_to), rev(_rev),\
    \ cap(_cap), cost(_cost){}\n\t};\n\n\tvector<vector<Edge>> G;\n    int N;\n\t\
    const ll MAX_DIST = 2002002002002002002LL;\n    vl h;\n    vl dist;\n    vi prevV;//\u30C0\
    \u30A4\u30AF\u30B9\u30C8\u30E9\u306F\u518D\u5E30\u95A2\u6570\u7684\u306B\u66F8\
    \u3051\u306A\u3044\u306E\u3067\u3001\u4FDD\u5B58\u3059\u308B\u5FC5\u8981\u304C\
    \u3042\u308B : \u6700\u5F8C\u306B\u6D41\u3057\u305F\u5206\u6E1B\u7B97\u3059\u308B\
    \u306E\u306B\u4F7F\u3046\u3002\n    vi prevE;//\u540C\u4E0A\u3002\n    ll now_ryuuryou\
    \ = 0;\n    ll now_cost = 0;\n    vector<pair<int, Edge>> es;//\u8FBA\u306E\u60C5\
    \u5831 [from, EDGE]\n    vector<unordered_map<int, int>> getid;\n    \n\tMinCostFlow(int\
    \ _N) {\n        N = _N;\n\t    G.resize(N+1);\n        h.assign(N+1, 0);\n  \
    \      dist.assign(N+1, MAX_DIST);\n        prevV.resize(N+1);\n        prevE.resize(N+1);\n\
    \        es.resize(1);\n        getid.resize(N+1);\n\t}\n\n    private:\n\n  \
    \      ll Daiku(int s, int t, ll &ryuuryou) {\n            ll res = 0;\n     \
    \       while(ryuuryou > 0) {\n                priority_queue<pair<ll, int>, vector<pair<ll,\
    \ int>>, greater<pair<ll, int>>> que;\n                dist.assign(N+1, MAX_DIST);\n\
    \                dist[s] = 0;\n                que.push(pli(0, s));        \n\
    \                while(!que.empty()) {\n                    ll cd = que.top().first;\n\
    \                    int cp = que.top().second;\n                    que.pop();\n\
    \                    if(dist[cp] < cd) {\n                      continue;\n  \
    \                  }\n                    for (int i = 0; i < int(G[cp].size());\
    \ i++) {\n                        Edge e = G[cp][i];\n                       \
    \ if(e.cap > 0 && dist[e.to] > dist[cp] + e.cost - (h[e.to] - h[cp])) {\n    \
    \                        //1\u96C6\u76EE\u306E\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\
    \u306E\u6642\u3001h\u306E\u4E2D\u8EAB\u306F0\u306A\u306E\u3067\u6700\u521D\u304B\
    \u3089\u3053\u306E\u66F8\u304D\u65B9\u3067\u4E0D\u90FD\u5408\u306F\u751F\u3058\
    \u306A\u3044\n                            dist[e.to] = dist[cp] + e.cost - (h[e.to]\
    \ - h[cp]);\n                            prevV.at(e.to) = cp;\n              \
    \              prevE.at(e.to) = i;\n                            que.push(pli(dist[e.to],\
    \ e.to));\n                        }\n                    }\n                }\
    \        \n                if(dist[t] == MAX_DIST) {\n                  return\
    \ 1;//\u8FBF\u308A\u7740\u3051\u306A\u304B\u3063\u305F\n                }    \
    \    \n                for (int i = 1; i <= N; i++) {\n                  h[i]\
    \ += dist[i];//\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u306E\u66F4\u65B0 \u9006\u8FBA\
    \u3092\u5F35\u308B\u524D\u306B\u3084\u308B\uFF08\u8CA0\u306E\u8FBA\u3092\u6D88\
    \u3059\u306E\u304C\u76EE\u7684\u306A\u306E\u3067\uFF09\n                }\n\n\
    \                ll flow = ryuuryou;\n                for (int v = t; v != s;\
    \ v = prevV[v]) {\n\t\t\t\t\tif(G[prevV[v]][prevE[v]].cap < flow) flow = G[prevV[v]][prevE[v]].cap;\n\
    \                }\n                ryuuryou -= flow;\n                now_ryuuryou\
    \ += flow;\n                res += h[t] * flow;//\u5927\u3044\u306A\u308B\u6CE8\
    \u610F\u70B9: dist\u306B\u5165\u3063\u3066\u3044\u308B\u306E\u306F\u30DD\u30C6\
    \u30F3\u30B7\u30E3\u30EB\u4ED8\u304D\u306E\u8DDD\u96E2 h\u306B\u5165\u3063\u3066\
    \u3044\u308B\u306E\u306F\u5143\u306E\u30B0\u30E9\u30D5\u3067\u306E\u8DDD\u96E2\
    \n                now_cost += h[t] * flow;        \n                for (int v\
    \ = t; v != s; v = prevV[v]) {\n                    Edge &e = G[prevV[v]][prevE[v]];\n\
    \                    e.cap -= flow;\n                    G[v][e.rev].cap += flow;\n\
    \                }\n            }\n            return res;\n        }    \n  \n\
    \ public:\n\n\tvoid add_edge(int from, int to, ll cap, ll cost) {\n\t\tint Current_Ga_idx\
    \ = G[from].size(); \n\t\tint Current_Gb_idx = G[to].size(); \n\t\tG[from].emplace_back(Edge(to,\
    \ Current_Gb_idx, cap, cost));\n\t\tG[to].emplace_back(Edge(from, Current_Ga_idx,\
    \ 0, -1 * cost));\n        es.emplace_back(from, Edge(to, Current_Gb_idx, cap,\
    \ cost));\n        getid[from][to] = es.size() - 1;\n\t}\n\n    void WF(int s)\
    \ {\n        vl d(N+1, MAX_DIST);\n        d[s] = 0;\n        for(int i = 1; i\
    \ <= N; i++) {\n            for(int j = 0; j <= N; j++) {\n                for(auto\
    \ e : G[j]) {\n                    if(e.cap != 0 && d[e.to] > d[j] + e.cost) d[e.to]\
    \ = d[j] + e.cost;\n                }\n            }\n        }\n        for(int\
    \ i = 1; i <= N; i++) h[i] = d[i];\n    }\n\n    int edgesize() {return int(es.size())\
    \ - 1;}\n    \n    int get_id(int s, int t) {return getid[s][t];}\n    \n  \n\
    \    ll get_flow(int id) {\n        auto [_, e] = es[id];\n        return G[e.to][e.rev].cap;\n\
    \    }\n  \n    pair<int, int> get_st(int id) {\n        auto [s, e] = es[id];\n\
    \        return make_pair(s, e.to);\n    }\n  \n    void change_edge(int id, ll\
    \ new_cap, ll new_flow) {//\u6D41\u91CF\u5909\u3048\u305F\u304F\u306A\u3044\u306A\
    \u3089\u3001new_flow = get_flow(id)\n        assert(new_cap >= new_flow);\n  \
    \      auto[s, e] = es[id];\n        G[s][G[e.to][e.rev].rev] = Edge(e.to,  e.rev,\
    \ new_cap-new_flow, e.cost);\n        G[e.to][e.rev] = Edge(s,G[e.to][e.rev].rev,\
    \  new_flow, -e.cost);\n    }\n  \n  \n  \tpli min_cost(int s, int t, ll target)\
    \ {\n        ll ryuuryou = target - now_ryuuryou;\n  \t    Daiku(s, t, ryuuryou);\n\
    \  \t  \treturn pli(now_cost, now_ryuuryou);\n  \t} \n\n\t/*\n\t    MinCostFlow(N)\
    \ \u7A7A\u9593O(N)\n\t\t@brief Mincostflow\n\n\t\tadd_edge(s, t, cap, cost) ...\
    \ s\u2192t \u306E\u8FBA\u3092\u5F35\u308B\u3002 \u8FBA\u304C\u8FFD\u52A0\u3055\
    \u308C\u305F\u9806\u756A\u306B\u5FDC\u3058\u3066\u3001\u8FBA\u306B\u306F1-indexed\u306E\
    \u756A\u53F7\u304C\u3064\u304F\u3002O(1)\n\t\tWF(s) ... s\u304B\u3089\u306E\u30DD\
    \u30C6\u30F3\u30B7\u30E3\u30EB\u3092\u8A08\u7B97\u3059\u308B\u3002\u8CA0\u306E\
    \u30B3\u30B9\u30C8\u304C\u542B\u307E\u308C\u308B\u5834\u5408\u306B\u547C\u3076\
    \u3002s\u306B\u306F\u3001\u30D5\u30ED\u30FC\u3092\u6D41\u3059\u59CB\u70B9\u3092\
    \u4E0E\u3048\u308B\u3002  O(VE)\n\t\tedgesize() ... \u8FBA\u306E\u672C\u6570 O(1)\n\
    \t\tget_id(s, t) ... s\u2192t\u306E\u8FBA\u306E\u3001\u8FBA\u756A\u53F7\u3092\u8FD4\
    \u3059\u3002 O(1)\n\t\tget_flow(id) ... \u8FBA\u756A\u53F7id\u306E\u8FBA\u306E\
    \u73FE\u5728\u306E\u6D41\u91CF\u3092\u8FD4\u3059\u3002 O(1)\n\t\tget_st(id) ...\
    \ \u8FBA\u756A\u53F7id\u306E\u8FBA\u306E\u8996\u70B9\u3068\u7D42\u70B9\u3092\u8FD4\
    \u3059\u3002O(1)\n\t\tchange_edge(id, new_cap, new_flow) ... \u8FBA\u756A\u53F7\
    id\u306E\u8FBA\u306Ecap, flow\u3092\u5909\u66F4\u3059\u308B\u3002 O(1)\n\t\tmin_cost(s,\
    \ t, target) ... \u73FE\u5728\u306E\u30B0\u30E9\u30D5\u3092\u5143\u306B\u3001\
    s\u304B\u3089t\u306B\u3001\u5408\u8A08\u6D41\u91CF\u304Ctarget\u306B\u306A\u308B\
    \u69D8\u306B\u6C34\u3092\u6D41\u3059\u4E8B\u3092\u8A66\u307F\u308B\u3002 {\u30B3\
    \u30B9\u30C8\u3001\u5B9F\u969B\u306B\u6D41\u308C\u305F\u6D41\u91CF}\u3092\u8FD4\
    \u3059\u3002 O(FElogV)\n\t\t\u5408\u8A08\u6D41\u91CF\u304C\u6E1B\u308B\u65B9\u5411\
    \u306B\u306F\u6D41\u308C\u306A\u3044\u3002\n\t*/\n};\n"
  code: "struct MinCostFlow {\n\tusing ll = long long;\n\tusing pli = pair<long long,\
    \ int>;\n\tusing vl = vector<ll>;\n\tusing vi = vector<int>;\n\n\tstruct Edge\
    \ {\n\t\tint to, rev;\n\t\tll cap, cost;\n\t\tEdge(){}\n\t\tEdge(int _to, int\
    \ _rev, ll _cap, ll _cost) : to(_to), rev(_rev), cap(_cap), cost(_cost){}\n\t\
    };\n\n\tvector<vector<Edge>> G;\n    int N;\n\tconst ll MAX_DIST = 2002002002002002002LL;\n\
    \    vl h;\n    vl dist;\n    vi prevV;//\u30C0\u30A4\u30AF\u30B9\u30C8\u30E9\u306F\
    \u518D\u5E30\u95A2\u6570\u7684\u306B\u66F8\u3051\u306A\u3044\u306E\u3067\u3001\
    \u4FDD\u5B58\u3059\u308B\u5FC5\u8981\u304C\u3042\u308B : \u6700\u5F8C\u306B\u6D41\
    \u3057\u305F\u5206\u6E1B\u7B97\u3059\u308B\u306E\u306B\u4F7F\u3046\u3002\n   \
    \ vi prevE;//\u540C\u4E0A\u3002\n    ll now_ryuuryou = 0;\n    ll now_cost = 0;\n\
    \    vector<pair<int, Edge>> es;//\u8FBA\u306E\u60C5\u5831 [from, EDGE]\n    vector<unordered_map<int,\
    \ int>> getid;\n    \n\tMinCostFlow(int _N) {\n        N = _N;\n\t    G.resize(N+1);\n\
    \        h.assign(N+1, 0);\n        dist.assign(N+1, MAX_DIST);\n        prevV.resize(N+1);\n\
    \        prevE.resize(N+1);\n        es.resize(1);\n        getid.resize(N+1);\n\
    \t}\n\n    private:\n\n        ll Daiku(int s, int t, ll &ryuuryou) {\n      \
    \      ll res = 0;\n            while(ryuuryou > 0) {\n                priority_queue<pair<ll,\
    \ int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;\n                dist.assign(N+1,\
    \ MAX_DIST);\n                dist[s] = 0;\n                que.push(pli(0, s));\
    \        \n                while(!que.empty()) {\n                    ll cd =\
    \ que.top().first;\n                    int cp = que.top().second;\n         \
    \           que.pop();\n                    if(dist[cp] < cd) {\n            \
    \          continue;\n                    }\n                    for (int i =\
    \ 0; i < int(G[cp].size()); i++) {\n                        Edge e = G[cp][i];\n\
    \                        if(e.cap > 0 && dist[e.to] > dist[cp] + e.cost - (h[e.to]\
    \ - h[cp])) {\n                            //1\u96C6\u76EE\u306E\u30C0\u30A4\u30AF\
    \u30B9\u30C8\u30E9\u306E\u6642\u3001h\u306E\u4E2D\u8EAB\u306F0\u306A\u306E\u3067\
    \u6700\u521D\u304B\u3089\u3053\u306E\u66F8\u304D\u65B9\u3067\u4E0D\u90FD\u5408\
    \u306F\u751F\u3058\u306A\u3044\n                            dist[e.to] = dist[cp]\
    \ + e.cost - (h[e.to] - h[cp]);\n                            prevV.at(e.to) =\
    \ cp;\n                            prevE.at(e.to) = i;\n                     \
    \       que.push(pli(dist[e.to], e.to));\n                        }\n        \
    \            }\n                }        \n                if(dist[t] == MAX_DIST)\
    \ {\n                  return 1;//\u8FBF\u308A\u7740\u3051\u306A\u304B\u3063\u305F\
    \n                }        \n                for (int i = 1; i <= N; i++) {\n\
    \                  h[i] += dist[i];//\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u306E\
    \u66F4\u65B0 \u9006\u8FBA\u3092\u5F35\u308B\u524D\u306B\u3084\u308B\uFF08\u8CA0\
    \u306E\u8FBA\u3092\u6D88\u3059\u306E\u304C\u76EE\u7684\u306A\u306E\u3067\uFF09\
    \n                }\n\n                ll flow = ryuuryou;\n                for\
    \ (int v = t; v != s; v = prevV[v]) {\n\t\t\t\t\tif(G[prevV[v]][prevE[v]].cap\
    \ < flow) flow = G[prevV[v]][prevE[v]].cap;\n                }\n             \
    \   ryuuryou -= flow;\n                now_ryuuryou += flow;\n               \
    \ res += h[t] * flow;//\u5927\u3044\u306A\u308B\u6CE8\u610F\u70B9: dist\u306B\u5165\
    \u3063\u3066\u3044\u308B\u306E\u306F\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u4ED8\
    \u304D\u306E\u8DDD\u96E2 h\u306B\u5165\u3063\u3066\u3044\u308B\u306E\u306F\u5143\
    \u306E\u30B0\u30E9\u30D5\u3067\u306E\u8DDD\u96E2\n                now_cost +=\
    \ h[t] * flow;        \n                for (int v = t; v != s; v = prevV[v])\
    \ {\n                    Edge &e = G[prevV[v]][prevE[v]];\n                  \
    \  e.cap -= flow;\n                    G[v][e.rev].cap += flow;\n            \
    \    }\n            }\n            return res;\n        }    \n  \n public:\n\n\
    \tvoid add_edge(int from, int to, ll cap, ll cost) {\n\t\tint Current_Ga_idx =\
    \ G[from].size(); \n\t\tint Current_Gb_idx = G[to].size(); \n\t\tG[from].emplace_back(Edge(to,\
    \ Current_Gb_idx, cap, cost));\n\t\tG[to].emplace_back(Edge(from, Current_Ga_idx,\
    \ 0, -1 * cost));\n        es.emplace_back(from, Edge(to, Current_Gb_idx, cap,\
    \ cost));\n        getid[from][to] = es.size() - 1;\n\t}\n\n    void WF(int s)\
    \ {\n        vl d(N+1, MAX_DIST);\n        d[s] = 0;\n        for(int i = 1; i\
    \ <= N; i++) {\n            for(int j = 0; j <= N; j++) {\n                for(auto\
    \ e : G[j]) {\n                    if(e.cap != 0 && d[e.to] > d[j] + e.cost) d[e.to]\
    \ = d[j] + e.cost;\n                }\n            }\n        }\n        for(int\
    \ i = 1; i <= N; i++) h[i] = d[i];\n    }\n\n    int edgesize() {return int(es.size())\
    \ - 1;}\n    \n    int get_id(int s, int t) {return getid[s][t];}\n    \n  \n\
    \    ll get_flow(int id) {\n        auto [_, e] = es[id];\n        return G[e.to][e.rev].cap;\n\
    \    }\n  \n    pair<int, int> get_st(int id) {\n        auto [s, e] = es[id];\n\
    \        return make_pair(s, e.to);\n    }\n  \n    void change_edge(int id, ll\
    \ new_cap, ll new_flow) {//\u6D41\u91CF\u5909\u3048\u305F\u304F\u306A\u3044\u306A\
    \u3089\u3001new_flow = get_flow(id)\n        assert(new_cap >= new_flow);\n  \
    \      auto[s, e] = es[id];\n        G[s][G[e.to][e.rev].rev] = Edge(e.to,  e.rev,\
    \ new_cap-new_flow, e.cost);\n        G[e.to][e.rev] = Edge(s,G[e.to][e.rev].rev,\
    \  new_flow, -e.cost);\n    }\n  \n  \n  \tpli min_cost(int s, int t, ll target)\
    \ {\n        ll ryuuryou = target - now_ryuuryou;\n  \t    Daiku(s, t, ryuuryou);\n\
    \  \t  \treturn pli(now_cost, now_ryuuryou);\n  \t} \n\n\t/*\n\t    MinCostFlow(N)\
    \ \u7A7A\u9593O(N)\n\t\t@brief Mincostflow\n\n\t\tadd_edge(s, t, cap, cost) ...\
    \ s\u2192t \u306E\u8FBA\u3092\u5F35\u308B\u3002 \u8FBA\u304C\u8FFD\u52A0\u3055\
    \u308C\u305F\u9806\u756A\u306B\u5FDC\u3058\u3066\u3001\u8FBA\u306B\u306F1-indexed\u306E\
    \u756A\u53F7\u304C\u3064\u304F\u3002O(1)\n\t\tWF(s) ... s\u304B\u3089\u306E\u30DD\
    \u30C6\u30F3\u30B7\u30E3\u30EB\u3092\u8A08\u7B97\u3059\u308B\u3002\u8CA0\u306E\
    \u30B3\u30B9\u30C8\u304C\u542B\u307E\u308C\u308B\u5834\u5408\u306B\u547C\u3076\
    \u3002s\u306B\u306F\u3001\u30D5\u30ED\u30FC\u3092\u6D41\u3059\u59CB\u70B9\u3092\
    \u4E0E\u3048\u308B\u3002  O(VE)\n\t\tedgesize() ... \u8FBA\u306E\u672C\u6570 O(1)\n\
    \t\tget_id(s, t) ... s\u2192t\u306E\u8FBA\u306E\u3001\u8FBA\u756A\u53F7\u3092\u8FD4\
    \u3059\u3002 O(1)\n\t\tget_flow(id) ... \u8FBA\u756A\u53F7id\u306E\u8FBA\u306E\
    \u73FE\u5728\u306E\u6D41\u91CF\u3092\u8FD4\u3059\u3002 O(1)\n\t\tget_st(id) ...\
    \ \u8FBA\u756A\u53F7id\u306E\u8FBA\u306E\u8996\u70B9\u3068\u7D42\u70B9\u3092\u8FD4\
    \u3059\u3002O(1)\n\t\tchange_edge(id, new_cap, new_flow) ... \u8FBA\u756A\u53F7\
    id\u306E\u8FBA\u306Ecap, flow\u3092\u5909\u66F4\u3059\u308B\u3002 O(1)\n\t\tmin_cost(s,\
    \ t, target) ... \u73FE\u5728\u306E\u30B0\u30E9\u30D5\u3092\u5143\u306B\u3001\
    s\u304B\u3089t\u306B\u3001\u5408\u8A08\u6D41\u91CF\u304Ctarget\u306B\u306A\u308B\
    \u69D8\u306B\u6C34\u3092\u6D41\u3059\u4E8B\u3092\u8A66\u307F\u308B\u3002 {\u30B3\
    \u30B9\u30C8\u3001\u5B9F\u969B\u306B\u6D41\u308C\u305F\u6D41\u91CF}\u3092\u8FD4\
    \u3059\u3002 O(FElogV)\n\t\t\u5408\u8A08\u6D41\u91CF\u304C\u6E1B\u308B\u65B9\u5411\
    \u306B\u306F\u6D41\u308C\u306A\u3044\u3002\n\t*/\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: Algorithms/mincostflow.cpp
  requiredBy: []
  timestamp: '2024-05-10 23:04:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Algorithms/mincostflow.cpp
layout: document
redirect_from:
- /library/Algorithms/mincostflow.cpp
- /library/Algorithms/mincostflow.cpp.html
title: Mincostflow
---
