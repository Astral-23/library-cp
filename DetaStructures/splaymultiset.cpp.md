---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "splaytree(multiset) \u30C8\u30C3\u30D7\u30C0\u30A6\u30F3splay"
    links: []
  bundledCode: "#line 1 \"DetaStructures/splaymultiset.cpp\"\ntemplate<typename X>\n\
    struct splay_multiset {\n    struct node_t {\n            X val;\n           \
    \ X acc;\n            int sum = 0;\n            node_t* lch;\n            node_t*\
    \ rch;\n            node_t(X v):  val(v), acc(v) {\n                sum = 1;\n\
    \                lch = nullptr;\n                rch = nullptr;\n            }\n\
    \    };\n    using NODE = node_t;\n    NODE* root = nullptr;//Splay\u6728\u306E\
    \u6839\u3092\u8868\u3059\u30CE\u30FC\u30C9\u3002\n    long long size_of_tree =\
    \ 0;//\u6728\u306B\u767B\u9332\u3055\u308C\u3066\u3044\u308B\u8981\u7D20\u6570\
    \u3092\u8FD4\u3059\u3002\n    int pre = 0;\n    splay_multiset(){}\n\n    private:\n\
    \n        long long count(NODE* now) {return now == nullptr ? 0 : now -> sum;}\n\
    \        X acc(NODE* now) {return !now ? X() : now -> acc;}\n\n        NODE* pushup(NODE*\
    \ now) {\n            if(now != nullptr) {\n                now -> sum = count(now\
    \ -> lch) + count(now -> rch) + 1;\n                now -> acc = acc(now -> lch)\
    \ + now -> val + acc(now -> rch);\n            }\n            return now;\n  \
    \      }\n\n\n        NODE* rotate(NODE* now, int b) {//\u30CE\u30FC\u30C9now\u3092\
    \u56DE\u8EE2\u3055\u305B\u308B\u51E6\u7406\u3002b = 1\u3067\u53F3\u56DE\u8EE2\u3001\
    \ b = 0\u3067\u5DE6\u56DE\u8EE2\u3002\u300D\n            if(b==1) {\n        \
    \        NODE* s = now -> lch;\n                now -> lch = s -> rch;\n     \
    \           s -> rch = now;\n                pushup(now), pushup(s);\n       \
    \         return s;//\u623B\u308A\u5024\u306F\u3001\u56DE\u8EE2\u3057\u305F\u5F8C\
    now\u306E\u4F4D\u7F6E\u306B\u304F\u308B\u30CE\u30FC\u30C9\u306E\u30DD\u30A4\u30F3\
    \u30BF\u3002\n            }\n            else {\n                NODE* s = now\
    \ -> rch;\n                now -> rch = s -> lch;\n                s -> lch =\
    \ now;\n                pushup(now), pushup(s);\n                return s;\n \
    \           }\n        }\n\n        NODE* splay_sub_pos(NODE* now, int pos, pair<int,\
    \ NODE*>& history, bool& found) {\n            if(now == nullptr) {\n        \
    \        found = false;\n                return now;\n            } \n       \
    \     if(count(now -> lch) + 1 == pos) {\n                return now;\n      \
    \      }\n\n            int b = 1;\n            if(count(now -> lch) + 1 < pos)\
    \ {\n                pos -= count(now -> lch) + 1;\n                now -> rch\
    \ = splay_sub_pos(now -> rch, pos, history, found);\n                pushup(now);\n\
    \            }\n            else {\n                b = 0, now -> lch = splay_sub_pos(now\
    \ -> lch, pos, history, found);\n                pushup(now);\n            } \n\
    \n            if(!found) return now;\n\n            auto [pb, pn] = history;\n\
    \            if(pn == nullptr) history = make_pair(b, now);\n            else\
    \ {\n                history = make_pair(-1, nullptr);\n                if(b ==\
    \ pb) {\n                    now = rotate(now, 1 - b);\n                    now\
    \ = rotate(now, 1 - b);\n                }\n                else {\n         \
    \           if(b==1) now -> rch = rotate(pn, 1 - pb);\n                    else\
    \ now -> lch = rotate(pn, 1 - pb);\n                    pushup(now);\n       \
    \             now = rotate(now, 1 - b);\n                }\n            }\n  \
    \          return now;\n        }\n\n        NODE* splay_sub(NODE* now, const\
    \ X& x, pair<int, NODE*>& history, bool& found) {\n            if(now == nullptr)\
    \ {\n                found = false;\n                return now;\n           \
    \ } \n            if(now -> val == x) {\n                return now;\n       \
    \     }\n\n            int b = 1;\n            if(x > now -> val) {\n        \
    \        now -> rch = splay_sub(now -> rch, x, history, found);\n            \
    \    pushup(now);\n            }\n            else if(x < now -> val) {\n    \
    \            b = 0, now -> lch = splay_sub(now -> lch, x, history, found);\n \
    \               pushup(now);\n            } \n\n            if(!found) return\
    \ now;\n\n            auto [pb, pn] = history;\n            if(pn == nullptr)\
    \ history = make_pair(b, now);\n            else {\n                history =\
    \ make_pair(-1, nullptr);\n                if(b == pb) {\n                   \
    \ now = rotate(now, 1 - b);\n                    now = rotate(now, 1 - b);\n \
    \               }\n                else {\n                    if(b==1) now ->\
    \ rch = rotate(pn, 1 - pb);\n                    else now -> lch = rotate(pn,\
    \ 1 - pb);\n                    pushup(now);\n                    now = rotate(now,\
    \ 1 - b);\n                }\n            }\n            return now;\n       \
    \ }\n\n        void splay(NODE* now, const X& x) {\n            bool found = true;\n\
    \            pair<int, NODE*> h(-1, nullptr);\n            root = splay_sub(now,\
    \ x, h, found);\n            if(found && h.second != nullptr) {\n            \
    \    root = rotate(root, 1 - h.first);\n            }\n            return ;\n\
    \        }\n\n        void splay_pos(NODE* now, int pos) {\n            bool found\
    \ = true;\n            pair<int, NODE*> h(-1, nullptr);\n            root = splay_sub_pos(now,\
    \ pos, h, found);\n            if(found && h.second != nullptr) {\n          \
    \      root = rotate(root, 1 - h.first);\n            }\n            return ;\n\
    \n        }\n \n \n        NODE* change__(NODE* now, X& x, int& pos) {//\u73FE\
    \u5728\u898B\u3066\u3044\u308B\u30CE\u30FC\u30C9 | \u633F\u5165\u3059\u308B\u5024\
    \n            if(now == nullptr) {\n                size_of_tree++;\n        \
    \        pos++;\n                return new NODE(x);\n            }\n        \
    \    if(x > now -> val) {\n                pos += count(now -> lch);\n       \
    \         now -> rch = change__(now -> rch, x, pos);\n                pushup(now);\n\
    \                return now;\n            }\n            else if(x < now -> val)\
    \ {\n                now -> lch = change__(now -> lch, x, pos);\n            \
    \    pushup(now);\n                return now;\n            }\n            else\
    \ {\n                pre ^= 1;\n                if(pre) {\n                  \
    \  pos += count(now -> lch);\n                    now -> rch = change__(now ->\
    \ rch, x, pos);\n                    pushup(now);\n                    return\
    \ now;\n                }\n                else {\n                    now ->\
    \ lch = change__(now -> lch, x, pos);\n                    pushup(now);\n    \
    \                return now;\n\n                }\n            }\n        }\n\n\
    \       \n        NODE* find_max_only(NODE* now) {//now\u3092\u6839\u3068\u3059\
    \u308B\u90E8\u5206\u6728\u306E\u4E2D\u3067\u6700\u5927\u306E\u8981\u7D20\u3092\
    \u6301\u3064\u30CE\u30FC\u30C9\u3092\u8FD4\u3059\u3002\u3053\u306E\u6642\u3001\
    splay\u64CD\u4F5C\u306F\u884C\u308F\u306A\u3044\u3002\n           if(now == nullptr)\
    \ return now;\n           NODE* res = now;\n           while(res -> rch != nullptr)\
    \ res  = res -> rch;\n           return res;\n        }\n\n        NODE* find_min_only(NODE*\
    \ now) {//now\u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306E\u4E2D\u3067\
    \u6700\u5C0F\u306E\u8981\u7D20\u3092\u6301\u3064\u30CE\u30FC\u30C9\u3092\u8FD4\
    \u3059\u3002\u3053\u306E\u6642\u3001splay\u64CD\u4F5C\u306F\u884C\u308F\u306A\u3044\
    \u3002\n           if(now == nullptr) return now;\n           NODE* res = now;\n\
    \           while(res -> lch != nullptr) res = res -> lch;\n           return\
    \ res;\n        }\n\n\n        NODE* erase__(NODE*now, X& x){//\u524A\u9664\u30CE\
    \u30FC\u30C9\u307E\u3067\u964D\u3063\u3066\u3044\u304D\u3001\u524A\u9664\u304C\
    \u5B8C\u4E86\u6B21\u7B2C\u8449\u306E\u65B9\u304B\u3089\u518D\u69CB\u6210\u3059\
    \u308B\u3002\n            if(now == nullptr) return now;\n            if(x < now\
    \ -> val) {\n                now -> lch = erase__(now -> lch, x);\n          \
    \      pushup(now);\n            }\n            else if(x > now -> val) {\n  \
    \              now -> rch = erase__(now -> rch, x);\n                pushup(now);\n\
    \            }\n            else {\n                if(now -> lch == nullptr)\
    \ {//\u5DE6\u306B\u5B50\u304C\u306A\u3044\u6642\n                    NODE* tmp\
    \ = now -> rch;\n                    delete now;\n                    size_of_tree--;\n\
    \                    return tmp;\n                }\n                else if(now\
    \ -> rch == nullptr) {//\u53F3\u306B\u5B50\u304C\u306A\u3044\u6642\n         \
    \           NODE* tmp = now -> lch;\n                    delete now;\n       \
    \             size_of_tree--;\n                    return tmp;\n             \
    \   } else {//\u53F3\u306B\u3082\u5DE6\u306B\u3082\u5B50\u304C\u3042\u308B\u6642\
    \n                    NODE* tmp = find_max_only(now -> lch);//\u5DE6\u5B50\u5B6B\
    \u306E\u6700\u5927\u5024\n                    now -> val = tmp -> val;\n     \
    \               now -> lch = erase__(now -> lch, tmp -> val);//\u79FB\u52D5\u3057\
    \u305F\u30CE\u30FC\u30C9\u3092\u524A\u9664\u3002(\u30DD\u30A4\u30F3\u30BF\u306E\
    \u64CD\u4F5C\u306B\u6CE8\u610F)\n                    pushup(now);\n          \
    \      }\n            }\n            return now;//\u73FE\u5728\u306E\u30CE\u30FC\
    \u30C9\u307E\u3067\u524A\u9664\u306E\u4F5C\u696D\u304C\u5B8C\u4E86\u3057\u305F\
    \u3089\u3070\u3001\u66F4\u65B0\u3055\u308C\u305F\u73FE\u5728\u306E\u30CE\u30FC\
    \u30C9\u3092\u8FD4\u3057\u3066\u7D42\u4E86\u3002\n        }\n\n\n        int count__(NODE*\
    \ now, X& x) {\n            if(now == nullptr) return 0;\n            if(now ->\
    \ val == x) {\n                return 1 + count__(now -> rch, x) + count__(now\
    \ -> lch, x);\n            }\n            else if(now -> val > x) return count__(now\
    \ -> lch, x);\n            else return count__(now -> rch, x);\n        }\n\n\
    \        void lower_bound_val__(NODE*now, X& x, X& res) {//x\u4EE5\u4E0A\u3067\
    \u6700\u5C0Fval\n        //\u524D\u63D0\uFF1A\u305D\u306E\u69D8\u306A\u5024\u304C\
    \u5B58\u5728\u3059\u308B\u3002\n            if(now -> val == x) {\n          \
    \      res = x;\n                return;\n            }\n            if(x < now\
    \ -> val) {//\u7B54\u3048\u306F\u3001min(now, now\u306E\u5DE6\u5B50\u5B6B\u306E\
    \u4E2D\u3067x\u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\u8981\u7D20)\n             \
    \   res = min(res, now -> val);\n                if(now -> lch != nullptr) lower_bound_val__(now\
    \ -> lch, x, res);\n            }\n            else {//\u7B54\u3048\u306F\u3001\
    \u53F3\u5B50\u5B6B\u306E\u4E2D\u3067x\u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\u5024\
    \n                if(now -> rch != nullptr)  lower_bound_val__(now -> rch, x,\
    \ res);//\u53F3\u306B\u5B50\u304C\u5B58\u5728\u3057\u306A\u3044\u3068\u3044\u3046\
    \u4E8B\u306F\u306A\u3044\u3002\n            }\n            return;\n        }\n\
    \n        void upper_bound_val__(NODE*now, X& x, X& res) {//x\u8D85\u904E\u3067\
    \u6700\u5C0Fval\n        //\u524D\u63D0\uFF1A\u305D\u306E\u69D8\u306A\u5024\u304C\
    \u5B58\u5728\u3059\u308B\u3002\n            if(x < now -> val) {//\u7B54\u3048\
    \u306F\u3001min(now, now\u306E\u5DE6\u5B50\u5B6B\u306E\u4E2D\u3067x\u3088\u308A\
    \u5927\u304D\u3044\u6700\u5C0F\u306E\u8981\u7D20)\n                res = min(res,\
    \ now -> val);\n                if(now -> lch != nullptr) upper_bound_val__(now\
    \ -> lch, x, res);\n            }\n            else {//\u7B54\u3048\u306F\u3001\
    \u53F3\u5B50\u5B6B\u306E\u4E2D\u3067x\u3088\u308A\u5927\u304D\u3044\u306E\u6700\
    \u5C0F\u306E\u5024\n                if(now -> rch != nullptr)  upper_bound_val__(now\
    \ -> rch, x, res);//\u53F3\u306B\u5B50\u304C\u5B58\u5728\u3057\u306A\u3044\u3068\
    \u3044\u3046\u4E8B\u306F\u306A\u3044\u3002\n            }\n            return;\n\
    \        }\n      \n      \n        void lower_left_bound_val__(NODE* now, X&\
    \ x, X& res) {//x\u4EE5\u4E0B\u3067\u6700\u5927val\n        //\u524D\u63D0\uFF1A\
    \u305D\u306E\u69D8\u306A\u5024\u304C\u5B58\u5728\u3059\u308B\u3002\n         \
    \   if(now -> val == x) {\n                res = x;\n                return;\n\
    \            }\n            if(x < now -> val) {//\u5DE6\n                if(now\
    \ -> lch != nullptr) lower_left_bound_val__(now -> lch, x, res);\n           \
    \ }\n            else {\n                res = max(res, now -> val);\n       \
    \         if(now -> rch != nullptr) lower_left_bound_val__(now -> rch, x, res);\n\
    \n            }\n        }\n\n        void upper_left_bound_val__(NODE* now, X&\
    \ x, X& res) {//x\u672A\u6E80\u3067\u6700\u5927val\n        //\u524D\u63D0\uFF1A\
    \u305D\u306E\u69D8\u306A\u5024\u304C\u5B58\u5728\u3059\u308B\u3002\n         \
    \   if(x <= now -> val) {//\u5DE6\n                if(now -> lch != nullptr) upper_left_bound_val__(now\
    \ -> lch, x, res);\n            }\n            else {\n                res = max(res,\
    \ now -> key);\n                if(now -> rch != nullptr) upper_left_bound_val__(now\
    \ -> rch, x, res);\n            }\n        }\n\n        NODE* lower_bound__(X\
    \ x) {//x\u4EE5\u4E0A\u3067\u6700\u5C0F\u3001\u5B58\u5728\u3057\u306A\u3044\u306A\
    \u3089nullptr\n            if(size_of_tree==0) return nullptr;\n            NODE*\
    \ M = find_max_only(root);\n            X t = M -> val;\n            if(t < x)\
    \ return nullptr;//x\u4EE5\u4E0A\u306E\u5024\u306F\u5B58\u5728\u3057\u306A\u3044\
    \u3002\n            lower_bound_val__(root, x, t);\n            splay(root, t);\n\
    \            return root;\n        }\n\n        NODE* upper_bound__(X x) {//k\u8D85\
    \u904E\u3067\u6700\u5C0F\u3001\u5B58\u5728\u3057\u306A\u3044\u306A\u3089nullptr\n\
    \            if(size_of_tree==0) return nullptr;\n            NODE* M = find_max_only(root);\n\
    \            X t = M -> val;\n            if(t <= x) return nullptr;\n       \
    \     upper_bound_val__(root, x, t);\n            splay(root, t);\n          \
    \  return root;\n        }\n\n        NODE* lower_left_bound__(X x) {//k\u4EE5\
    \u4E0B\u3067\u6700\u5927\u3002\n            if(size_of_tree==0) return nullptr;\n\
    \            NODE* m = find_min_only(root);\n            X t = m -> val;\n   \
    \         ;\n            if(t > x) return nullptr;\n            lower_left_bound_val__(root,\
    \ x, t);\n            splay(root, t);\n            return root;\n        }\n\n\
    \        NODE* upper_left_bound__(X x) {//k\u672A\u6E80\u3067\u6700\u5927\u3002\
    \n            if(size_of_tree==0) return nullptr;\n            NODE* m = find_min_only(root);\n\
    \            X t = m -> val;\n            if(t >= x) return nullptr;\n       \
    \     upper_left_bound_val__(root, x, t);\n            splay(root, t);\n     \
    \       return root;\n        }\n\n        NODE* ith_element__(NODE* now, long\
    \ long i) {\n            long long ls = count(now -> lch);\n            if(ls\
    \ + 1 <= i && i <= ls + 1) {\n                return now;\n            }\n   \
    \         else if(ls >= i) return ith_element__(now -> lch, i);\n            else\
    \ return ith_element__(now -> rch, i - 1 - ls);\n        }\n\n        NODE* max_element__()\
    \ {//\u6700\u5927\u306Ekey\u3001\u5B58\u5728\u3057\u306A\u3044\u306A\u3089nullptr\n\
    \            NODE* tar = find_max_only(root);\n            if(tar == nullptr)\
    \ return tar;\n            pair<int, NODE*> h (-1, nullptr);\n            splay(root\
    \ , tar -> val);\n            return root;\n        }\n\n        NODE* min_element__()\
    \ {//\u6700\u5C0F\u306Ekey\u3001\u5B58\u5728\u3057\u306A\u3044\u306A\u3089nullptr\n\
    \            NODE* tar = find_min_only(root);\n            if(tar == nullptr)\
    \ return tar;\n            pair<int, NODE*> h (-1, nullptr);\n            splay(root\
    \ , tar -> val);\n            return root;\n        }\n\n        NODE* lower_sum_left__(NODE*\
    \ now, X S, int L) {\n            X now_sum = X();\n            if(L != 1) {\n\
    \                S = S + accL(L-1);\n            }\n            int pos = 0;\n\
    \            if(S > acc(root)) return nullptr;\n            while(1) {\n     \
    \           X tmp = now_sum + acc(now -> lch);\n                if(tmp >= S) now\
    \ = now -> lch;\n                else {\n                    tmp += now -> val;\n\
    \                    pos += 1 + count(now -> lch);\n                    if(tmp\
    \ >= S) {\n                        splay_pos(root, pos);\n                   \
    \     return root;\n                    }\n                    else {\n      \
    \                  now_sum = tmp;\n                        now = now -> rch;\n\
    \                    }\n                }\n            }\n        }\n\n      \
    \  NODE* upper_sum_left__(NODE* now, X S, int L) {\n            X now_sum = X();\n\
    \            if(L != 1) {\n                S = S + accL(L-1);\n            }\n\
    \            int pos = 0;\n            if(S >= acc(root)) return nullptr;\n  \
    \          while(1) {\n                X tmp = now_sum + acc(now -> lch);\n  \
    \              if(tmp > S) now = now -> lch;\n                else {\n       \
    \             tmp += now -> val;\n                    pos += 1 + count(now ->\
    \ lch);\n                    if(tmp > S) {\n                        splay_pos(root,\
    \ pos);\n                        return root;\n                    }\n       \
    \             else {\n                        now_sum = tmp;\n               \
    \         now = now -> rch;\n                    }\n                }\n      \
    \      }\n        }\n\n        NODE* next(NODE*& now) {//\u6B21\u306Ekey\u3001\
    \u5B58\u5728\u3057\u306A\u3044\u306A\u3089nullptr\n            if(now == nullptr)\
    \ return now;\n            else return upper_bound__(now -> val);\n        }\n\
    \n\n        NODE* prev(NODE*& now) {//\u524D\u306Ekey\u3002\u5B58\u5728\u3057\u306A\
    \u3051\u308C\u3070nullptr\n            if(now == nullptr) return now;\n      \
    \      else return upper_left_bound__(now -> val);\n        }\n\n        void\
    \ in_order__(NODE* now, vector<X>& res) {\n            if(now == nullptr) return;\n\
    \            in_order__(now -> lch, res);\n            res.push_back(now -> val);\n\
    \            in_order__(now -> rch, res);\n            return;\n        }\n  \
    \      \n        void change(X x) {//x\u3092\u633F\u5165)\n            pushup(root);\n\
    \            int pos = 0;\n            root = change__(root, x, pos);\n      \
    \      splay_pos(root, pos);//\u6839\u3092\u66F4\u65B0\u3002\n            return;\n\
    \        }\n\n\n\n\n    public:\n\n\n        void insert(X x) {\n            pushup(root);\n\
    \            change(x);\n        }\n\n        void erase(X x) {//\u5B58\u5728\u3057\
    \u306A\u304B\u3063\u305F\u5834\u5408\u3001\u4F55\u3082\u3057\u306A\u3044\u3002\
    \n            pushup(root);\n            root = erase__(root, x);\n        }\n\
    \n        bool find(X x) {\n            pushup(root);\n            splay(root,x);\n\
    \            if(root == nullptr || root -> val != x) return false;\n         \
    \   return true;\n        }\n\n        int count(X x) {\n            pushup(root);\n\
    \            pair<int, NODE*> h (-1, nullptr);\n            splay(root, x);\n\
    \            if(root == nullptr || root -> val != x) return 0;\n            return\
    \ count__(root, x);\n        }\n\n\n        \n        \n  \n        int size()\
    \ {\n            return size_of_tree;\n        }\n\n        bool empty() {\n \
    \           return size_of_tree == 0;\n        }\n\n        \n        bool next(X\
    \ x, X& res) {//\u6B21\u306Ekey\u3002\u5B58\u5728\u3057\u306A\u3044\u306A\u3089\
    false\u3002\u7D50\u679C\u306Fres\u306B\u6E21\u3055\u308C\u308B\u3002\n       \
    \     pushup(root);\n            NODE* r = upper_bound__(x);\n            if(r==nullptr)return\
    \ false;\n            else {\n                res = r -> val;\n              \
    \  return true;\n            }\n        }\n\n        \n        bool prev(X x,\
    \ X& res) {//\u524D\u306Ekey.\u5B58\u5728\u3057\u306A\u3044\u306A\u3089false\u3002\
    \u7D50\u679C\u306Fres\u306B\u6E21\u3055\u308C\u308B\u3002\n            pushup(root);\n\
    \            NODE* r = upper_left_bound__(x);\n            if(r==nullptr)return\
    \ false;\n            else {\n                res = r -> val;\n              \
    \  return true;\n            }\n        }\n\n        bool ith_element(long long\
    \ i, X& res) {\n            pushup(root);\n            if(count(root) < i) return\
    \ false;\n            else {\n                NODE* tar = ith_element__(root,\
    \ i);\n                res = tar -> val;\n                return i;\n        \
    \    }\n        }\n\n        bool max_element(X& res) {//\u6700\u5927\u306Ekey\n\
    \            pushup(root);\n            NODE* tar = max_element__();\n       \
    \     if(tar == nullptr) return false;\n            else {\n                res\
    \ =  tar -> val;\n                return true;\n            }\n        }\n\n \
    \       bool min_element(X& res) {//\u6700\u5C0F\u306Ekey\n            pushup(root);\n\
    \            NODE* tar = min_element__();\n            if(tar == nullptr) return\
    \ false;\n            else {\n                res =  tar -> val;\n           \
    \     return true;\n            }\n        }\n\n        bool lower_bound(X x,\
    \ X& res) {//x\u4EE5\u4E0A\u3067\u6700\u5C0Fkey\n            pushup(root);\n \
    \           NODE* r = lower_bound__(x);\n            if(r == nullptr) return false;\n\
    \            else {\n                res = r -> val;\n                return true;\n\
    \            }\n        }\n\n        bool upper_bound(X x, X& res) {//k\u8D85\u904E\
    \u3067\u6700\u5C0F\u3068\u306A\u308B\n            pushup(root);\n            NODE*\
    \ r = upper_bound__(x);\n            if(r == nullptr) return false;\n        \
    \    else {\n                res = r -> val;\n                return true;\n \
    \           }\n        }\n\n        bool lower_left_bound(X x, X& res) {//k\u4EE5\
    \u4E0B\u3067\u6700\u5927\u3002 \n            pushup(root);\n            NODE*\
    \ r = lower_left_bound__(x);\n            if(r == nullptr) return false;\n   \
    \         else {\n                res = r -> val;\n                return true;\n\
    \            }\n        }\n\n        bool upper_left_bound(X x, X& res) {//k\u672A\
    \u6E80\u3067\u6700\u5927\u3002\n            pushup(root);\n            NODE* r\
    \ = upper_left_bound__(x);\n            if(r == nullptr) return false;\n     \
    \       else {\n                res = r -> val;\n                return true;\n\
    \            }\n        }\n\n        X accL(int R) {//[1, R]\u306Eval\u306E\u30E2\
    \u30CE\u30A4\u30C9\u7A4D R\u304Ckey\u306E\u6570\u3088\u308A\u591A\u3044\u3068\u5358\
    \u4F4D\u5143\n            if(R < 1 || size_of_tree < R) return X();\n        \
    \    pushup(root);\n            X tar;\n            if(!ith_element(R, tar)) return\
    \ X();\n            splay(root, tar);\n            return acc(root -> lch) + root\
    \ -> val;\n        }\n\n        X accR(int L) {//[L, MAX]\u306Eval\u306E\u30E2\
    \u30CE\u30A4\u30C9\n            if(L < 1 || size_of_tree < L) return X();\n  \
    \          pushup(root);\n            X tar;\n            if(!ith_element(L, tar))\
    \ return X();\n            splay(root, tar);\n            return root -> val +\
    \ acc(root -> rch);\n        }\n\n        bool lower_sum_left(X sum, int L, X&\
    \ res) {\n            pushup(root);\n            NODE* tar = lower_sum_left__(root,\
    \ sum, L);\n            if(tar == nullptr) return false;\n            else {\n\
    \                res = acc(tar -> lch) + tar -> val;\n                return true;\n\
    \            }\n\n        }\n\n        bool upper_sum_left(X sum, int L, X& res)\
    \ {\n            pushup(root);\n            NODE* tar = upper_sum_left__(root,\
    \ sum, L);\n            if(tar == nullptr) return false;\n            else {\n\
    \                //res = acc(tar -> lch) + tar -> val;\n                res =\
    \ count(tar -> lch) + 1;\n                return true;\n            }\n\n    \
    \    }\n\n        \n        vector<X> in_order() {//\u8981\u7D20\u3092\u5168\u3066\
    \u5165\u308C\u305F\u914D\u5217 \u8981\u7D20\u304C\u306A\u3044\u306A\u3089\u7A7A\
    \u914D\u5217\n            pushup(root);\n            vector<X> res;\n        \
    \    in_order__(root, res);\n            return res;\n        }\n\n        void\
    \ dump() {\n            pushup(root);\n            auto r = in_order();\n    \
    \        for(X& x : r) cout << x << \" \";\n            cout << endl;\n      \
    \  }\n\n        NODE* end() {\n            return nullptr;\n        }\n\n};\n\n\
    /*\n@brief splaytree(multiset) \u30C8\u30C3\u30D7\u30C0\u30A6\u30F3splay\n*/\n"
  code: "template<typename X>\nstruct splay_multiset {\n    struct node_t {\n    \
    \        X val;\n            X acc;\n            int sum = 0;\n            node_t*\
    \ lch;\n            node_t* rch;\n            node_t(X v):  val(v), acc(v) {\n\
    \                sum = 1;\n                lch = nullptr;\n                rch\
    \ = nullptr;\n            }\n    };\n    using NODE = node_t;\n    NODE* root\
    \ = nullptr;//Splay\u6728\u306E\u6839\u3092\u8868\u3059\u30CE\u30FC\u30C9\u3002\
    \n    long long size_of_tree = 0;//\u6728\u306B\u767B\u9332\u3055\u308C\u3066\u3044\
    \u308B\u8981\u7D20\u6570\u3092\u8FD4\u3059\u3002\n    int pre = 0;\n    splay_multiset(){}\n\
    \n    private:\n\n        long long count(NODE* now) {return now == nullptr ?\
    \ 0 : now -> sum;}\n        X acc(NODE* now) {return !now ? X() : now -> acc;}\n\
    \n        NODE* pushup(NODE* now) {\n            if(now != nullptr) {\n      \
    \          now -> sum = count(now -> lch) + count(now -> rch) + 1;\n         \
    \       now -> acc = acc(now -> lch) + now -> val + acc(now -> rch);\n       \
    \     }\n            return now;\n        }\n\n\n        NODE* rotate(NODE* now,\
    \ int b) {//\u30CE\u30FC\u30C9now\u3092\u56DE\u8EE2\u3055\u305B\u308B\u51E6\u7406\
    \u3002b = 1\u3067\u53F3\u56DE\u8EE2\u3001 b = 0\u3067\u5DE6\u56DE\u8EE2\u3002\u300D\
    \n            if(b==1) {\n                NODE* s = now -> lch;\n            \
    \    now -> lch = s -> rch;\n                s -> rch = now;\n               \
    \ pushup(now), pushup(s);\n                return s;//\u623B\u308A\u5024\u306F\
    \u3001\u56DE\u8EE2\u3057\u305F\u5F8Cnow\u306E\u4F4D\u7F6E\u306B\u304F\u308B\u30CE\
    \u30FC\u30C9\u306E\u30DD\u30A4\u30F3\u30BF\u3002\n            }\n            else\
    \ {\n                NODE* s = now -> rch;\n                now -> rch = s ->\
    \ lch;\n                s -> lch = now;\n                pushup(now), pushup(s);\n\
    \                return s;\n            }\n        }\n\n        NODE* splay_sub_pos(NODE*\
    \ now, int pos, pair<int, NODE*>& history, bool& found) {\n            if(now\
    \ == nullptr) {\n                found = false;\n                return now;\n\
    \            } \n            if(count(now -> lch) + 1 == pos) {\n            \
    \    return now;\n            }\n\n            int b = 1;\n            if(count(now\
    \ -> lch) + 1 < pos) {\n                pos -= count(now -> lch) + 1;\n      \
    \          now -> rch = splay_sub_pos(now -> rch, pos, history, found);\n    \
    \            pushup(now);\n            }\n            else {\n               \
    \ b = 0, now -> lch = splay_sub_pos(now -> lch, pos, history, found);\n      \
    \          pushup(now);\n            } \n\n            if(!found) return now;\n\
    \n            auto [pb, pn] = history;\n            if(pn == nullptr) history\
    \ = make_pair(b, now);\n            else {\n                history = make_pair(-1,\
    \ nullptr);\n                if(b == pb) {\n                    now = rotate(now,\
    \ 1 - b);\n                    now = rotate(now, 1 - b);\n                }\n\
    \                else {\n                    if(b==1) now -> rch = rotate(pn,\
    \ 1 - pb);\n                    else now -> lch = rotate(pn, 1 - pb);\n      \
    \              pushup(now);\n                    now = rotate(now, 1 - b);\n \
    \               }\n            }\n            return now;\n        }\n\n     \
    \   NODE* splay_sub(NODE* now, const X& x, pair<int, NODE*>& history, bool& found)\
    \ {\n            if(now == nullptr) {\n                found = false;\n      \
    \          return now;\n            } \n            if(now -> val == x) {\n  \
    \              return now;\n            }\n\n            int b = 1;\n        \
    \    if(x > now -> val) {\n                now -> rch = splay_sub(now -> rch,\
    \ x, history, found);\n                pushup(now);\n            }\n         \
    \   else if(x < now -> val) {\n                b = 0, now -> lch = splay_sub(now\
    \ -> lch, x, history, found);\n                pushup(now);\n            } \n\n\
    \            if(!found) return now;\n\n            auto [pb, pn] = history;\n\
    \            if(pn == nullptr) history = make_pair(b, now);\n            else\
    \ {\n                history = make_pair(-1, nullptr);\n                if(b ==\
    \ pb) {\n                    now = rotate(now, 1 - b);\n                    now\
    \ = rotate(now, 1 - b);\n                }\n                else {\n         \
    \           if(b==1) now -> rch = rotate(pn, 1 - pb);\n                    else\
    \ now -> lch = rotate(pn, 1 - pb);\n                    pushup(now);\n       \
    \             now = rotate(now, 1 - b);\n                }\n            }\n  \
    \          return now;\n        }\n\n        void splay(NODE* now, const X& x)\
    \ {\n            bool found = true;\n            pair<int, NODE*> h(-1, nullptr);\n\
    \            root = splay_sub(now, x, h, found);\n            if(found && h.second\
    \ != nullptr) {\n                root = rotate(root, 1 - h.first);\n         \
    \   }\n            return ;\n        }\n\n        void splay_pos(NODE* now, int\
    \ pos) {\n            bool found = true;\n            pair<int, NODE*> h(-1, nullptr);\n\
    \            root = splay_sub_pos(now, pos, h, found);\n            if(found &&\
    \ h.second != nullptr) {\n                root = rotate(root, 1 - h.first);\n\
    \            }\n            return ;\n\n        }\n \n \n        NODE* change__(NODE*\
    \ now, X& x, int& pos) {//\u73FE\u5728\u898B\u3066\u3044\u308B\u30CE\u30FC\u30C9\
    \ | \u633F\u5165\u3059\u308B\u5024\n            if(now == nullptr) {\n       \
    \         size_of_tree++;\n                pos++;\n                return new\
    \ NODE(x);\n            }\n            if(x > now -> val) {\n                pos\
    \ += count(now -> lch);\n                now -> rch = change__(now -> rch, x,\
    \ pos);\n                pushup(now);\n                return now;\n         \
    \   }\n            else if(x < now -> val) {\n                now -> lch = change__(now\
    \ -> lch, x, pos);\n                pushup(now);\n                return now;\n\
    \            }\n            else {\n                pre ^= 1;\n              \
    \  if(pre) {\n                    pos += count(now -> lch);\n                \
    \    now -> rch = change__(now -> rch, x, pos);\n                    pushup(now);\n\
    \                    return now;\n                }\n                else {\n\
    \                    now -> lch = change__(now -> lch, x, pos);\n            \
    \        pushup(now);\n                    return now;\n\n                }\n\
    \            }\n        }\n\n       \n        NODE* find_max_only(NODE* now) {//now\u3092\
    \u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306E\u4E2D\u3067\u6700\u5927\u306E\
    \u8981\u7D20\u3092\u6301\u3064\u30CE\u30FC\u30C9\u3092\u8FD4\u3059\u3002\u3053\
    \u306E\u6642\u3001splay\u64CD\u4F5C\u306F\u884C\u308F\u306A\u3044\u3002\n    \
    \       if(now == nullptr) return now;\n           NODE* res = now;\n        \
    \   while(res -> rch != nullptr) res  = res -> rch;\n           return res;\n\
    \        }\n\n        NODE* find_min_only(NODE* now) {//now\u3092\u6839\u3068\u3059\
    \u308B\u90E8\u5206\u6728\u306E\u4E2D\u3067\u6700\u5C0F\u306E\u8981\u7D20\u3092\
    \u6301\u3064\u30CE\u30FC\u30C9\u3092\u8FD4\u3059\u3002\u3053\u306E\u6642\u3001\
    splay\u64CD\u4F5C\u306F\u884C\u308F\u306A\u3044\u3002\n           if(now == nullptr)\
    \ return now;\n           NODE* res = now;\n           while(res -> lch != nullptr)\
    \ res = res -> lch;\n           return res;\n        }\n\n\n        NODE* erase__(NODE*now,\
    \ X& x){//\u524A\u9664\u30CE\u30FC\u30C9\u307E\u3067\u964D\u3063\u3066\u3044\u304D\
    \u3001\u524A\u9664\u304C\u5B8C\u4E86\u6B21\u7B2C\u8449\u306E\u65B9\u304B\u3089\
    \u518D\u69CB\u6210\u3059\u308B\u3002\n            if(now == nullptr) return now;\n\
    \            if(x < now -> val) {\n                now -> lch = erase__(now ->\
    \ lch, x);\n                pushup(now);\n            }\n            else if(x\
    \ > now -> val) {\n                now -> rch = erase__(now -> rch, x);\n    \
    \            pushup(now);\n            }\n            else {\n               \
    \ if(now -> lch == nullptr) {//\u5DE6\u306B\u5B50\u304C\u306A\u3044\u6642\n  \
    \                  NODE* tmp = now -> rch;\n                    delete now;\n\
    \                    size_of_tree--;\n                    return tmp;\n      \
    \          }\n                else if(now -> rch == nullptr) {//\u53F3\u306B\u5B50\
    \u304C\u306A\u3044\u6642\n                    NODE* tmp = now -> lch;\n      \
    \              delete now;\n                    size_of_tree--;\n            \
    \        return tmp;\n                } else {//\u53F3\u306B\u3082\u5DE6\u306B\
    \u3082\u5B50\u304C\u3042\u308B\u6642\n                    NODE* tmp = find_max_only(now\
    \ -> lch);//\u5DE6\u5B50\u5B6B\u306E\u6700\u5927\u5024\n                    now\
    \ -> val = tmp -> val;\n                    now -> lch = erase__(now -> lch, tmp\
    \ -> val);//\u79FB\u52D5\u3057\u305F\u30CE\u30FC\u30C9\u3092\u524A\u9664\u3002\
    (\u30DD\u30A4\u30F3\u30BF\u306E\u64CD\u4F5C\u306B\u6CE8\u610F)\n             \
    \       pushup(now);\n                }\n            }\n            return now;//\u73FE\
    \u5728\u306E\u30CE\u30FC\u30C9\u307E\u3067\u524A\u9664\u306E\u4F5C\u696D\u304C\
    \u5B8C\u4E86\u3057\u305F\u3089\u3070\u3001\u66F4\u65B0\u3055\u308C\u305F\u73FE\
    \u5728\u306E\u30CE\u30FC\u30C9\u3092\u8FD4\u3057\u3066\u7D42\u4E86\u3002\n   \
    \     }\n\n\n        int count__(NODE* now, X& x) {\n            if(now == nullptr)\
    \ return 0;\n            if(now -> val == x) {\n                return 1 + count__(now\
    \ -> rch, x) + count__(now -> lch, x);\n            }\n            else if(now\
    \ -> val > x) return count__(now -> lch, x);\n            else return count__(now\
    \ -> rch, x);\n        }\n\n        void lower_bound_val__(NODE*now, X& x, X&\
    \ res) {//x\u4EE5\u4E0A\u3067\u6700\u5C0Fval\n        //\u524D\u63D0\uFF1A\u305D\
    \u306E\u69D8\u306A\u5024\u304C\u5B58\u5728\u3059\u308B\u3002\n            if(now\
    \ -> val == x) {\n                res = x;\n                return;\n        \
    \    }\n            if(x < now -> val) {//\u7B54\u3048\u306F\u3001min(now, now\u306E\
    \u5DE6\u5B50\u5B6B\u306E\u4E2D\u3067x\u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\u8981\
    \u7D20)\n                res = min(res, now -> val);\n                if(now ->\
    \ lch != nullptr) lower_bound_val__(now -> lch, x, res);\n            }\n    \
    \        else {//\u7B54\u3048\u306F\u3001\u53F3\u5B50\u5B6B\u306E\u4E2D\u3067\
    x\u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\u5024\n                if(now -> rch !=\
    \ nullptr)  lower_bound_val__(now -> rch, x, res);//\u53F3\u306B\u5B50\u304C\u5B58\
    \u5728\u3057\u306A\u3044\u3068\u3044\u3046\u4E8B\u306F\u306A\u3044\u3002\n   \
    \         }\n            return;\n        }\n\n        void upper_bound_val__(NODE*now,\
    \ X& x, X& res) {//x\u8D85\u904E\u3067\u6700\u5C0Fval\n        //\u524D\u63D0\uFF1A\
    \u305D\u306E\u69D8\u306A\u5024\u304C\u5B58\u5728\u3059\u308B\u3002\n         \
    \   if(x < now -> val) {//\u7B54\u3048\u306F\u3001min(now, now\u306E\u5DE6\u5B50\
    \u5B6B\u306E\u4E2D\u3067x\u3088\u308A\u5927\u304D\u3044\u6700\u5C0F\u306E\u8981\
    \u7D20)\n                res = min(res, now -> val);\n                if(now ->\
    \ lch != nullptr) upper_bound_val__(now -> lch, x, res);\n            }\n    \
    \        else {//\u7B54\u3048\u306F\u3001\u53F3\u5B50\u5B6B\u306E\u4E2D\u3067\
    x\u3088\u308A\u5927\u304D\u3044\u306E\u6700\u5C0F\u306E\u5024\n              \
    \  if(now -> rch != nullptr)  upper_bound_val__(now -> rch, x, res);//\u53F3\u306B\
    \u5B50\u304C\u5B58\u5728\u3057\u306A\u3044\u3068\u3044\u3046\u4E8B\u306F\u306A\
    \u3044\u3002\n            }\n            return;\n        }\n      \n      \n\
    \        void lower_left_bound_val__(NODE* now, X& x, X& res) {//x\u4EE5\u4E0B\
    \u3067\u6700\u5927val\n        //\u524D\u63D0\uFF1A\u305D\u306E\u69D8\u306A\u5024\
    \u304C\u5B58\u5728\u3059\u308B\u3002\n            if(now -> val == x) {\n    \
    \            res = x;\n                return;\n            }\n            if(x\
    \ < now -> val) {//\u5DE6\n                if(now -> lch != nullptr) lower_left_bound_val__(now\
    \ -> lch, x, res);\n            }\n            else {\n                res = max(res,\
    \ now -> val);\n                if(now -> rch != nullptr) lower_left_bound_val__(now\
    \ -> rch, x, res);\n\n            }\n        }\n\n        void upper_left_bound_val__(NODE*\
    \ now, X& x, X& res) {//x\u672A\u6E80\u3067\u6700\u5927val\n        //\u524D\u63D0\
    \uFF1A\u305D\u306E\u69D8\u306A\u5024\u304C\u5B58\u5728\u3059\u308B\u3002\n   \
    \         if(x <= now -> val) {//\u5DE6\n                if(now -> lch != nullptr)\
    \ upper_left_bound_val__(now -> lch, x, res);\n            }\n            else\
    \ {\n                res = max(res, now -> key);\n                if(now -> rch\
    \ != nullptr) upper_left_bound_val__(now -> rch, x, res);\n            }\n   \
    \     }\n\n        NODE* lower_bound__(X x) {//x\u4EE5\u4E0A\u3067\u6700\u5C0F\
    \u3001\u5B58\u5728\u3057\u306A\u3044\u306A\u3089nullptr\n            if(size_of_tree==0)\
    \ return nullptr;\n            NODE* M = find_max_only(root);\n            X t\
    \ = M -> val;\n            if(t < x) return nullptr;//x\u4EE5\u4E0A\u306E\u5024\
    \u306F\u5B58\u5728\u3057\u306A\u3044\u3002\n            lower_bound_val__(root,\
    \ x, t);\n            splay(root, t);\n            return root;\n        }\n\n\
    \        NODE* upper_bound__(X x) {//k\u8D85\u904E\u3067\u6700\u5C0F\u3001\u5B58\
    \u5728\u3057\u306A\u3044\u306A\u3089nullptr\n            if(size_of_tree==0) return\
    \ nullptr;\n            NODE* M = find_max_only(root);\n            X t = M ->\
    \ val;\n            if(t <= x) return nullptr;\n            upper_bound_val__(root,\
    \ x, t);\n            splay(root, t);\n            return root;\n        }\n\n\
    \        NODE* lower_left_bound__(X x) {//k\u4EE5\u4E0B\u3067\u6700\u5927\u3002\
    \n            if(size_of_tree==0) return nullptr;\n            NODE* m = find_min_only(root);\n\
    \            X t = m -> val;\n            ;\n            if(t > x) return nullptr;\n\
    \            lower_left_bound_val__(root, x, t);\n            splay(root, t);\n\
    \            return root;\n        }\n\n        NODE* upper_left_bound__(X x)\
    \ {//k\u672A\u6E80\u3067\u6700\u5927\u3002\n            if(size_of_tree==0) return\
    \ nullptr;\n            NODE* m = find_min_only(root);\n            X t = m ->\
    \ val;\n            if(t >= x) return nullptr;\n            upper_left_bound_val__(root,\
    \ x, t);\n            splay(root, t);\n            return root;\n        }\n\n\
    \        NODE* ith_element__(NODE* now, long long i) {\n            long long\
    \ ls = count(now -> lch);\n            if(ls + 1 <= i && i <= ls + 1) {\n    \
    \            return now;\n            }\n            else if(ls >= i) return ith_element__(now\
    \ -> lch, i);\n            else return ith_element__(now -> rch, i - 1 - ls);\n\
    \        }\n\n        NODE* max_element__() {//\u6700\u5927\u306Ekey\u3001\u5B58\
    \u5728\u3057\u306A\u3044\u306A\u3089nullptr\n            NODE* tar = find_max_only(root);\n\
    \            if(tar == nullptr) return tar;\n            pair<int, NODE*> h (-1,\
    \ nullptr);\n            splay(root , tar -> val);\n            return root;\n\
    \        }\n\n        NODE* min_element__() {//\u6700\u5C0F\u306Ekey\u3001\u5B58\
    \u5728\u3057\u306A\u3044\u306A\u3089nullptr\n            NODE* tar = find_min_only(root);\n\
    \            if(tar == nullptr) return tar;\n            pair<int, NODE*> h (-1,\
    \ nullptr);\n            splay(root , tar -> val);\n            return root;\n\
    \        }\n\n        NODE* lower_sum_left__(NODE* now, X S, int L) {\n      \
    \      X now_sum = X();\n            if(L != 1) {\n                S = S + accL(L-1);\n\
    \            }\n            int pos = 0;\n            if(S > acc(root)) return\
    \ nullptr;\n            while(1) {\n                X tmp = now_sum + acc(now\
    \ -> lch);\n                if(tmp >= S) now = now -> lch;\n                else\
    \ {\n                    tmp += now -> val;\n                    pos += 1 + count(now\
    \ -> lch);\n                    if(tmp >= S) {\n                        splay_pos(root,\
    \ pos);\n                        return root;\n                    }\n       \
    \             else {\n                        now_sum = tmp;\n               \
    \         now = now -> rch;\n                    }\n                }\n      \
    \      }\n        }\n\n        NODE* upper_sum_left__(NODE* now, X S, int L) {\n\
    \            X now_sum = X();\n            if(L != 1) {\n                S = S\
    \ + accL(L-1);\n            }\n            int pos = 0;\n            if(S >= acc(root))\
    \ return nullptr;\n            while(1) {\n                X tmp = now_sum + acc(now\
    \ -> lch);\n                if(tmp > S) now = now -> lch;\n                else\
    \ {\n                    tmp += now -> val;\n                    pos += 1 + count(now\
    \ -> lch);\n                    if(tmp > S) {\n                        splay_pos(root,\
    \ pos);\n                        return root;\n                    }\n       \
    \             else {\n                        now_sum = tmp;\n               \
    \         now = now -> rch;\n                    }\n                }\n      \
    \      }\n        }\n\n        NODE* next(NODE*& now) {//\u6B21\u306Ekey\u3001\
    \u5B58\u5728\u3057\u306A\u3044\u306A\u3089nullptr\n            if(now == nullptr)\
    \ return now;\n            else return upper_bound__(now -> val);\n        }\n\
    \n\n        NODE* prev(NODE*& now) {//\u524D\u306Ekey\u3002\u5B58\u5728\u3057\u306A\
    \u3051\u308C\u3070nullptr\n            if(now == nullptr) return now;\n      \
    \      else return upper_left_bound__(now -> val);\n        }\n\n        void\
    \ in_order__(NODE* now, vector<X>& res) {\n            if(now == nullptr) return;\n\
    \            in_order__(now -> lch, res);\n            res.push_back(now -> val);\n\
    \            in_order__(now -> rch, res);\n            return;\n        }\n  \
    \      \n        void change(X x) {//x\u3092\u633F\u5165)\n            pushup(root);\n\
    \            int pos = 0;\n            root = change__(root, x, pos);\n      \
    \      splay_pos(root, pos);//\u6839\u3092\u66F4\u65B0\u3002\n            return;\n\
    \        }\n\n\n\n\n    public:\n\n\n        void insert(X x) {\n            pushup(root);\n\
    \            change(x);\n        }\n\n        void erase(X x) {//\u5B58\u5728\u3057\
    \u306A\u304B\u3063\u305F\u5834\u5408\u3001\u4F55\u3082\u3057\u306A\u3044\u3002\
    \n            pushup(root);\n            root = erase__(root, x);\n        }\n\
    \n        bool find(X x) {\n            pushup(root);\n            splay(root,x);\n\
    \            if(root == nullptr || root -> val != x) return false;\n         \
    \   return true;\n        }\n\n        int count(X x) {\n            pushup(root);\n\
    \            pair<int, NODE*> h (-1, nullptr);\n            splay(root, x);\n\
    \            if(root == nullptr || root -> val != x) return 0;\n            return\
    \ count__(root, x);\n        }\n\n\n        \n        \n  \n        int size()\
    \ {\n            return size_of_tree;\n        }\n\n        bool empty() {\n \
    \           return size_of_tree == 0;\n        }\n\n        \n        bool next(X\
    \ x, X& res) {//\u6B21\u306Ekey\u3002\u5B58\u5728\u3057\u306A\u3044\u306A\u3089\
    false\u3002\u7D50\u679C\u306Fres\u306B\u6E21\u3055\u308C\u308B\u3002\n       \
    \     pushup(root);\n            NODE* r = upper_bound__(x);\n            if(r==nullptr)return\
    \ false;\n            else {\n                res = r -> val;\n              \
    \  return true;\n            }\n        }\n\n        \n        bool prev(X x,\
    \ X& res) {//\u524D\u306Ekey.\u5B58\u5728\u3057\u306A\u3044\u306A\u3089false\u3002\
    \u7D50\u679C\u306Fres\u306B\u6E21\u3055\u308C\u308B\u3002\n            pushup(root);\n\
    \            NODE* r = upper_left_bound__(x);\n            if(r==nullptr)return\
    \ false;\n            else {\n                res = r -> val;\n              \
    \  return true;\n            }\n        }\n\n        bool ith_element(long long\
    \ i, X& res) {\n            pushup(root);\n            if(count(root) < i) return\
    \ false;\n            else {\n                NODE* tar = ith_element__(root,\
    \ i);\n                res = tar -> val;\n                return i;\n        \
    \    }\n        }\n\n        bool max_element(X& res) {//\u6700\u5927\u306Ekey\n\
    \            pushup(root);\n            NODE* tar = max_element__();\n       \
    \     if(tar == nullptr) return false;\n            else {\n                res\
    \ =  tar -> val;\n                return true;\n            }\n        }\n\n \
    \       bool min_element(X& res) {//\u6700\u5C0F\u306Ekey\n            pushup(root);\n\
    \            NODE* tar = min_element__();\n            if(tar == nullptr) return\
    \ false;\n            else {\n                res =  tar -> val;\n           \
    \     return true;\n            }\n        }\n\n        bool lower_bound(X x,\
    \ X& res) {//x\u4EE5\u4E0A\u3067\u6700\u5C0Fkey\n            pushup(root);\n \
    \           NODE* r = lower_bound__(x);\n            if(r == nullptr) return false;\n\
    \            else {\n                res = r -> val;\n                return true;\n\
    \            }\n        }\n\n        bool upper_bound(X x, X& res) {//k\u8D85\u904E\
    \u3067\u6700\u5C0F\u3068\u306A\u308B\n            pushup(root);\n            NODE*\
    \ r = upper_bound__(x);\n            if(r == nullptr) return false;\n        \
    \    else {\n                res = r -> val;\n                return true;\n \
    \           }\n        }\n\n        bool lower_left_bound(X x, X& res) {//k\u4EE5\
    \u4E0B\u3067\u6700\u5927\u3002 \n            pushup(root);\n            NODE*\
    \ r = lower_left_bound__(x);\n            if(r == nullptr) return false;\n   \
    \         else {\n                res = r -> val;\n                return true;\n\
    \            }\n        }\n\n        bool upper_left_bound(X x, X& res) {//k\u672A\
    \u6E80\u3067\u6700\u5927\u3002\n            pushup(root);\n            NODE* r\
    \ = upper_left_bound__(x);\n            if(r == nullptr) return false;\n     \
    \       else {\n                res = r -> val;\n                return true;\n\
    \            }\n        }\n\n        X accL(int R) {//[1, R]\u306Eval\u306E\u30E2\
    \u30CE\u30A4\u30C9\u7A4D R\u304Ckey\u306E\u6570\u3088\u308A\u591A\u3044\u3068\u5358\
    \u4F4D\u5143\n            if(R < 1 || size_of_tree < R) return X();\n        \
    \    pushup(root);\n            X tar;\n            if(!ith_element(R, tar)) return\
    \ X();\n            splay(root, tar);\n            return acc(root -> lch) + root\
    \ -> val;\n        }\n\n        X accR(int L) {//[L, MAX]\u306Eval\u306E\u30E2\
    \u30CE\u30A4\u30C9\n            if(L < 1 || size_of_tree < L) return X();\n  \
    \          pushup(root);\n            X tar;\n            if(!ith_element(L, tar))\
    \ return X();\n            splay(root, tar);\n            return root -> val +\
    \ acc(root -> rch);\n        }\n\n        bool lower_sum_left(X sum, int L, X&\
    \ res) {\n            pushup(root);\n            NODE* tar = lower_sum_left__(root,\
    \ sum, L);\n            if(tar == nullptr) return false;\n            else {\n\
    \                res = acc(tar -> lch) + tar -> val;\n                return true;\n\
    \            }\n\n        }\n\n        bool upper_sum_left(X sum, int L, X& res)\
    \ {\n            pushup(root);\n            NODE* tar = upper_sum_left__(root,\
    \ sum, L);\n            if(tar == nullptr) return false;\n            else {\n\
    \                //res = acc(tar -> lch) + tar -> val;\n                res =\
    \ count(tar -> lch) + 1;\n                return true;\n            }\n\n    \
    \    }\n\n        \n        vector<X> in_order() {//\u8981\u7D20\u3092\u5168\u3066\
    \u5165\u308C\u305F\u914D\u5217 \u8981\u7D20\u304C\u306A\u3044\u306A\u3089\u7A7A\
    \u914D\u5217\n            pushup(root);\n            vector<X> res;\n        \
    \    in_order__(root, res);\n            return res;\n        }\n\n        void\
    \ dump() {\n            pushup(root);\n            auto r = in_order();\n    \
    \        for(X& x : r) cout << x << \" \";\n            cout << endl;\n      \
    \  }\n\n        NODE* end() {\n            return nullptr;\n        }\n\n};\n\n\
    /*\n@brief splaytree(multiset) \u30C8\u30C3\u30D7\u30C0\u30A6\u30F3splay\n*/"
  dependsOn: []
  isVerificationFile: false
  path: DetaStructures/splaymultiset.cpp
  requiredBy: []
  timestamp: '2024-05-10 23:04:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DetaStructures/splaymultiset.cpp
layout: document
redirect_from:
- /library/DetaStructures/splaymultiset.cpp
- /library/DetaStructures/splaymultiset.cpp.html
title: "splaytree(multiset) \u30C8\u30C3\u30D7\u30C0\u30A6\u30F3splay"
---
