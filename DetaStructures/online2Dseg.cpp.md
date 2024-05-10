---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: ": \u52D5\u76842\u6B21\u5143\u30BB\u30B0\u6728"
    links: []
  bundledCode: "#line 1 \"DetaStructures/online2Dseg.cpp\"\ntemplate<typename X, typename\
    \ W>\nstruct DynamicSegTree {// max_pos < LLONG_MAX(\u958B\u533A\u9593\u306E\u5F0A\
    \u5BB3)\n    \n\n    W  min_pos;\n    W  max_pos;//\u6E21\u3059\u6642\u306F\u9589\
    \u533A\u9593\u3060\u304C\u3001\u958B\u533A\u9593\u3067\u6271\u3046\u3002\n   \
    \ DynamicSegTree(){} \n    DynamicSegTree(W _min_pos, W _max_pos) :  min_pos(_min_pos),\
    \ max_pos(_max_pos) {\n        assert(min_pos <= max_pos);//\u9069\u5207\u306A\
    \u533A\u9593\u304C\u6307\u5B9A\u3055\u308C\u3066\u3044\u308B\u304B\n        assert(max_pos\
    \ < LLONG_MAX);\n\t\tmax_pos++;\n\n    };\n\n\n    private:\n        struct Node\
    \ {\n            W pos;\n            X val;\n            X prod;\n           \
    \ Node* lch;\n\t\t\tNode* rch;\n        \n            Node(W p, X v, X pro) :\
    \ pos(p), val(v), prod(pro) {\n                lch = nullptr;\n\t\t\t\trch = nullptr;\n\
    \            }\n        };\n        \n        Node* root = nullptr;\n\n \n   \
    \    \n        X value(Node* now) {\n            return now!=nullptr ? now ->\
    \ prod : X::ide(); \n        }\n\n        Node* change__(Node* now, W& a, W& b,\
    \ W& p, X& x) {\n            if(now == nullptr) {\n                now = new Node(p,\
    \ x, x);\n                return now;\n            }\n            if(now -> pos\
    \ == p) {\n                now -> val = update(now -> val, x);\n             \
    \   now -> prod = op(value(now -> lch), op(now -> val, value(now -> rch)));//\u533A\
    \u9593\u3092\u7BA1\u7406\u3059\u308B\u30CE\u30FC\u30C9\u306E\u7B54\u3048\u3092\
    \u8FD4\u3059(\u5DE6\u5B50\u30FB\u3053\u306E\u30CE\u30FC\u30C9\u306B\u5165\u3063\
    \u3066\u308B\u5206(\u5E38\u306B1\u30CE\u30FC\u30C9\u5206\uFF09\u30FB\u53F3\u5B50\
    )\n                return now;\n            }\n            \n            W mid\
    \ = (a+b)>>1;\n            if(p < mid) {\n                if(now -> pos < p) swap(p,\
    \ now -> pos), swap(x, now -> val);//\u5B50\u306E\u65B9\u304C\u9806\u5E8F\u304C\
    \u5DE6\u306B\u306A\u308B\u3088\u3046\u306B\n                now -> lch = change__(now\
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
    \ min_pos, max_pos, l, r+1);\n        }\n\n\t\t/*\n\t\t    UnlimitedSegTree<X,\
    \ W> seg(minpos, maxpos)  X...\u30C7\u30FC\u30BF W...\u6DFB\u5B57\u306E\u578B\
    \  O(1)\n\t\t\t@brief: \u52D5\u7684\u30BB\u30B0\u6728\n\t\t\n\t\t*/\n\n};\n\n\
    template<typename X, typename W>\nstruct online2Dseg {\n\n    W MIN_H, MAX_H,\
    \ MIN_W, MAX_W;\n    online2Dseg(W _MIN_H, W _MAX_H, W _MIN_W, W _MAX_W) :  MIN_H(_MIN_H),\
    \ MAX_H(_MAX_H), MIN_W(_MIN_W), MAX_W(_MAX_W) {\n\t\tMAX_H++;  MAX_W++;\n\t}\n\
    \n    private:\n        struct NODE {\n            UnlimitedSegTree<X, W> subtree;\n\
    \            NODE* lch;\n\t\t\tNODE* rch;\n            \n            NODE(W _MIN_W,\
    \ W _MAX_W) {\n              subtree = DynamicSegTree<X, W>(_MIN_W, _MAX_W-1);\n\
    \              lch = nullptr;\n              rch = nullptr;\n            }\n \
    \       };\n\n        NODE* root = nullptr;\n\n    \n \n        void change__(NODE*&\
    \ now, W& a, W& b, W& h, W& w,  X& val) {//\u6728\u306E\u69CB\u9020\u304C\u5909\
    \u5316\u3057\u306A\u3044\u306A\u3089\u3001\u69CB\u6210\u3057\u76F4\u3059\u5FC5\
    \u8981\u3082\u7121\u3044\uFF08splay\u6728\u7B49\u6839\u304C\u5909\u308F\u308A\u3046\
    \u308B\u3084\u3064\u306F\u8A71\u304C\u5225\uFF09\n            if(now == nullptr)\
    \  now = new NODE(MIN_W, MAX_W);\n            now -> subtree.change(w, val);//h\u3092\
    \u542B\u3080\u533A\u9593\u3092\u6301\u3064\u90E8\u5206\u6728\u306B\u5024\u3092\
    \u767B\u9332\u3002\u3053\u306E\u6642\u3001x(w)\u5EA7\u6A19\u3092\u767B\u9332\u3059\
    \u308B\u3002\n            W mid = (a+b)>>1;\n            if(b - a == 1) return;//\u8449\
    \u307E\u3067\u767B\u9332\u3057\u305F\u3089\u7D42\u308F\u308A\u3002\n         \
    \   if(h < mid) change__(now -> lch, a, mid, h, w, val);\n            else change__(now\
    \ -> rch, mid, b, h, w, val);\n        }\n\n        \n        X get__(NODE*& now,\
    \ W& a, W& b, W& sy, W& ty, W& sx, W& tx) {// [sy, ty) \xD7 [sx, tx) := \u30AF\
    \u30A8\u30EA\u533A\u9593  [a, b) := \u4ECA\u898B\u3066\u3044\u308By(h)\u5EA7\u6A19\
    \u306E\u533A\u9593   y = [sy, ty)\u3067\u306E\u7D50\u679C\u3092\u8FD4\u3059\u3002\
    \n            if(b <= sy || ty <= a) return X::ide();//\u7BC4\u56F2\u5916\u306A\
    \u3089\u5358\u4F4D\u5143\n            if(now == nullptr) return X::ide();//\u7BC4\
    \u56F2\u5185\u306B\u3064\u3044\u3066\u3001\u30C7\u30FC\u30BF\u304C\u5B58\u5728\
    \u3057\u306A\u3044\u306A\u3089\u5358\u4F4D\u5143//(\u3053\u308C\u3088\u308A\u5B50\
    \u306F\u3001\u4ECA\u3088\u308A\u533A\u9593\u304C\u72ED\u3044\u5B50\u3057\u304B\
    \u5B58\u5728\u3057\u5F97\u306A\u3044\u304B\u3089\u6253\u3061\u5207\u3063\u3066\
    \u826F\u3044\u3002\uFF08\u4EEE\u60F3\u4E0A\u306E\u5B8C\u5168\u30CB\u5206\u5C90\
    \u3092\u60F3\u50CF\u3059\u308B\u3068\u65E9\u3044)\n            if(sy <= a && b\
    \ <= ty) return now -> subtree.get(sx, tx-1);//w2\u306F\u534A\u958B\u533A\u9593\
    \u3002y\u304C\u5B8C\u5168\u306B\u542B\u307E\u308C\u308B\u6642\u3002\n        \
    \    W mid = (a+b)>>1;\n            X L = get__(now -> lch, a, mid, sy, ty, sx,\
    \ tx);\n            X R = get__(now -> rch, mid, b, sy, ty, sx, tx);\n       \
    \     return op(L, R);\n        }\n\n\n    public:\n        void change(W y, W\
    \ x, X val) {\n           change__(root, MIN_H, MAX_H, y, x, val);\n        }\n\
    \n        X  get(W sy, W ty, W sx, W tx) {\n\t\t\tty++; tx++;\n            return\
    \ get__(root, MIN_H, MAX_H, sy, ty, sx, tx);\n        }\n\n        \n};\n\nstruct\
    \ Monoid {\n    long long a;\n    \n    Monoid(){}\n    Monoid(long long _a) :\
    \ a(_a){};\n\n    friend Monoid op(const Monoid& l, const Monoid& r) {\n     \
    \   Monoid res;\n        res.a = l.a + r.a;\n        return res;\n    } \n   \
    \ friend Monoid update(const Monoid& l, const Monoid& x) {\n        Monoid res\
    \ = l;\n        res.a += x.a;\n        return res;\n    }\n\n\tstatic Monoid ide()\
    \ {\n\t\treturn 0;\n\t}\n};\n\n/*\n@brief : \u52D5\u76842\u6B21\u5143\u30BB\u30B0\
    \u6728\n*/\n"
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
    \ min_pos, max_pos, l, r+1);\n        }\n\n\t\t/*\n\t\t    UnlimitedSegTree<X,\
    \ W> seg(minpos, maxpos)  X...\u30C7\u30FC\u30BF W...\u6DFB\u5B57\u306E\u578B\
    \  O(1)\n\t\t\t@brief: \u52D5\u7684\u30BB\u30B0\u6728\n\t\t\n\t\t*/\n\n};\n\n\
    template<typename X, typename W>\nstruct online2Dseg {\n\n    W MIN_H, MAX_H,\
    \ MIN_W, MAX_W;\n    online2Dseg(W _MIN_H, W _MAX_H, W _MIN_W, W _MAX_W) :  MIN_H(_MIN_H),\
    \ MAX_H(_MAX_H), MIN_W(_MIN_W), MAX_W(_MAX_W) {\n\t\tMAX_H++;  MAX_W++;\n\t}\n\
    \n    private:\n        struct NODE {\n            UnlimitedSegTree<X, W> subtree;\n\
    \            NODE* lch;\n\t\t\tNODE* rch;\n            \n            NODE(W _MIN_W,\
    \ W _MAX_W) {\n              subtree = DynamicSegTree<X, W>(_MIN_W, _MAX_W-1);\n\
    \              lch = nullptr;\n              rch = nullptr;\n            }\n \
    \       };\n\n        NODE* root = nullptr;\n\n    \n \n        void change__(NODE*&\
    \ now, W& a, W& b, W& h, W& w,  X& val) {//\u6728\u306E\u69CB\u9020\u304C\u5909\
    \u5316\u3057\u306A\u3044\u306A\u3089\u3001\u69CB\u6210\u3057\u76F4\u3059\u5FC5\
    \u8981\u3082\u7121\u3044\uFF08splay\u6728\u7B49\u6839\u304C\u5909\u308F\u308A\u3046\
    \u308B\u3084\u3064\u306F\u8A71\u304C\u5225\uFF09\n            if(now == nullptr)\
    \  now = new NODE(MIN_W, MAX_W);\n            now -> subtree.change(w, val);//h\u3092\
    \u542B\u3080\u533A\u9593\u3092\u6301\u3064\u90E8\u5206\u6728\u306B\u5024\u3092\
    \u767B\u9332\u3002\u3053\u306E\u6642\u3001x(w)\u5EA7\u6A19\u3092\u767B\u9332\u3059\
    \u308B\u3002\n            W mid = (a+b)>>1;\n            if(b - a == 1) return;//\u8449\
    \u307E\u3067\u767B\u9332\u3057\u305F\u3089\u7D42\u308F\u308A\u3002\n         \
    \   if(h < mid) change__(now -> lch, a, mid, h, w, val);\n            else change__(now\
    \ -> rch, mid, b, h, w, val);\n        }\n\n        \n        X get__(NODE*& now,\
    \ W& a, W& b, W& sy, W& ty, W& sx, W& tx) {// [sy, ty) \xD7 [sx, tx) := \u30AF\
    \u30A8\u30EA\u533A\u9593  [a, b) := \u4ECA\u898B\u3066\u3044\u308By(h)\u5EA7\u6A19\
    \u306E\u533A\u9593   y = [sy, ty)\u3067\u306E\u7D50\u679C\u3092\u8FD4\u3059\u3002\
    \n            if(b <= sy || ty <= a) return X::ide();//\u7BC4\u56F2\u5916\u306A\
    \u3089\u5358\u4F4D\u5143\n            if(now == nullptr) return X::ide();//\u7BC4\
    \u56F2\u5185\u306B\u3064\u3044\u3066\u3001\u30C7\u30FC\u30BF\u304C\u5B58\u5728\
    \u3057\u306A\u3044\u306A\u3089\u5358\u4F4D\u5143//(\u3053\u308C\u3088\u308A\u5B50\
    \u306F\u3001\u4ECA\u3088\u308A\u533A\u9593\u304C\u72ED\u3044\u5B50\u3057\u304B\
    \u5B58\u5728\u3057\u5F97\u306A\u3044\u304B\u3089\u6253\u3061\u5207\u3063\u3066\
    \u826F\u3044\u3002\uFF08\u4EEE\u60F3\u4E0A\u306E\u5B8C\u5168\u30CB\u5206\u5C90\
    \u3092\u60F3\u50CF\u3059\u308B\u3068\u65E9\u3044)\n            if(sy <= a && b\
    \ <= ty) return now -> subtree.get(sx, tx-1);//w2\u306F\u534A\u958B\u533A\u9593\
    \u3002y\u304C\u5B8C\u5168\u306B\u542B\u307E\u308C\u308B\u6642\u3002\n        \
    \    W mid = (a+b)>>1;\n            X L = get__(now -> lch, a, mid, sy, ty, sx,\
    \ tx);\n            X R = get__(now -> rch, mid, b, sy, ty, sx, tx);\n       \
    \     return op(L, R);\n        }\n\n\n    public:\n        void change(W y, W\
    \ x, X val) {\n           change__(root, MIN_H, MAX_H, y, x, val);\n        }\n\
    \n        X  get(W sy, W ty, W sx, W tx) {\n\t\t\tty++; tx++;\n            return\
    \ get__(root, MIN_H, MAX_H, sy, ty, sx, tx);\n        }\n\n        \n};\n\nstruct\
    \ Monoid {\n    long long a;\n    \n    Monoid(){}\n    Monoid(long long _a) :\
    \ a(_a){};\n\n    friend Monoid op(const Monoid& l, const Monoid& r) {\n     \
    \   Monoid res;\n        res.a = l.a + r.a;\n        return res;\n    } \n   \
    \ friend Monoid update(const Monoid& l, const Monoid& x) {\n        Monoid res\
    \ = l;\n        res.a += x.a;\n        return res;\n    }\n\n\tstatic Monoid ide()\
    \ {\n\t\treturn 0;\n\t}\n};\n\n/*\n@brief : \u52D5\u76842\u6B21\u5143\u30BB\u30B0\
    \u6728\n*/"
  dependsOn: []
  isVerificationFile: false
  path: DetaStructures/online2Dseg.cpp
  requiredBy: []
  timestamp: '2024-05-10 22:30:14+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DetaStructures/online2Dseg.cpp
layout: document
redirect_from:
- /library/DetaStructures/online2Dseg.cpp
- /library/DetaStructures/online2Dseg.cpp.html
title: ": \u52D5\u76842\u6B21\u5143\u30BB\u30B0\u6728"
---
