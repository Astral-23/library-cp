---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Graph/hld.hpp
    title: "HLD(\u975E\u53EF\u63DB)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"verify/hld_path.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\n#line 1 \"Graph/hld.hpp\"\ntemplate<typename\
    \ T>\nstruct SegTree {\n    int n;\n    vector<T> dat;\n   \n    SegTree(){}\n\
    \         \n    SegTree(int siz) {\n        n = 1;\n        while(n < siz) n <<=\
    \ 1;\n        dat.resize(n * 2, T::ide());\n    }\n\n    private:\n         \n\
    \        T query(int l, int r) {\n            T L = T::ide(), R = T::ide();\n\
    \            l += n - 1, r += n - 1;\n            while(l < r) {\n           \
    \     if(l & 1) L = op(L, dat[l++]);\n                if(r & 1) R = op(dat[--r],\
    \ R);\n                l >>= 1, r >>= 1;\n            }  \n            return\
    \  op(L, R);\n        }\n\n    \n    public:\n\n        void set(int pos, T x)\
    \ {\n            pos += n-1;\n            dat[pos] = x;\n        }\n         \
    \ \n        void init() {\n            for(int i = n-1; i >= 1; i--)  dat[i] =\
    \ op(dat[i<<1], dat[(i<<1) + 1]);\n        }\n          \n        void change(int\
    \ pos, T x) {\n            pos += n - 1;\n            dat[pos] = update(dat[pos],\
    \ x);\n            while(pos >= 2) {\n                pos >>= 1;\n           \
    \     dat[pos] = op(dat[pos<<1], dat[pos<<1|1]);\n            }\n        }\n \
    \        \n        T get(int l, int r) {// [l, r]\u306E\u6F14\u7B97\u7D50\u679C\
    \u3002\n            return query(l, r+1);\n        }\n\n        T operator[](int\
    \ pos) {\n            return dat[pos + n - 1];\n        }\n         \n};\n\n\n\
    \ntemplate <typename X>\nstruct HLD {\n    vector<int> siz;\n    vector<int> in;\n\
    \tvector<int> rev;\n    vector<int> out;\n    vector<int> par;\n    vector<int>\
    \ head;\n    SegTree<X> seg;\n    int N;\n    int size = 1;\n\tint root;\n   \
    \ \n  \n    HLD(vector<vector<int>>& G, int _root) : root(_root) {\n\t\tN = int(G.size())\
    \ - 1;\n        par.resize(N+1);\n        iota(par.begin(), par.end(), 0);\n \
    \       siz.resize(N+1, 1);\n        in.assign(N+1, -1);\n        rev.resize(N+1,\
    \ -1);\n        out.resize(N+1, -1);\n        head.resize(N+1);\n        seg =\
    \ SegTree<X>(N);\n    \n        auto dfs_siz = [&](auto f, int now, int prev)\
    \ -> void {\n            int sum = 1;\n            for(int to : G[now]) {\n  \
    \              if(to == prev) continue;\n                f(f, to, now);\n    \
    \            sum += siz[to];\n            }\n            siz[now] = sum;\n   \
    \         return;\n        };\n        dfs_siz(dfs_siz, root, -1);\n        for(int\
    \ i = 0; i <= N; i++) {\n          sort(G[i].begin(), G[i].end(), [&](int a, int\
    \ b) {\n            return siz[a] > siz[b];\n          });\n        }\n    \n\
    \        int idx = 1;\n        auto dfs_bunkai = [&](auto f, int now, int prev,\
    \ int hed) -> void {\n            in[now] = idx;//\u756A\u53F7\u4ED8\n       \
    \     rev[idx] = now;\n            idx++;\n            par[now] = prev;//\u89AA\
    \u306E\u9802\u70B9   //1\u3060\u3051\u306F\u76F4\u524D\u3082\u81EA\u5206\u3082\
    1\n            if(hed == -1)hed = now;\n            head[now] = hed;\n      \n\
    \            bool flag = true;\n            \n            for(int i = 0; i <=\
    \ int(G[now].size()) - 1; i++) {\n                if(in[G[now][i]] != -1) continue;\n\
    \                if(flag) f(f, G[now][i], now, hed), flag = false;\n         \
    \       else f(f, G[now][i], now, -1);\n            }\n            out[now] =\
    \ idx;\n            return;\n        };\n        dfs_bunkai(dfs_bunkai, root,\
    \ root, -1);\n    }\n\n\n    private:\n\n\t   \n\n        X get__(int u, int v)\
    \ {\n            int w = getLCA(u, v);//lca\u3067\u5DE6\u53F3\u306B\u5206\u3051\
    \u308B\n            X L = X::ide(), R = X::ide();\n            while(u != w) {\n\
    \                int hed = max<int>(in[head[u]], in[w]+1);//w\u307E\u3067\u767B\
    \u308B\u3068\u3001w\u3092\u5DE6\u53F3\u30672\u56DE\u30AB\u30A6\u30F3\u30C8\u3057\
    \u3066\u3057\u307E\u3046\u3002\n                L = op(seg.get(hed, in[u]), L);\
    \ //\u6839\u304B\u3089\u4E0A\u306E\u65B9\u3078\n                u = par[rev[hed]];\n\
    \            }   \n            L = op(seg.get(in[w], in[w]),  L);//\u6839\u304B\
    \u3089\u4E0A\u306E\u65B9\u3078\n            while(v != w) {\n                int\
    \ hed = max<int>(in[head[v]], in[w]+1);\n                R = op(seg.get(hed, in[v]),\
    \ R); //\u6839\u304B\u3089\u4E0A\u306E\u65B9\u3078\n                v = par[rev[hed]];\n\
    \            }\n            return op(L, R);//\u4EA4\u63DB\u5247\u3092\u8981\u3059\
    \u308B\u6642\u306F\u3053\u306E\u884C\u3092\u5909\u66F4\u3059\u308B\u5FC5\u8981\
    \u304C\u3042\u308B\u304B\u3082\u3057\u308C\u306A\u3044 : \u7121\u3044\u3068\u601D\
    \u3046\u304Cr\n        }\n    \n    public:\n\n        void set(int pos, X x)\
    \ {\n            seg.set(in[pos], x);\n        }\n\n        void init() {\n  \
    \          seg.init();\n        }\n\n        void change(int pos, X x) {\n   \
    \         seg.change(in[pos], x);\n        }\n\n        X get(int u, int v) {\n\
    \            return get__(u, v);\n        }\n\n        X subtree(int v) {\n  \
    \          return seg.get(in[v],  out[v]-1);\n        }\n  \n        int getLCA(int\
    \ a, int b) {\n            while(true) {\n                if(in[a] > in[b]) swap(a,\
    \ b);\n                if(head[a] == head[b]) return a;\n                b = par[head[b]];\n\
    \            }\n        }\n      \n        int parent(int a) {\n            return\
    \ par[a];\n        }\n\n\t\tvoid dump() {\n\t\t\tfor(int i = 1; i <= N; i++) {\n\
    \t\t\t\tcout << seg.get(in[i], in[i]).a << \" \";\n\t\t\t}\n\t\t\tcout << endl;\n\
    \t\t}\n\n        /*\n        HLD<Monoid> hld(G, root)  \u7A7A\u9593 O(N)\n\t\t\
    @brief HLD(\u975E\u53EF\u63DB)\n\t\tget(u, v) ... path(u, v)\u306E\u9802\u70B9\
    \u306E\u30E2\u30CE\u30A4\u30C9\u7A4D  O(log^2)\n\t\tchange(v) ... v\u3092\u5909\
    \u66F4 O(log)\n\t\tsubtree(v) ... v\u3092\u542B\u3080\u3001v\u306E\u90E8\u5206\
    \u6728\u306E\u30E2\u30CE\u30A4\u30C9\u7A4D O(log)\n        \n        \n      \
    \  out\u306F\u534A\u958B\u533A\u9593\u3002\n        \n        */\n};  \n\n#line\
    \ 5 \"verify/hld_path.test.cpp\"\nusing ll = long long;\nusing vvl = vector<vector<ll>>;\n\
    using vl = vector<ll>;\n#define rep(i, s, f) for(long long i = s; i <= f; i++)\n\
    #define ENDL '\\n'\n\n\nstruct Monoid {\n    long long a;\n   \n    Monoid(){}\n\
    \      \n    Monoid(long long _a) : a(_a) {\n      \n    }\n\n    friend Monoid\
    \ op(const Monoid& l, const Monoid& r) {\n      return l.a + r.a;\n    }\n\n \
    \   friend Monoid update(const Monoid& l, const Monoid& r) {\n        return l.a\
    \ + r.a;\n    }\n\n    static Monoid ide() {\n       return 0LL;\n    }\n    \n\
    };\n\n\nint main() {\n    ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    cout << fixed << setprecision(15);\n    int N;\n    cin >> N;\n    int Q;\n\
    \    cin >> Q;\n    vector<int> A(N+1);\n    for(int i = 1; i <= N; i++)cin >>\
    \ A[i];\n    vector<vector<int>> G(N+1);\n    for(int i = 1; i <= N-1; i++) {\n\
    \        int u, v;\n        cin >> u >> v;\n        u++, v++;\n        G[u].push_back(v);\n\
    \        G[v].push_back(u);\n    }\n\n    HLD<Monoid> hld(G, 1);\n\n    for(int\
    \ i = 1; i <= N; i++) hld.set(i, A[i]);\n    hld.init();\n\n    while(Q--) {\n\
    \        int t;\n        cin >> t;\n        if(t == 0){\n            long long\
    \ p, x;\n            cin >> p >> x;\n            p++;\n            hld.change(p,\
    \ x);\n        }\n        else {\n            int u, v;\n            cin >> u\
    \ >> v;\n            u++, v++;\n            cout << hld.get(u, v).a << '\\n';\n\
    \n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    #include<bits/stdc++.h>\nusing namespace std;\n#include \"../Graph/hld.hpp\"\n\
    using ll = long long;\nusing vvl = vector<vector<ll>>;\nusing vl = vector<ll>;\n\
    #define rep(i, s, f) for(long long i = s; i <= f; i++)\n#define ENDL '\\n'\n\n\
    \nstruct Monoid {\n    long long a;\n   \n    Monoid(){}\n      \n    Monoid(long\
    \ long _a) : a(_a) {\n      \n    }\n\n    friend Monoid op(const Monoid& l, const\
    \ Monoid& r) {\n      return l.a + r.a;\n    }\n\n    friend Monoid update(const\
    \ Monoid& l, const Monoid& r) {\n        return l.a + r.a;\n    }\n\n    static\
    \ Monoid ide() {\n       return 0LL;\n    }\n    \n};\n\n\nint main() {\n    ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    cout << fixed << setprecision(15);\n    int N;\n\
    \    cin >> N;\n    int Q;\n    cin >> Q;\n    vector<int> A(N+1);\n    for(int\
    \ i = 1; i <= N; i++)cin >> A[i];\n    vector<vector<int>> G(N+1);\n    for(int\
    \ i = 1; i <= N-1; i++) {\n        int u, v;\n        cin >> u >> v;\n       \
    \ u++, v++;\n        G[u].push_back(v);\n        G[v].push_back(u);\n    }\n\n\
    \    HLD<Monoid> hld(G, 1);\n\n    for(int i = 1; i <= N; i++) hld.set(i, A[i]);\n\
    \    hld.init();\n\n    while(Q--) {\n        int t;\n        cin >> t;\n    \
    \    if(t == 0){\n            long long p, x;\n            cin >> p >> x;\n  \
    \          p++;\n            hld.change(p, x);\n        }\n        else {\n  \
    \          int u, v;\n            cin >> u >> v;\n            u++, v++;\n    \
    \        cout << hld.get(u, v).a << '\\n';\n\n        }\n    }\n}"
  dependsOn:
  - Graph/hld.hpp
  isVerificationFile: true
  path: verify/hld_path.test.cpp
  requiredBy: []
  timestamp: '2024-05-11 03:44:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/hld_path.test.cpp
layout: document
redirect_from:
- /verify/verify/hld_path.test.cpp
- /verify/verify/hld_path.test.cpp.html
title: verify/hld_path.test.cpp
---
