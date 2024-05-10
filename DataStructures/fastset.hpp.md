---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/fastset.test.cpp
    title: verify/fastset.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DataStructures/fastset.hpp\"\n\n#include<bits/stdc++.h>\n\
    using namespace std;\n\n\nstruct intset {\n\tusing ll = long long;\n\tusing ull\
    \ = unsigned long long;\n\tint W = 3;\n\tll siz;\n\tvector<int> B = {0, 6, 12,\
    \ 18, 24, 30, 36, 42};\n\tvector<ull> mask;\n\tvector<ull> mask_rev;\n\tvector<vector<ull>>\
    \ tr;\n\n\tintset(){}\n\n\tintset(int _W) : W(_W) {\n\t\ttr.resize(W);\n\t\tmask.resize(65,0);\n\
    \t\tmask_rev.resize(65, 18446744073709551615ULL);\n\t\tsiz = 0;\n\t\tfor(int i\
    \ = 0; i < W; i++) {\n\t\t\ttr[i].resize(1ULL << B[W-i-1], 0);\n\t\t}\n\t\tfor(int\
    \ i = 1; i <= 64; i++) {\n\t\t\tmask[i] = mask[i-1] << 1 | 1;\n\t\t}\n\t\tfor(int\
    \ i = 63; i >= 0; i--) {\n\t\t\tmask_rev[i] = mask_rev[i+1]<<1;\n\t\t}\n\t}\n\n\
    \tprivate:\n\t    ull Q(ull x, int w) {//x \u3092 2^w \u3067\u5272\u3063\u305F\
    \u5546\n\t        return x >> w;\n\t    }\n\n\t\t\t\n\t    ull lower_bound__(ull\
    \ x, int i, ull res) {\n\t    \tif(i<0) return res;\n\t    \tif(res == Q(x, B[i+1]))\
    \ {\n\t    \t\tif(tr[i][res] >> (Q(x, B[i])&63) & 1) {\t\n\t    \t\t\tif((tr[i][res]\
    \ & mask_rev[63-(Q(x, B[i])&63)]) == 0) return lower_bound__(x, i-1, res << 6\
    \ | __builtin_ctzll(tr[i][res] & mask_rev[64-(Q(x, B[i])&63)]));\n\t    \t\t\t\
    return min(lower_bound__(x, i-1, res << 6 | __builtin_ctzll(tr[i][res] & mask_rev[64-(Q(x,\
    \ B[i])&63)])), lower_bound__(x, i-1, res << 6 | __builtin_ctzll(tr[i][res] &\
    \ mask_rev[63-(Q(x, B[i])&63)])));\n\t    \t\t}\n\t    \t\telse {\n\t    \t\t\t\
    if(!(tr[i][res] & mask_rev[63-(Q(x, B[i])&63)])) return 18446744073709551615ULL;\n\
    \t    \t\t\treturn lower_bound__(x, i-1, res << 6 | __builtin_ctzll(tr[i][res]\
    \ & mask_rev[63-(Q(x, B[i])&63)]));\n\t    \t\t}\n\t    \t}\n\t    \telse {\n\t\
    \    \t\treturn lower_bound__(x, i-1, res << 6 | __builtin_ctzll(tr[i][res]));\n\
    \t    \t}\n\t    }\n    \n\t    ull lower_left_bound__(ull x, int i, ull res)\
    \ {\n\t    \tif(i<0) return res;\n\t    \tif(res == Q(x, B[i+1])) {\n\t    \t\t\
    if(tr[i][res] >> (Q(x, B[i])&63) & 1) {\t\t\n\t    \t\t\tif((tr[i][res]&mask[(Q(x,\
    \ B[i])&63)]) == 0) return lower_left_bound__(x, i-1, res << 6 | (63-__builtin_clzll(tr[i][res]\
    \ & mask[(Q(x, B[i])&63)+1])));\n\t    \t\t\treturn max(lower_left_bound__(x,\
    \ i-1, res << 6 | (63-__builtin_clzll(tr[i][res]&mask[(Q(x, B[i])&63)]))),lower_left_bound__(x,\
    \ i-1, res << 6 | (63-__builtin_clzll(tr[i][res]&mask[(Q(x, B[i])&63)+1]))));\n\
    \t    \t\t}\n\t    \t\telse {\n\t    \t\t\tif(!(tr[i][res]&mask[(Q(x, B[i])&63)]))\
    \ return 0ULL;\n\t    \t\t\treturn lower_left_bound__(x, i-1, res << 6 | (63-__builtin_clzll(tr[i][res]&mask[(Q(x,\
    \ B[i])&63)])));\n\t    \t\t}\n\t    \t}\n\t    \telse {\n\t    \t\treturn lower_left_bound__(x,\
    \ i-1, res << 6 | (63-__builtin_clzll(tr[i][res])));\n\t    \t}\n\t    }\n\n\t\
    public:\n\n\n\tvoid set(ull x) {\n\t\tif(count(x))return;\n\t\tsiz++;\n\t\ttr[0][Q(x,\
    \ 6)] |= (1ULL << (x&63));\n\t}\n\n\tvoid init() {\n\t\tfor(int i = 0; i < W-1;\
    \ i++) {\n\t\t\tfor(int j = 0; j < int(tr[i].size()); j++) {\n\t\t\t\tull d =\
    \ tr[i][j] != 0;\n\t\t\t\ttr[i+1][j/64] |= d << (j&63);\n\t\t\t}\n\t\t}\n\t}\n\
    \n\tvoid insert(ull x) {\n\t\tif(count(x))return;\n\t\tsiz++;\n\t\tfor(int i =\
    \ W-1; i >= 0; i--) {\n\t\t\ttr[i][Q(x, B[i+1])] |= 1ULL << (Q(x, B[i])&63);\n\
    \t\t}\n\t}\n\n\tvoid erase(ull x) {\n\t\tif(!count(x))return;\n\t\tsiz--;\n\t\t\
    tr[0][Q(x, 6)] ^= 1ULL << (x&63);\n\t\tfor (int i = 1; i < W; i++) {\n\t\t\tull\
    \ d = (!tr[i-1][Q(x, B[i])]);\n\t\t\ttr[i][Q(x, B[i+1])] ^= d << (Q(x, B[i])&63);\n\
    \t\t}\n\t}\n\n\tint count(ull x) {\n\t\treturn tr[0][Q(x, 6)] >> (x&63) & 1;\n\
    \t}\n\n\tull min_element() {\n\t\tull res = 0;\n\t\tfor(int i = W-1; i >= 0; i--)\
    \ {\n\t\t\tres = res << 6 | __builtin_ctzll(tr[i][res]);\n\t\t}\n\t\treturn res;\n\
    \t}\n\n\tull max_element() {\n\t\tull res = 0;\n\t\tfor(int i = W-1; i >= 0; i--)\
    \ {\n\t\t\tres = res << 6 | (63-__builtin_clzll(tr[i][res]));\n\t\t}\n\t\treturn\
    \ res;\n\t}\n\n\tull lower_bound(ull x) {\n\t\treturn lower_bound__(x,W-1,0);\n\
    \t}\n\n\tull lower_left_bound(ull x) {\n\t\treturn lower_left_bound__(x,W-1,0);\n\
    \t}\n\n\n\n\tll size() {\n\t\treturn siz;\n\t}\n\n\tbool empty() {\n\t\treturn\
    \ siz==0;\n\t}\n\n\tvoid dump() {\n\t\tll M = 1LL << B[W];\n\t\tM--;\n\t\tfor(int\
    \ i = 0; i <= M; i++) {\n\t\t\tif(count(i)) cout << i << \" \";\n\t\t}\n\t\tcout\
    \ << endl;\n\t}\n\n\t/*\n\t    intset(W) \n\t\t@brief:\u975E\u8CA0\u6574\u6570\
    \u3092\u7BA1\u7406\u3059\u308B64\u5206\u6728\u3002 W\u306F\u6728\u306E\u9AD8\u3055\
    \u3002\n\t\tW = 3  [0, 262'143]        3MB 1ms  \n\t\tW = 4  [0, 16'777'215] \
    \    5MB 2ms\n\t\tW = 5  [0, 1'073'741'823]  136MB 60ms\n\n\t\tinsert(x) x\u3092\
    \u633F\u5165\u3059\u308B\u3002\u5B58\u5728\u3059\u308B\u306A\u3089\u306A\u306B\
    \u3082\u3057\u306A\u3044\u3002 O(W)\n\t\terase(x) x\u3092\u524A\u9664\u3002\u5B58\
    \u5728\u3057\u306A\u3044\u6642\u306A\u306B\u3082\u3057\u306A\u3044\u3002 O(W)\n\
    \n\t\n\t*/\n};\n\n"
  code: "\n#include<bits/stdc++.h>\nusing namespace std;\n\n\nstruct intset {\n\t\
    using ll = long long;\n\tusing ull = unsigned long long;\n\tint W = 3;\n\tll siz;\n\
    \tvector<int> B = {0, 6, 12, 18, 24, 30, 36, 42};\n\tvector<ull> mask;\n\tvector<ull>\
    \ mask_rev;\n\tvector<vector<ull>> tr;\n\n\tintset(){}\n\n\tintset(int _W) : W(_W)\
    \ {\n\t\ttr.resize(W);\n\t\tmask.resize(65,0);\n\t\tmask_rev.resize(65, 18446744073709551615ULL);\n\
    \t\tsiz = 0;\n\t\tfor(int i = 0; i < W; i++) {\n\t\t\ttr[i].resize(1ULL << B[W-i-1],\
    \ 0);\n\t\t}\n\t\tfor(int i = 1; i <= 64; i++) {\n\t\t\tmask[i] = mask[i-1] <<\
    \ 1 | 1;\n\t\t}\n\t\tfor(int i = 63; i >= 0; i--) {\n\t\t\tmask_rev[i] = mask_rev[i+1]<<1;\n\
    \t\t}\n\t}\n\n\tprivate:\n\t    ull Q(ull x, int w) {//x \u3092 2^w \u3067\u5272\
    \u3063\u305F\u5546\n\t        return x >> w;\n\t    }\n\n\t\t\t\n\t    ull lower_bound__(ull\
    \ x, int i, ull res) {\n\t    \tif(i<0) return res;\n\t    \tif(res == Q(x, B[i+1]))\
    \ {\n\t    \t\tif(tr[i][res] >> (Q(x, B[i])&63) & 1) {\t\n\t    \t\t\tif((tr[i][res]\
    \ & mask_rev[63-(Q(x, B[i])&63)]) == 0) return lower_bound__(x, i-1, res << 6\
    \ | __builtin_ctzll(tr[i][res] & mask_rev[64-(Q(x, B[i])&63)]));\n\t    \t\t\t\
    return min(lower_bound__(x, i-1, res << 6 | __builtin_ctzll(tr[i][res] & mask_rev[64-(Q(x,\
    \ B[i])&63)])), lower_bound__(x, i-1, res << 6 | __builtin_ctzll(tr[i][res] &\
    \ mask_rev[63-(Q(x, B[i])&63)])));\n\t    \t\t}\n\t    \t\telse {\n\t    \t\t\t\
    if(!(tr[i][res] & mask_rev[63-(Q(x, B[i])&63)])) return 18446744073709551615ULL;\n\
    \t    \t\t\treturn lower_bound__(x, i-1, res << 6 | __builtin_ctzll(tr[i][res]\
    \ & mask_rev[63-(Q(x, B[i])&63)]));\n\t    \t\t}\n\t    \t}\n\t    \telse {\n\t\
    \    \t\treturn lower_bound__(x, i-1, res << 6 | __builtin_ctzll(tr[i][res]));\n\
    \t    \t}\n\t    }\n    \n\t    ull lower_left_bound__(ull x, int i, ull res)\
    \ {\n\t    \tif(i<0) return res;\n\t    \tif(res == Q(x, B[i+1])) {\n\t    \t\t\
    if(tr[i][res] >> (Q(x, B[i])&63) & 1) {\t\t\n\t    \t\t\tif((tr[i][res]&mask[(Q(x,\
    \ B[i])&63)]) == 0) return lower_left_bound__(x, i-1, res << 6 | (63-__builtin_clzll(tr[i][res]\
    \ & mask[(Q(x, B[i])&63)+1])));\n\t    \t\t\treturn max(lower_left_bound__(x,\
    \ i-1, res << 6 | (63-__builtin_clzll(tr[i][res]&mask[(Q(x, B[i])&63)]))),lower_left_bound__(x,\
    \ i-1, res << 6 | (63-__builtin_clzll(tr[i][res]&mask[(Q(x, B[i])&63)+1]))));\n\
    \t    \t\t}\n\t    \t\telse {\n\t    \t\t\tif(!(tr[i][res]&mask[(Q(x, B[i])&63)]))\
    \ return 0ULL;\n\t    \t\t\treturn lower_left_bound__(x, i-1, res << 6 | (63-__builtin_clzll(tr[i][res]&mask[(Q(x,\
    \ B[i])&63)])));\n\t    \t\t}\n\t    \t}\n\t    \telse {\n\t    \t\treturn lower_left_bound__(x,\
    \ i-1, res << 6 | (63-__builtin_clzll(tr[i][res])));\n\t    \t}\n\t    }\n\n\t\
    public:\n\n\n\tvoid set(ull x) {\n\t\tif(count(x))return;\n\t\tsiz++;\n\t\ttr[0][Q(x,\
    \ 6)] |= (1ULL << (x&63));\n\t}\n\n\tvoid init() {\n\t\tfor(int i = 0; i < W-1;\
    \ i++) {\n\t\t\tfor(int j = 0; j < int(tr[i].size()); j++) {\n\t\t\t\tull d =\
    \ tr[i][j] != 0;\n\t\t\t\ttr[i+1][j/64] |= d << (j&63);\n\t\t\t}\n\t\t}\n\t}\n\
    \n\tvoid insert(ull x) {\n\t\tif(count(x))return;\n\t\tsiz++;\n\t\tfor(int i =\
    \ W-1; i >= 0; i--) {\n\t\t\ttr[i][Q(x, B[i+1])] |= 1ULL << (Q(x, B[i])&63);\n\
    \t\t}\n\t}\n\n\tvoid erase(ull x) {\n\t\tif(!count(x))return;\n\t\tsiz--;\n\t\t\
    tr[0][Q(x, 6)] ^= 1ULL << (x&63);\n\t\tfor (int i = 1; i < W; i++) {\n\t\t\tull\
    \ d = (!tr[i-1][Q(x, B[i])]);\n\t\t\ttr[i][Q(x, B[i+1])] ^= d << (Q(x, B[i])&63);\n\
    \t\t}\n\t}\n\n\tint count(ull x) {\n\t\treturn tr[0][Q(x, 6)] >> (x&63) & 1;\n\
    \t}\n\n\tull min_element() {\n\t\tull res = 0;\n\t\tfor(int i = W-1; i >= 0; i--)\
    \ {\n\t\t\tres = res << 6 | __builtin_ctzll(tr[i][res]);\n\t\t}\n\t\treturn res;\n\
    \t}\n\n\tull max_element() {\n\t\tull res = 0;\n\t\tfor(int i = W-1; i >= 0; i--)\
    \ {\n\t\t\tres = res << 6 | (63-__builtin_clzll(tr[i][res]));\n\t\t}\n\t\treturn\
    \ res;\n\t}\n\n\tull lower_bound(ull x) {\n\t\treturn lower_bound__(x,W-1,0);\n\
    \t}\n\n\tull lower_left_bound(ull x) {\n\t\treturn lower_left_bound__(x,W-1,0);\n\
    \t}\n\n\n\n\tll size() {\n\t\treturn siz;\n\t}\n\n\tbool empty() {\n\t\treturn\
    \ siz==0;\n\t}\n\n\tvoid dump() {\n\t\tll M = 1LL << B[W];\n\t\tM--;\n\t\tfor(int\
    \ i = 0; i <= M; i++) {\n\t\t\tif(count(i)) cout << i << \" \";\n\t\t}\n\t\tcout\
    \ << endl;\n\t}\n\n\t/*\n\t    intset(W) \n\t\t@brief:\u975E\u8CA0\u6574\u6570\
    \u3092\u7BA1\u7406\u3059\u308B64\u5206\u6728\u3002 W\u306F\u6728\u306E\u9AD8\u3055\
    \u3002\n\t\tW = 3  [0, 262'143]        3MB 1ms  \n\t\tW = 4  [0, 16'777'215] \
    \    5MB 2ms\n\t\tW = 5  [0, 1'073'741'823]  136MB 60ms\n\n\t\tinsert(x) x\u3092\
    \u633F\u5165\u3059\u308B\u3002\u5B58\u5728\u3059\u308B\u306A\u3089\u306A\u306B\
    \u3082\u3057\u306A\u3044\u3002 O(W)\n\t\terase(x) x\u3092\u524A\u9664\u3002\u5B58\
    \u5728\u3057\u306A\u3044\u6642\u306A\u306B\u3082\u3057\u306A\u3044\u3002 O(W)\n\
    \n\t\n\t*/\n};\n\n"
  dependsOn: []
  isVerificationFile: false
  path: DataStructures/fastset.hpp
  requiredBy: []
  timestamp: '2024-05-11 03:22:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/fastset.test.cpp
documentation_of: DataStructures/fastset.hpp
layout: document
redirect_from:
- /library/DataStructures/fastset.hpp
- /library/DataStructures/fastset.hpp.html
title: DataStructures/fastset.hpp
---
