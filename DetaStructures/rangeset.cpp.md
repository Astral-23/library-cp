---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u533A\u9593\u3092\u7BA1\u7406\u3059\u308Bset"
    links: []
  bundledCode: "#line 1 \"DetaStructures/rangeset.cpp\"\ntemplate<typename T>\nstruct\
    \ rangeset {//\u533A\u9593\u3092\u7BA1\u7406\u3059\u308B\u3002\u3064\u3044\u3067\
    \u3067\u3001mex\u3092\u53D6\u5F97\u3067\u304D\u308B\u3002\n    set<pair<T, T>>\
    \ s;\n    long long sum; //\u533A\u9593\u9577\u306E\u5408\u8A08\u3002\n\n    rangeset()\
    \ {\n        T M = numeric_limits<T>::max();\n        T m = numeric_limits<T>::min();\n\
    \        s.emplace(m, m);\n        s.emplace(M, M);\n        sum = 0;\n    }\n\
    \n    private:\n        void insert__(T x) {\n            auto nitr = s.lower_bound(make_pair(x+1,\
    \ x+1));\n            auto itr = prev(nitr);\n            auto[nl, nr] = *nitr;\n\
    \            auto[l, r] = *itr;\n            if(l <= x && x <= r) return;//\u65E2\
    \u306B\u5B58\u5728\u3057\u305F\u3002\n            sum++;//\u5408\u8A08\u306B\u8DB3\
    \u3057\u3068\u304F\u3002\n            if(r == x-1) {\n                if(nl ==\
    \ x+1) {\n                    s.erase(itr);\n                    s.erase(nitr);\n\
    \                    s.emplace(l, nr);\n                } \n                else\
    \ {\n                    s.erase(itr);\n                    s.emplace(l, r+1);\n\
    \                }\n            }\n            else {\n                if(nl ==\
    \ x+1) {\n                    s.erase(nitr);\n                    s.emplace(nl-1,\
    \ nr);\n                }\n                else {\n                    s.emplace(x,\
    \ x);\n                }\n            }\n            return;\n        }\n\n  \
    \      void insert__(T L, T R) {\n            //\u5408\u8A08\u306F\u3001\u6700\
    \u5F8C\u306B[L, R]\u5206\u8DB3\u3059\u4E8B\u306B\u3057\u3066\u3001\u9053\u4E2D\
    \u306F\u5F15\u304F\u3002\n            if(L > R) return;\n            auto itr\
    \ = prev(s.lower_bound(make_pair(L+1, L+1)));\n\n            {//\u307E\u305A\u3001\
    \ l <= L \u3067\u3042\u3063\u3066\u4E00\u756A\u53F3\u306B\u3042\u308B\u533A\u9593\
    [l, r]\n                auto [l, r] = *itr;\n                if(l <= L && R <=\
    \ r) {//\u65B0\u305F\u306A\u533A\u9593\u304C\u5185\u5305\u3055\u308C\u308B\u3002\
    \n                    return;\n                }\n                else if(l ==\
    \ L && r <= R) {//\u65B0\u305F\u306A\u533A\u9593\u304C\u5185\u5305\u3059\u308B\
    \u3002\n                    s.erase(itr++);//\u878D\u5408\n                  \
    \  sum -= (r - l) + 1;\n                }\n                else if(l < L && L\
    \ <= r+1 && r < R) {//\u91CD\u306A\u308B\u90E8\u5206\u304C\u3042\u308B || i] \
    \ [i+1  \u306E\u3088\u3046\u306A\u69CB\u9020\n                    L = l;\n   \
    \                 s.erase(itr++);//\u878D\u5408\n                    sum -= (r\
    \ - l) + 1;\n                }\n                else {//\u91CD\u306A\u308B\u533A\
    \u9593\u304C\u306A\u3044\u3002\n                  itr++;\n                }\n\
    \            } \n            \n            {//\u5B8C\u5168\u306B\u5185\u5305\u3055\
    \u308C\u308B\u533A\u9593\u3092\u6D88\u3057\u3001\u53F3\u7AEF\u3082\u51E6\u7406\
    \u3002\n                while(1) {\n                    auto[l, r] = *itr;\n \
    \                   if(R+1 < l) break;//\u5171\u901A\u533A\u9593\u306A\u3057 &&\
    \ R] [l+1  \u3067\u306F\u306A\u3044\n                    if(r <= R) {//\u65B0\u305F\
    \u306A\u533A\u9593\u304C\u5185\u5305\u3059\u308B\u3002\n                     \
    \ s.erase(itr++);\n                      sum -= (r - l) + 1;\n               \
    \     }\n                    else {//\u5171\u901A\u533A\u9593\u304C\u3042\u308B\
    \u3002\uFF08\u53F3\u7AEF\uFF09\n                      s.erase(itr++);\n      \
    \                sum -= (r - l) + 1;\n                      R = r;\n         \
    \             break;\n                    }\n                }\n             \
    \   s.emplace(L, R);\n                sum += (R - L) + 1;\n            }\n   \
    \         return;\n        }\n\n        void erase__(T x) {\n            auto\
    \ itr = prev(s.lower_bound(make_pair(x+1, x+1)));\n            auto [l, r] = *itr;\n\
    \            if(l <= x && x <= r) {//\u5B58\u5728\u3059\u308B\u306A\u3089\u3070\
    \n                sum--;\n                s.erase(itr);\n                if(l\
    \ != x)s.emplace(l, x-1);\n                if(r != x)s.emplace(x+1, r);\n    \
    \        }\n            return;\n        }\n\n        void erase__(T L, T R) {\n\
    \            //\u5408\u8A08\u306F\u3001\u9053\u4E2D\u6BCE\u56DE\u5F15\u304F\u3002\
    \n            if(L > R) return;\n             auto itr = prev(s.lower_bound(make_pair(L+1,\
    \ L+1)));\n              {//\u307E\u305A\u3001 l <= L \u3067\u3042\u3063\u3066\
    \u4E00\u756A\u53F3\u306B\u3042\u308B\u533A\u9593[l, r]\n                auto [l,\
    \ r] = *itr;\n                if(l <= L && R <= r) {//\u6D88\u3059\u533A\u9593\
    \u304C\u5185\u5305\u3055\u308C\u308B\u3002\n                    s.erase(itr++);//\u9593\
    \u3092\u524A\u9664\n                    sum -= (R - L) + 1;\n                \
    \    if(l < L) s.emplace(l, L-1);\n                    if(R < r) s.emplace(R+1,\
    \ r);\n                    return;\n                }\n                else if(l\
    \ == L && r <= R) {//\u6D88\u3059\u533A\u9593\u304C\u5185\u5305\u3059\u308B\u3002\
    \n                    s.erase(itr++);//\u524A\u9664\n                    sum -=\
    \ (r - l) + 1;\n                }\n                else if(l < L && L <= r &&\
    \ r < R) {//\u91CD\u306A\u308B\u90E8\u5206\u304C\u3042\u308B\n               \
    \     s.erase(itr++);//\u524A\u9664\n                    sum -= (r - l) + 1;\n\
    \                    s.emplace(l, L-1);\n                    sum += (L-1 - l)\
    \ + 1;\n                }\n                else {//\u91CD\u306A\u308B\u533A\u9593\
    \u304C\u306A\u3044\u3002\n                  itr++;\n                }\n      \
    \      } \n\n            {//\u5B8C\u5168\u306B\u5185\u5305\u3055\u308C\u308B\u533A\
    \u9593\u3092\u6D88\u3057\u3001\u53F3\u7AEF\u3082\u51E6\u7406\u3002\n         \
    \       while(1) {\n                    auto[l, r] = *itr;\n                 \
    \   if(R < l) break;//\u5171\u901A\u533A\u9593\u306A\u3057\n                 \
    \   if(r <= R) {//\u6D88\u3059\u533A\u9593\u304C\u5185\u5305\u3059\u308B\u3002\
    \n                      s.erase(itr++);\n                      sum -= (r - l)\
    \ + 1;\n                    }\n                    else {//\u5171\u901A\u533A\u9593\
    \u304C\u3042\u308B\u3002\uFF08\u53F3\u7AEF\uFF09\n                      s.erase(itr++);\n\
    \                      sum -= (r - l) + 1;\n                      s.emplace(R+1,\
    \ r);\n                      sum += (r - (R+1)) + 1;\n                      break;\n\
    \                    }\n                }\n            }\n            return;\n\
    \        }\n\n      \n\n    public:\n        bool count(T x) {\n            auto\
    \ itr = prev(s.lower_bound(make_pair(x+1, x+1)));\n            auto [l, r] = *itr;\n\
    \            return l <= x && x <= r;\n        }\n\n\n        void insert(T x)\
    \ {\n            insert__(x);\n        }\n\n        void insert(T l, T r) {\n\
    \            insert__(l, r);\n        }\n\n        void erase(T x) {\n       \
    \     erase__(x);\n        }\n\n        void erase(T l, T r) {\n            erase__(l,\
    \ r);\n        }\n\n        T mex(T x) {\n            auto itr = s.lower_bound(make_pair(x+1,\
    \ x+1));\n            itr--;\n            auto [l, r] = *itr;\n            if(l\
    \ <= x && x <= r) return r+1;\n            else return x;\n        }\n\n     \
    \   int size() {\n            return int(s.size()) - 2;\n        }\n\n       \
    \ long long getsum() {\n            return sum;\n        }\n\n\t\t/*\n\t\t   \
    \ rangeset<T>   T...\u533A\u9593\u306E\u6065\u3092\u8868\u3059\u6574\u6570\u306E\
    \u578B O(1)  \u901A\u5E38: int or long long\n\t\t\t@brief \u533A\u9593\u3092\u7BA1\
    \u7406\u3059\u308Bset\n\t\t\tcount(x) ... x\u304C\u542B\u307E\u308C\u308B\u304B\
    \   O(logN)\n\t\t\tinsert(x) ... x\u3092\u633F\u5165\u3002\u5B58\u5728\u3059\u308B\
    \u306A\u3089\u4F55\u3082\u3057\u306A\u3044  O(logN)\n\t\t\terase(x) ... x\u3092\
    \u524A\u9664\u3002\u5B58\u5728\u3059\u308B\u306A\u3089\u4F55\u3082\u3057\u306A\
    \u3044 O(logN)\n\t\t\tinsert(l, r) ... [l, r]\u3092\u633F\u5165\u3002[l, r]\u3092\
    \u5185\u5305\u3059\u308B\u533A\u9593\u304C\u3042\u3063\u305F\u3089\u4F55\u3082\
    \u3057\u306A\u3044 O(logN)\n\t\t\terase(l, r) ... [l, r]\u3092\u524A\u9664\u3002\
    [l, r]\u304C\u5B8C\u5168\u306B\u306A\u304B\u3063\u305F\u3089\u4F55\u3057\u306A\
    \u3044  O(logN)\n\t\t\tmex(x) ... [x, LLONG_MAX]\u3067\u5B58\u5728\u3057\u306A\
    \u3044\u6700\u5C0F\u306E\u8981\u7D20  O(logN)\n\t\t\tsize() ... \u533A\u9593\u306E\
    \u7DCF\u6570 O(1)\n\t\t\tgetsum()... \u8981\u7D20\u306E\u7DCF\u6570 O(1)\n\t\t\
    \n\t\t*/\n         \n};\n"
  code: "template<typename T>\nstruct rangeset {//\u533A\u9593\u3092\u7BA1\u7406\u3059\
    \u308B\u3002\u3064\u3044\u3067\u3067\u3001mex\u3092\u53D6\u5F97\u3067\u304D\u308B\
    \u3002\n    set<pair<T, T>> s;\n    long long sum; //\u533A\u9593\u9577\u306E\u5408\
    \u8A08\u3002\n\n    rangeset() {\n        T M = numeric_limits<T>::max();\n  \
    \      T m = numeric_limits<T>::min();\n        s.emplace(m, m);\n        s.emplace(M,\
    \ M);\n        sum = 0;\n    }\n\n    private:\n        void insert__(T x) {\n\
    \            auto nitr = s.lower_bound(make_pair(x+1, x+1));\n            auto\
    \ itr = prev(nitr);\n            auto[nl, nr] = *nitr;\n            auto[l, r]\
    \ = *itr;\n            if(l <= x && x <= r) return;//\u65E2\u306B\u5B58\u5728\u3057\
    \u305F\u3002\n            sum++;//\u5408\u8A08\u306B\u8DB3\u3057\u3068\u304F\u3002\
    \n            if(r == x-1) {\n                if(nl == x+1) {\n              \
    \      s.erase(itr);\n                    s.erase(nitr);\n                   \
    \ s.emplace(l, nr);\n                } \n                else {\n            \
    \        s.erase(itr);\n                    s.emplace(l, r+1);\n             \
    \   }\n            }\n            else {\n                if(nl == x+1) {\n  \
    \                  s.erase(nitr);\n                    s.emplace(nl-1, nr);\n\
    \                }\n                else {\n                    s.emplace(x, x);\n\
    \                }\n            }\n            return;\n        }\n\n        void\
    \ insert__(T L, T R) {\n            //\u5408\u8A08\u306F\u3001\u6700\u5F8C\u306B\
    [L, R]\u5206\u8DB3\u3059\u4E8B\u306B\u3057\u3066\u3001\u9053\u4E2D\u306F\u5F15\
    \u304F\u3002\n            if(L > R) return;\n            auto itr = prev(s.lower_bound(make_pair(L+1,\
    \ L+1)));\n\n            {//\u307E\u305A\u3001 l <= L \u3067\u3042\u3063\u3066\
    \u4E00\u756A\u53F3\u306B\u3042\u308B\u533A\u9593[l, r]\n                auto [l,\
    \ r] = *itr;\n                if(l <= L && R <= r) {//\u65B0\u305F\u306A\u533A\
    \u9593\u304C\u5185\u5305\u3055\u308C\u308B\u3002\n                    return;\n\
    \                }\n                else if(l == L && r <= R) {//\u65B0\u305F\u306A\
    \u533A\u9593\u304C\u5185\u5305\u3059\u308B\u3002\n                    s.erase(itr++);//\u878D\
    \u5408\n                    sum -= (r - l) + 1;\n                }\n         \
    \       else if(l < L && L <= r+1 && r < R) {//\u91CD\u306A\u308B\u90E8\u5206\u304C\
    \u3042\u308B || i]  [i+1  \u306E\u3088\u3046\u306A\u69CB\u9020\n             \
    \       L = l;\n                    s.erase(itr++);//\u878D\u5408\n          \
    \          sum -= (r - l) + 1;\n                }\n                else {//\u91CD\
    \u306A\u308B\u533A\u9593\u304C\u306A\u3044\u3002\n                  itr++;\n \
    \               }\n            } \n            \n            {//\u5B8C\u5168\u306B\
    \u5185\u5305\u3055\u308C\u308B\u533A\u9593\u3092\u6D88\u3057\u3001\u53F3\u7AEF\
    \u3082\u51E6\u7406\u3002\n                while(1) {\n                    auto[l,\
    \ r] = *itr;\n                    if(R+1 < l) break;//\u5171\u901A\u533A\u9593\
    \u306A\u3057 && R] [l+1  \u3067\u306F\u306A\u3044\n                    if(r <=\
    \ R) {//\u65B0\u305F\u306A\u533A\u9593\u304C\u5185\u5305\u3059\u308B\u3002\n \
    \                     s.erase(itr++);\n                      sum -= (r - l) +\
    \ 1;\n                    }\n                    else {//\u5171\u901A\u533A\u9593\
    \u304C\u3042\u308B\u3002\uFF08\u53F3\u7AEF\uFF09\n                      s.erase(itr++);\n\
    \                      sum -= (r - l) + 1;\n                      R = r;\n   \
    \                   break;\n                    }\n                }\n       \
    \         s.emplace(L, R);\n                sum += (R - L) + 1;\n            }\n\
    \            return;\n        }\n\n        void erase__(T x) {\n            auto\
    \ itr = prev(s.lower_bound(make_pair(x+1, x+1)));\n            auto [l, r] = *itr;\n\
    \            if(l <= x && x <= r) {//\u5B58\u5728\u3059\u308B\u306A\u3089\u3070\
    \n                sum--;\n                s.erase(itr);\n                if(l\
    \ != x)s.emplace(l, x-1);\n                if(r != x)s.emplace(x+1, r);\n    \
    \        }\n            return;\n        }\n\n        void erase__(T L, T R) {\n\
    \            //\u5408\u8A08\u306F\u3001\u9053\u4E2D\u6BCE\u56DE\u5F15\u304F\u3002\
    \n            if(L > R) return;\n             auto itr = prev(s.lower_bound(make_pair(L+1,\
    \ L+1)));\n              {//\u307E\u305A\u3001 l <= L \u3067\u3042\u3063\u3066\
    \u4E00\u756A\u53F3\u306B\u3042\u308B\u533A\u9593[l, r]\n                auto [l,\
    \ r] = *itr;\n                if(l <= L && R <= r) {//\u6D88\u3059\u533A\u9593\
    \u304C\u5185\u5305\u3055\u308C\u308B\u3002\n                    s.erase(itr++);//\u9593\
    \u3092\u524A\u9664\n                    sum -= (R - L) + 1;\n                \
    \    if(l < L) s.emplace(l, L-1);\n                    if(R < r) s.emplace(R+1,\
    \ r);\n                    return;\n                }\n                else if(l\
    \ == L && r <= R) {//\u6D88\u3059\u533A\u9593\u304C\u5185\u5305\u3059\u308B\u3002\
    \n                    s.erase(itr++);//\u524A\u9664\n                    sum -=\
    \ (r - l) + 1;\n                }\n                else if(l < L && L <= r &&\
    \ r < R) {//\u91CD\u306A\u308B\u90E8\u5206\u304C\u3042\u308B\n               \
    \     s.erase(itr++);//\u524A\u9664\n                    sum -= (r - l) + 1;\n\
    \                    s.emplace(l, L-1);\n                    sum += (L-1 - l)\
    \ + 1;\n                }\n                else {//\u91CD\u306A\u308B\u533A\u9593\
    \u304C\u306A\u3044\u3002\n                  itr++;\n                }\n      \
    \      } \n\n            {//\u5B8C\u5168\u306B\u5185\u5305\u3055\u308C\u308B\u533A\
    \u9593\u3092\u6D88\u3057\u3001\u53F3\u7AEF\u3082\u51E6\u7406\u3002\n         \
    \       while(1) {\n                    auto[l, r] = *itr;\n                 \
    \   if(R < l) break;//\u5171\u901A\u533A\u9593\u306A\u3057\n                 \
    \   if(r <= R) {//\u6D88\u3059\u533A\u9593\u304C\u5185\u5305\u3059\u308B\u3002\
    \n                      s.erase(itr++);\n                      sum -= (r - l)\
    \ + 1;\n                    }\n                    else {//\u5171\u901A\u533A\u9593\
    \u304C\u3042\u308B\u3002\uFF08\u53F3\u7AEF\uFF09\n                      s.erase(itr++);\n\
    \                      sum -= (r - l) + 1;\n                      s.emplace(R+1,\
    \ r);\n                      sum += (r - (R+1)) + 1;\n                      break;\n\
    \                    }\n                }\n            }\n            return;\n\
    \        }\n\n      \n\n    public:\n        bool count(T x) {\n            auto\
    \ itr = prev(s.lower_bound(make_pair(x+1, x+1)));\n            auto [l, r] = *itr;\n\
    \            return l <= x && x <= r;\n        }\n\n\n        void insert(T x)\
    \ {\n            insert__(x);\n        }\n\n        void insert(T l, T r) {\n\
    \            insert__(l, r);\n        }\n\n        void erase(T x) {\n       \
    \     erase__(x);\n        }\n\n        void erase(T l, T r) {\n            erase__(l,\
    \ r);\n        }\n\n        T mex(T x) {\n            auto itr = s.lower_bound(make_pair(x+1,\
    \ x+1));\n            itr--;\n            auto [l, r] = *itr;\n            if(l\
    \ <= x && x <= r) return r+1;\n            else return x;\n        }\n\n     \
    \   int size() {\n            return int(s.size()) - 2;\n        }\n\n       \
    \ long long getsum() {\n            return sum;\n        }\n\n\t\t/*\n\t\t   \
    \ rangeset<T>   T...\u533A\u9593\u306E\u6065\u3092\u8868\u3059\u6574\u6570\u306E\
    \u578B O(1)  \u901A\u5E38: int or long long\n\t\t\t@brief \u533A\u9593\u3092\u7BA1\
    \u7406\u3059\u308Bset\n\t\t\tcount(x) ... x\u304C\u542B\u307E\u308C\u308B\u304B\
    \   O(logN)\n\t\t\tinsert(x) ... x\u3092\u633F\u5165\u3002\u5B58\u5728\u3059\u308B\
    \u306A\u3089\u4F55\u3082\u3057\u306A\u3044  O(logN)\n\t\t\terase(x) ... x\u3092\
    \u524A\u9664\u3002\u5B58\u5728\u3059\u308B\u306A\u3089\u4F55\u3082\u3057\u306A\
    \u3044 O(logN)\n\t\t\tinsert(l, r) ... [l, r]\u3092\u633F\u5165\u3002[l, r]\u3092\
    \u5185\u5305\u3059\u308B\u533A\u9593\u304C\u3042\u3063\u305F\u3089\u4F55\u3082\
    \u3057\u306A\u3044 O(logN)\n\t\t\terase(l, r) ... [l, r]\u3092\u524A\u9664\u3002\
    [l, r]\u304C\u5B8C\u5168\u306B\u306A\u304B\u3063\u305F\u3089\u4F55\u3057\u306A\
    \u3044  O(logN)\n\t\t\tmex(x) ... [x, LLONG_MAX]\u3067\u5B58\u5728\u3057\u306A\
    \u3044\u6700\u5C0F\u306E\u8981\u7D20  O(logN)\n\t\t\tsize() ... \u533A\u9593\u306E\
    \u7DCF\u6570 O(1)\n\t\t\tgetsum()... \u8981\u7D20\u306E\u7DCF\u6570 O(1)\n\t\t\
    \n\t\t*/\n         \n};"
  dependsOn: []
  isVerificationFile: false
  path: DetaStructures/rangeset.cpp
  requiredBy: []
  timestamp: '2024-05-10 22:41:34+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DetaStructures/rangeset.cpp
layout: document
redirect_from:
- /library/DetaStructures/rangeset.cpp
- /library/DetaStructures/rangeset.cpp.html
title: "\u533A\u9593\u3092\u7BA1\u7406\u3059\u308Bset"
---
