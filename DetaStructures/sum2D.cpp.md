---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: ": 2\u6B21\u5143\u7D2F\u7A4D\u548C"
    links: []
  bundledCode: "#line 1 \"DetaStructures/sum2D.cpp\"\ntemplate<typename T>\nstruct\
    \ sum2D {\n    int H; int W;\n    vector<vector<T>> table;\n\tbool inited;\n\n\
    \    sum2D(int _H, int _W) : H(_H), W(_W) {\n        table = vector<vector<T>>(H+1,\
    \ vector<T>(W+1, T(0)));\n\t\tinited = false;\n    }\n\n\tsum2D(vector<vector<T>>&\
    \ A) {\n\t\tassert(A.size()>=1);\n\t\tH = A.size()-1;\n\t\tW = A[0].size()-1;\n\
    \t\ttable = A;\n\t\tinit();\n\t}\n\n\n    private:\n        void init__() {\n\
    \            for(int i = 0; i <= H; i++) {\n                for(int j = 1; j <=\
    \ W; j++) {\n                    table[i][j] += table[i][j-1];\n             \
    \   }\n            }\n\n\t\t\tfor(int i = 1; i <= H; i++) {\n\t\t\t\tfor(int j\
    \ = 0; j <= W; j++) {\n\t\t\t\t\ttable[i][j] += table[i-1][j];\n\t\t\t\t}\n\t\t\
    \t}\n        }\n\n\n    public:\n        void add(int y, int x, T val) {\n   \
    \         table[y][x] += val;\n        }\n\n        void init() {\n          \
    \  init__();\n\t\t\tinited = true;\n        }\n\n\n        T get(int sy, int ty,\
    \ int sx, int tx) {\n\t\t\tassert(inited);\n\t\t\tassert(0 <= sy && sy <= H &&\
    \ 0 <= sx && tx <= W);\n            T res = table[ty][tx];\n            if(sy\
    \ >= 1 && sx >= 1) res += table[sy-1][sx-1];\n            if(sy >= 1) res -= table[sy-1][tx];\n\
    \            if(sx >= 1) res -= table[ty][sx-1];\n            return res;\n  \
    \      }\n\n        /*\n            sum2D<T> (H, W)   O(HW)\n\t\t\tsum2D<T> (vector<vector<T>>\
    \ A)   O(HW)    \u7A7A\u914D\u5217\u3092\u6E21\u3057\u3066\u306F\u3044\u3051\u306A\
    \u3044\u3002\n            @brief : 2\u6B21\u5143\u7D2F\u7A4D\u548C\n\n       \
    \     add(y, x, val) ... (y, x) \u306B val\u3092\u8DB3\u3059\u3002 O(1)\n    \
    \        init() ... \u7D2F\u7A4D\u548C\u3092\u8A08\u7B97\u3059\u308B\u3002  O(HW)\t\
    \t\n\t\t\t--\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\u306B\u914D\u5217\u3092\
    \u6E21\u3057\u305F\u5834\u5408\u3001\u4E0A\u4E8C\u3064\u3092\u4F7F\u3063\u3066\
    \u306F\u3044\u3051\u306A\u3044--\n            get(sy, ty, sx, tx) ... [sy, ty]\
    \ * [sx, tx]\u306E\u77E9\u5F62\u548C\u3092\u53D6\u5F97\u3002 O(1)\n        \n\
    \        */\n\n};\n"
  code: "template<typename T>\nstruct sum2D {\n    int H; int W;\n    vector<vector<T>>\
    \ table;\n\tbool inited;\n\n    sum2D(int _H, int _W) : H(_H), W(_W) {\n     \
    \   table = vector<vector<T>>(H+1, vector<T>(W+1, T(0)));\n\t\tinited = false;\n\
    \    }\n\n\tsum2D(vector<vector<T>>& A) {\n\t\tassert(A.size()>=1);\n\t\tH = A.size()-1;\n\
    \t\tW = A[0].size()-1;\n\t\ttable = A;\n\t\tinit();\n\t}\n\n\n    private:\n \
    \       void init__() {\n            for(int i = 0; i <= H; i++) {\n         \
    \       for(int j = 1; j <= W; j++) {\n                    table[i][j] += table[i][j-1];\n\
    \                }\n            }\n\n\t\t\tfor(int i = 1; i <= H; i++) {\n\t\t\
    \t\tfor(int j = 0; j <= W; j++) {\n\t\t\t\t\ttable[i][j] += table[i-1][j];\n\t\
    \t\t\t}\n\t\t\t}\n        }\n\n\n    public:\n        void add(int y, int x, T\
    \ val) {\n            table[y][x] += val;\n        }\n\n        void init() {\n\
    \            init__();\n\t\t\tinited = true;\n        }\n\n\n        T get(int\
    \ sy, int ty, int sx, int tx) {\n\t\t\tassert(inited);\n\t\t\tassert(0 <= sy &&\
    \ sy <= H && 0 <= sx && tx <= W);\n            T res = table[ty][tx];\n      \
    \      if(sy >= 1 && sx >= 1) res += table[sy-1][sx-1];\n            if(sy >=\
    \ 1) res -= table[sy-1][tx];\n            if(sx >= 1) res -= table[ty][sx-1];\n\
    \            return res;\n        }\n\n        /*\n            sum2D<T> (H, W)\
    \   O(HW)\n\t\t\tsum2D<T> (vector<vector<T>> A)   O(HW)    \u7A7A\u914D\u5217\u3092\
    \u6E21\u3057\u3066\u306F\u3044\u3051\u306A\u3044\u3002\n            @brief : 2\u6B21\
    \u5143\u7D2F\u7A4D\u548C\n\n            add(y, x, val) ... (y, x) \u306B val\u3092\
    \u8DB3\u3059\u3002 O(1)\n            init() ... \u7D2F\u7A4D\u548C\u3092\u8A08\
    \u7B97\u3059\u308B\u3002  O(HW)\t\t\n\t\t\t--\u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\
    \u30BF\u306B\u914D\u5217\u3092\u6E21\u3057\u305F\u5834\u5408\u3001\u4E0A\u4E8C\
    \u3064\u3092\u4F7F\u3063\u3066\u306F\u3044\u3051\u306A\u3044--\n            get(sy,\
    \ ty, sx, tx) ... [sy, ty] * [sx, tx]\u306E\u77E9\u5F62\u548C\u3092\u53D6\u5F97\
    \u3002 O(1)\n        \n        */\n\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DetaStructures/sum2D.cpp
  requiredBy: []
  timestamp: '2024-05-10 22:34:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DetaStructures/sum2D.cpp
layout: document
redirect_from:
- /library/DetaStructures/sum2D.cpp
- /library/DetaStructures/sum2D.cpp.html
title: ": 2\u6B21\u5143\u7D2F\u7A4D\u548C"
---
