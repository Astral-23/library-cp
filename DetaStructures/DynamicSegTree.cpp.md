---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"DetaStructures/DynamicSegTree.cpp\"\ntemplate<typename X,\
    \ typename W>\nstruct DynamicSegTree {// max_pos < LLONG_MAX(\u958B\u533A\u9593\
    \u306E\u5F0A\u5BB3)\n    \n\n    W  min_pos;\n    W  max_pos;//\u6E21\u3059\u6642\
    \u306F\u9589\u533A\u9593\u3060\u304C\u3001\u958B\u533A\u9593\u3067\u6271\u3046\
    \u3002\n    DynamicSegTree(){} \n    DynamicSegTree(W _min_pos, W _max_pos) :\
    \  min_pos(_min_pos), max_pos(_max_pos) {\n        assert(min_pos <= max_pos);//\u9069\
    \u5207\u306A\u533A\u9593\u304C\u6307\u5B9A\u3055\u308C\u3066\u3044\u308B\u304B\
    \n        assert(max_pos < LLONG_MAX);\n\t\tmax_pos++;\n\n    };\n\n\n    private:\n\
    \        struct Node {\n            W pos;\n            X val;\n            X\
    \ prod;\n            Node* lch;\n\t\t\tNode* rch;\n        \n            Node(W\
    \ p, X v, X pro) : pos(p), val(v), prod(pro) {\n                lch = nullptr;\n\
    \t\t\t\trch = nullptr;\n            }\n        };\n        \n        Node* root\
    \ = nullptr;\n\n \n       \n        X value(Node* now) {\n            return now!=nullptr\
    \ ? now -> prod : X::ide(); \n        }\n\n        Node* change__(Node* now, W&\
    \ a, W& b, W& p, X& x) {\n            if(now == nullptr) {\n                now\
    \ = new Node(p, x, x);\n                return now;\n            }\n         \
    \   if(now -> pos == p) {\n                now -> val = update(now -> val, x);\n\
    \                now -> prod = op(value(now -> lch), op(now -> val, value(now\
    \ -> rch)));//\u533A\u9593\u3092\u7BA1\u7406\u3059\u308B\u30CE\u30FC\u30C9\u306E\
    \u7B54\u3048\u3092\u8FD4\u3059(\u5DE6\u5B50\u30FB\u3053\u306E\u30CE\u30FC\u30C9\
    \u306B\u5165\u3063\u3066\u308B\u5206(\u5E38\u306B1\u30CE\u30FC\u30C9\u5206\uFF09\
    \u30FB\u53F3\u5B50)\n                return now;\n            }\n            \n\
    \            W mid = (a+b)>>1;\n            if(p < mid) {\n                if(now\
    \ -> pos < p) swap(p, now -> pos), swap(x, now -> val);//\u5B50\u306E\u65B9\u304C\
    \u9806\u5E8F\u304C\u5DE6\u306B\u306A\u308B\u3088\u3046\u306B\n               \
    \ now -> lch = change__(now -> lch, a, mid, p, x);\n            }\n          \
    \  else {\n                if(now -> pos > p) swap(p, now -> pos), swap(x, now\
    \ -> val);//\u5B50\u306E\u65B9\u304C\u9806\u5E8F\u304C\u53F3\u306B\u306A\u308B\
    \u3088\u3046\u306B\n                now -> rch = change__(now -> rch, mid, b,\
    \ p, x);\n            }\n            now -> prod = op(value(now -> lch), op(now\
    \ -> val, value(now -> rch)));\n            return now;\n        }\n\n       \
    \ X get__(Node* now, W& a, W& b, W l, W r) {// [l, r) := \u30AF\u30A8\u30EA\u533A\
    \u9593  [a, b) := \u4ECA\u898B\u3066\u3044\u308B\u533A\u9593   [a, b]\u3067\u306E\
    \u7D50\u679C\u3092\u8FD4\u3059\u3002\n            if(b <= l || r <= a) return\
    \ X::ide();//\u7BC4\u56F2\u5916\u306A\u3089\u5358\u4F4D\u5143\n            if(now\
    \ == nullptr) return X::ide();//\u7BC4\u56F2\u5185\u306B\u3064\u3044\u3066\u3001\
    \u30C7\u30FC\u30BF\u304C\u5B58\u5728\u3057\u306A\u3044\u306A\u3089\u5358\u4F4D\
    \u5143\n            if(l <= a && b <= r) return now -> prod;//\u5B8C\u5168\u306B\
    \u542B\u307E\u308C\u3066\u3044\u308B\u306A\u3089\u8FD4\u3059\u3002\n         \
    \   W mid = (a+b)>>1;\n            X res = get__(now -> lch, a, mid, l, r);\n\
    \            if(l <= now -> pos && now -> pos < r) res = op(res, now -> val);//[a\
    \ , b)\u306E\u5024\u306E\u5C45\u5834\u6240 : \u4ECA\u898B\u3066\u3044\u308B\u30CE\
    \u30FC\u30C9\u304C\u6301\u3063\u3066\u3044\u308B\u5024\u306E\u6DFB\u3048\u5B57\
    \u3092id\u3068\u3057\u3066 [a, id)\u3092\u5DE6\u306E\u5B50\u304C\u3001id\u3092\
    \u3053\u308C\u304C\u3001(id, b)\u3092\u53F3\u306E\u5B50\u304C\u6301\u3063\u3066\
    \u3044\u308B\u3002\n            return op(res, get__(now -> rch, mid, b, l, r));//\u4ECA\
    \u898B\u3066\u3044\u308B\u30CE\u30FC\u30C9\u304C\u6301\u3064\u7BC4\u56F2\u306E\
    \u5206\u304C\u8A08\u7B97\u3057\u7D42\u308F\u3063\u305F\u306E\u3067\u3001\u8FD4\
    \u3059\u3002\n\n        }\n\n\n\n    public:\n        void change(W pos, X x)\
    \ {\n           root = change__(root, min_pos, max_pos, pos, x);\n        }\n\n\
    \        X  get(W l, W r) {\n            return get__(root, min_pos, max_pos,\
    \ l, r+1);\n        }\n\n\t\t/*\n\t\t    DynamicSegTree<X, W> seg(minpos, maxpos)\
    \  X...\u30C7\u30FC\u30BF W...\u6DFB\u5B57\u306E\u578B  O(1)\n\t\t\t@brief: \u52D5\
    \u7684\u30BB\u30B0\u6728\n\t\t\n\t\t*/\n\n};\n\nstruct Monoid {\n    mint a, b;\n\
    \    \n    Monoid(){}\n    Monoid(mint _a, mint _b) : a(_a), b(_b){};\n\n    friend\
    \ Monoid op(const Monoid& l, const Monoid& r) {\n        Monoid res;\n       \
    \ res.a = l.a * r.a;\n        res.b = r.a * l.b + r.b;\n        return res;\n\
    \    } \n    friend Monoid update(const Monoid& l, const Monoid& x) {\n      \
    \  return x;\n    }\n\n\n\tstatic Monoid ide() {\n\t\treturn Monoid(1, 0);\n\t\
    }\n};\n"
  code: "template<typename X, typename W>\nstruct DynamicSegTree {// max_pos < LLONG_MAX(\u958B\
    \u533A\u9593\u306E\u5F0A\u5BB3)\n    \n\n    W  min_pos;\n    W  max_pos;//\u6E21\
    \u3059\u6642\u306F\u9589\u533A\u9593\u3060\u304C\u3001\u958B\u533A\u9593\u3067\
    \u6271\u3046\u3002\n    DynamicSegTree(){} \n    DynamicSegTree(W _min_pos, W\
    \ _max_pos) :  min_pos(_min_pos), max_pos(_max_pos) {\n        assert(min_pos\
    \ <= max_pos);//\u9069\u5207\u306A\u533A\u9593\u304C\u6307\u5B9A\u3055\u308C\u3066\
    \u3044\u308B\u304B\n        assert(max_pos < LLONG_MAX);\n\t\tmax_pos++;\n\n \
    \   };\n\n\n    private:\n        struct Node {\n            W pos;\n        \
    \    X val;\n            X prod;\n            Node* lch;\n\t\t\tNode* rch;\n \
    \       \n            Node(W p, X v, X pro) : pos(p), val(v), prod(pro) {\n  \
    \              lch = nullptr;\n\t\t\t\trch = nullptr;\n            }\n       \
    \ };\n        \n        Node* root = nullptr;\n\n \n       \n        X value(Node*\
    \ now) {\n            return now!=nullptr ? now -> prod : X::ide(); \n       \
    \ }\n\n        Node* change__(Node* now, W& a, W& b, W& p, X& x) {\n         \
    \   if(now == nullptr) {\n                now = new Node(p, x, x);\n         \
    \       return now;\n            }\n            if(now -> pos == p) {\n      \
    \          now -> val = update(now -> val, x);\n                now -> prod =\
    \ op(value(now -> lch), op(now -> val, value(now -> rch)));//\u533A\u9593\u3092\
    \u7BA1\u7406\u3059\u308B\u30CE\u30FC\u30C9\u306E\u7B54\u3048\u3092\u8FD4\u3059\
    (\u5DE6\u5B50\u30FB\u3053\u306E\u30CE\u30FC\u30C9\u306B\u5165\u3063\u3066\u308B\
    \u5206(\u5E38\u306B1\u30CE\u30FC\u30C9\u5206\uFF09\u30FB\u53F3\u5B50)\n      \
    \          return now;\n            }\n            \n            W mid = (a+b)>>1;\n\
    \            if(p < mid) {\n                if(now -> pos < p) swap(p, now ->\
    \ pos), swap(x, now -> val);//\u5B50\u306E\u65B9\u304C\u9806\u5E8F\u304C\u5DE6\
    \u306B\u306A\u308B\u3088\u3046\u306B\n                now -> lch = change__(now\
    \ -> lch, a, mid, p, x);\n            }\n            else {\n                if(now\
    \ -> pos > p) swap(p, now -> pos), swap(x, now -> val);//\u5B50\u306E\u65B9\u304C\
    \u9806\u5E8F\u304C\u53F3\u306B\u306A\u308B\u3088\u3046\u306B\n               \
    \ now -> rch = change__(now -> rch, mid, b, p, x);\n            }\n          \
    \  now -> prod = op(value(now -> lch), op(now -> val, value(now -> rch)));\n \
    \           return now;\n        }\n\n        X get__(Node* now, W& a, W& b, W\
    \ l, W r) {// [l, r) := \u30AF\u30A8\u30EA\u533A\u9593  [a, b) := \u4ECA\u898B\
    \u3066\u3044\u308B\u533A\u9593   [a, b]\u3067\u306E\u7D50\u679C\u3092\u8FD4\u3059\
    \u3002\n            if(b <= l || r <= a) return X::ide();//\u7BC4\u56F2\u5916\u306A\
    \u3089\u5358\u4F4D\u5143\n            if(now == nullptr) return X::ide();//\u7BC4\
    \u56F2\u5185\u306B\u3064\u3044\u3066\u3001\u30C7\u30FC\u30BF\u304C\u5B58\u5728\
    \u3057\u306A\u3044\u306A\u3089\u5358\u4F4D\u5143\n            if(l <= a && b <=\
    \ r) return now -> prod;//\u5B8C\u5168\u306B\u542B\u307E\u308C\u3066\u3044\u308B\
    \u306A\u3089\u8FD4\u3059\u3002\n            W mid = (a+b)>>1;\n            X res\
    \ = get__(now -> lch, a, mid, l, r);\n            if(l <= now -> pos && now ->\
    \ pos < r) res = op(res, now -> val);//[a , b)\u306E\u5024\u306E\u5C45\u5834\u6240\
    \ : \u4ECA\u898B\u3066\u3044\u308B\u30CE\u30FC\u30C9\u304C\u6301\u3063\u3066\u3044\
    \u308B\u5024\u306E\u6DFB\u3048\u5B57\u3092id\u3068\u3057\u3066 [a, id)\u3092\u5DE6\
    \u306E\u5B50\u304C\u3001id\u3092\u3053\u308C\u304C\u3001(id, b)\u3092\u53F3\u306E\
    \u5B50\u304C\u6301\u3063\u3066\u3044\u308B\u3002\n            return op(res, get__(now\
    \ -> rch, mid, b, l, r));//\u4ECA\u898B\u3066\u3044\u308B\u30CE\u30FC\u30C9\u304C\
    \u6301\u3064\u7BC4\u56F2\u306E\u5206\u304C\u8A08\u7B97\u3057\u7D42\u308F\u3063\
    \u305F\u306E\u3067\u3001\u8FD4\u3059\u3002\n\n        }\n\n\n\n    public:\n \
    \       void change(W pos, X x) {\n           root = change__(root, min_pos, max_pos,\
    \ pos, x);\n        }\n\n        X  get(W l, W r) {\n            return get__(root,\
    \ min_pos, max_pos, l, r+1);\n        }\n\n\t\t/*\n\t\t    DynamicSegTree<X, W>\
    \ seg(minpos, maxpos)  X...\u30C7\u30FC\u30BF W...\u6DFB\u5B57\u306E\u578B  O(1)\n\
    \t\t\t@brief: \u52D5\u7684\u30BB\u30B0\u6728\n\t\t\n\t\t*/\n\n};\n\nstruct Monoid\
    \ {\n    mint a, b;\n    \n    Monoid(){}\n    Monoid(mint _a, mint _b) : a(_a),\
    \ b(_b){};\n\n    friend Monoid op(const Monoid& l, const Monoid& r) {\n     \
    \   Monoid res;\n        res.a = l.a * r.a;\n        res.b = r.a * l.b + r.b;\n\
    \        return res;\n    } \n    friend Monoid update(const Monoid& l, const\
    \ Monoid& x) {\n        return x;\n    }\n\n\n\tstatic Monoid ide() {\n\t\treturn\
    \ Monoid(1, 0);\n\t}\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: DetaStructures/DynamicSegTree.cpp
  requiredBy: []
  timestamp: '2024-05-10 22:23:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DetaStructures/DynamicSegTree.cpp
layout: document
redirect_from:
- /library/DetaStructures/DynamicSegTree.cpp
- /library/DetaStructures/DynamicSegTree.cpp.html
title: DetaStructures/DynamicSegTree.cpp
---
