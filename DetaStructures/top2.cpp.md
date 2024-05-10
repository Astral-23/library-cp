---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: ': top2'
    links: []
  bundledCode: "#line 1 \"DetaStructures/top2.cpp\"\ntemplate<typename K, typename\
    \ X>\nstruct top2 {\n    struct D {\n        K key;\n        X val;\n    \n  \
    \      D(){}\n        D(K _key, X _val) : key(_key), val(_val){}\n    \n     \
    \   static D ide() {\n            //Edit here   return D(-1, -BIG);\n        }\n\
    \    };\n    \n    D a = D::ide();\n    D b = D::ide();\n    top2(){}\n\n    void\
    \ add(K key, X val) {\n        if(b.val < val) {\n            swap(b.val, val);\n\
    \            swap(b.key, key);\n        }\n        if(a.val < b.val) {\n     \
    \       swap(a.val, b.val);\n            swap(a.key, b.key);\n        }\n    \
    \    if(a.key == b.key) {\n            b.val = val;\n            b.key = key;\n\
    \        }\n    }\n\n    X get(K key) {\n        if(a.key==key) return b.val;\n\
    \        else return a.val;\n    }\n\n    /*\n        top2<K, X>() O(1)\n    \
    \    @brief : top2\n        add(key, val) KEY\u3068\u3057\u3066key\u304C\u4ED8\
    \u52A0\u3055\u308C\u305F\u5024\u3092\u8FFD\u52A0\u3059\u308B.  O(1)\n        get(key)\
    \ \u767B\u9332\u3055\u308C\u305F\u5024\u306E\u4E2D\u3067\u3001\u4ED8\u52A0\u3055\
    \u308C\u305FKEY\u304Ckey\u3067\u306A\u3044\u3082\u306E\u306E\u6700\u5927\u3092\
    \u53D6\u5F97\u3002 O(1)\n\n        \u6CE8\u610F\uFF1A\u524A\u9664\u4E0D\u53EF\
    \        \n    */\n};\n"
  code: "template<typename K, typename X>\nstruct top2 {\n    struct D {\n       \
    \ K key;\n        X val;\n    \n        D(){}\n        D(K _key, X _val) : key(_key),\
    \ val(_val){}\n    \n        static D ide() {\n            //Edit here   return\
    \ D(-1, -BIG);\n        }\n    };\n    \n    D a = D::ide();\n    D b = D::ide();\n\
    \    top2(){}\n\n    void add(K key, X val) {\n        if(b.val < val) {\n   \
    \         swap(b.val, val);\n            swap(b.key, key);\n        }\n      \
    \  if(a.val < b.val) {\n            swap(a.val, b.val);\n            swap(a.key,\
    \ b.key);\n        }\n        if(a.key == b.key) {\n            b.val = val;\n\
    \            b.key = key;\n        }\n    }\n\n    X get(K key) {\n        if(a.key==key)\
    \ return b.val;\n        else return a.val;\n    }\n\n    /*\n        top2<K,\
    \ X>() O(1)\n        @brief : top2\n        add(key, val) KEY\u3068\u3057\u3066\
    key\u304C\u4ED8\u52A0\u3055\u308C\u305F\u5024\u3092\u8FFD\u52A0\u3059\u308B. \
    \ O(1)\n        get(key) \u767B\u9332\u3055\u308C\u305F\u5024\u306E\u4E2D\u3067\
    \u3001\u4ED8\u52A0\u3055\u308C\u305FKEY\u304Ckey\u3067\u306A\u3044\u3082\u306E\
    \u306E\u6700\u5927\u3092\u53D6\u5F97\u3002 O(1)\n\n        \u6CE8\u610F\uFF1A\u524A\
    \u9664\u4E0D\u53EF        \n    */\n};"
  dependsOn: []
  isVerificationFile: false
  path: DetaStructures/top2.cpp
  requiredBy: []
  timestamp: '2024-05-10 22:34:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DetaStructures/top2.cpp
layout: document
redirect_from:
- /library/DetaStructures/top2.cpp
- /library/DetaStructures/top2.cpp.html
title: ': top2'
---
