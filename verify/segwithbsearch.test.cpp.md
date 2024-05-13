---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: DataStructures/SegTree_with_binary-search.hpp
    title: "\u30BB\u30B0\u6728 + \u4E8C\u5206\u63A2\u7D22"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/predecessor_problem
    links:
    - https://judge.yosupo.jp/problem/predecessor_problem
  bundledCode: "#line 1 \"verify/segwithbsearch.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\n#line 1 \"DataStructures/SegTree_with_binary-search.hpp\"\
    \ntemplate<typename T>\nstruct SegTree {\n    int n;\n    vector<T> dat;\n\n \
    \        \n    SegTree(int siz) {\n        n = 1;\n        while(n < siz) n <<=\
    \ 1;\n        dat.resize(n * 2, T::ide());\n    }\n\n    private:\n         \n\
    \        T query(int l, int r) {\n            T L = T::ide(), R = T::ide();\n\
    \            l += n - 1, r += n - 1;\n            while(l < r) {\n           \
    \     if(l & 1) L = op(L, dat[l++]);\n                if(r & 1) R = op(dat[--r],\
    \ R);\n                l >>= 1, r >>= 1;\n            }  \n            return\
    \  op(L, R);\n        }\n\n\t\ttemplate<class F> \n\t\tint min_right__(int L,\
    \ F f) {//\u521D\u3081\u3066true\u306B\u306A\u308B\u30A4\u30F3\u30C7\u30C3\u30AF\
    \u30B9\u3002\u4F46\u3057\u3001\u3069\u3093\u306A\u306B\u53F3\u7AEF\u3092\u4F38\
    \u3070\u3057\u3066\u3082true\u306B\u306A\u3089\u306A\u3044\u306A\u3089-1\n\t\t\
    \    if(!f(get(L, n))) return -1;\n\n\t\t\tint l = L + n - 1;\n\t\t\tT res = T::ide();\n\
    \t\t\twhile(true) {\n\t\t\t\tif(l&1) {\n\t\t\t\t\tif(f(op(res, dat[l]))) break;\n\
    \t\t\t\t\telse res = op(res, dat[l++]);\n\t\t\t\t}\n\t\t\t\tl >>= 1;\n\t\t\t}\n\
    \n\t\t\twhile(l < n) {//\u5DE6\u3092\u8DB3\u3057\u3066true\u306A\u3089\u5DE6\u3002\
    \u305D\u3046\u3058\u3083\u306A\u3044\u306A\u3089\u53F3\u3002\n\t\t\t    if(f(op(res,\
    \ dat[l<<1]))) {\n\t\t\t\t\tl <<= 1;\n\t\t\t\t}\n\t\t\t\telse {\n\t\t\t\t\tres\
    \ = op(res, dat[l<<1]);\n\t\t\t\t\tl = l << 1 | 1;\n\t\t\t\t}\n\t\t\t}\n\t\t\t\
    //index\u3092\u8FD4\u3059\u3002\n\t\t\t//\u4ECA\u3044\u308Bindex\u304C\u305D\u3046\
    \u3067\u3042\u308B\u3002\n\t\t\treturn l - (n-1);\n\t\t}\n\n\t\ttemplate<class\
    \ F>\n\t\tint max_left__(int R, F f) {//\u521D\u3081\u3066true\u306B\u306A\u308B\
    \u30A4\u30F3\u30C7\u30C3\u30AF\u30B9\u3002\u3069\u3053\u307E\u3067\u4F38\u3070\
    \u3057\u3066\u3082false\u306A\u3089-1\n\t\t    if(!f(get(1, R))) return -1;\n\n\
    \t\t\tint r = R + n - 1;\n\t\t\tT res = T::ide();\n\n\t\t\twhile(true) {\n\t\t\
    \t\tif(!(r&1) || r==1) {\n\t\t\t\t\tif(f(op(dat[r], res))) break;\n\t\t\t    \
    \    else res = op(dat[r--], res);\n\t\t\t\t}\n\t\t\t\tr >>= 1;\n\t\t\t}\n\n\t\
    \t\twhile(r < n) {\n\t\t\t\tif(f(op(dat[r<<1|1], res))) {\n\t\t\t\t\tr = r<<1|1;\n\
    \t\t\t\t}\n\t\t\t\telse {\n\t\t\t\t\tres = op(dat[r<<1|1], res);\n\t\t\t\t\tr\
    \ <<= 1;\n\t\t\t\t}\n\t\t\t}\n\n\t\t\treturn r - (n-1);\n\t\t}\n\n    public:\n\
    \n        void set(int pos, T x) {\n            pos += n-1;\n            dat[pos]\
    \ = x;\n        }\n          \n        void init() {\n            for(int i =\
    \ n-1; i >= 1; i--)  dat[i] = op(dat[i<<1], dat[i<<1|1]);\n        }\n       \
    \   \n        void change(int pos, T x) {\n            pos += n - 1;\n       \
    \     dat[pos] = update(dat[pos], x);\n            while(pos >= 2) {\n       \
    \         pos >>= 1;\n                dat[pos] = op(dat[pos<<1], dat[pos<<1|1]);\n\
    \            }\n        }\n         \n        T get(int l, int r) {// [l, r]\u306E\
    \u6F14\u7B97\u7D50\u679C\u3002\n            return query(l, r+1);\n        }\n\
    \n        T operator[](int pos) {\n            return dat[pos + n - 1];\n    \
    \    }\n\n\t\ttemplate<class F>\n\t\tint min_right(int L, F f) {\n\t\t\treturn\
    \ min_right__(L, f);\n\t\t}\n\n\t\ttemplate<class F>\n\t\tint max_left(int R,\
    \ F f) {\n\t\t\treturn max_left__(R, f);\n\t\t}\n         \n};\n\n/*\n@brief \u30BB\
    \u30B0\u6728 + \u4E8C\u5206\u63A2\u7D22\n*/\n#line 5 \"verify/segwithbsearch.test.cpp\"\
    \nusing ll = long long;\nusing vvl = vector<vector<ll>>;\nusing vl = vector<ll>;\n\
    #define rep(i, s, f) for(long long i = s; i <= f; i++)\n#define ENDL '\\n'\n\n\
    \n\nstruct Monoid {\n    int a;\n   \n    Monoid(){}\n      \n    Monoid(int _a)\
    \ : a(_a) {\n      \n    }\n\n    friend Monoid op(const Monoid& l, const Monoid&\
    \ r) {\n        return l.a + r.a;\n    }\n\n    friend Monoid update(const Monoid&\
    \ l, const Monoid& r) {\n\t\treturn r;\n   \n    }\n\n    static Monoid ide()\
    \ {\n       return 0LL;\n    }\n};\n\n\nint nex(const Monoid& now) {\n\treturn\
    \ now.a >= 1;\n}\n\n\nint main() {\n\tios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    int N, Q;\n    cin >> N >> Q;\n\tSegTree<Monoid> seg(N);\n\tstring T;\n\t\
    cin >> T;\n\trep(i, 0, N-1) {\n\t\tif(T[i] == '1') seg.set(i+1, 1);\n\t}\n\tseg.init();\n\
    \n\twhile(Q--) {\n        int t, k;\n        cin >> t >> k;\n        if(t==0)\
    \ {\n            seg.change(k+1, 1);\n        }\n        else if(t==1) {\n\t\t\
    \tseg.change(k+1, 0);\n        }\n        else if(t==2) {\n            if(seg.get(k+1,\
    \ k+1).a) cout << 1 << '\\n';\n            else cout << 0 << '\\n';\n        }\n\
    \        else if(t==3) {\n\t\t\tint res = seg.min_right(k+1, nex);\n\t\t    if(res==-1)\
    \ cout << -1 << '\\n';\n\t\t\telse cout << res-1 << '\\n';\n        }\n      \
    \  else {\n           int res = seg.max_left(k+1, nex);\n\t\t   if(res==-1) cout\
    \ << -1 << '\\n';\n\t\t   else cout << res-1 << '\\n';\n\t\t}\n    }\n}\n\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/predecessor_problem\"\n\
    #include<bits/stdc++.h>\nusing namespace std;\n#include \"../DataStructures/SegTree_with_binary-search.hpp\"\
    \nusing ll = long long;\nusing vvl = vector<vector<ll>>;\nusing vl = vector<ll>;\n\
    #define rep(i, s, f) for(long long i = s; i <= f; i++)\n#define ENDL '\\n'\n\n\
    \n\nstruct Monoid {\n    int a;\n   \n    Monoid(){}\n      \n    Monoid(int _a)\
    \ : a(_a) {\n      \n    }\n\n    friend Monoid op(const Monoid& l, const Monoid&\
    \ r) {\n        return l.a + r.a;\n    }\n\n    friend Monoid update(const Monoid&\
    \ l, const Monoid& r) {\n\t\treturn r;\n   \n    }\n\n    static Monoid ide()\
    \ {\n       return 0LL;\n    }\n};\n\n\nint nex(const Monoid& now) {\n\treturn\
    \ now.a >= 1;\n}\n\n\nint main() {\n\tios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    int N, Q;\n    cin >> N >> Q;\n\tSegTree<Monoid> seg(N);\n\tstring T;\n\t\
    cin >> T;\n\trep(i, 0, N-1) {\n\t\tif(T[i] == '1') seg.set(i+1, 1);\n\t}\n\tseg.init();\n\
    \n\twhile(Q--) {\n        int t, k;\n        cin >> t >> k;\n        if(t==0)\
    \ {\n            seg.change(k+1, 1);\n        }\n        else if(t==1) {\n\t\t\
    \tseg.change(k+1, 0);\n        }\n        else if(t==2) {\n            if(seg.get(k+1,\
    \ k+1).a) cout << 1 << '\\n';\n            else cout << 0 << '\\n';\n        }\n\
    \        else if(t==3) {\n\t\t\tint res = seg.min_right(k+1, nex);\n\t\t    if(res==-1)\
    \ cout << -1 << '\\n';\n\t\t\telse cout << res-1 << '\\n';\n        }\n      \
    \  else {\n           int res = seg.max_left(k+1, nex);\n\t\t   if(res==-1) cout\
    \ << -1 << '\\n';\n\t\t   else cout << res-1 << '\\n';\n\t\t}\n    }\n}\n\n\n"
  dependsOn:
  - DataStructures/SegTree_with_binary-search.hpp
  isVerificationFile: true
  path: verify/segwithbsearch.test.cpp
  requiredBy: []
  timestamp: '2024-05-11 18:05:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/segwithbsearch.test.cpp
layout: document
redirect_from:
- /verify/verify/segwithbsearch.test.cpp
- /verify/verify/segwithbsearch.test.cpp.html
title: verify/segwithbsearch.test.cpp
---