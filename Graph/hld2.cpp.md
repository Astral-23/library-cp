---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "HLD(\u53EF\u63DB)"
    links: []
  bundledCode: "#line 1 \"Graph/hld2.cpp\"\ntemplate <typename X, typename EDGE>\n\
    struct HL {\n  vector<int> siz;//[\u5143\u306E\u9802\u70B9\u756A\u53F7] = \u30B5\
    \u30A4\u30BA\n  vector<int> num;//[\u5143\u306E\u9802\u70B9\u756A\u53F7] = \u632F\
    \u308A\u76F4\u3057\u305F\u9802\u70B9\u756A\u53F7\n  vector<int> numrev;\n  vector<int>\
    \ par;//[\u632F\u3089\u308C\u305F] = \u632F\u3089\u308C\u305F \u81EA\u5206\u306E\
    \u89AA\n  vector<int> head;//[\u632F\u3089\u308C\u305F\u756A\u53F7] = \u632F\u3089\
    \u308C\u305F\u756A\u53F7 \u81EA\u5206\u306E\u9023\u7D50\u6210\u5206\u306E\u982D\
    \n  int N;\n  vector<vector<X>> dat;//\u30BB\u30B0\u6728\u7528\u306E\u914D\u5217\
    \u3001[0](\u756A\u53F7\u304C\u5C0F\u3055\u3044, \u756A\u53F7\u304C\u3067\u304B\
    \u3044)\u306E\u9806\u3067\u7D50\u5408   [1](\u3067\u304B\u3044, \u5C0F\u3055\u3044\
    )\n  \n  int size = 1;\n  X def;\n  \n\n  HL(int _N, vector<vector<EDGE>>& G,\
    \ X _def): N(_N), def(_def) {\n    par.resize(N+1);\n    iota(par.begin(), par.end(),\
    \ 0);\n    siz.resize(N+1, 1);\n    num.assign(N+1, -1);\n    numrev.resize(N+1,\
    \ -1);\n    head.resize(N+1);\n    while(size < N) size <<= 1;\n    dat.resize(2);\n\
    \    dat[0].assign(size*2, def), dat[1].assign(size*2, def);\n\n    auto dfs_siz\
    \ = [&](auto dfs_siz, int now, int prev) -> void {\n      int sum = 1;\n     \
    \ for(int i = 0; i < G[now].size(); i++) {\n        EDGE& e = G[now][i];\n   \
    \     if(e.to == prev) continue;\n         dfs_siz(dfs_siz, e.to, now);\n    \
    \     sum += siz[e.to];\n      }\n      siz[now] = sum;\n      return;\n    };\n\
    \    dfs_siz(dfs_siz, 1, -1);\n    for(int i = 1; i <= N; i++) {\n      sort(G[i].begin(),\
    \ G[i].end(), [&](EDGE& a, EDGE& b) {\n        return siz[a.to] > siz[b.to];\n\
    \      });\n    }\n\n    int idx = 1;\n    auto dfs_bunkai = [&](auto dfs_bunkai,\
    \ int now, int prev, int hed) -> void {\n      num[now] = idx;//\u756A\u53F7\u4ED8\
    \n      numrev[idx] = now;\n      idx++;\n      par[num[now]] = prev;//\u89AA\u306E\
    \u9802\u70B9   //1\u3060\u3051\u306F\u76F4\u524D\u3082\u81EA\u5206\u30821\n  \
    \    if(hed == -1)hed = num[now];\n      head[num[now]] = hed;\n\n      bool flag\
    \ = true;\n     \n      for(int i = 0; i < G[now].size(); i++) {\n        if(num[G[now][i].to]\
    \ != -1) continue;\n        if(flag) dfs_bunkai(dfs_bunkai, G[now][i].to, num[now],\
    \ hed), flag = false;\n        else dfs_bunkai(dfs_bunkai, G[now][i].to, num[now],\
    \ -1);\n      }\n      return;\n    };\n    dfs_bunkai(dfs_bunkai, 1, 1, -1);\n\
    \  }\n  // \u632F\u308A\u7D42\u308F\u3063\u305F\n  //////////////////////////////////////////\n\
    \  \n  \n  void change(int pos, X x) { //\u5165 : \u5143\u756A\u53F7\n    pos\
    \ = num[pos];//\u632F\u308A\u5F53\u3066\u305F\u756A\u53F7\u3067\u6271\u3046\uFF01\
    \uFF01\uFF01\n    pos = size + pos - 1;\n    dat[0][pos] = update(dat[0][pos],\
    \ x);\n    dat[1][pos] = update(dat[1][pos], x);\n    while(pos >= 2) {\n    \
    \  pos >>= 1;\n      dat[0][pos] = op(dat[0][pos * 2], dat[0][pos * 2 + 1]);\n\
    \      dat[1][pos] = op(dat[1][pos * 2 + 1], dat[1][pos * 2]);\n    }\n  }\n\n\
    \  X query(int a, int b, int t) {// \u5165 : \u65B0\u756A\u53F7//\u534A\u958B\u533A\
    \u9593 t...\u7D50\u5408\u306E\u5411\u304D\n    X L = def, R = def;\n    a += size\
    \ - 1, b += size - 1;\n    while(a < b) {\n      if(t == 0) {\n        if(a &\
    \ 1) L = op(L, dat[0][a++]);\n        if(b & 1) R = op(dat[0][--b], R);\n    \
    \  }\n      else {\n        if(a & 1) R = op(dat[1][a++], R);\n        if(b &\
    \ 1) L = op(L, dat[1][--b]);\n      }\n      a >>= 1, b >>= 1;\n    }\n    return\
    \  op(L, R);\n  }\n\n  X get(int s, int t) {// \u5165 : \u5143\u756A\u53F7\n \
    \   int w = num[getLCA(s, t)];//lca\u3067\u5DE6\u53F3\u306B\u5206\u3051\u308B\n\
    \    s = num[s];\n    t = num[t];\n    X L = def, R = def;\n    while(s != w)\
    \ {//s\u306F\u306E\u307C\u308B\uFF08\u9802\u70B9\u756A\u53F7\u304C\u3067\u304B\
    \u3044\u65B9\u304B\u3089\u5C0F\u3055\u3044\u65B9\u306B\u884C\u304F)\u3002s \u2192\
    \ t \u3092\u5217\u3067\u8003\u3048\u308B\u3068\u308F\u304B\u308A\u3084\u3059\u3044\
    \u3002 s\u306F\u5DE6\u3001t\u306F\u53F3\n      int hed = max<int>(head[s], w+1);\n\
    \      L = op(L, query(hed, s+1, 1)); \n      if(hed != w)  s = par[hed];\n  \
    \    else s = w;\n    }   \n    L = op(L, query(w, w+1, 1));//\u8449\u304B\u3089\
    \u4E0A\u306E\u65B9\u3078\n    while(t != w) {//t\u306F\u304F\u3060\u308B\uFF08\
    \u9802\u70B9\u756A\u53F7\u304C\u5C0F\u3055\u3044\u65B9\u304B\u3089\u3067\u304B\
    \u3044\u65B9\u306B\u884C\u304F\uFF09\u3002\n      int hed = max<int>(head[t],\
    \ w+1);\n      R = op(query(hed, t+1, 0), R); //\u8449\u304B\u3089\u4E0A\u306E\
    \u65B9\u3078\n      if(hed != w)  t = par[hed];\n      else t = w;\n    }\n  \
    \  //R = operation(query(1, size+1, w, w+1, 1), R); \u3053\u308C\u3092\u3057\u3066\
    \u306A\u3044\u306E\u3067\u3001R\u306F\u307E\u3060LCA\u306B\u8FBF\u308A\u7740\u3044\
    \u3066\u306A\u3044\u3002\n    return op(L, R);\n  }\n\n  int getLCA(int a, int\
    \ b) {//\u5165 : \u5143\u756A\u53F7  \u51FA : \u5143\u756A\u53F7\n    a = num[a];\n\
    \    b = num[b];\n    while(true) {\n      if(a > b) swap(a, b);\n      if(head[a]\
    \ == head[b]) return numrev[a];\n      b = par[head[b]];\n    }\n  }\n\n  int\
    \ parent(int a) {//\u5165 : \u5143\u756A\u53F7\n    return numrev[par[num[a]]];\n\
    \  }\n};\n\n//\u3044\u3058\u308B\u3068\u3053\u308D\u3002\nstruct Monoid {\n \n\
    \n    friend Monoid op(const Monoid& l, const Monoid& r) {\n        Monoid res;\n\
    \      \n        return res;\n    }\n\n    friend Monoid update(const Monoid&\
    \ l, const Monoid& r) {\n    \n    }\n};\n\nMonoid def = {1, 0};\n\nstruct edge\
    \ {\n    long long to;\n\n};\n\n/*\n@brief HLD(\u53EF\u63DB)\n*/\n"
  code: "template <typename X, typename EDGE>\nstruct HL {\n  vector<int> siz;//[\u5143\
    \u306E\u9802\u70B9\u756A\u53F7] = \u30B5\u30A4\u30BA\n  vector<int> num;//[\u5143\
    \u306E\u9802\u70B9\u756A\u53F7] = \u632F\u308A\u76F4\u3057\u305F\u9802\u70B9\u756A\
    \u53F7\n  vector<int> numrev;\n  vector<int> par;//[\u632F\u3089\u308C\u305F]\
    \ = \u632F\u3089\u308C\u305F \u81EA\u5206\u306E\u89AA\n  vector<int> head;//[\u632F\
    \u3089\u308C\u305F\u756A\u53F7] = \u632F\u3089\u308C\u305F\u756A\u53F7 \u81EA\u5206\
    \u306E\u9023\u7D50\u6210\u5206\u306E\u982D\n  int N;\n  vector<vector<X>> dat;//\u30BB\
    \u30B0\u6728\u7528\u306E\u914D\u5217\u3001[0](\u756A\u53F7\u304C\u5C0F\u3055\u3044\
    , \u756A\u53F7\u304C\u3067\u304B\u3044)\u306E\u9806\u3067\u7D50\u5408   [1](\u3067\
    \u304B\u3044, \u5C0F\u3055\u3044)\n  \n  int size = 1;\n  X def;\n  \n\n  HL(int\
    \ _N, vector<vector<EDGE>>& G, X _def): N(_N), def(_def) {\n    par.resize(N+1);\n\
    \    iota(par.begin(), par.end(), 0);\n    siz.resize(N+1, 1);\n    num.assign(N+1,\
    \ -1);\n    numrev.resize(N+1, -1);\n    head.resize(N+1);\n    while(size < N)\
    \ size <<= 1;\n    dat.resize(2);\n    dat[0].assign(size*2, def), dat[1].assign(size*2,\
    \ def);\n\n    auto dfs_siz = [&](auto dfs_siz, int now, int prev) -> void {\n\
    \      int sum = 1;\n      for(int i = 0; i < G[now].size(); i++) {\n        EDGE&\
    \ e = G[now][i];\n        if(e.to == prev) continue;\n         dfs_siz(dfs_siz,\
    \ e.to, now);\n         sum += siz[e.to];\n      }\n      siz[now] = sum;\n  \
    \    return;\n    };\n    dfs_siz(dfs_siz, 1, -1);\n    for(int i = 1; i <= N;\
    \ i++) {\n      sort(G[i].begin(), G[i].end(), [&](EDGE& a, EDGE& b) {\n     \
    \   return siz[a.to] > siz[b.to];\n      });\n    }\n\n    int idx = 1;\n    auto\
    \ dfs_bunkai = [&](auto dfs_bunkai, int now, int prev, int hed) -> void {\n  \
    \    num[now] = idx;//\u756A\u53F7\u4ED8\n      numrev[idx] = now;\n      idx++;\n\
    \      par[num[now]] = prev;//\u89AA\u306E\u9802\u70B9   //1\u3060\u3051\u306F\
    \u76F4\u524D\u3082\u81EA\u5206\u30821\n      if(hed == -1)hed = num[now];\n  \
    \    head[num[now]] = hed;\n\n      bool flag = true;\n     \n      for(int i\
    \ = 0; i < G[now].size(); i++) {\n        if(num[G[now][i].to] != -1) continue;\n\
    \        if(flag) dfs_bunkai(dfs_bunkai, G[now][i].to, num[now], hed), flag =\
    \ false;\n        else dfs_bunkai(dfs_bunkai, G[now][i].to, num[now], -1);\n \
    \     }\n      return;\n    };\n    dfs_bunkai(dfs_bunkai, 1, 1, -1);\n  }\n \
    \ // \u632F\u308A\u7D42\u308F\u3063\u305F\n  //////////////////////////////////////////\n\
    \  \n  \n  void change(int pos, X x) { //\u5165 : \u5143\u756A\u53F7\n    pos\
    \ = num[pos];//\u632F\u308A\u5F53\u3066\u305F\u756A\u53F7\u3067\u6271\u3046\uFF01\
    \uFF01\uFF01\n    pos = size + pos - 1;\n    dat[0][pos] = update(dat[0][pos],\
    \ x);\n    dat[1][pos] = update(dat[1][pos], x);\n    while(pos >= 2) {\n    \
    \  pos >>= 1;\n      dat[0][pos] = op(dat[0][pos * 2], dat[0][pos * 2 + 1]);\n\
    \      dat[1][pos] = op(dat[1][pos * 2 + 1], dat[1][pos * 2]);\n    }\n  }\n\n\
    \  X query(int a, int b, int t) {// \u5165 : \u65B0\u756A\u53F7//\u534A\u958B\u533A\
    \u9593 t...\u7D50\u5408\u306E\u5411\u304D\n    X L = def, R = def;\n    a += size\
    \ - 1, b += size - 1;\n    while(a < b) {\n      if(t == 0) {\n        if(a &\
    \ 1) L = op(L, dat[0][a++]);\n        if(b & 1) R = op(dat[0][--b], R);\n    \
    \  }\n      else {\n        if(a & 1) R = op(dat[1][a++], R);\n        if(b &\
    \ 1) L = op(L, dat[1][--b]);\n      }\n      a >>= 1, b >>= 1;\n    }\n    return\
    \  op(L, R);\n  }\n\n  X get(int s, int t) {// \u5165 : \u5143\u756A\u53F7\n \
    \   int w = num[getLCA(s, t)];//lca\u3067\u5DE6\u53F3\u306B\u5206\u3051\u308B\n\
    \    s = num[s];\n    t = num[t];\n    X L = def, R = def;\n    while(s != w)\
    \ {//s\u306F\u306E\u307C\u308B\uFF08\u9802\u70B9\u756A\u53F7\u304C\u3067\u304B\
    \u3044\u65B9\u304B\u3089\u5C0F\u3055\u3044\u65B9\u306B\u884C\u304F)\u3002s \u2192\
    \ t \u3092\u5217\u3067\u8003\u3048\u308B\u3068\u308F\u304B\u308A\u3084\u3059\u3044\
    \u3002 s\u306F\u5DE6\u3001t\u306F\u53F3\n      int hed = max<int>(head[s], w+1);\n\
    \      L = op(L, query(hed, s+1, 1)); \n      if(hed != w)  s = par[hed];\n  \
    \    else s = w;\n    }   \n    L = op(L, query(w, w+1, 1));//\u8449\u304B\u3089\
    \u4E0A\u306E\u65B9\u3078\n    while(t != w) {//t\u306F\u304F\u3060\u308B\uFF08\
    \u9802\u70B9\u756A\u53F7\u304C\u5C0F\u3055\u3044\u65B9\u304B\u3089\u3067\u304B\
    \u3044\u65B9\u306B\u884C\u304F\uFF09\u3002\n      int hed = max<int>(head[t],\
    \ w+1);\n      R = op(query(hed, t+1, 0), R); //\u8449\u304B\u3089\u4E0A\u306E\
    \u65B9\u3078\n      if(hed != w)  t = par[hed];\n      else t = w;\n    }\n  \
    \  //R = operation(query(1, size+1, w, w+1, 1), R); \u3053\u308C\u3092\u3057\u3066\
    \u306A\u3044\u306E\u3067\u3001R\u306F\u307E\u3060LCA\u306B\u8FBF\u308A\u7740\u3044\
    \u3066\u306A\u3044\u3002\n    return op(L, R);\n  }\n\n  int getLCA(int a, int\
    \ b) {//\u5165 : \u5143\u756A\u53F7  \u51FA : \u5143\u756A\u53F7\n    a = num[a];\n\
    \    b = num[b];\n    while(true) {\n      if(a > b) swap(a, b);\n      if(head[a]\
    \ == head[b]) return numrev[a];\n      b = par[head[b]];\n    }\n  }\n\n  int\
    \ parent(int a) {//\u5165 : \u5143\u756A\u53F7\n    return numrev[par[num[a]]];\n\
    \  }\n};\n\n//\u3044\u3058\u308B\u3068\u3053\u308D\u3002\nstruct Monoid {\n \n\
    \n    friend Monoid op(const Monoid& l, const Monoid& r) {\n        Monoid res;\n\
    \      \n        return res;\n    }\n\n    friend Monoid update(const Monoid&\
    \ l, const Monoid& r) {\n    \n    }\n};\n\nMonoid def = {1, 0};\n\nstruct edge\
    \ {\n    long long to;\n\n};\n\n/*\n@brief HLD(\u53EF\u63DB)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Graph/hld2.cpp
  requiredBy: []
  timestamp: '2024-05-10 23:04:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Graph/hld2.cpp
layout: document
redirect_from:
- /library/Graph/hld2.cpp
- /library/Graph/hld2.cpp.html
title: "HLD(\u53EF\u63DB)"
---
