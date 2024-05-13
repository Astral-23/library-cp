---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: verify/test_of_int_to_lexico.cpp
    title: verify/test_of_int_to_lexico.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "[0, r]\u3067\u8F9E\u66F8\u9806K\u756A\u76EE\u306E\u6574\u6570"
    links:
    - https://atcoder.jp/contests/arc078/submissions/53435109
  bundledCode: "#line 1 \"Math/int_to_lexico.hpp\"\nvector<long long> p10(19, 1);\n\
    \nll count(ll pref, ll r, int k, int M) {//[0, r]\u306B\u304A\u3044\u3066\u3001\
    prefix\u304Cpref\u3068\u4E00\u81F4\u3059\u308B\u6570\u5B57\u306F\u4F55\u500B\u3042\
    \u308B\u304B\uFF08\u30EA\u30FC\u30C7\u30A3\u30F3\u30B00\u306F\u7701\u304F\u3002\
    \  O(1)\n    r++;\n    if(pref==0) return 1LL;\n    ll res = 0;\n\tif(M >= k)\
    \ {\n\t    res += (p10[M-k] - 1) / 9;\n    \tll nl = pref * p10[M - k];\n\t  \
    \  ll nr = (pref+1) * p10[M - k];\n\t    nr = min(nr, r);\n\t    res += max(0LL,\
    \ nr - nl);\n\t}\n\treturn res;\n\n}\n\nll kth(ll k, ll r) {//[0, r]\u3067\u8F9E\
    \u66F8\u9806k\u756A\u76EE\u306E\u6570\u5B57\u3092\u8FD4\u3059\u3002 0-indexed(kth(0)\
    \ = 0)  10 * log(r) \n    k++;\n\tif(k==1) return 0LL;\n    int M = (to_string(r)).size();\n\
    \tll pref = 0;\n\trep(i, 1, M) {\n\t\tif(k==1) break;\n\t\tk--;\n\t\trep(nex,\
    \ 0, 9) if(!(i==1 && nex == 0)){\n\t\t\tll c = count(pref*10+nex, r, i, M);\n\t\
    \t\tif(k <= c) pref = pref * 10 + nex, nex = 9;\n\t\t\telse k -= c;\n\t\t}\n\t\
    }\n\treturn pref;\n\n}\n/*\n@brief [0, r]\u3067\u8F9E\u66F8\u9806K\u756A\u76EE\
    \u306E\u6574\u6570   \np10\u3092\u3069\u3053\u304B\u3067\u8A08\u7B97\u3057\u3066\
    \u304A\u304F\u3002\nverified with https://atcoder.jp/contests/arc078/submissions/53435109\n\
    \u3042\u308B\u3044\u306F r = 10000000\u3067\u306E\u30B9\u30C8\u30EC\u30B9\u30C6\
    \u30B9\u30C8\n\u88DC\u8DB3\uFF1A\u6574\u6570\u306E\u8F9E\u66F8\u9806\u6BD4\u8F03\
    \u306B\u3064\u3044\u3066\u3001\uFF08\u30EA\u30FC\u30C7\u30A3\u30F3\u30B00\u3092\
    \u9664\u3044\u305F)\u6841\u6570\u304C\u7B49\u3057\u3044\u306A\u3089\u3070\u3001\
    \u5927\u5C0F\u95A2\u4FC2\u3068\u8F9E\u66F8\u9806\u304C\u4E00\u81F4\n*/\n"
  code: "vector<long long> p10(19, 1);\n\nll count(ll pref, ll r, int k, int M) {//[0,\
    \ r]\u306B\u304A\u3044\u3066\u3001prefix\u304Cpref\u3068\u4E00\u81F4\u3059\u308B\
    \u6570\u5B57\u306F\u4F55\u500B\u3042\u308B\u304B\uFF08\u30EA\u30FC\u30C7\u30A3\
    \u30F3\u30B00\u306F\u7701\u304F\u3002  O(1)\n    r++;\n    if(pref==0) return\
    \ 1LL;\n    ll res = 0;\n\tif(M >= k) {\n\t    res += (p10[M-k] - 1) / 9;\n  \
    \  \tll nl = pref * p10[M - k];\n\t    ll nr = (pref+1) * p10[M - k];\n\t    nr\
    \ = min(nr, r);\n\t    res += max(0LL, nr - nl);\n\t}\n\treturn res;\n\n}\n\n\
    ll kth(ll k, ll r) {//[0, r]\u3067\u8F9E\u66F8\u9806k\u756A\u76EE\u306E\u6570\u5B57\
    \u3092\u8FD4\u3059\u3002 0-indexed(kth(0) = 0)  10 * log(r) \n    k++;\n\tif(k==1)\
    \ return 0LL;\n    int M = (to_string(r)).size();\n\tll pref = 0;\n\trep(i, 1,\
    \ M) {\n\t\tif(k==1) break;\n\t\tk--;\n\t\trep(nex, 0, 9) if(!(i==1 && nex ==\
    \ 0)){\n\t\t\tll c = count(pref*10+nex, r, i, M);\n\t\t\tif(k <= c) pref = pref\
    \ * 10 + nex, nex = 9;\n\t\t\telse k -= c;\n\t\t}\n\t}\n\treturn pref;\n\n}\n\
    /*\n@brief [0, r]\u3067\u8F9E\u66F8\u9806K\u756A\u76EE\u306E\u6574\u6570   \n\
    p10\u3092\u3069\u3053\u304B\u3067\u8A08\u7B97\u3057\u3066\u304A\u304F\u3002\n\
    verified with https://atcoder.jp/contests/arc078/submissions/53435109\n\u3042\u308B\
    \u3044\u306F r = 10000000\u3067\u306E\u30B9\u30C8\u30EC\u30B9\u30C6\u30B9\u30C8\
    \n\u88DC\u8DB3\uFF1A\u6574\u6570\u306E\u8F9E\u66F8\u9806\u6BD4\u8F03\u306B\u3064\
    \u3044\u3066\u3001\uFF08\u30EA\u30FC\u30C7\u30A3\u30F3\u30B00\u3092\u9664\u3044\
    \u305F)\u6841\u6570\u304C\u7B49\u3057\u3044\u306A\u3089\u3070\u3001\u5927\u5C0F\
    \u95A2\u4FC2\u3068\u8F9E\u66F8\u9806\u304C\u4E00\u81F4\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Math/int_to_lexico.hpp
  requiredBy:
  - verify/test_of_int_to_lexico.cpp
  timestamp: '2024-05-13 17:40:20+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/int_to_lexico.hpp
layout: document
redirect_from:
- /library/Math/int_to_lexico.hpp
- /library/Math/int_to_lexico.hpp.html
title: "[0, r]\u3067\u8F9E\u66F8\u9806K\u756A\u76EE\u306E\u6574\u6570"
---