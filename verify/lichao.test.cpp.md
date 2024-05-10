---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: DataStructures/li_chao_tree.hpp
    title: Li chao tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/line_add_get_min
    links:
    - https://judge.yosupo.jp/problem/line_add_get_min
  bundledCode: "#line 1 \"verify/lichao.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\n#line 1 \"DataStructures/li_chao_tree.hpp\"\
    \ntemplate<typename T>\nstruct li_chao_tree {\n    struct line {\n        T a,\
    \ b; // y = ax + b\n        line (T _a, T _b) : a(_a), b(_b) {}\n        bool\
    \ operator==(const line &c) {return a == c.a && b == c.b;}\n        bool operator!=(const\
    \ line& c) {return !(a == *this);}\n        T operator()(T x) const {return a\
    \ * x + b;}\n    };\n\n    int siz = 1;\n    vector<line> dat;\n    vector<T>\
    \ X;//\u30AF\u30A8\u30EA\u3067\u805E\u304B\u308C\u308Bx\u5EA7\u6A19 sorted &&\
    \ unique\u6E08\u307F\u524D\u63D0\n    T M = numeric_limits<T>::max();\n\n  \n\
    \    li_chao_tree (vector<T> &xs) { \n        while(siz < xs.size()) siz <<= 1;\n\
    \        dat.resize(siz<<1, line(0, M));\n        X.resize(siz+1, M);\n      \
    \  X[0] = -M;\n        for(int i = 1; i <= int(xs.size()); i++) X[i] = xs[i-1];\n\
    \    }\n  \n    void add_line_query(line nw, long long l, long long r, int idx)\
    \ {\n        int m = (l + r)/2;\n        if(dat[idx] == line(0, M)) {\n      \
    \      dat[idx] = nw;\n            return ; \n        }    \n\n        T lx =\
    \ X[l], mx = X[m], rx = X[r-1];\n        bool lef = (nw(lx) < dat[idx](lx));\n\
    \        bool mid = (nw(mx) < dat[idx](mx));\n        bool rig = (nw(rx) < dat[idx](rx));\n\
    \  \n        if(lef && rig) {\n            dat[idx] = nw;\n            return;\n\
    \        }\n        if(!lef && !rig) return;\n        if(mid)swap(dat[idx], nw);\n\
    \        if(lef != mid) add_line_query(nw, l, m, idx<<1);\n        else add_line_query(nw,\
    \ m, r, idx<<1|1);\n        \n    }\n  \n    T get_query(T id) {\n        T x\
    \ = X[id];\n        id += siz-1;\n        T res = numeric_limits<T>::max();\n\
    \        while(id >= 1) {\n            res = min(res, dat[id](x));\n         \
    \   id >>= 1;\n        }\n        return res;\n    }\n  \n    void add_line(T\
    \ a, T b) {\n        line nw(a, b);\n        add_line_query(nw, 1, siz + 1, 1);\n\
    \     }\n\n    T get(T x) {\n        int id = lower_bound(X.begin(), X.end(),\
    \ x) - X.begin();\n        return get_query(id);\n    }\n\n};\n\n/*\n@brief Li\
    \ chao tree\n*/\n#line 5 \"verify/lichao.test.cpp\"\nusing ll = long long;\nusing\
    \ vvl = vector<vector<ll>>;\nusing vl = vector<ll>;\n#define rep(i, s, f) for(long\
    \ long i = s; i <= f; i++)\n#define ENDL '\\n'\n\n\nstruct que {\n    ll t, a,\
    \ b;\n    que(int _t, ll _a, ll _b) : t(_t), a(_a), b(_b){}\n    que(){}\n};\n\
    \nint main() {\n  ios::sync_with_stdio(false);\n  std::cin.tie(nullptr);\n  cout\
    \ << fixed << setprecision(15);\n\n\n  ll N, Q;\n    cin >> N >> Q;\n    vl A(N+1),\
    \ B(N+1);\n    rep(i,1,N) {\n        ll a, b;\n        cin >> a >> b;\n      \
    \  A[i] = a, B[i] = b;\n    }\n    vector<que> qs(Q+1);\n    vector<ll> xs;\n\n\
    \    rep(qi, 1, Q) {\n        ll t, a, b;\n        cin >> t;\n        if(t ==\
    \ 0) {\n            cin >> a >> b;\n        }\n        else cin >> a;\n      \
    \  qs[qi] = que(t, a, b);\n\n        if(t == 1) {\n            xs.push_back(a);\n\
    \        }\n    }\n    sort(xs.begin(), xs.end());\n    unique(xs.begin(), xs.end());\n\
    \    li_chao_tree<ll> tr(xs);\n    rep(i,1,N) {\n        tr.add_line(A[i], B[i]);\n\
    \    }\n\n    rep(qi, 1, Q) {\n        auto [t, a, b] = qs[qi];\n        if(t\
    \ == 0) {\n            tr.add_line(a, b);\n        }\n        else {\n       \
    \     cout << tr.get(a) << ENDL;\n        }\n    }\n    \n    \n  \n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/line_add_get_min\"\n#include<bits/stdc++.h>\n\
    using namespace std;\n#include \"../DataStructures/li_chao_tree.hpp\"\nusing ll\
    \ = long long;\nusing vvl = vector<vector<ll>>;\nusing vl = vector<ll>;\n#define\
    \ rep(i, s, f) for(long long i = s; i <= f; i++)\n#define ENDL '\\n'\n\n\nstruct\
    \ que {\n    ll t, a, b;\n    que(int _t, ll _a, ll _b) : t(_t), a(_a), b(_b){}\n\
    \    que(){}\n};\n\nint main() {\n  ios::sync_with_stdio(false);\n  std::cin.tie(nullptr);\n\
    \  cout << fixed << setprecision(15);\n\n\n  ll N, Q;\n    cin >> N >> Q;\n  \
    \  vl A(N+1), B(N+1);\n    rep(i,1,N) {\n        ll a, b;\n        cin >> a >>\
    \ b;\n        A[i] = a, B[i] = b;\n    }\n    vector<que> qs(Q+1);\n    vector<ll>\
    \ xs;\n\n    rep(qi, 1, Q) {\n        ll t, a, b;\n        cin >> t;\n       \
    \ if(t == 0) {\n            cin >> a >> b;\n        }\n        else cin >> a;\n\
    \        qs[qi] = que(t, a, b);\n\n        if(t == 1) {\n            xs.push_back(a);\n\
    \        }\n    }\n    sort(xs.begin(), xs.end());\n    unique(xs.begin(), xs.end());\n\
    \    li_chao_tree<ll> tr(xs);\n    rep(i,1,N) {\n        tr.add_line(A[i], B[i]);\n\
    \    }\n\n    rep(qi, 1, Q) {\n        auto [t, a, b] = qs[qi];\n        if(t\
    \ == 0) {\n            tr.add_line(a, b);\n        }\n        else {\n       \
    \     cout << tr.get(a) << ENDL;\n        }\n    }\n    \n    \n  \n}\n"
  dependsOn:
  - DataStructures/li_chao_tree.hpp
  isVerificationFile: true
  path: verify/lichao.test.cpp
  requiredBy: []
  timestamp: '2024-05-11 03:49:52+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/lichao.test.cpp
layout: document
redirect_from:
- /verify/verify/lichao.test.cpp
- /verify/verify/lichao.test.cpp.html
title: verify/lichao.test.cpp
---
