---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "[0, r]\u3067\u8F9E\u66F8\u9806K\u756A\u76EE\u306E\u6574\u6570"
    links:
    - https://atcoder.jp/contests/arc078/submissions/53435109
  bundledCode: "#line 1 \"Utilities/int_to_lexico.hpp\"\nvl p10(19, 1);\n\nll count(ll\
    \ pref, ll r) {//[0, r]\u306B\u304A\u3044\u3066\u3001prefix\u304Cpref\u3068\u4E00\
    \u81F4\u3059\u308B\u6570\u5B57\u306F\u4F55\u500B\u3042\u308B\u304B\uFF08\u30EA\
    \u30FC\u30C7\u30A3\u30F3\u30B00\u306F\u7701\u304F\u3002  log(r) \n    r++;\n \
    \   if(pref==0) return 1LL;\n\tint k = (to_string(pref)).size();\n\tint M = (to_string(r)).size();\n\
    \    ll res = 0;\n\tif(M >= k) {\n\t    res += (p10[M-k] - 1) / 9;\n    \n   \
    \ \tll nl = pref * p10[M - k];\n\t    ll nr = (pref+1) * p10[M - k];\n\t    nr\
    \ = min(nr, r);\n\t    res += max(0LL, nr - nl);\n\t}\n\treturn res;\n\n}\n\n\
    ll kth(ll k, ll r) {//[0, r]\u3067\u8F9E\u66F8\u9806k\u756A\u76EE\u306E\u6570\u5B57\
    \u3092\u8FD4\u3059\u3002 0-indexed(kth(0) = 0) log^2(r)\n    k++;\n\tif(k==1)\
    \ return 0LL;\n    ll M = (to_string(r)).size()+1;\n\tstring pref = \"0\";\n\t\
    rep(i, 1, M) {\n\t\tif(k==1) break;\n\t\tk--;\n\t\tll pre = stoll(pref);\n\t\t\
    rep(nex, 0, 9) if(!(i==1 && nex == 0)){\n\t\t\tll c = count(pre*10+nex, r);\n\t\
    \t\tif(k <= c) pref += ('0'+nex), nex = 9;\n\t\t\telse k -= c;\n\t\t}\n\t}\n\t\
    return stoll(pref.substr(1));\n\n}\n\n/*\n@brief [0, r]\u3067\u8F9E\u66F8\u9806\
    K\u756A\u76EE\u306E\u6574\u6570\np10\u3092\u3069\u3053\u304B\u3067\u8A08\u7B97\
    \u3057\u3066\u304A\u304F\u3002\nverified with https://atcoder.jp/contests/arc078/submissions/53435109\n\
    */\n"
  code: "vl p10(19, 1);\n\nll count(ll pref, ll r) {//[0, r]\u306B\u304A\u3044\u3066\
    \u3001prefix\u304Cpref\u3068\u4E00\u81F4\u3059\u308B\u6570\u5B57\u306F\u4F55\u500B\
    \u3042\u308B\u304B\uFF08\u30EA\u30FC\u30C7\u30A3\u30F3\u30B00\u306F\u7701\u304F\
    \u3002  log(r) \n    r++;\n    if(pref==0) return 1LL;\n\tint k = (to_string(pref)).size();\n\
    \tint M = (to_string(r)).size();\n    ll res = 0;\n\tif(M >= k) {\n\t    res +=\
    \ (p10[M-k] - 1) / 9;\n    \n    \tll nl = pref * p10[M - k];\n\t    ll nr = (pref+1)\
    \ * p10[M - k];\n\t    nr = min(nr, r);\n\t    res += max(0LL, nr - nl);\n\t}\n\
    \treturn res;\n\n}\n\nll kth(ll k, ll r) {//[0, r]\u3067\u8F9E\u66F8\u9806k\u756A\
    \u76EE\u306E\u6570\u5B57\u3092\u8FD4\u3059\u3002 0-indexed(kth(0) = 0) log^2(r)\n\
    \    k++;\n\tif(k==1) return 0LL;\n    ll M = (to_string(r)).size()+1;\n\tstring\
    \ pref = \"0\";\n\trep(i, 1, M) {\n\t\tif(k==1) break;\n\t\tk--;\n\t\tll pre =\
    \ stoll(pref);\n\t\trep(nex, 0, 9) if(!(i==1 && nex == 0)){\n\t\t\tll c = count(pre*10+nex,\
    \ r);\n\t\t\tif(k <= c) pref += ('0'+nex), nex = 9;\n\t\t\telse k -= c;\n\t\t\
    }\n\t}\n\treturn stoll(pref.substr(1));\n\n}\n\n/*\n@brief [0, r]\u3067\u8F9E\u66F8\
    \u9806K\u756A\u76EE\u306E\u6574\u6570\np10\u3092\u3069\u3053\u304B\u3067\u8A08\
    \u7B97\u3057\u3066\u304A\u304F\u3002\nverified with https://atcoder.jp/contests/arc078/submissions/53435109\n\
    */"
  dependsOn: []
  isVerificationFile: false
  path: Utilities/int_to_lexico.hpp
  requiredBy: []
  timestamp: '2024-05-13 09:54:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utilities/int_to_lexico.hpp
layout: document
redirect_from:
- /library/Utilities/int_to_lexico.hpp
- /library/Utilities/int_to_lexico.hpp.html
title: "[0, r]\u3067\u8F9E\u66F8\u9806K\u756A\u76EE\u306E\u6574\u6570"
---
