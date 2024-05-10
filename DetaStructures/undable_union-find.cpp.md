---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "undo\u53EF\u80FDunion_find"
    links: []
  bundledCode: "#line 1 \"DetaStructures/undable_union-find.cpp\"\nstruct Union {\
    \   \n\tprivate:\n\t    struct data {\n            int a, b;\n\t\t\tint par_b;\n\
    \t\t\tint siz_a;\n\t\t\tint edge_a;\n\n\t\t\tdata(){}\n\t\t\tdata(int _a, int\
    \ _b, int _par_b, int _siz_a, int _edge_a) : a(_a), b(_b), par_b(_par_b), siz_a(_siz_a),\
    \ edge_a(_edge_a){}\n        };\n\n\tpublic:\n     \tusing vi = vector<int>;\n\
    \t\tvi par;\n\t\tvi size;\n\t\tvi edge;\n\t\tstack<data> history;\n\t\tint cc;\n\
    \n    \n        Union(int N) {\n            par.resize(N);\n            iota(par.begin(),\
    \ par.end(), 0);\n            size.assign(N, 1);\n            edge.assign(N, 0);\n\
    \t\t\tcc = N;\n        }\n      \n        int root(int u) {\n          while (par[u]\
    \ != u) {\n              u = par[u];\n          }    \n          return u;\n \
    \       }\n        \n        bool same(int a, int b) {\n            if (root(a)\
    \ == root(b)) {\n                return true;\n            }\n            return\
    \ false;\n        }\n        \n        bool unit(int a, int b) {\n           \
    \ a = root(a), b = root(b);\n            if(size[a] < size[b]) swap(a, b);\n\t\
    \t    history.push(data(a, b, par[b], size[a], edge[a]));   \n\t\t\t \n\t\t  \
    \  if(a==b) {\n\t\t\t\tedge[a]++;\n\t\t\t\treturn false;\n\t\t    }\n\n\t\t\t\
    cc--;\n\t\t\tpar[b] = a;\n\t\t\tsize[a] += size[b];\n\t\t\tedge[a] += edge[b];\n\
    \t\t\tedge[a]++;\n\t\t\treturn true;\n        }\n      \n        void undo() {\n\
    \t\t\tdata pre = history.top();\n\t\t\thistory.pop();\n\t\t\tpar[pre.b] = pre.par_b;\n\
    \t\t\tsize[pre.a] = pre.siz_a;\n\t\t\tedge[pre.a] = pre.edge_a;\n\t\t\tif(pre.a\
    \ != pre.b) cc++;\n        }\n\n\n        int getsize(int u) {\n            return\
    \ size[root(u)];\n        }\n\n\t\tint component_count() {\n\t\t\treturn cc;\n\
    \t\t}\n\n\t\t/*  0-indexed\n\t\t    Union(N) O(N)\n\t\t\t@brief undo\u53EF\u80FD\
    union_find\n\t\t\troot(u), same(a, b), unit(a, b) ... O(logN)\n\t\t\tundo() ...\
    \ O(1)\n\t\t\tgetsize(u) ... u\u3092\u542B\u3080\u9023\u7D50\u6210\u5206\u306E\
    \u30B5\u30A4\u30BA O(1)\n\t\t\tcomponent_count() ... \u9023\u7D50\u6210\u5206\u306E\
    \u500B\u6570\u3092\u623B\u3059\u3002\u30CE\u30FC\u30920\u3092\u542B\u3093\u3067\
    \u3044\u308B\u4E8B\u306B\u6CE8\u610F\u3002 O(1)\u3002\u672Averified\n\n\t\t\t\u6CE8\
    \u610F\uFF1Aundo\u306F\u3001\u76F4\u524D\u306Eunit\u3092\u547C\u3076\u76F4\u524D\
    \u306E\u72B6\u614B\u306B\u623B\u3059\u3068\u3044\u3046\u3053\u3068\u3002\n\t\t\
    \    unit(a, b)\u3092\u547C\u3093\u3060\u969B\u306Ba, b\u304C\u540C\u3058\u9023\
    \u7D50\u6210\u5206\u304B\u3069\u3046\u304B\u306F\u95A2\u4FC2\u304C\u306A\u3044\
    \u3002\n\t\t*/\n      \n};\n"
  code: "struct Union {   \n\tprivate:\n\t    struct data {\n            int a, b;\n\
    \t\t\tint par_b;\n\t\t\tint siz_a;\n\t\t\tint edge_a;\n\n\t\t\tdata(){}\n\t\t\t\
    data(int _a, int _b, int _par_b, int _siz_a, int _edge_a) : a(_a), b(_b), par_b(_par_b),\
    \ siz_a(_siz_a), edge_a(_edge_a){}\n        };\n\n\tpublic:\n     \tusing vi =\
    \ vector<int>;\n\t\tvi par;\n\t\tvi size;\n\t\tvi edge;\n\t\tstack<data> history;\n\
    \t\tint cc;\n\n    \n        Union(int N) {\n            par.resize(N);\n    \
    \        iota(par.begin(), par.end(), 0);\n            size.assign(N, 1);\n  \
    \          edge.assign(N, 0);\n\t\t\tcc = N;\n        }\n      \n        int root(int\
    \ u) {\n          while (par[u] != u) {\n              u = par[u];\n         \
    \ }    \n          return u;\n        }\n        \n        bool same(int a, int\
    \ b) {\n            if (root(a) == root(b)) {\n                return true;\n\
    \            }\n            return false;\n        }\n        \n        bool unit(int\
    \ a, int b) {\n            a = root(a), b = root(b);\n            if(size[a] <\
    \ size[b]) swap(a, b);\n\t\t    history.push(data(a, b, par[b], size[a], edge[a]));\
    \   \n\t\t\t \n\t\t    if(a==b) {\n\t\t\t\tedge[a]++;\n\t\t\t\treturn false;\n\
    \t\t    }\n\n\t\t\tcc--;\n\t\t\tpar[b] = a;\n\t\t\tsize[a] += size[b];\n\t\t\t\
    edge[a] += edge[b];\n\t\t\tedge[a]++;\n\t\t\treturn true;\n        }\n      \n\
    \        void undo() {\n\t\t\tdata pre = history.top();\n\t\t\thistory.pop();\n\
    \t\t\tpar[pre.b] = pre.par_b;\n\t\t\tsize[pre.a] = pre.siz_a;\n\t\t\tedge[pre.a]\
    \ = pre.edge_a;\n\t\t\tif(pre.a != pre.b) cc++;\n        }\n\n\n        int getsize(int\
    \ u) {\n            return size[root(u)];\n        }\n\n\t\tint component_count()\
    \ {\n\t\t\treturn cc;\n\t\t}\n\n\t\t/*  0-indexed\n\t\t    Union(N) O(N)\n\t\t\
    \t@brief undo\u53EF\u80FDunion_find\n\t\t\troot(u), same(a, b), unit(a, b) ...\
    \ O(logN)\n\t\t\tundo() ... O(1)\n\t\t\tgetsize(u) ... u\u3092\u542B\u3080\u9023\
    \u7D50\u6210\u5206\u306E\u30B5\u30A4\u30BA O(1)\n\t\t\tcomponent_count() ... \u9023\
    \u7D50\u6210\u5206\u306E\u500B\u6570\u3092\u623B\u3059\u3002\u30CE\u30FC\u3092\
    0\u3092\u542B\u3093\u3067\u3044\u308B\u4E8B\u306B\u6CE8\u610F\u3002 O(1)\u3002\
    \u672Averified\n\n\t\t\t\u6CE8\u610F\uFF1Aundo\u306F\u3001\u76F4\u524D\u306Eunit\u3092\
    \u547C\u3076\u76F4\u524D\u306E\u72B6\u614B\u306B\u623B\u3059\u3068\u3044\u3046\
    \u3053\u3068\u3002\n\t\t    unit(a, b)\u3092\u547C\u3093\u3060\u969B\u306Ba, b\u304C\
    \u540C\u3058\u9023\u7D50\u6210\u5206\u304B\u3069\u3046\u304B\u306F\u95A2\u4FC2\
    \u304C\u306A\u3044\u3002\n\t\t*/\n      \n};"
  dependsOn: []
  isVerificationFile: false
  path: DetaStructures/undable_union-find.cpp
  requiredBy: []
  timestamp: '2024-05-10 22:41:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DetaStructures/undable_union-find.cpp
layout: document
redirect_from:
- /library/DetaStructures/undable_union-find.cpp
- /library/DetaStructures/undable_union-find.cpp.html
title: "undo\u53EF\u80FDunion_find"
---
