---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: dynamic_connectivity
    links: []
  bundledCode: "#line 1 \"DetaStructures/dynamic_connectivity.cpp\"\nstruct dynamic_connectivity\
    \ {\n    struct euler_tour_tree {\n    \tstruct node_t;\n    \tusing np = node_t*;\n\
    \    \tstruct node_t {\n    \t\tnode_t *lch, *rch, *par;\n\t\t\tint s, t;\n  \
    \  \t\tint sz;\n\t\t\tbool exact;//\u3053\u306E\u30CE\u30FC\u30C9(\u8FBA) \u306E\
    \u30EC\u30D9\u30EB == ett\u306E\u30EC\u30D9\u30EB && s < t   edge_levelup\n\t\t\
    \tbool child_exact;\n\t\t\tbool have_auxedge = false;\n\t\t\tbool child_have_auxedge\
    \ = false;\n    \n    \t\t//node_t() : lch(nullptr), rch(nullptr), par(nullptr),\
    \ sz(0) {}\n\t\t\tnode_t(int _s, int _t) : s(_s), t(_t), lch(nullptr), rch(nullptr),\
    \ par(nullptr), sz(s==t), exact(s<t), child_exact(s<t) {\n\n\t\t\t}\n    \t  \
    \  bool is_root() {\n    \t    \treturn !par;\n    \t    }\n    \n    \t\tvoid\
    \ take_copy(np x) {//x\u306E\u96C6\u7D04\u5024\u3001\u4F5C\u7528\u7D20\u3092\u81EA\
    \u8EAB\u306B\u30B3\u30D4\u30FC. x\u306Fnullptr\u3067\u306F\u7121\u3044\u3002\n\
    \t\t\t\tsz = x -> sz;\n\t\t\t\tchild_have_auxedge = x -> child_have_auxedge;\n\
    \t\t\t\tchild_exact = x -> child_exact;\n    \t\t}\n    \t};\n    \n    \t\n \
    \   \n    \n    \tint sz;\n    \tvector<unordered_map<int, np>> ptr;\n\n    \t\
    void push(np t) {}\n    \n    \tvoid update(np t) {\n    \t    t -> sz = (t->s\
    \ == t->t);\n\t\t\tif(t -> lch) t -> sz += t -> lch -> sz;\n\t\t\tif(t -> rch)\
    \ t -> sz += t -> rch -> sz;\n\t\t\tt -> child_exact = (t -> lch ? t -> lch ->\
    \ child_exact : 0) | (t -> exact) | (t -> rch ? t -> rch -> child_exact : 0);\n\
    \t\t\tt -> child_have_auxedge = (t -> lch ? t -> lch -> child_have_auxedge : 0)\
    \ | (t -> have_auxedge) | (t -> rch ? t -> rch -> child_have_auxedge : 0);\n \
    \   \t}\n        \n\t\tvoid update_only_child_have_auxedge(np t) {\n\t\t\tt ->\
    \ child_have_auxedge = (t -> lch ? t -> lch -> child_have_auxedge : 0) | (t ->\
    \ have_auxedge) | (t -> rch ? t -> rch -> child_have_auxedge : 0);\n\t\t}\n\t\t\
    void update_only_child_exact(np t) {\n\t\t\tt -> child_exact = (t -> lch ? t ->\
    \ lch -> child_exact : 0) | (t -> exact) | (t -> rch ? t -> rch -> child_exact\
    \ : 0);\n\t\t}\n    \n    \tvoid rotR(np t) {//x\u306E\u4F5C\u7528\u7D20\u3001\
    \u7A7A\u306B\u3057\u306A\u304D\u3083\u9045\u5EF6\u4F1D\u64AD\u304A\u304B\u3057\
    \u304F\u306A\u3044\uFF1FTODO\n    \t\tnp x = t -> par, y = x -> par;\n    \t\t\
    push(t);\n    \t\tif((x -> lch = t -> rch)) t -> rch -> par = x;\n    \t\tt ->\
    \ rch = x, x -> par = t;\n    \t\tif((t -> par = y)) {\n    \t\t\tif(y -> lch\
    \ == x) y -> lch = t;\n    \t\t\telse y -> rch = t;\n    \t\t}\n    \t\tt -> take_copy(x);\n\
    \    \t\tpush(x -> lch); push(x -> rch);\n    \t\tupdate(x); \n    \t}\n    \n\
    \    \tvoid rotL(np t) {//x\u306E\u4F5C\u7528\u7D20\u3001\u7A7A\u306B\u3057\u306A\
    \u304D\u3083\u9045\u5EF6\u4F1D\u64AD\u304A\u304B\u3057\u304F\u306A\u3044\uFF1F\
    TODO\n    \t\tnp x = t -> par, y = x -> par;\n    \t\tpush(t);\n    \t\tif((x\
    \ -> rch = t -> lch)) t -> lch -> par = x;\n    \t\tt -> lch = x, x -> par = t;\n\
    \    \t\tif((t -> par = y)) {\n    \t\t\tif(y -> lch == x) y -> lch = t;\n   \
    \ \t\t\telse y -> rch = t;\n    \t\t}\n    \t    t -> take_copy(x);\n    \t\t\
    push(x -> lch); push(x -> rch);\n    \t\tupdate(x); \n    \t}\n    \n    \tvoid\
    \ splay(np t) {\n    \t\twhile(!t -> is_root()) {\n    \t\t\tnp x = t -> par;\n\
    \    \t\t\tif(x -> is_root()) {\n    \t\t\t\tif(x -> lch == t) rotR(t);\n    \t\
    \t\t\telse rotL(t);\n    \t\t\t} else {\n    \t\t\t\tnp y = x -> par;\n    \t\t\
    \t\tif(y -> lch == x) {\n    \t\t\t\t\tif(x -> lch == t) rotR(x), rotR(t);\n \
    \   \t\t\t\t\telse rotL(t), rotR(t);\n    \t\t\t\t}\n    \t\t\t\telse {\n    \t\
    \t\t\t\tif(x -> rch == t) rotL(x), rotL(t);\n    \t\t\t\t\telse rotR(t), rotL(t);\n\
    \    \t\t\t\t}\n    \t\t\t}\n    \t\t}\n    \t\tpush(t);//t\u306Elazy\u3092\u6052\
    \u7B49\u4F5C\u7528\u306B\u3057\u3066\u304A\u304F\n    \t}\n    \n    \tnp merge(np\
    \ l, np r) {\n    \t\tif(!l) return r;\n    \t\tif(!r) return l;\n    \t\twhile(l\
    \ -> rch) l = l -> rch;\n    \t\tsplay(l);\n    \t\tif((l -> rch = r)) {\n   \
    \ \t\t\tpush(r);\n    \t\t\tr -> par = l;\n    \t\t}\n    \t\tupdate(l);\n   \
    \ \t\treturn l;\n    \t}\n    \n    \n    \tpair<np, np> split(np t) {//  t) [t,\
    \ \n    \t    splay(t);\n    \t\tnp l = t -> lch;\n    \t\tif(l) l -> par = nullptr;\n\
    \    \t\tt -> lch = nullptr;\n    \t\tupdate(t);\n    \t\treturn make_pair(l,\
    \ t);\n    \t}\n\n    \tpair<np, np> split2(np t) { //move t to top and detach\
    \ t\n    \t\tsplay(t);\n    \t\tnp l = t -> lch;\n    \t\tnp r = t -> rch;\n \
    \   \t\tif(l) l -> par = nullptr;\n    \t\tt -> lch = nullptr;\n    \t\tif(r)\
    \ r -> par = nullptr;\n    \t\tt -> rch = nullptr;\n    \t\tupdate(t);\n    \t\
    \treturn make_pair(l, r);\n    \t}\n\n    \ttuple<np, np, np> split(np u, np t)\
    \ {// u) (u  t) (t    /    t) (t  u) (u\n    \t    auto v = split2(u);\n    \t\
    \tif(same(v.first, t)) {\n    \t\t\tauto r = split2(t);\n    \t\t\treturn make_tuple(r.first,\
    \ r.second, v.second);\n    \t\t} else {\n    \t\t\tauto r = split2(t);\n    \t\
    \t\treturn make_tuple(v.first, r.first, r.second);\n    \t\t}\n    \t}\n    \n\
    \    \tnp get_node(int s, int t) {\n    \t\tif(ptr[s].find(t) == ptr[s].end())ptr[s][t]\
    \ = new node_t(s, t);\n    \t\treturn ptr[s][t];\n    \t}\n    \n    \tnp root(np\
    \ t) {\n    \t\tif(!t) return t;\n    \t\twhile(t -> par) t = t -> par;\n    \t\
    \treturn t;\n    \t}\n\n    \tnp reroot(np t) {\n    \t\tauto[l, r] = split(t);\n\
    \    \t\treturn merge(r, l);\n    \t}\n\t\tint size(np u) { // NEW!\n\t\t\tsplay(u);\n\
    \t\t\treturn u -> sz;\n\t\t}\n    \n    \tbool same(np u, np v) {\n    \t\tif(u)\
    \ splay(u);\n    \t\tif(v) splay(v);\n    \t\treturn root(u) == root(v);\n   \
    \ \t}\n\t\teuler_tour_tree(){}\n    \t\n    \teuler_tour_tree(int _sz) : sz(_sz)\
    \ {\n    \t    ptr.resize(sz);\n    \t}\n\n    \tbool same(int u, int v) {\n \
    \   \t\treturn same(get_node(u, u), get_node(v, v));\n    \t}\n\n    \tbool link(int\
    \ u, int v) {\n    \t\tif(same(u, v)) return false;\n    \t\tmerge(merge(merge(reroot(get_node(u,\
    \ u)), get_node(u, v)), reroot(get_node(v, v))), get_node(v, u));\n    \t\treturn\
    \ true;\n    \t}\n\n    \tbool cut(int u, int v) {\n    \t\tif(ptr[u].find(v)\
    \ == ptr[u].end()) return false;\n    \t\tauto [i, j, k] = split(get_node(u, v),\
    \ get_node(v, u));\n    \t\tmerge(i, k);\n    \t\tnp p = ptr[u][v];\n    \t\t\
    np q = ptr[v][u];\n    \t\tptr[u].erase(v);\n    \t\tptr[v].erase(u);\n    \t\t\
    delete p; delete q;\n    \t\treturn true;\n    \t}\n\t\tint size(int u) {\n\t\t\
    \treturn size(get_node(u, u));\n\t\t}\n\t\tvoid have_auxedge_update(int t, bool\
    \ b) {\n\t\t\tnp v = get_node(t, t);\n\t\t\tsplay(v);\n\t\t\tv -> have_auxedge\
    \ = b;\n\t\t\tupdate_only_child_have_auxedge(v);\n\t\t}\n\n\t\tvector<int> vertex_list(int\
    \ t) {\n\t\t\tnp v = get_node(t, t);\n\t\t\tsplay(v);\n\t\t\tvector<int> res;\n\
    \n\t\t\tauto dfs = [&](auto f, np now) -> void {\n\t\t\t\tif(now -> lch) f(f,\
    \ now -> lch);\n\t\t\t\tif(now -> s == now -> t) res.push_back(now -> s);\n\t\t\
    \t\tif(now -> rch) f(f, now -> rch);\n\t\t\t\treturn;\n\t\t\t};\n\n\t\t\tdfs(dfs,\
    \ v);\n\t\t\treturn res;\n\t\t}\n\n    };\n    int cc;\n    int sz;\n\tint dep;\n\
    \    vector<euler_tour_tree> ett;\n\tvector<vector<unordered_set<int>>> aux_edges;\n\
    \    using np = typename euler_tour_tree::node_t*;\n\n\tprivate:\n\t \n\n\t  \
    \  void edge_level_increment(int t, int k) {\n\t\t\tnp v = ett[k].get_node(t,\
    \ t);\n\t\t\tett[k].splay(v);\n\t\t\tauto dfs = [&](auto f, np now) -> void {\n\
    \t\t\t\tif(now->exact) {\n\t\t\t\t\tett[k].splay(now);\n\t\t\t\t\tnow -> exact\
    \ = 0;\n\t\t\t\t\tett[k].update_only_child_exact(now);\n\t\t\t\t\tett[k+1].link(now\
    \ -> s, now -> t);\n\t\t\t\t\treturn;\n\t\t\t\t}\n\t\t\t\tif(now -> lch && now\
    \ -> lch -> child_exact) f(f, now -> lch);\n\t\t\t\telse f(f, now -> rch);\n\t\
    \t\t\treturn;\n\t\t\t};\n\n\t\t\twhile(v && v -> child_exact) {\n\t\t\t\tdfs(dfs,\
    \ v);\n\t\t\t\tett[k].splay(v);\n\t\t\t}\n\t\t}\n\t    \n\t\tbool try_reconnect(int\
    \ u, int v, int k) {\n\t\t\tfor(int i=0; i<k;i++) {\n\t\t\t\tett[i].cut(u, v);\n\
    \t\t\t}\n\n\t\t\tfor(int i=k; i >=0; i--) {\n\t\t\t\tif(ett[i].size(u) > ett[i].size(v))\
    \ swap(u, v);\n\t\t\t\tedge_level_increment(u, i);\n\n\t\t\t\tnp t = ett[i].get_node(u,\
    \ u);\n\t\t\t\tett[i].splay(t);\n\t\t\t\tauto dfs = [&](auto f, np now) -> bool\
    \ {\n\t\t\t\t\tif(now -> have_auxedge) {\n\t\t\t\t\t\tett[i].splay(now);\n\t\t\
    \t\t\t\tfor(auto itr = aux_edges[i][now->s].begin(); itr != aux_edges[i][now->s].end();\
    \ ) {\n\t\t\t\t\t\t\tauto y = *itr;\n\t\t\t\t\t\t\titr = aux_edges[i][now->s].erase(itr);\n\
    \t\t\t\t\t\t\taux_edges[i][y].erase(now->s);\n\t\t\t\t\t\t\tif(aux_edges[i][now->s].size()==0)ett[i].have_auxedge_update(now->s,\
    \ 0);\n\t\t\t\t\t\t\tif(aux_edges[i][y].size()==0)ett[i].have_auxedge_update(y,\
    \ 0);\n\t\t\t\t\t\t\tif(ett[i].same(now->s, y)) {//\u8FBA\u306E\u5148\u304C\u81EA\
    \u5206\u306E\u9023\u7D50\u6210\u5206\n\t\t\t\t\t\t\t    aux_edges[i+1][now->s].insert(y);\n\
    \t\t\t\t\t\t\t\taux_edges[i+1][y].insert(now->s);\n\t\t\t\t\t\t\t\tif(aux_edges[i+1][now->s].size()==1)ett[i+1].have_auxedge_update(now->s,\
    \ 1);\n\t\t\t\t\t\t\t\tif(aux_edges[i+1][y].size()==1)ett[i+1].have_auxedge_update(y,\
    \ 1);\n\t\t\t\t\t\t\t}\n\t\t\t\t\t\t\telse {\n\t\t\t\t\t\t\t\tfor(int j = 0; j\
    \ <= i; j++) {\n\t\t\t\t\t\t\t\t\tett[j].link(now->s, y);\n\t\t\t\t\t\t\t\t}\n\
    \t\t\t\t\t\t\t\treturn 1;\n\t\t\t\t\t\t\t}\n\t\t\t\t\t\t}\n\t\t\t\t\t\treturn\
    \ 0;\n\t\t\t\t\t}\n\n\t\t\t\t\tif(now -> lch && now -> lch -> child_have_auxedge)\
    \ return f(f, now -> lch);\n\t\t\t\t\telse return f(f, now -> rch);\n\t\t\t\t\
    };\n\n\t\t\t\twhile(t -> child_have_auxedge) {\n\t\t\t\t\tif(dfs(dfs, t)) return\
    \ 1;\n\t\t\t\t\tett[i].splay(t);\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn 0;\n\t\t}\n\
    \n\tpublic:\n\n\t   \n\n\n\t    dynamic_connectivity(int _sz) : sz(_sz) {\n\t\t\
    \tcc = sz;\n\t\t\tdep = 1;\n\t\t\tett.emplace_back(sz);\n\t\t\taux_edges.emplace_back(sz);\n\
    \t\t}\n\n\n\t\tbool same(int u, int v) {\n\t\t\treturn ett[0].same(u, v);\n\t\t\
    }\n\n\t\tbool link(int u, int v) {//\u9023\u7D50\u6210\u5206\u304C\u6E1B\u3063\
    \u305F\u304B\n\t\t\tif(u==v)return false;\n\t\t\tif(ett[0].link(u, v)) {\n\t\t\
    \t\tcc--;\n\t\t\t\treturn true;\n\t\t\t} \n\t\t\taux_edges[0][u].insert(v);\n\t\
    \t\taux_edges[0][v].insert(u);\n\t\t\tif(aux_edges[0][u].size()==1)ett[0].have_auxedge_update(u,\
    \ 1);\n\t\t\tif(aux_edges[0][v].size()==1)ett[0].have_auxedge_update(v, 1);\n\t\
    \t\treturn false;\n\t\t}\n\n\t\tbool cut(int u, int v) {//\u5207\u3063\u305F\u7D50\
    \u679C\u3001\u5206\u65AD\u3055\u308C\u305F\u304B\uFF1F\n\t\t\tfor(int i=0; i<dep;\
    \ i++) {\n\t\t\t\taux_edges[i][u].erase(v);\n\t\t\t\taux_edges[i][v].erase(u);\n\
    \t\t\t\tif(aux_edges[i][u].size()==0)ett[i].have_auxedge_update(u, 0);\n\t\t\t\
    \tif(aux_edges[i][v].size()==0)ett[i].have_auxedge_update(v, 0);\n\t\t\t}\n\n\t\
    \t\tfor(int i=dep-1; i >=0; i--) {\n\t\t\t\tif(ett[i].cut(u, v)) {\n\t\t\t\t\t\
    if(dep-1==i) {\n\t\t\t\t\t\tdep++;\n\t\t\t\t\t\tett.emplace_back(sz);\n\t\t\t\t\
    \t\taux_edges.emplace_back(sz);\n\t\t\t\t\t}\n\t\t\t\t\tbool b = try_reconnect(u,\
    \ v, i);\n\t\t\t\t\tif(!b)cc++;\n\t\t\t\t\treturn b;\n\t\t\t\t}\n\t\t\t}\n\t\t\
    \treturn false;\n\t\t}\n\n\t\tint component_count() {\n\t\t\treturn cc;\n\n\t\t\
    }\n\n\t\tint size(int u) {\n\t\t\tnp v = ett[0].get_node(u, u);\n\t\t\tett[0].splay(v);\n\
    \t\t\treturn v -> sz;\n\t\t}\n\n\t\tvector<int> vertex_list(int u) {\n\t\t\treturn\
    \ ett[0].vertex_list(u);\n\t\t}\n\n\t\t/*\n\t\t    dynamic_connectivity(sz)  \
    \ O(sz)  \u7A7A\u9593O(szlogsz) (\u91CD\u3044!)\n\t\t\t@brief dynamic_connectivity\n\
    \t\t\tlink(u, v) ... uv\u9593\u306B\u8FBA\u3092\u5F35\u308B\u3002\u3059\u3067\u306B\
    \u3042\u3063\u305F\u3089\u4F55\u3082\u3057\u306A\u3044\u3002amortized O(log^2N)\
    \  \u3089\u3057\u3044\uFF1F\n\t\t\tcut(u, v) ... uv\u9593\u306E\u8FBA\u3092\u524A\
    \u9664\u3059\u308B\u3002\u3059\u3067\u306B\u3042\u3063\u305F\u3089\u4F55\u3082\
    \u3057\u306A\u3044\u3002amortized O(log^2N)\n\t\t\tsame(u, v) ... uv\u304C\u540C\
    \u3058\u9023\u7D50\u6210\u5206\u306B\u3042\u308B\u304B\u3002 O(logN)\n\t\t\tsize(u)\
    \ ... u\u304C\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E\u30B5\u30A4\u30BA\
    \ \u672Averify\n\t\t\tcomponent_count()...\u9023\u7D50\u6210\u5206\u306E\u500B\
    \u6570 O(1).\u9802\u70B90\u3092\u542B\u3093\u3067\u3044\u308B\u4E8B\u306B\u6CE8\
    \u610F\u3002\n\t\t\tvertex_list(u) ... u\u304C\u5C5E\u3059\u308B\u9023\u7D50\u6210\
    \u5206\u306E\u9802\u70B9 O(logN + |SIZE|)  \u672Averify\n\t\t*/\n\n};\n"
  code: "struct dynamic_connectivity {\n    struct euler_tour_tree {\n    \tstruct\
    \ node_t;\n    \tusing np = node_t*;\n    \tstruct node_t {\n    \t\tnode_t *lch,\
    \ *rch, *par;\n\t\t\tint s, t;\n    \t\tint sz;\n\t\t\tbool exact;//\u3053\u306E\
    \u30CE\u30FC\u30C9(\u8FBA) \u306E\u30EC\u30D9\u30EB == ett\u306E\u30EC\u30D9\u30EB\
    \ && s < t   edge_levelup\n\t\t\tbool child_exact;\n\t\t\tbool have_auxedge =\
    \ false;\n\t\t\tbool child_have_auxedge = false;\n    \n    \t\t//node_t() : lch(nullptr),\
    \ rch(nullptr), par(nullptr), sz(0) {}\n\t\t\tnode_t(int _s, int _t) : s(_s),\
    \ t(_t), lch(nullptr), rch(nullptr), par(nullptr), sz(s==t), exact(s<t), child_exact(s<t)\
    \ {\n\n\t\t\t}\n    \t    bool is_root() {\n    \t    \treturn !par;\n    \t \
    \   }\n    \n    \t\tvoid take_copy(np x) {//x\u306E\u96C6\u7D04\u5024\u3001\u4F5C\
    \u7528\u7D20\u3092\u81EA\u8EAB\u306B\u30B3\u30D4\u30FC. x\u306Fnullptr\u3067\u306F\
    \u7121\u3044\u3002\n\t\t\t\tsz = x -> sz;\n\t\t\t\tchild_have_auxedge = x -> child_have_auxedge;\n\
    \t\t\t\tchild_exact = x -> child_exact;\n    \t\t}\n    \t};\n    \n    \t\n \
    \   \n    \n    \tint sz;\n    \tvector<unordered_map<int, np>> ptr;\n\n    \t\
    void push(np t) {}\n    \n    \tvoid update(np t) {\n    \t    t -> sz = (t->s\
    \ == t->t);\n\t\t\tif(t -> lch) t -> sz += t -> lch -> sz;\n\t\t\tif(t -> rch)\
    \ t -> sz += t -> rch -> sz;\n\t\t\tt -> child_exact = (t -> lch ? t -> lch ->\
    \ child_exact : 0) | (t -> exact) | (t -> rch ? t -> rch -> child_exact : 0);\n\
    \t\t\tt -> child_have_auxedge = (t -> lch ? t -> lch -> child_have_auxedge : 0)\
    \ | (t -> have_auxedge) | (t -> rch ? t -> rch -> child_have_auxedge : 0);\n \
    \   \t}\n        \n\t\tvoid update_only_child_have_auxedge(np t) {\n\t\t\tt ->\
    \ child_have_auxedge = (t -> lch ? t -> lch -> child_have_auxedge : 0) | (t ->\
    \ have_auxedge) | (t -> rch ? t -> rch -> child_have_auxedge : 0);\n\t\t}\n\t\t\
    void update_only_child_exact(np t) {\n\t\t\tt -> child_exact = (t -> lch ? t ->\
    \ lch -> child_exact : 0) | (t -> exact) | (t -> rch ? t -> rch -> child_exact\
    \ : 0);\n\t\t}\n    \n    \tvoid rotR(np t) {//x\u306E\u4F5C\u7528\u7D20\u3001\
    \u7A7A\u306B\u3057\u306A\u304D\u3083\u9045\u5EF6\u4F1D\u64AD\u304A\u304B\u3057\
    \u304F\u306A\u3044\uFF1FTODO\n    \t\tnp x = t -> par, y = x -> par;\n    \t\t\
    push(t);\n    \t\tif((x -> lch = t -> rch)) t -> rch -> par = x;\n    \t\tt ->\
    \ rch = x, x -> par = t;\n    \t\tif((t -> par = y)) {\n    \t\t\tif(y -> lch\
    \ == x) y -> lch = t;\n    \t\t\telse y -> rch = t;\n    \t\t}\n    \t\tt -> take_copy(x);\n\
    \    \t\tpush(x -> lch); push(x -> rch);\n    \t\tupdate(x); \n    \t}\n    \n\
    \    \tvoid rotL(np t) {//x\u306E\u4F5C\u7528\u7D20\u3001\u7A7A\u306B\u3057\u306A\
    \u304D\u3083\u9045\u5EF6\u4F1D\u64AD\u304A\u304B\u3057\u304F\u306A\u3044\uFF1F\
    TODO\n    \t\tnp x = t -> par, y = x -> par;\n    \t\tpush(t);\n    \t\tif((x\
    \ -> rch = t -> lch)) t -> lch -> par = x;\n    \t\tt -> lch = x, x -> par = t;\n\
    \    \t\tif((t -> par = y)) {\n    \t\t\tif(y -> lch == x) y -> lch = t;\n   \
    \ \t\t\telse y -> rch = t;\n    \t\t}\n    \t    t -> take_copy(x);\n    \t\t\
    push(x -> lch); push(x -> rch);\n    \t\tupdate(x); \n    \t}\n    \n    \tvoid\
    \ splay(np t) {\n    \t\twhile(!t -> is_root()) {\n    \t\t\tnp x = t -> par;\n\
    \    \t\t\tif(x -> is_root()) {\n    \t\t\t\tif(x -> lch == t) rotR(t);\n    \t\
    \t\t\telse rotL(t);\n    \t\t\t} else {\n    \t\t\t\tnp y = x -> par;\n    \t\t\
    \t\tif(y -> lch == x) {\n    \t\t\t\t\tif(x -> lch == t) rotR(x), rotR(t);\n \
    \   \t\t\t\t\telse rotL(t), rotR(t);\n    \t\t\t\t}\n    \t\t\t\telse {\n    \t\
    \t\t\t\tif(x -> rch == t) rotL(x), rotL(t);\n    \t\t\t\t\telse rotR(t), rotL(t);\n\
    \    \t\t\t\t}\n    \t\t\t}\n    \t\t}\n    \t\tpush(t);//t\u306Elazy\u3092\u6052\
    \u7B49\u4F5C\u7528\u306B\u3057\u3066\u304A\u304F\n    \t}\n    \n    \tnp merge(np\
    \ l, np r) {\n    \t\tif(!l) return r;\n    \t\tif(!r) return l;\n    \t\twhile(l\
    \ -> rch) l = l -> rch;\n    \t\tsplay(l);\n    \t\tif((l -> rch = r)) {\n   \
    \ \t\t\tpush(r);\n    \t\t\tr -> par = l;\n    \t\t}\n    \t\tupdate(l);\n   \
    \ \t\treturn l;\n    \t}\n    \n    \n    \tpair<np, np> split(np t) {//  t) [t,\
    \ \n    \t    splay(t);\n    \t\tnp l = t -> lch;\n    \t\tif(l) l -> par = nullptr;\n\
    \    \t\tt -> lch = nullptr;\n    \t\tupdate(t);\n    \t\treturn make_pair(l,\
    \ t);\n    \t}\n\n    \tpair<np, np> split2(np t) { //move t to top and detach\
    \ t\n    \t\tsplay(t);\n    \t\tnp l = t -> lch;\n    \t\tnp r = t -> rch;\n \
    \   \t\tif(l) l -> par = nullptr;\n    \t\tt -> lch = nullptr;\n    \t\tif(r)\
    \ r -> par = nullptr;\n    \t\tt -> rch = nullptr;\n    \t\tupdate(t);\n    \t\
    \treturn make_pair(l, r);\n    \t}\n\n    \ttuple<np, np, np> split(np u, np t)\
    \ {// u) (u  t) (t    /    t) (t  u) (u\n    \t    auto v = split2(u);\n    \t\
    \tif(same(v.first, t)) {\n    \t\t\tauto r = split2(t);\n    \t\t\treturn make_tuple(r.first,\
    \ r.second, v.second);\n    \t\t} else {\n    \t\t\tauto r = split2(t);\n    \t\
    \t\treturn make_tuple(v.first, r.first, r.second);\n    \t\t}\n    \t}\n    \n\
    \    \tnp get_node(int s, int t) {\n    \t\tif(ptr[s].find(t) == ptr[s].end())ptr[s][t]\
    \ = new node_t(s, t);\n    \t\treturn ptr[s][t];\n    \t}\n    \n    \tnp root(np\
    \ t) {\n    \t\tif(!t) return t;\n    \t\twhile(t -> par) t = t -> par;\n    \t\
    \treturn t;\n    \t}\n\n    \tnp reroot(np t) {\n    \t\tauto[l, r] = split(t);\n\
    \    \t\treturn merge(r, l);\n    \t}\n\t\tint size(np u) { // NEW!\n\t\t\tsplay(u);\n\
    \t\t\treturn u -> sz;\n\t\t}\n    \n    \tbool same(np u, np v) {\n    \t\tif(u)\
    \ splay(u);\n    \t\tif(v) splay(v);\n    \t\treturn root(u) == root(v);\n   \
    \ \t}\n\t\teuler_tour_tree(){}\n    \t\n    \teuler_tour_tree(int _sz) : sz(_sz)\
    \ {\n    \t    ptr.resize(sz);\n    \t}\n\n    \tbool same(int u, int v) {\n \
    \   \t\treturn same(get_node(u, u), get_node(v, v));\n    \t}\n\n    \tbool link(int\
    \ u, int v) {\n    \t\tif(same(u, v)) return false;\n    \t\tmerge(merge(merge(reroot(get_node(u,\
    \ u)), get_node(u, v)), reroot(get_node(v, v))), get_node(v, u));\n    \t\treturn\
    \ true;\n    \t}\n\n    \tbool cut(int u, int v) {\n    \t\tif(ptr[u].find(v)\
    \ == ptr[u].end()) return false;\n    \t\tauto [i, j, k] = split(get_node(u, v),\
    \ get_node(v, u));\n    \t\tmerge(i, k);\n    \t\tnp p = ptr[u][v];\n    \t\t\
    np q = ptr[v][u];\n    \t\tptr[u].erase(v);\n    \t\tptr[v].erase(u);\n    \t\t\
    delete p; delete q;\n    \t\treturn true;\n    \t}\n\t\tint size(int u) {\n\t\t\
    \treturn size(get_node(u, u));\n\t\t}\n\t\tvoid have_auxedge_update(int t, bool\
    \ b) {\n\t\t\tnp v = get_node(t, t);\n\t\t\tsplay(v);\n\t\t\tv -> have_auxedge\
    \ = b;\n\t\t\tupdate_only_child_have_auxedge(v);\n\t\t}\n\n\t\tvector<int> vertex_list(int\
    \ t) {\n\t\t\tnp v = get_node(t, t);\n\t\t\tsplay(v);\n\t\t\tvector<int> res;\n\
    \n\t\t\tauto dfs = [&](auto f, np now) -> void {\n\t\t\t\tif(now -> lch) f(f,\
    \ now -> lch);\n\t\t\t\tif(now -> s == now -> t) res.push_back(now -> s);\n\t\t\
    \t\tif(now -> rch) f(f, now -> rch);\n\t\t\t\treturn;\n\t\t\t};\n\n\t\t\tdfs(dfs,\
    \ v);\n\t\t\treturn res;\n\t\t}\n\n    };\n    int cc;\n    int sz;\n\tint dep;\n\
    \    vector<euler_tour_tree> ett;\n\tvector<vector<unordered_set<int>>> aux_edges;\n\
    \    using np = typename euler_tour_tree::node_t*;\n\n\tprivate:\n\t \n\n\t  \
    \  void edge_level_increment(int t, int k) {\n\t\t\tnp v = ett[k].get_node(t,\
    \ t);\n\t\t\tett[k].splay(v);\n\t\t\tauto dfs = [&](auto f, np now) -> void {\n\
    \t\t\t\tif(now->exact) {\n\t\t\t\t\tett[k].splay(now);\n\t\t\t\t\tnow -> exact\
    \ = 0;\n\t\t\t\t\tett[k].update_only_child_exact(now);\n\t\t\t\t\tett[k+1].link(now\
    \ -> s, now -> t);\n\t\t\t\t\treturn;\n\t\t\t\t}\n\t\t\t\tif(now -> lch && now\
    \ -> lch -> child_exact) f(f, now -> lch);\n\t\t\t\telse f(f, now -> rch);\n\t\
    \t\t\treturn;\n\t\t\t};\n\n\t\t\twhile(v && v -> child_exact) {\n\t\t\t\tdfs(dfs,\
    \ v);\n\t\t\t\tett[k].splay(v);\n\t\t\t}\n\t\t}\n\t    \n\t\tbool try_reconnect(int\
    \ u, int v, int k) {\n\t\t\tfor(int i=0; i<k;i++) {\n\t\t\t\tett[i].cut(u, v);\n\
    \t\t\t}\n\n\t\t\tfor(int i=k; i >=0; i--) {\n\t\t\t\tif(ett[i].size(u) > ett[i].size(v))\
    \ swap(u, v);\n\t\t\t\tedge_level_increment(u, i);\n\n\t\t\t\tnp t = ett[i].get_node(u,\
    \ u);\n\t\t\t\tett[i].splay(t);\n\t\t\t\tauto dfs = [&](auto f, np now) -> bool\
    \ {\n\t\t\t\t\tif(now -> have_auxedge) {\n\t\t\t\t\t\tett[i].splay(now);\n\t\t\
    \t\t\t\tfor(auto itr = aux_edges[i][now->s].begin(); itr != aux_edges[i][now->s].end();\
    \ ) {\n\t\t\t\t\t\t\tauto y = *itr;\n\t\t\t\t\t\t\titr = aux_edges[i][now->s].erase(itr);\n\
    \t\t\t\t\t\t\taux_edges[i][y].erase(now->s);\n\t\t\t\t\t\t\tif(aux_edges[i][now->s].size()==0)ett[i].have_auxedge_update(now->s,\
    \ 0);\n\t\t\t\t\t\t\tif(aux_edges[i][y].size()==0)ett[i].have_auxedge_update(y,\
    \ 0);\n\t\t\t\t\t\t\tif(ett[i].same(now->s, y)) {//\u8FBA\u306E\u5148\u304C\u81EA\
    \u5206\u306E\u9023\u7D50\u6210\u5206\n\t\t\t\t\t\t\t    aux_edges[i+1][now->s].insert(y);\n\
    \t\t\t\t\t\t\t\taux_edges[i+1][y].insert(now->s);\n\t\t\t\t\t\t\t\tif(aux_edges[i+1][now->s].size()==1)ett[i+1].have_auxedge_update(now->s,\
    \ 1);\n\t\t\t\t\t\t\t\tif(aux_edges[i+1][y].size()==1)ett[i+1].have_auxedge_update(y,\
    \ 1);\n\t\t\t\t\t\t\t}\n\t\t\t\t\t\t\telse {\n\t\t\t\t\t\t\t\tfor(int j = 0; j\
    \ <= i; j++) {\n\t\t\t\t\t\t\t\t\tett[j].link(now->s, y);\n\t\t\t\t\t\t\t\t}\n\
    \t\t\t\t\t\t\t\treturn 1;\n\t\t\t\t\t\t\t}\n\t\t\t\t\t\t}\n\t\t\t\t\t\treturn\
    \ 0;\n\t\t\t\t\t}\n\n\t\t\t\t\tif(now -> lch && now -> lch -> child_have_auxedge)\
    \ return f(f, now -> lch);\n\t\t\t\t\telse return f(f, now -> rch);\n\t\t\t\t\
    };\n\n\t\t\t\twhile(t -> child_have_auxedge) {\n\t\t\t\t\tif(dfs(dfs, t)) return\
    \ 1;\n\t\t\t\t\tett[i].splay(t);\n\t\t\t\t}\n\t\t\t}\n\t\t\treturn 0;\n\t\t}\n\
    \n\tpublic:\n\n\t   \n\n\n\t    dynamic_connectivity(int _sz) : sz(_sz) {\n\t\t\
    \tcc = sz;\n\t\t\tdep = 1;\n\t\t\tett.emplace_back(sz);\n\t\t\taux_edges.emplace_back(sz);\n\
    \t\t}\n\n\n\t\tbool same(int u, int v) {\n\t\t\treturn ett[0].same(u, v);\n\t\t\
    }\n\n\t\tbool link(int u, int v) {//\u9023\u7D50\u6210\u5206\u304C\u6E1B\u3063\
    \u305F\u304B\n\t\t\tif(u==v)return false;\n\t\t\tif(ett[0].link(u, v)) {\n\t\t\
    \t\tcc--;\n\t\t\t\treturn true;\n\t\t\t} \n\t\t\taux_edges[0][u].insert(v);\n\t\
    \t\taux_edges[0][v].insert(u);\n\t\t\tif(aux_edges[0][u].size()==1)ett[0].have_auxedge_update(u,\
    \ 1);\n\t\t\tif(aux_edges[0][v].size()==1)ett[0].have_auxedge_update(v, 1);\n\t\
    \t\treturn false;\n\t\t}\n\n\t\tbool cut(int u, int v) {//\u5207\u3063\u305F\u7D50\
    \u679C\u3001\u5206\u65AD\u3055\u308C\u305F\u304B\uFF1F\n\t\t\tfor(int i=0; i<dep;\
    \ i++) {\n\t\t\t\taux_edges[i][u].erase(v);\n\t\t\t\taux_edges[i][v].erase(u);\n\
    \t\t\t\tif(aux_edges[i][u].size()==0)ett[i].have_auxedge_update(u, 0);\n\t\t\t\
    \tif(aux_edges[i][v].size()==0)ett[i].have_auxedge_update(v, 0);\n\t\t\t}\n\n\t\
    \t\tfor(int i=dep-1; i >=0; i--) {\n\t\t\t\tif(ett[i].cut(u, v)) {\n\t\t\t\t\t\
    if(dep-1==i) {\n\t\t\t\t\t\tdep++;\n\t\t\t\t\t\tett.emplace_back(sz);\n\t\t\t\t\
    \t\taux_edges.emplace_back(sz);\n\t\t\t\t\t}\n\t\t\t\t\tbool b = try_reconnect(u,\
    \ v, i);\n\t\t\t\t\tif(!b)cc++;\n\t\t\t\t\treturn b;\n\t\t\t\t}\n\t\t\t}\n\t\t\
    \treturn false;\n\t\t}\n\n\t\tint component_count() {\n\t\t\treturn cc;\n\n\t\t\
    }\n\n\t\tint size(int u) {\n\t\t\tnp v = ett[0].get_node(u, u);\n\t\t\tett[0].splay(v);\n\
    \t\t\treturn v -> sz;\n\t\t}\n\n\t\tvector<int> vertex_list(int u) {\n\t\t\treturn\
    \ ett[0].vertex_list(u);\n\t\t}\n\n\t\t/*\n\t\t    dynamic_connectivity(sz)  \
    \ O(sz)  \u7A7A\u9593O(szlogsz) (\u91CD\u3044!)\n\t\t\t@brief dynamic_connectivity\n\
    \t\t\tlink(u, v) ... uv\u9593\u306B\u8FBA\u3092\u5F35\u308B\u3002\u3059\u3067\u306B\
    \u3042\u3063\u305F\u3089\u4F55\u3082\u3057\u306A\u3044\u3002amortized O(log^2N)\
    \  \u3089\u3057\u3044\uFF1F\n\t\t\tcut(u, v) ... uv\u9593\u306E\u8FBA\u3092\u524A\
    \u9664\u3059\u308B\u3002\u3059\u3067\u306B\u3042\u3063\u305F\u3089\u4F55\u3082\
    \u3057\u306A\u3044\u3002amortized O(log^2N)\n\t\t\tsame(u, v) ... uv\u304C\u540C\
    \u3058\u9023\u7D50\u6210\u5206\u306B\u3042\u308B\u304B\u3002 O(logN)\n\t\t\tsize(u)\
    \ ... u\u304C\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E\u30B5\u30A4\u30BA\
    \ \u672Averify\n\t\t\tcomponent_count()...\u9023\u7D50\u6210\u5206\u306E\u500B\
    \u6570 O(1).\u9802\u70B90\u3092\u542B\u3093\u3067\u3044\u308B\u4E8B\u306B\u6CE8\
    \u610F\u3002\n\t\t\tvertex_list(u) ... u\u304C\u5C5E\u3059\u308B\u9023\u7D50\u6210\
    \u5206\u306E\u9802\u70B9 O(logN + |SIZE|)  \u672Averify\n\t\t*/\n\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DetaStructures/dynamic_connectivity.cpp
  requiredBy: []
  timestamp: '2024-05-10 22:51:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DetaStructures/dynamic_connectivity.cpp
layout: document
redirect_from:
- /library/DetaStructures/dynamic_connectivity.cpp
- /library/DetaStructures/dynamic_connectivity.cpp.html
title: dynamic_connectivity
---
