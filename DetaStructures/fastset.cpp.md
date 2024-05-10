---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u975E\u8CA0\u6574\u6570\u3092\u7BA1\u7406\u3059\u308B64\u5206\
      \u6728\u3002 W\u306F\u6728\u306E\u9AD8\u3055"
    links: []
  bundledCode: "#line 1 \"DetaStructures/fastset.cpp\"\nstruct fastset {\n\tusing\
    \ ll = long long;\n\tusing ull = unsigned long long;\n\tint W;\n\tll siz;\n\t\
    vector<int> B = {0, 6, 12, 18, 24, 30, 36, 42};\n\tvector<ull> mask;\n\tvector<ull>\
    \ mask_rev;\n\tvector<vector<ull>> tr;\n\n\tfastset(){}\n\n\tfastset(int _W) :\
    \ W(_W) {\n\t\ttr.resize(W);\n\t\tmask.resize(65,0);\n\t\tmask_rev.resize(65,\
    \ 18446744073709551615ULL);\n\t\tsiz = 0;\n\t\tfor(int i = 0; i < W; i++) {\n\t\
    \t\ttr[i].resize(1ULL << B[W-i-1], 0);\n\t\t}\n\t\tfor(int i = 1; i <= 64; i++)\
    \ {\n\t\t\tmask[i] = mask[i-1] << 1 | 1;\n\t\t}\n\t\tfor(int i = 63; i >= 0; i--)\
    \ {\n\t\t\tmask_rev[i] = mask_rev[i+1]<<1;\n\t\t}\n\t}\n\n\tprivate:\n\t    ull\
    \ Q(ull x, int w) {//x \u3092 2^w \u3067\u5272\u3063\u305F\u5546\n\t        return\
    \ x >> w;\n\t    }\n\n\t\t\t\n\t    ull lower_bound__(ull x, int i, ull res) {\n\
    \t    \tif(i<0) return res;\n\t    \tif(res == Q(x, B[i+1])) {\n\t    \t\tif(tr[i][res]\
    \ >> (Q(x, B[i])&63) & 1) {\t\n\t    \t\t\tif((tr[i][res] & mask_rev[63-(Q(x,\
    \ B[i])&63)]) == 0) return lower_bound__(x, i-1, res << 6 | __builtin_ctzll(tr[i][res]\
    \ & mask_rev[64-(Q(x, B[i])&63)]));\n\t    \t\t\treturn min(lower_bound__(x, i-1,\
    \ res << 6 | __builtin_ctzll(tr[i][res] & mask_rev[64-(Q(x, B[i])&63)])), lower_bound__(x,\
    \ i-1, res << 6 | __builtin_ctzll(tr[i][res] & mask_rev[63-(Q(x, B[i])&63)])));\n\
    \t    \t\t}\n\t    \t\telse {\n\t    \t\t\tif((tr[i][res] & mask_rev[63-(Q(x,\
    \ B[i])&63)]) == 0) return 18446744073709551615ULL;\n\t    \t\t\treturn lower_bound__(x,\
    \ i-1, res << 6 | __builtin_ctzll(tr[i][res] & mask_rev[63-(Q(x, B[i])&63)]));\n\
    \t    \t\t}\n\t    \t}\n\t    \telse {\n\t    \t\treturn lower_bound__(x, i-1,\
    \ res << 6 | __builtin_ctzll(tr[i][res]));\n\t    \t}\n\t    }\n    \n\t    ull\
    \ lower_left_bound__(ull x, int i, ull res) {\n\t    \tif(i<0) return res;\n\t\
    \    \tif(res == Q(x, B[i+1])) {\n\t    \t\tif(tr[i][res] >> (Q(x, B[i])&63) &\
    \ 1) {\t\t\n\t    \t\t\tif((tr[i][res]&mask[(Q(x, B[i])&63)]) == 0) return lower_left_bound__(x,\
    \ i-1, res << 6 | (63-__builtin_clzll(tr[i][res] & mask[(Q(x, B[i])&63)+1])));\n\
    \t    \t\t\treturn max(lower_left_bound__(x, i-1, res << 6 | (63-__builtin_clzll(tr[i][res]&mask[(Q(x,\
    \ B[i])&63)]))),lower_left_bound__(x, i-1, res << 6 | (63-__builtin_clzll(tr[i][res]&mask[(Q(x,\
    \ B[i])&63)+1]))));\n\t    \t\t}\n\t    \t\telse {\n\t    \t\t\tif((tr[i][res]&mask[(Q(x,\
    \ B[i])&63)]) == 0) return 0ULL;\n\t    \t\t\treturn lower_left_bound__(x, i-1,\
    \ res << 6 | (63-__builtin_clzll(tr[i][res]&mask[(Q(x, B[i])&63)])));\n\t    \t\
    \t}\n\t    \t}\n\t    \telse {\n\t    \t\treturn lower_left_bound__(x, i-1, res\
    \ << 6 | (63-__builtin_clzll(tr[i][res])));\n\t    \t}\n\t    }\n\n\tpublic:\n\
    \n\n\t    void insert(ll x) {\n\t    \tif(count(x))return;\n\t    \tsiz++;\n\t\
    \    \tfor(int i = W-1; i >= 0; i--) {\n\t    \t\ttr[i][Q(x, B[i+1])] |= 1ULL\
    \ << (Q(x, B[i])&63);\n\t    \t}\n\t    }\n    \n\t    void erase(ll x) {\n\t\
    \    \tif(!count(x))return;\n\t    \tsiz--;\n\t    \ttr[0][Q(x, 6)] ^= 1ULL <<\
    \ (x&63);\n\t    \tfor (int i = 1; i < W; i++) {\n\t    \t\tull d = (!tr[i-1][Q(x,\
    \ B[i])]);\n\t    \t\ttr[i][Q(x, B[i+1])] ^= d << (Q(x, B[i])&63);\n\t    \t}\n\
    \t    }\n    \n\t    int count(ll x) {\n\t    \treturn tr[0][Q(x, 6)] >> (x&63)\
    \ & 1;\n\t    }\n    \n\t    ll min_element() {\n\t\t\tassert(siz!=0);\n\t   \
    \ \tull res = 0;\n\t    \tfor(int i = W-1; i >= 0; i--) {\n\t    \t\tres = res\
    \ << 6 | __builtin_ctzll(tr[i][res]);\n\t    \t}\n\t    \treturn res;\n\t    }\n\
    \    \n\t    ll max_element() {\n\t\t\tassert(siz!=0);\n\t    \tull res = 0;\n\
    \t    \tfor(int i = W-1; i >= 0; i--) {\n\t    \t\tres = res << 6 | (63-__builtin_clzll(tr[i][res]));\n\
    \t    \t}\n\t    \treturn res;\n\t    }\n    \n\t    ll lower_bound(ll x) {\n\t\
    \t\tif(siz==0 || max_element() < x) return -1LL;\n\t    \treturn lower_bound__(x,W-1,0);\n\
    \t    }\n    \n\t    ll lower_left_bound(ll x) {\n\t\t\tif(siz==0 || min_element()\
    \ > x) return -1LL;\n\t    \treturn lower_left_bound__(x,W-1,0);\n\t    }\n  \
    \  \n\t    ll size() {\n\t    \treturn siz;\n\t    }\n    \n\t    bool empty()\
    \ {\n\t    \treturn siz==0;\n\t    }\n    \n\t    void dump() {\n\t    \tll M\
    \ = 1LL << B[W];\n\t    \tM--;\n\t    \tfor(int i = 0; i <= M; i++) {\n\t    \t\
    \tif(count(i)) cout << i << \" \";\n\t    \t}\n\t    \tcout << endl;\n\t    }\n\
    \    \n\t/*\n\t    fastset(W) \n\t\t@brief \u975E\u8CA0\u6574\u6570\u3092\u7BA1\
    \u7406\u3059\u308B64\u5206\u6728\u3002 W\u306F\u6728\u306E\u9AD8\u3055\n\t\tW\
    \ = 3  [0, 262'143]        3MB 1ms  \n\t\tW = 4  [0, 16'777'215]     5MB 2ms\n\
    \t\tW = 5  [0, 1'073'741'823]  136MB 60ms\n\n\t\tinsert(x) x\u3092\u633F\u5165\
    \u3059\u308B\u3002\u5B58\u5728\u3059\u308B\u306A\u3089\u306A\u306B\u3082\u3057\
    \u306A\u3044\u3002 O(W)\n\t\terase(x) x\u3092\u524A\u9664\u3002\u5B58\u5728\u3057\
    \u306A\u3044\u6642\u306A\u306B\u3082\u3057\u306A\u3044\u3002 O(W)\n\t\tcount(x)\
    \ x\u304C\u5B58\u5728\u3059\u308B\u304B\u3002O(W)\n\t\tmin_element()/max_element()\
    \ \u6700\u5C0F\u30FB\u6700\u5927\u8981\u7D20\u3002\u8981\u7D20\u65700\u306A\u3089\
    assert\u3002 O(W)\n\t\tlower_bound(x) x\u4EE5\u4E0A\u6700\u5C0F\u3002\u5B58\u5728\
    \u3057\u306A\u3044\u306A\u3089-1 O(W)\n\t\tlower_left_bound(x) x\u4EE5\u4E0B\u6700\
    \u5927\u3002\u5B58\u5728\u3057\u306A\u3044\u306A\u3089-1. O(W)\n\t\tsize(), empty()\
    \ ... O(1)\n\t\n\t*/\n};\n"
  code: "struct fastset {\n\tusing ll = long long;\n\tusing ull = unsigned long long;\n\
    \tint W;\n\tll siz;\n\tvector<int> B = {0, 6, 12, 18, 24, 30, 36, 42};\n\tvector<ull>\
    \ mask;\n\tvector<ull> mask_rev;\n\tvector<vector<ull>> tr;\n\n\tfastset(){}\n\
    \n\tfastset(int _W) : W(_W) {\n\t\ttr.resize(W);\n\t\tmask.resize(65,0);\n\t\t\
    mask_rev.resize(65, 18446744073709551615ULL);\n\t\tsiz = 0;\n\t\tfor(int i = 0;\
    \ i < W; i++) {\n\t\t\ttr[i].resize(1ULL << B[W-i-1], 0);\n\t\t}\n\t\tfor(int\
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
    if((tr[i][res] & mask_rev[63-(Q(x, B[i])&63)]) == 0) return 18446744073709551615ULL;\n\
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
    \t    \t\t}\n\t    \t\telse {\n\t    \t\t\tif((tr[i][res]&mask[(Q(x, B[i])&63)])\
    \ == 0) return 0ULL;\n\t    \t\t\treturn lower_left_bound__(x, i-1, res << 6 |\
    \ (63-__builtin_clzll(tr[i][res]&mask[(Q(x, B[i])&63)])));\n\t    \t\t}\n\t  \
    \  \t}\n\t    \telse {\n\t    \t\treturn lower_left_bound__(x, i-1, res << 6 |\
    \ (63-__builtin_clzll(tr[i][res])));\n\t    \t}\n\t    }\n\n\tpublic:\n\n\n\t\
    \    void insert(ll x) {\n\t    \tif(count(x))return;\n\t    \tsiz++;\n\t    \t\
    for(int i = W-1; i >= 0; i--) {\n\t    \t\ttr[i][Q(x, B[i+1])] |= 1ULL << (Q(x,\
    \ B[i])&63);\n\t    \t}\n\t    }\n    \n\t    void erase(ll x) {\n\t    \tif(!count(x))return;\n\
    \t    \tsiz--;\n\t    \ttr[0][Q(x, 6)] ^= 1ULL << (x&63);\n\t    \tfor (int i\
    \ = 1; i < W; i++) {\n\t    \t\tull d = (!tr[i-1][Q(x, B[i])]);\n\t    \t\ttr[i][Q(x,\
    \ B[i+1])] ^= d << (Q(x, B[i])&63);\n\t    \t}\n\t    }\n    \n\t    int count(ll\
    \ x) {\n\t    \treturn tr[0][Q(x, 6)] >> (x&63) & 1;\n\t    }\n    \n\t    ll\
    \ min_element() {\n\t\t\tassert(siz!=0);\n\t    \tull res = 0;\n\t    \tfor(int\
    \ i = W-1; i >= 0; i--) {\n\t    \t\tres = res << 6 | __builtin_ctzll(tr[i][res]);\n\
    \t    \t}\n\t    \treturn res;\n\t    }\n    \n\t    ll max_element() {\n\t\t\t\
    assert(siz!=0);\n\t    \tull res = 0;\n\t    \tfor(int i = W-1; i >= 0; i--) {\n\
    \t    \t\tres = res << 6 | (63-__builtin_clzll(tr[i][res]));\n\t    \t}\n\t  \
    \  \treturn res;\n\t    }\n    \n\t    ll lower_bound(ll x) {\n\t\t\tif(siz==0\
    \ || max_element() < x) return -1LL;\n\t    \treturn lower_bound__(x,W-1,0);\n\
    \t    }\n    \n\t    ll lower_left_bound(ll x) {\n\t\t\tif(siz==0 || min_element()\
    \ > x) return -1LL;\n\t    \treturn lower_left_bound__(x,W-1,0);\n\t    }\n  \
    \  \n\t    ll size() {\n\t    \treturn siz;\n\t    }\n    \n\t    bool empty()\
    \ {\n\t    \treturn siz==0;\n\t    }\n    \n\t    void dump() {\n\t    \tll M\
    \ = 1LL << B[W];\n\t    \tM--;\n\t    \tfor(int i = 0; i <= M; i++) {\n\t    \t\
    \tif(count(i)) cout << i << \" \";\n\t    \t}\n\t    \tcout << endl;\n\t    }\n\
    \    \n\t/*\n\t    fastset(W) \n\t\t@brief \u975E\u8CA0\u6574\u6570\u3092\u7BA1\
    \u7406\u3059\u308B64\u5206\u6728\u3002 W\u306F\u6728\u306E\u9AD8\u3055\n\t\tW\
    \ = 3  [0, 262'143]        3MB 1ms  \n\t\tW = 4  [0, 16'777'215]     5MB 2ms\n\
    \t\tW = 5  [0, 1'073'741'823]  136MB 60ms\n\n\t\tinsert(x) x\u3092\u633F\u5165\
    \u3059\u308B\u3002\u5B58\u5728\u3059\u308B\u306A\u3089\u306A\u306B\u3082\u3057\
    \u306A\u3044\u3002 O(W)\n\t\terase(x) x\u3092\u524A\u9664\u3002\u5B58\u5728\u3057\
    \u306A\u3044\u6642\u306A\u306B\u3082\u3057\u306A\u3044\u3002 O(W)\n\t\tcount(x)\
    \ x\u304C\u5B58\u5728\u3059\u308B\u304B\u3002O(W)\n\t\tmin_element()/max_element()\
    \ \u6700\u5C0F\u30FB\u6700\u5927\u8981\u7D20\u3002\u8981\u7D20\u65700\u306A\u3089\
    assert\u3002 O(W)\n\t\tlower_bound(x) x\u4EE5\u4E0A\u6700\u5C0F\u3002\u5B58\u5728\
    \u3057\u306A\u3044\u306A\u3089-1 O(W)\n\t\tlower_left_bound(x) x\u4EE5\u4E0B\u6700\
    \u5927\u3002\u5B58\u5728\u3057\u306A\u3044\u306A\u3089-1. O(W)\n\t\tsize(), empty()\
    \ ... O(1)\n\t\n\t*/\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DetaStructures/fastset.cpp
  requiredBy: []
  timestamp: '2024-05-10 22:41:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DetaStructures/fastset.cpp
layout: document
redirect_from:
- /library/DetaStructures/fastset.cpp
- /library/DetaStructures/fastset.cpp.html
title: "\u975E\u8CA0\u6574\u6570\u3092\u7BA1\u7406\u3059\u308B64\u5206\u6728\u3002\
  \ W\u306F\u6728\u306E\u9AD8\u3055"
---
