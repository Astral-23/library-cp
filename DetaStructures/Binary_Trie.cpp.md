---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Binary_Trie
    links: []
  bundledCode: "#line 1 \"DetaStructures/Binary_Trie.cpp\"\ntemplate<typename X, typename\
    \ S>\nstruct Binary_Trie {\n    struct Node {\n          Node* l = nullptr;\n\
    \          Node* r = nullptr;\n          S s = 0; \n          X lazy = 0;\n  \
    \        Node (){}\n    };\n\n    int W = 0;\n\tBinary_Trie(){}\n    Binary_Trie(int\
    \ _W) : W(_W){}\n\n\t\n    Node* root = new Node;//Binary_Trie_Tree\u306E\u6839\
    \u3092\u8868\u3059\u30CE\u30FC\u30C9\u3002\n\n\n    private:\n        void eval(Node*\
    \ k, int l) {\n            X x = k -> lazy;//\u4ECA\u306E\u30CE\u30FC\u30C9\u306E\
    lazy\n            if(l != W && x != 0) {//\u8449\u3067\u306A\u3044\u306A\u3089\
    \n                if(k -> l)k -> l -> lazy ^= x;//\u4F1D\u64AD\n             \
    \   if(k -> r)k -> r -> lazy ^= x;//\u4F1D\u64AD\n          \n               \
    \ if(x >> (W - l - 1) & 1) {\n\t\t\t\t    swap(k -> l, k -> r);//\u76F8\u5F53\u3059\
    \u308Bbit\u304C\u7ACB\u3063\u3066\u3044\u308B\u306A\u3089swap\n\t\t\t    }\n\t\
    \t\t}\n            k -> lazy = 0;\n            return ;\n        }    \n    \n\
    \        X search_kth(Node* k, int l, S remain) {\n\t\t\tX res = 0;\n\t\t\twhile(1)\
    \ {\n                if(l == W) break;\n\t\t\t\teval(k, l);\n                if(k\
    \ -> l && k -> l -> s >= remain) {\n\t\t\t\t\tk = k -> l;\n\t\t\t\t}\n       \
    \         else {\n\t\t\t\t\tif(k -> l) remain -= k -> l -> s;\n\t\t\t\t\tres +=\
    \ X(1) << (W - l - 1);\n\t\t\t\t\tk = k -> r;\n                }\n\t\t\t\tl++;\n\
    \t\t\t}\n\t\t\treturn res;\n        }\n    \n        void search_ie(Node*& k,\
    \ int l, S t, X& x) {//insert/erase\u306E\u63A2\u7D22\u95A2\u6570\u3002t\u306F\
    \u95A2\u6570\u3092\u5171\u901A\u5316\u3059\u308B\u70BA\u306E\u30D1\u30E9\u30E1\
    \u30FC\u30BF\u3002t >= 1\u306A\u3089insert\u3001t <= -1\u306A\u3089erase\n\t\t\
    \    if(!k) k = new Node;\n            eval(k, l);\n            k -> s += t;\n\
    \            //assert(k -> s >= 0);\n            if(l != W) {\n              \
    \  if(x >> (W - l - 1) & 1) search_ie(k -> r, l+1, t, x);//\u53F3\u306B\u79FB\u52D5\
    \  //Wbit\u4E2D\u3001\u4E0A\u304B\u3089l + 1\u756A\u76EE \u21D4 \u4E0B\u304B\u3089\
    \ W - l\u756A\u76EE\n                else search_ie(k -> l, l+1, t, x);//\u5DE6\
    \u306B\u79FB\u52D5\n\t\t\t}\n            return ;\n        }\n\n        S search_count(Node*&\
    \ k, int l, X& x) {//count\u306E\u70BA\u306E\u63A2\u7D22\u95A2\u6570\n\t\t   \
    \ if(!k) k = new Node;\n            eval(k, l);\n            if(l == W) return\
    \ k -> s;//\u8449\u306B\u5230\u9054\u3057\u305F\u306A\u3089\u3070\u305D\u306E\
    s\u3092\u8FD4\u3059\u3002\n            if(k -> s == 0) return S(0);//s = 0\u306E\
    \u9802\u70B9\u304C\u5B58\u5728\u3057\u305F\u306A\u3089\u3070\u5373\u5EA7\u306B\
    0\u3092\u8FD4\u3059\u3002\n            //eval\u306B\u3088\u3063\u3066\u65E2\u306B\
    \u5B50\u306E\u5B58\u5728\u306F\u4FDD\u8A3C\u3055\u308C\u3066\u3044\u308B\u3002\
    \n            if(x >> (W - l - 1) & 1) return search_count(k -> r, l+1, x);//\u53F3\
    \u306B\u79FB\u52D5\n            else return search_count(k -> l, l+1, x);//\u5DE6\
    \u306B\u79FB\u52D5\n        }\n\n        X search_maix(Node* k, int l, int type)\
    \ {//type == 1\u304Cmax\u3001type == 0\u304Cmin\n\t\t    X res = 0;\n\t\t    while(1)\
    \ {\n                eval(k, l);\n                if(l == W) break;\n        \
    \        if(type == 1) {\n\t\t\t\t\tif(k -> r && k -> r -> s != 0) {\n\t\t\t\t\
    \t\tres += X(1) << (W - l - 1);\n\t\t\t\t\t\tk = k -> r;\n\t\t\t\t\t}\n\t\t\t\t\
    \telse k = k -> l;\n\t\t\t\t\tl++;\n                }\n                else {\n\
    \                    if(k -> l && k -> l -> s != 0) {\n\t\t\t\t\t\tk = k -> l;\n\
    \t\t\t\t\t\tl++;\n\t\t\t\t\t}\n                    else {\n\t\t\t\t\t\tres +=\
    \ X(1) << (W - l - 1);\n\t\t\t\t\t\tk = k -> r;\n\t\t\t\t\t\tl++;\n\t\t\t\t\t\
    } \n                }\n\t\t\t}\n\t\t\treturn res;\n        }\n        \n     \
    \   \n        S cnt_bound__(Node* k, int l, X& x) {//x\u4EE5\u4E0B\u306E\u8981\
    \u7D20\u306E\u7DCF\u6570\n\t\t    if(!k) return S();\n            eval(k, l);\n\
    \            if(l == W) return k -> s;\n            if(x >> (W-l-1)&1) return\
    \ upper_bound__(k -> r, l+1, x) + k -> l -> s;\n            else return upper_bound_(k\
    \ -> l, l+1, x);\n        }\n    \n    \n    public:\n        void insert(X x,\
    \ S cnt) {//\u5024x\u3092cnt\u500B\u633F\u5165\n            search_ie(root, 0,\
    \ cnt, x);\n        }\n    \n        void erase(X x, S cnt) {//\u5024x\u3092cnt\u500B\
    \u524A\u9664(\u5143\u306E\u500B\u6570\u3092\u8D85\u3048\u305F\u5834\u5408\u30A8\
    \u30E9\u30FC)\n            search_ie(root, 0,  cnt * -1, x);\n        }\n    \
    \    \n        S count(X x) {//\u5024x\u306E\u500B\u6570\n            return search_count(root,\
    \ 0, x);\n        }\n    \n        X max_element() {//\u6700\u5927\u5024 \u8981\
    \u7D20\u6570 = 0\u306E\u5834\u5408\u30A8\u30E9\u30FC\n            assert(root\
    \ -> s > 0);\n            return search_maix(root, 0, 1);\n        }\n    \n \
    \       X min_element() {//\u6700\u5C0F\u5024 \u8981\u7D20\u6570 = 0\u306E\u5834\
    \u5408\u30A8\u30E9\u30FC\n            assert(root -> s > 0);\n            return\
    \ search_maix(root, 0, 0);\n        }\n    \n        X kth_element(S k) {//\u5C0F\
    \u3055\u3044\u65B9\u304B\u3089k\u756A\u76EE\u306E\u5024 \u8981\u7D20\u6570 < k\u306E\
    \u5834\u5408\u30A8\u30E9-\n            assert(root -> s >= k);\n            return\
    \ search_kth(root, 0, k);\n        }\n    \n        void ope_xor(X x) {//\u53CE\
    \u5BB9\u3055\u308C\u3066\u3044\u308B\u8981\u7D20\u5168\u3066\u306Bx\u3092xor\u4F5C\
    \u7528\u3055\u305B\u308B\n            if(root -> s == 0) return;//\u8981\u7D20\
    \u304C\u5B58\u5728\u3057\u306A\u3044\n            root -> lazy ^= x;\n       \
    \     eval(root, 0);\n        }\n        \n\t\t\n        bool upper_bound(X x,\
    \ X& res) {//x\u3088\u308A\u5927\u304D\u3044\u6700\u5C0F\u306E\u8981\u7D20\n\t\
    \t    S pos = 1 + cnt_count__(root, 0, x);\n\t\t\tif(pos > size) return false;\n\
    \t\t\tres = kth_element(pos);\n\t\t\treturn true;\n        }\n    \n        bool\
    \ lower_bound(X x, X& res) {//x\u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\u8981\u7D20\
    \n\t\t    if(x==0) {\n\t\t\t\tif(size()==0) return false;\n\t\t\t\tres = min_element();\n\
    \t\t\t\treturn true;\n\t\t\t}\n            return upper_bound(x-1, res);\n   \
    \     }\n    \n        S size() {//\u53CE\u5BB9\u3055\u308C\u3066\u3044\u308B\u8981\
    \u7D20\u306E\u7DCF\u6570\n            return root -> s;\n        }\n\n\n\t\tvoid\
    \ dump() {\n\t\t\tS s = size();\n\t\t\tfor(S i = 1; i <= s; i++) {\n\t\t\t\tcout\
    \ << kth_element(i).first << \" \";\n\t\t\t}\n\t\t\tcout << endl;\n\t\t}\n\n\t\
    \t/*\n\t\t    Binary_Trie<X, S>(W)   X...\u767B\u9332\u3059\u308B\u5024\u30FB\
    xor\u3059\u308B\u5024\u306E\u578B  S...\u5024\u306E\u500B\u6570\u306E\u578B  W...\u6700\
    \u5927bit\u9577   O(1)\n\t\t\t@brief Binary_Trie\n\t\t\tinsert(x, cnt = 1) ...\
    \ O(W)\n\t\t\terase(x, cnt = 1) ... O(W)\n\t\t\tcount(x) ... O(W)\n\t\t\tmex_element()/min_element()\
    \ ... O(W)\n\t\t\tpair<X, S> kth_element(k)  ... O(W) {\u5024\u3001\u500B\u6570\
    }\u3092\u8FD4\u3059\n\t\t\tope_xor(x) ... \u96C6\u5408\u5168\u4F53\u306Bx\u3092\
    xor\u4F5C\u7528 O(1)\n\t\t\tsize() ... O(1)\n\n\t\t\tbool lower_bound(x, &res)\
    \ ... x\u4EE5\u4E0A\u306E\u8981\u7D20\u304C\u5B58\u5728\u3059\u308B\u306A\u3089\
    true, \u305D\u306E\u3046\u3061\u6700\u5C0F\u3092res\u306B\u4EE3\u5165  O(W)\n\t\
    \t\tbool upper_bound(x, &res) ... O(W)\n\n\t\t\t\u7A7A\u9593: \u633F\u5165\u3054\
    \u3068\u306BO(W)\n\n\t\t\n\t\t*/\n};    \n"
  code: "template<typename X, typename S>\nstruct Binary_Trie {\n    struct Node {\n\
    \          Node* l = nullptr;\n          Node* r = nullptr;\n          S s = 0;\
    \ \n          X lazy = 0;\n          Node (){}\n    };\n\n    int W = 0;\n\tBinary_Trie(){}\n\
    \    Binary_Trie(int _W) : W(_W){}\n\n\t\n    Node* root = new Node;//Binary_Trie_Tree\u306E\
    \u6839\u3092\u8868\u3059\u30CE\u30FC\u30C9\u3002\n\n\n    private:\n        void\
    \ eval(Node* k, int l) {\n            X x = k -> lazy;//\u4ECA\u306E\u30CE\u30FC\
    \u30C9\u306Elazy\n            if(l != W && x != 0) {//\u8449\u3067\u306A\u3044\
    \u306A\u3089\n                if(k -> l)k -> l -> lazy ^= x;//\u4F1D\u64AD\n \
    \               if(k -> r)k -> r -> lazy ^= x;//\u4F1D\u64AD\n          \n   \
    \             if(x >> (W - l - 1) & 1) {\n\t\t\t\t    swap(k -> l, k -> r);//\u76F8\
    \u5F53\u3059\u308Bbit\u304C\u7ACB\u3063\u3066\u3044\u308B\u306A\u3089swap\n\t\t\
    \t    }\n\t\t\t}\n            k -> lazy = 0;\n            return ;\n        }\
    \    \n    \n        X search_kth(Node* k, int l, S remain) {\n\t\t\tX res = 0;\n\
    \t\t\twhile(1) {\n                if(l == W) break;\n\t\t\t\teval(k, l);\n   \
    \             if(k -> l && k -> l -> s >= remain) {\n\t\t\t\t\tk = k -> l;\n\t\
    \t\t\t}\n                else {\n\t\t\t\t\tif(k -> l) remain -= k -> l -> s;\n\
    \t\t\t\t\tres += X(1) << (W - l - 1);\n\t\t\t\t\tk = k -> r;\n               \
    \ }\n\t\t\t\tl++;\n\t\t\t}\n\t\t\treturn res;\n        }\n    \n        void search_ie(Node*&\
    \ k, int l, S t, X& x) {//insert/erase\u306E\u63A2\u7D22\u95A2\u6570\u3002t\u306F\
    \u95A2\u6570\u3092\u5171\u901A\u5316\u3059\u308B\u70BA\u306E\u30D1\u30E9\u30E1\
    \u30FC\u30BF\u3002t >= 1\u306A\u3089insert\u3001t <= -1\u306A\u3089erase\n\t\t\
    \    if(!k) k = new Node;\n            eval(k, l);\n            k -> s += t;\n\
    \            //assert(k -> s >= 0);\n            if(l != W) {\n              \
    \  if(x >> (W - l - 1) & 1) search_ie(k -> r, l+1, t, x);//\u53F3\u306B\u79FB\u52D5\
    \  //Wbit\u4E2D\u3001\u4E0A\u304B\u3089l + 1\u756A\u76EE \u21D4 \u4E0B\u304B\u3089\
    \ W - l\u756A\u76EE\n                else search_ie(k -> l, l+1, t, x);//\u5DE6\
    \u306B\u79FB\u52D5\n\t\t\t}\n            return ;\n        }\n\n        S search_count(Node*&\
    \ k, int l, X& x) {//count\u306E\u70BA\u306E\u63A2\u7D22\u95A2\u6570\n\t\t   \
    \ if(!k) k = new Node;\n            eval(k, l);\n            if(l == W) return\
    \ k -> s;//\u8449\u306B\u5230\u9054\u3057\u305F\u306A\u3089\u3070\u305D\u306E\
    s\u3092\u8FD4\u3059\u3002\n            if(k -> s == 0) return S(0);//s = 0\u306E\
    \u9802\u70B9\u304C\u5B58\u5728\u3057\u305F\u306A\u3089\u3070\u5373\u5EA7\u306B\
    0\u3092\u8FD4\u3059\u3002\n            //eval\u306B\u3088\u3063\u3066\u65E2\u306B\
    \u5B50\u306E\u5B58\u5728\u306F\u4FDD\u8A3C\u3055\u308C\u3066\u3044\u308B\u3002\
    \n            if(x >> (W - l - 1) & 1) return search_count(k -> r, l+1, x);//\u53F3\
    \u306B\u79FB\u52D5\n            else return search_count(k -> l, l+1, x);//\u5DE6\
    \u306B\u79FB\u52D5\n        }\n\n        X search_maix(Node* k, int l, int type)\
    \ {//type == 1\u304Cmax\u3001type == 0\u304Cmin\n\t\t    X res = 0;\n\t\t    while(1)\
    \ {\n                eval(k, l);\n                if(l == W) break;\n        \
    \        if(type == 1) {\n\t\t\t\t\tif(k -> r && k -> r -> s != 0) {\n\t\t\t\t\
    \t\tres += X(1) << (W - l - 1);\n\t\t\t\t\t\tk = k -> r;\n\t\t\t\t\t}\n\t\t\t\t\
    \telse k = k -> l;\n\t\t\t\t\tl++;\n                }\n                else {\n\
    \                    if(k -> l && k -> l -> s != 0) {\n\t\t\t\t\t\tk = k -> l;\n\
    \t\t\t\t\t\tl++;\n\t\t\t\t\t}\n                    else {\n\t\t\t\t\t\tres +=\
    \ X(1) << (W - l - 1);\n\t\t\t\t\t\tk = k -> r;\n\t\t\t\t\t\tl++;\n\t\t\t\t\t\
    } \n                }\n\t\t\t}\n\t\t\treturn res;\n        }\n        \n     \
    \   \n        S cnt_bound__(Node* k, int l, X& x) {//x\u4EE5\u4E0B\u306E\u8981\
    \u7D20\u306E\u7DCF\u6570\n\t\t    if(!k) return S();\n            eval(k, l);\n\
    \            if(l == W) return k -> s;\n            if(x >> (W-l-1)&1) return\
    \ upper_bound__(k -> r, l+1, x) + k -> l -> s;\n            else return upper_bound_(k\
    \ -> l, l+1, x);\n        }\n    \n    \n    public:\n        void insert(X x,\
    \ S cnt) {//\u5024x\u3092cnt\u500B\u633F\u5165\n            search_ie(root, 0,\
    \ cnt, x);\n        }\n    \n        void erase(X x, S cnt) {//\u5024x\u3092cnt\u500B\
    \u524A\u9664(\u5143\u306E\u500B\u6570\u3092\u8D85\u3048\u305F\u5834\u5408\u30A8\
    \u30E9\u30FC)\n            search_ie(root, 0,  cnt * -1, x);\n        }\n    \
    \    \n        S count(X x) {//\u5024x\u306E\u500B\u6570\n            return search_count(root,\
    \ 0, x);\n        }\n    \n        X max_element() {//\u6700\u5927\u5024 \u8981\
    \u7D20\u6570 = 0\u306E\u5834\u5408\u30A8\u30E9\u30FC\n            assert(root\
    \ -> s > 0);\n            return search_maix(root, 0, 1);\n        }\n    \n \
    \       X min_element() {//\u6700\u5C0F\u5024 \u8981\u7D20\u6570 = 0\u306E\u5834\
    \u5408\u30A8\u30E9\u30FC\n            assert(root -> s > 0);\n            return\
    \ search_maix(root, 0, 0);\n        }\n    \n        X kth_element(S k) {//\u5C0F\
    \u3055\u3044\u65B9\u304B\u3089k\u756A\u76EE\u306E\u5024 \u8981\u7D20\u6570 < k\u306E\
    \u5834\u5408\u30A8\u30E9-\n            assert(root -> s >= k);\n            return\
    \ search_kth(root, 0, k);\n        }\n    \n        void ope_xor(X x) {//\u53CE\
    \u5BB9\u3055\u308C\u3066\u3044\u308B\u8981\u7D20\u5168\u3066\u306Bx\u3092xor\u4F5C\
    \u7528\u3055\u305B\u308B\n            if(root -> s == 0) return;//\u8981\u7D20\
    \u304C\u5B58\u5728\u3057\u306A\u3044\n            root -> lazy ^= x;\n       \
    \     eval(root, 0);\n        }\n        \n\t\t\n        bool upper_bound(X x,\
    \ X& res) {//x\u3088\u308A\u5927\u304D\u3044\u6700\u5C0F\u306E\u8981\u7D20\n\t\
    \t    S pos = 1 + cnt_count__(root, 0, x);\n\t\t\tif(pos > size) return false;\n\
    \t\t\tres = kth_element(pos);\n\t\t\treturn true;\n        }\n    \n        bool\
    \ lower_bound(X x, X& res) {//x\u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\u8981\u7D20\
    \n\t\t    if(x==0) {\n\t\t\t\tif(size()==0) return false;\n\t\t\t\tres = min_element();\n\
    \t\t\t\treturn true;\n\t\t\t}\n            return upper_bound(x-1, res);\n   \
    \     }\n    \n        S size() {//\u53CE\u5BB9\u3055\u308C\u3066\u3044\u308B\u8981\
    \u7D20\u306E\u7DCF\u6570\n            return root -> s;\n        }\n\n\n\t\tvoid\
    \ dump() {\n\t\t\tS s = size();\n\t\t\tfor(S i = 1; i <= s; i++) {\n\t\t\t\tcout\
    \ << kth_element(i).first << \" \";\n\t\t\t}\n\t\t\tcout << endl;\n\t\t}\n\n\t\
    \t/*\n\t\t    Binary_Trie<X, S>(W)   X...\u767B\u9332\u3059\u308B\u5024\u30FB\
    xor\u3059\u308B\u5024\u306E\u578B  S...\u5024\u306E\u500B\u6570\u306E\u578B  W...\u6700\
    \u5927bit\u9577   O(1)\n\t\t\t@brief Binary_Trie\n\t\t\tinsert(x, cnt = 1) ...\
    \ O(W)\n\t\t\terase(x, cnt = 1) ... O(W)\n\t\t\tcount(x) ... O(W)\n\t\t\tmex_element()/min_element()\
    \ ... O(W)\n\t\t\tpair<X, S> kth_element(k)  ... O(W) {\u5024\u3001\u500B\u6570\
    }\u3092\u8FD4\u3059\n\t\t\tope_xor(x) ... \u96C6\u5408\u5168\u4F53\u306Bx\u3092\
    xor\u4F5C\u7528 O(1)\n\t\t\tsize() ... O(1)\n\n\t\t\tbool lower_bound(x, &res)\
    \ ... x\u4EE5\u4E0A\u306E\u8981\u7D20\u304C\u5B58\u5728\u3059\u308B\u306A\u3089\
    true, \u305D\u306E\u3046\u3061\u6700\u5C0F\u3092res\u306B\u4EE3\u5165  O(W)\n\t\
    \t\tbool upper_bound(x, &res) ... O(W)\n\n\t\t\t\u7A7A\u9593: \u633F\u5165\u3054\
    \u3068\u306BO(W)\n\n\t\t\n\t\t*/\n};    \n"
  dependsOn: []
  isVerificationFile: false
  path: DetaStructures/Binary_Trie.cpp
  requiredBy: []
  timestamp: '2024-05-10 22:41:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DetaStructures/Binary_Trie.cpp
layout: document
redirect_from:
- /library/DetaStructures/Binary_Trie.cpp
- /library/DetaStructures/Binary_Trie.cpp.html
title: Binary_Trie
---
