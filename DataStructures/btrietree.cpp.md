---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: range xor range min
    links: []
  bundledCode: "#line 1 \"DataStructures/btrietree.cpp\"\ntemplate<typename X, typename\
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
    \        pair<X, S> search_kth(Node*& k, int l, S& remain) {\n\t\t\tif(!k) k =\
    \ new Node;\n            eval(k, l);\n            if(l == W) return pair(X(0),\
    \ k -> s);//\u8449\u306A\u3089\u5373\u5EA7\u306B0\u3092\u8FD4\u3059\u3002\n  \
    \          if(k -> l && k -> l -> s >= remain) return search_kth(k -> l, l+1,\
    \ remain);\n            else {\n                if(k -> l)remain -= k -> l ->\
    \ s;\n                auto f = search_kth(k -> r, l+1, remain);\n            \
    \    f.first += (X(1) << (W - l - 1));//\u4E0A\u304B\u3089l+1bit\u76EE\u21D4\u3057\
    \u305F\u304B\u3089W - lbit\u76EE\n                return f;\n            }\n \
    \       }\n    \n        void search_ie(Node*& k, int l, S t, X& x) {//insert/erase\u306E\
    \u63A2\u7D22\u95A2\u6570\u3002t\u306F\u95A2\u6570\u3092\u5171\u901A\u5316\u3059\
    \u308B\u70BA\u306E\u30D1\u30E9\u30E1\u30FC\u30BF\u3002t >= 1\u306A\u3089insert\u3001\
    t <= -1\u306A\u3089erase\n\t\t    if(!k) k = new Node;\n            eval(k, l);\n\
    \            k -> s += t;\n            //assert(k -> s >= 0);\n            if(l\
    \ != W) {\n                if(x >> (W - l - 1) & 1) search_ie(k -> r, l+1, t,\
    \ x);//\u53F3\u306B\u79FB\u52D5  //Wbit\u4E2D\u3001\u4E0A\u304B\u3089l + 1\u756A\
    \u76EE \u21D4 \u4E0B\u304B\u3089 W - l\u756A\u76EE\n                else search_ie(k\
    \ -> l, l+1, t, x);//\u5DE6\u306B\u79FB\u52D5\n\t\t\t}\n            return ;\n\
    \        }\n\n        S search_count(Node*& k, int l, X& x) {//count\u306E\u70BA\
    \u306E\u63A2\u7D22\u95A2\u6570\n\t\t    if(!k) k = new Node;\n            eval(k,\
    \ l);\n            if(l == W) return k -> s;//\u8449\u306B\u5230\u9054\u3057\u305F\
    \u306A\u3089\u3070\u305D\u306Es\u3092\u8FD4\u3059\u3002\n            if(k -> s\
    \ == 0) return S(0);//s = 0\u306E\u9802\u70B9\u304C\u5B58\u5728\u3057\u305F\u306A\
    \u3089\u3070\u5373\u5EA7\u306B0\u3092\u8FD4\u3059\u3002\n            //eval\u306B\
    \u3088\u3063\u3066\u65E2\u306B\u5B50\u306E\u5B58\u5728\u306F\u4FDD\u8A3C\u3055\
    \u308C\u3066\u3044\u308B\u3002\n            if(x >> (W - l - 1) & 1) return search_count(k\
    \ -> r, l+1, x);//\u53F3\u306B\u79FB\u52D5\n            else return search_count(k\
    \ -> l, l+1, x);//\u5DE6\u306B\u79FB\u52D5\n        }\n\n        X search_maix(Node*&\
    \ k, int l, int type) {//type == 1\u304Cmax\u3001type == 0\u304Cmin\n\t\t    if(!k)\
    \ k = new Node;\n            eval(k, l);\n            if(l == W) return X(0);//\u8449\
    \u306A\u3089\u5373\u5EA7\u306B0\u3092\u8FD4\u3059\u3002\n            if(type ==\
    \ 1) {\n                if(k -> r && k -> r -> s != 0) return (X(1) << (W - l\
    \ - 1)) + search_maix(k -> r, l+1, type); //\u53F3\u306B\u79FB\u52D5 //\u4E0A\u304B\
    \u3089l+1bit\u76EE\u304C1\u3060\u3068\u308F\u304B\u3063\u305F \u21D4 \u4E0B\u304B\
    \u3089W - lbit\u76EE\u304C1\n                else return search_maix(k -> l, l+1,\
    \ type);//\u5DE6\u306B\u79FB\u52D5\n            }\n            else {\n      \
    \          if(k -> l && k -> l -> s != 0) return search_maix(k -> l, l+1, type);//\u5DE6\
    \u306B\u79FB\u52D5  \n                else return (X(1) << (W - l - 1)) + search_maix(k\
    \ -> r, l+1, type);//\u53F3\u306B\u79FB\u52D5\n            }\n        }\n    \
    \    \n        /*\n        S _bound__(Node* k, int l, X& x) {//x\u8D85\u904E\u306E\
    \u8981\u7D20\u306E\u7DCF\u6570\n            eval(k, l);\n            if(l == W)\
    \ return k -> s;\n            if(x >> (W-l-1)&1) return upper_bound__(k -> r,\
    \ l+1, x) + k -> l -> s;\n            else return upper_bound_(k -> l, l+1, x);\n\
    \        }*/\n    \n    \n    public:\n        void insert(X x, S cnt) {//\u5024\
    x\u3092cnt\u500B\u633F\u5165\n            search_ie(root, 0, cnt, x);\n      \
    \  }\n    \n        void erase(X x, S cnt) {//\u5024x\u3092cnt\u500B\u524A\u9664\
    (\u5143\u306E\u500B\u6570\u3092\u8D85\u3048\u305F\u5834\u5408\u30A8\u30E9\u30FC\
    )\n            search_ie(root, 0,  cnt * -1, x);\n        }\n        \n      \
    \  S count(X x) {//\u5024x\u306E\u500B\u6570\n            return search_count(root,\
    \ 0, x);\n        }\n    \n        X max_element() {//\u6700\u5927\u5024 \u8981\
    \u7D20\u6570 = 0\u306E\u5834\u5408\u30A8\u30E9\u30FC\n            assert(root\
    \ -> s > 0);\n            return search_maix(root, 0, 1);\n        }\n    \n \
    \       X min_element() {//\u6700\u5C0F\u5024 \u8981\u7D20\u6570 = 0\u306E\u5834\
    \u5408\u30A8\u30E9\u30FC\n            assert(root -> s > 0);\n            return\
    \ search_maix(root, 0, 0);\n        }\n    \n        pair<X, S> kth_element(S\
    \ k) {//\u5C0F\u3055\u3044\u65B9\u304B\u3089k\u756A\u76EE\u306E\u5024\u3068\u305D\
    \u306E\u500B\u6570 \u8981\u7D20\u6570 < k\u306E\u5834\u5408\u30A8\u30E9-\n   \
    \         assert(root -> s >= k);\n            return search_kth(root, 0, k);\n\
    \        }\n    \n        void ope_xor(X x) {//\u53CE\u5BB9\u3055\u308C\u3066\u3044\
    \u308B\u8981\u7D20\u5168\u3066\u306Bx\u3092xor\u4F5C\u7528\u3055\u305B\u308B\n\
    \            if(root -> s == 0) return;//\u8981\u7D20\u304C\u5B58\u5728\u3057\u306A\
    \u3044\n            root -> lazy ^= x;\n            eval(root, 0);\n        }\n\
    \        \n\t\t/*\n        S upper_bound(X x) {//x\u3088\u308A\u5927\u304D\u3044\
    \u6700\u5C0F\u306E\u8981\u7D20\u304C\u4F55\u756A\u76EE\u304B\n            return\
    \ 1 + upper_bound_(root, 0, x);\n        }\n    \n        S lower_bound(X x) {//x\u4EE5\
    \u4E0A\u306E\u6700\u5C0F\u306E\u8981\u7D20\u304C\u4F55\u756A\u76EE\u304B\n   \
    \         if(x == 0) return size();\n            else return upper_bound(x - 1);\n\
    \        }*/\n    \n        S size() {//\u53CE\u5BB9\u3055\u308C\u3066\u3044\u308B\
    \u8981\u7D20\u306E\u7DCF\u6570\n            return root -> s;\n        }\n\n\n\
    \t\tvoid dump() {\n\t\t\tS s = size();\n\t\t\tfor(S i = 1; i <= s; i++) {\n\t\t\
    \t\tcout << kth_element(i).first << \" \";\n\t\t\t}\n\t\t\tcout << endl;\n\t\t\
    }\n\n\t\t/*\n\t\t    Binary_Trie<X, S>(W)   X...\u767B\u9332\u3059\u308B\u5024\
    \u30FBxor\u3059\u308B\u5024\u306E\u578B  S...\u5024\u306E\u500B\u6570\u306E\u578B\
    \  W...\u6700\u5927bit\u9577   O(1)\n\t\t\t@brief: Binary_Trie\n\t\t\tinsert(x,\
    \ cnt = 1) ... O(W)\n\t\t\terase(x, cnt = 1) ... O(W)\n\t\t\tcount(x) ... O(W)\n\
    \t\t\tmex_element()/min_element() ... O(W)\n\t\t\tpair<X, S> kth_element(k)  ...\
    \ O(W) {\u5024\u3001\u500B\u6570}\u3092\u8FD4\u3059\n\t\t\tope_xor(x) ... \u96C6\
    \u5408\u5168\u4F53\u306Bx\u3092xor\u4F5C\u7528 O(1)\n\t\t\tsize() ... O(1)\n\n\
    \t\t\t\u7A7A\u9593: \u633F\u5165\u3054\u3068\u306BO(W)\n\n\t\t\n\t\t*/\n};   \
    \ \n\ntemplate<typename T>\nstruct SegTree {\n    int n;\n    vector<Binary_Trie<T,int>>\
    \ dat;\n\n         \n    SegTree(int siz, int W) {\n        n = 1;\n        while(n\
    \ < siz) n <<= 1;\n        //dat.resize(n * 2, Binary_Trie<T, int>(W));\n\t\t\
    dat.resize(n*2);\n\t\tfor(int i = 1; i < n * 2; i++) dat[i] = Binary_Trie<T, int>(W);\n\
    \    }\n\n    private:\n         \n        T query(int l, int r, T x) {\n    \
    \        T L = numeric_limits<T>::max();\n\t\t\tT R = numeric_limits<T>::max();\n\
    \            l += n - 1, r += n - 1;\n            while(l < r) {\n           \
    \     if(l & 1) {\n\t\t\t\t\tdat[l].ope_xor(x);\n\t\t\t\t\tL = min(L, dat[l].min_element());\n\
    \t\t\t\t\tdat[l].ope_xor(x);\n\t\t\t\t\tl++;\n\t\t\t\t}\n                if(r\
    \ & 1) {\n\t\t\t\t\tr--;\n\t\t\t\t\tdat[r].ope_xor(x);\n\t\t\t\t\tR = min(dat[r].min_element(),\
    \ R);\n\t\t\t\t\tdat[r].ope_xor(x);\n\t\t\t\t}\n                l >>= 1, r >>=\
    \ 1;\n            }  \n            return  min(L, R);\n        }\n\n    \n   \
    \ public:\n        /*\n        void set(int pos, T x) {\n            pos += n-1;\n\
    \            dat[pos] = x;\n        }\n          \n        void init() {\n   \
    \         for(int i = n-1; i >= 1; i--)  dat[i] = op(dat[i<<1], dat[(i<<1) + 1]);\n\
    \        }*/\n          \n        void add(int pos, T x, int cnt) {\n        \
    \    pos += n - 1;\n            dat[pos].insert(x, cnt);\n            while(pos\
    \ >= 2) {\n                pos >>= 1;\n\t\t\t\tdat[pos].insert(x, cnt);\n    \
    \        }\n        }\n\n\n        T get(int l, int r, T x) {// [l, r]\u306E\u6F14\
    \u7B97\u7D50\u679C\u3002\n            return query(l, r+1, x);\n        }\n\n\
    \        T operator[](int pos) {\n            return dat[pos + n - 1];\n     \
    \   }\n         \n};\n\n/*\n@brief range xor range min\n*/\n"
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
    \    \n    \n        pair<X, S> search_kth(Node*& k, int l, S& remain) {\n\t\t\
    \tif(!k) k = new Node;\n            eval(k, l);\n            if(l == W) return\
    \ pair(X(0), k -> s);//\u8449\u306A\u3089\u5373\u5EA7\u306B0\u3092\u8FD4\u3059\
    \u3002\n            if(k -> l && k -> l -> s >= remain) return search_kth(k ->\
    \ l, l+1, remain);\n            else {\n                if(k -> l)remain -= k\
    \ -> l -> s;\n                auto f = search_kth(k -> r, l+1, remain);\n    \
    \            f.first += (X(1) << (W - l - 1));//\u4E0A\u304B\u3089l+1bit\u76EE\
    \u21D4\u3057\u305F\u304B\u3089W - lbit\u76EE\n                return f;\n    \
    \        }\n        }\n    \n        void search_ie(Node*& k, int l, S t, X& x)\
    \ {//insert/erase\u306E\u63A2\u7D22\u95A2\u6570\u3002t\u306F\u95A2\u6570\u3092\
    \u5171\u901A\u5316\u3059\u308B\u70BA\u306E\u30D1\u30E9\u30E1\u30FC\u30BF\u3002\
    t >= 1\u306A\u3089insert\u3001t <= -1\u306A\u3089erase\n\t\t    if(!k) k = new\
    \ Node;\n            eval(k, l);\n            k -> s += t;\n            //assert(k\
    \ -> s >= 0);\n            if(l != W) {\n                if(x >> (W - l - 1) &\
    \ 1) search_ie(k -> r, l+1, t, x);//\u53F3\u306B\u79FB\u52D5  //Wbit\u4E2D\u3001\
    \u4E0A\u304B\u3089l + 1\u756A\u76EE \u21D4 \u4E0B\u304B\u3089 W - l\u756A\u76EE\
    \n                else search_ie(k -> l, l+1, t, x);//\u5DE6\u306B\u79FB\u52D5\
    \n\t\t\t}\n            return ;\n        }\n\n        S search_count(Node*& k,\
    \ int l, X& x) {//count\u306E\u70BA\u306E\u63A2\u7D22\u95A2\u6570\n\t\t    if(!k)\
    \ k = new Node;\n            eval(k, l);\n            if(l == W) return k -> s;//\u8449\
    \u306B\u5230\u9054\u3057\u305F\u306A\u3089\u3070\u305D\u306Es\u3092\u8FD4\u3059\
    \u3002\n            if(k -> s == 0) return S(0);//s = 0\u306E\u9802\u70B9\u304C\
    \u5B58\u5728\u3057\u305F\u306A\u3089\u3070\u5373\u5EA7\u306B0\u3092\u8FD4\u3059\
    \u3002\n            //eval\u306B\u3088\u3063\u3066\u65E2\u306B\u5B50\u306E\u5B58\
    \u5728\u306F\u4FDD\u8A3C\u3055\u308C\u3066\u3044\u308B\u3002\n            if(x\
    \ >> (W - l - 1) & 1) return search_count(k -> r, l+1, x);//\u53F3\u306B\u79FB\
    \u52D5\n            else return search_count(k -> l, l+1, x);//\u5DE6\u306B\u79FB\
    \u52D5\n        }\n\n        X search_maix(Node*& k, int l, int type) {//type\
    \ == 1\u304Cmax\u3001type == 0\u304Cmin\n\t\t    if(!k) k = new Node;\n      \
    \      eval(k, l);\n            if(l == W) return X(0);//\u8449\u306A\u3089\u5373\
    \u5EA7\u306B0\u3092\u8FD4\u3059\u3002\n            if(type == 1) {\n         \
    \       if(k -> r && k -> r -> s != 0) return (X(1) << (W - l - 1)) + search_maix(k\
    \ -> r, l+1, type); //\u53F3\u306B\u79FB\u52D5 //\u4E0A\u304B\u3089l+1bit\u76EE\
    \u304C1\u3060\u3068\u308F\u304B\u3063\u305F \u21D4 \u4E0B\u304B\u3089W - lbit\u76EE\
    \u304C1\n                else return search_maix(k -> l, l+1, type);//\u5DE6\u306B\
    \u79FB\u52D5\n            }\n            else {\n                if(k -> l &&\
    \ k -> l -> s != 0) return search_maix(k -> l, l+1, type);//\u5DE6\u306B\u79FB\
    \u52D5  \n                else return (X(1) << (W - l - 1)) + search_maix(k ->\
    \ r, l+1, type);//\u53F3\u306B\u79FB\u52D5\n            }\n        }\n       \
    \ \n        /*\n        S _bound__(Node* k, int l, X& x) {//x\u8D85\u904E\u306E\
    \u8981\u7D20\u306E\u7DCF\u6570\n            eval(k, l);\n            if(l == W)\
    \ return k -> s;\n            if(x >> (W-l-1)&1) return upper_bound__(k -> r,\
    \ l+1, x) + k -> l -> s;\n            else return upper_bound_(k -> l, l+1, x);\n\
    \        }*/\n    \n    \n    public:\n        void insert(X x, S cnt) {//\u5024\
    x\u3092cnt\u500B\u633F\u5165\n            search_ie(root, 0, cnt, x);\n      \
    \  }\n    \n        void erase(X x, S cnt) {//\u5024x\u3092cnt\u500B\u524A\u9664\
    (\u5143\u306E\u500B\u6570\u3092\u8D85\u3048\u305F\u5834\u5408\u30A8\u30E9\u30FC\
    )\n            search_ie(root, 0,  cnt * -1, x);\n        }\n        \n      \
    \  S count(X x) {//\u5024x\u306E\u500B\u6570\n            return search_count(root,\
    \ 0, x);\n        }\n    \n        X max_element() {//\u6700\u5927\u5024 \u8981\
    \u7D20\u6570 = 0\u306E\u5834\u5408\u30A8\u30E9\u30FC\n            assert(root\
    \ -> s > 0);\n            return search_maix(root, 0, 1);\n        }\n    \n \
    \       X min_element() {//\u6700\u5C0F\u5024 \u8981\u7D20\u6570 = 0\u306E\u5834\
    \u5408\u30A8\u30E9\u30FC\n            assert(root -> s > 0);\n            return\
    \ search_maix(root, 0, 0);\n        }\n    \n        pair<X, S> kth_element(S\
    \ k) {//\u5C0F\u3055\u3044\u65B9\u304B\u3089k\u756A\u76EE\u306E\u5024\u3068\u305D\
    \u306E\u500B\u6570 \u8981\u7D20\u6570 < k\u306E\u5834\u5408\u30A8\u30E9-\n   \
    \         assert(root -> s >= k);\n            return search_kth(root, 0, k);\n\
    \        }\n    \n        void ope_xor(X x) {//\u53CE\u5BB9\u3055\u308C\u3066\u3044\
    \u308B\u8981\u7D20\u5168\u3066\u306Bx\u3092xor\u4F5C\u7528\u3055\u305B\u308B\n\
    \            if(root -> s == 0) return;//\u8981\u7D20\u304C\u5B58\u5728\u3057\u306A\
    \u3044\n            root -> lazy ^= x;\n            eval(root, 0);\n        }\n\
    \        \n\t\t/*\n        S upper_bound(X x) {//x\u3088\u308A\u5927\u304D\u3044\
    \u6700\u5C0F\u306E\u8981\u7D20\u304C\u4F55\u756A\u76EE\u304B\n            return\
    \ 1 + upper_bound_(root, 0, x);\n        }\n    \n        S lower_bound(X x) {//x\u4EE5\
    \u4E0A\u306E\u6700\u5C0F\u306E\u8981\u7D20\u304C\u4F55\u756A\u76EE\u304B\n   \
    \         if(x == 0) return size();\n            else return upper_bound(x - 1);\n\
    \        }*/\n    \n        S size() {//\u53CE\u5BB9\u3055\u308C\u3066\u3044\u308B\
    \u8981\u7D20\u306E\u7DCF\u6570\n            return root -> s;\n        }\n\n\n\
    \t\tvoid dump() {\n\t\t\tS s = size();\n\t\t\tfor(S i = 1; i <= s; i++) {\n\t\t\
    \t\tcout << kth_element(i).first << \" \";\n\t\t\t}\n\t\t\tcout << endl;\n\t\t\
    }\n\n\t\t/*\n\t\t    Binary_Trie<X, S>(W)   X...\u767B\u9332\u3059\u308B\u5024\
    \u30FBxor\u3059\u308B\u5024\u306E\u578B  S...\u5024\u306E\u500B\u6570\u306E\u578B\
    \  W...\u6700\u5927bit\u9577   O(1)\n\t\t\t@brief: Binary_Trie\n\t\t\tinsert(x,\
    \ cnt = 1) ... O(W)\n\t\t\terase(x, cnt = 1) ... O(W)\n\t\t\tcount(x) ... O(W)\n\
    \t\t\tmex_element()/min_element() ... O(W)\n\t\t\tpair<X, S> kth_element(k)  ...\
    \ O(W) {\u5024\u3001\u500B\u6570}\u3092\u8FD4\u3059\n\t\t\tope_xor(x) ... \u96C6\
    \u5408\u5168\u4F53\u306Bx\u3092xor\u4F5C\u7528 O(1)\n\t\t\tsize() ... O(1)\n\n\
    \t\t\t\u7A7A\u9593: \u633F\u5165\u3054\u3068\u306BO(W)\n\n\t\t\n\t\t*/\n};   \
    \ \n\ntemplate<typename T>\nstruct SegTree {\n    int n;\n    vector<Binary_Trie<T,int>>\
    \ dat;\n\n         \n    SegTree(int siz, int W) {\n        n = 1;\n        while(n\
    \ < siz) n <<= 1;\n        //dat.resize(n * 2, Binary_Trie<T, int>(W));\n\t\t\
    dat.resize(n*2);\n\t\tfor(int i = 1; i < n * 2; i++) dat[i] = Binary_Trie<T, int>(W);\n\
    \    }\n\n    private:\n         \n        T query(int l, int r, T x) {\n    \
    \        T L = numeric_limits<T>::max();\n\t\t\tT R = numeric_limits<T>::max();\n\
    \            l += n - 1, r += n - 1;\n            while(l < r) {\n           \
    \     if(l & 1) {\n\t\t\t\t\tdat[l].ope_xor(x);\n\t\t\t\t\tL = min(L, dat[l].min_element());\n\
    \t\t\t\t\tdat[l].ope_xor(x);\n\t\t\t\t\tl++;\n\t\t\t\t}\n                if(r\
    \ & 1) {\n\t\t\t\t\tr--;\n\t\t\t\t\tdat[r].ope_xor(x);\n\t\t\t\t\tR = min(dat[r].min_element(),\
    \ R);\n\t\t\t\t\tdat[r].ope_xor(x);\n\t\t\t\t}\n                l >>= 1, r >>=\
    \ 1;\n            }  \n            return  min(L, R);\n        }\n\n    \n   \
    \ public:\n        /*\n        void set(int pos, T x) {\n            pos += n-1;\n\
    \            dat[pos] = x;\n        }\n          \n        void init() {\n   \
    \         for(int i = n-1; i >= 1; i--)  dat[i] = op(dat[i<<1], dat[(i<<1) + 1]);\n\
    \        }*/\n          \n        void add(int pos, T x, int cnt) {\n        \
    \    pos += n - 1;\n            dat[pos].insert(x, cnt);\n            while(pos\
    \ >= 2) {\n                pos >>= 1;\n\t\t\t\tdat[pos].insert(x, cnt);\n    \
    \        }\n        }\n\n\n        T get(int l, int r, T x) {// [l, r]\u306E\u6F14\
    \u7B97\u7D50\u679C\u3002\n            return query(l, r+1, x);\n        }\n\n\
    \        T operator[](int pos) {\n            return dat[pos + n - 1];\n     \
    \   }\n         \n};\n\n/*\n@brief range xor range min\n*/"
  dependsOn: []
  isVerificationFile: false
  path: DataStructures/btrietree.cpp
  requiredBy: []
  timestamp: '2024-05-11 03:22:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DataStructures/btrietree.cpp
layout: document
redirect_from:
- /library/DataStructures/btrietree.cpp
- /library/DataStructures/btrietree.cpp.html
title: range xor range min
---
