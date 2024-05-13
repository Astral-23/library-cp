---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: Math/int_to_lexico.hpp
    title: "[0, r]\u3067\u8F9E\u66F8\u9806K\u756A\u76EE\u306E\u6574\u6570"
  - icon: ':x:'
    path: Utilities/timer.hpp
    title: Timer
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 1 \"verify/int_to_lexico.test.cpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\nusing ll = long long;\nusing vvl = vector<vector<ll>>;\n\
    using vl = vector<ll>;\n#define rep(i, s, f) for(long long i = s; i <= f; i++)\n\
    #line 1 \"Math/int_to_lexico.hpp\"\nvector<long long> p10(19, 1);\n\nll count(ll\
    \ pref, ll r, int k, int M) {//[0, r]\u306B\u304A\u3044\u3066\u3001prefix\u304C\
    pref\u3068\u4E00\u81F4\u3059\u308B\u6570\u5B57\u306F\u4F55\u500B\u3042\u308B\u304B\
    \uFF08\u30EA\u30FC\u30C7\u30A3\u30F3\u30B00\u306F\u7701\u304F\u3002  O(1)\n  \
    \  r++;\n    if(pref==0) return 1LL;\n    ll res = 0;\n\tif(M >= k) {\n\t    res\
    \ += (p10[M-k] - 1) / 9;\n    \tll nl = pref * p10[M - k];\n\t    ll nr = (pref+1)\
    \ * p10[M - k];\n\t    nr = min(nr, r);\n\t    res += max(0LL, nr - nl);\n\t}\n\
    \treturn res;\n\n}\n\nll kth(ll k, ll r) {//[0, r]\u3067\u8F9E\u66F8\u9806k\u756A\
    \u76EE\u306E\u6570\u5B57\u3092\u8FD4\u3059\u3002 0-indexed(kth(0) = 0)  10 * log(r)\
    \ \n    k++;\n\tif(k==1) return 0LL;\n    int M = (to_string(r)).size();\n\tll\
    \ pref = 0;\n\trep(i, 1, M) {\n\t\tif(k==1) break;\n\t\tk--;\n\t\trep(nex, 0,\
    \ 9) if(!(i==1 && nex == 0)){\n\t\t\tll c = count(pref*10+nex, r, i, M);\n\t\t\
    \tif(k <= c) pref = pref * 10 + nex, nex = 9;\n\t\t\telse k -= c;\n\t\t}\n\t}\n\
    \treturn pref;\n\n}\n/*\n@brief [0, r]\u3067\u8F9E\u66F8\u9806K\u756A\u76EE\u306E\
    \u6574\u6570   \np10\u3092\u3069\u3053\u304B\u3067\u8A08\u7B97\u3057\u3066\u304A\
    \u304F\u3002\nverified with https://atcoder.jp/contests/arc078/submissions/53435109\n\
    \u3042\u308B\u3044\u306F r = 10000000\u3067\u306E\u30B9\u30C8\u30EC\u30B9\u30C6\
    \u30B9\u30C8\n\u88DC\u8DB3\uFF1A\u6574\u6570\u306E\u8F9E\u66F8\u9806\u6BD4\u8F03\
    \u306B\u3064\u3044\u3066\u3001\uFF08\u30EA\u30FC\u30C7\u30A3\u30F3\u30B00\u3092\
    \u9664\u3044\u305F)\u6841\u6570\u304C\u7B49\u3057\u3044\u306A\u3089\u3070\u3001\
    \u5927\u5C0F\u95A2\u4FC2\u3068\u8F9E\u66F8\u9806\u304C\u4E00\u81F4\n*/\n#line\
    \ 1 \"Utilities/timer.hpp\"\nstruct Timer {\n\tchrono::system_clock::time_point\
    \ s;\n\tchrono::system_clock::time_point pre;\n\tbool active = false;\n\n\tTimer(){active\
    \ = false;}\n\n\tvoid start() {\n\t\tassert(!active);\n\t\tactive = true;\n\t\t\
    s = chrono::system_clock::now();\n\t}\n\n\tvoid stop() {\n\t\tpre = chrono::system_clock::now();\n\
    \t\tassert(active);\n\t\tactive = false;\n\t}\n\n\tvoid restart() {//non_active\u306E\
    \u6642\u9593\u5206\u3001\u59CB\u70B9\u3092\u305A\u3089\u3059\n\t    assert(!active);\n\
    \t\tactive = true;\n\t\ts += chrono::system_clock::now() - pre;\n\t}\n\n\n\tdouble\
    \ now() {\n\t\tif(active) {\n\t\t    chrono::system_clock::time_point t = chrono::system_clock::now();\n\
    \t\t    return chrono::duration<double>(t - s).count();\n\t\t}\n\t\telse {\n\t\
    \t\treturn chrono::duration<double>(pre - s).count();\n\t\t}\n\t}\n\n\tvoid out()\
    \ {\n\t\tcout << now() << \" sec\" << endl;\n\t}\n};\nTimer tim;\n/*\n@brief Timer\n\
    */\n#line 10 \"verify/int_to_lexico.test.cpp\"\n#define ENDL '\\n'\n\n\nint main()\
    \ {\n\trep(i,1,18) p10[i] = p10[i-1] * 10;\n\n\n\tll B = 10000000;\n\tvector<string>\
    \ vs(B+1);\n\trep(i, 0, B) vs[i] = to_string(i);\n\tsort(vs.begin(), vs.end());\n\
    \n\ttim.start();\n\n\trep(i, 0, B) {\n\t\tassert(stoll(vs[i]) == kth(i, B));\n\
    \t}\n\n\ttim.out();\n\t\n\n\n}\n"
  code: "\n#include<bits/stdc++.h>\nusing namespace std;\nusing ll = long long;\n\
    using vvl = vector<vector<ll>>;\nusing vl = vector<ll>;\n#define rep(i, s, f)\
    \ for(long long i = s; i <= f; i++)\n#include \"../Math/int_to_lexico.hpp\"\n\
    #include \"../Utilities/timer.hpp\"\n#define ENDL '\\n'\n\n\nint main() {\n\t\
    rep(i,1,18) p10[i] = p10[i-1] * 10;\n\n\n\tll B = 10000000;\n\tvector<string>\
    \ vs(B+1);\n\trep(i, 0, B) vs[i] = to_string(i);\n\tsort(vs.begin(), vs.end());\n\
    \n\ttim.start();\n\n\trep(i, 0, B) {\n\t\tassert(stoll(vs[i]) == kth(i, B));\n\
    \t}\n\n\ttim.out();\n\t\n\n\n}"
  dependsOn:
  - Math/int_to_lexico.hpp
  - Utilities/timer.hpp
  isVerificationFile: true
  path: verify/int_to_lexico.test.cpp
  requiredBy: []
  timestamp: '2024-05-13 17:47:39+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/int_to_lexico.test.cpp
layout: document
redirect_from:
- /verify/verify/int_to_lexico.test.cpp
- /verify/verify/int_to_lexico.test.cpp.html
title: verify/int_to_lexico.test.cpp
---
