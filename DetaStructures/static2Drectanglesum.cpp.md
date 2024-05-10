---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://onedrive.live.com/view.aspx?resid=CD510BE428DBA1E7%21106&authkey=!AFD6EO1-AReoPBk
  bundledCode: "#line 1 \"DetaStructures/static2Drectanglesum.cpp\"\ntemplate<typename\
    \ T>\nstruct CC {\n  bool initialized;\n  vector<T> xs;\n  CC () : initialized(false)\
    \ {}\n  void add(T x) {xs.push_back(x);}\n  void init() {\n    sort(xs.begin(),\
    \ xs.end());\n    xs.erase(unique(xs.begin(), xs.end()), xs.end());\n    initialized\
    \ = true;\n  }\n\n  int operator()(T x) {//\u5024(x)\u306E\u5727\u7E2E\u5F8C\u306E\
    \u5024\uFF08\u4F55\u756A\u76EE\u306B\u5927\u304D\u304B\u3063\u305F\uFF1F\uFF09\
    \ O(logN)\n    if(!initialized) init();\n    return lower_bound(xs.begin(), xs.end(),\
    \ x) - xs.begin() + 1;\n    //1-indexed\u3067\u3042\u308B\u3002\n    //\u5927\u304D\
    \u3044\u65B9\u306B\u4E38\u3081\u3066\u3044\u308B\u3002{10,  15}\u306E\u6642\u3001\
    (13) = (15) = 2\u3002\u3053\u308C\u306F\u3001\u534A\u958B\u533A\u9593\u3092\u610F\
    \u8B58\u3057\u3066\u3044\u308B\u3002\n  }\n  T operator[](int i)  {//[i]\u756A\
    \u76EE\u306B\u5927\u304D\u3044\u5024\u3000\uFF08\u5727\u7E2E\u5F8C\u306Bi\u306B\
    \u306A\u308B\u306E\u306F\u5024\u306A\u3093\u3060\uFF09 O(1)\n    if(!initialized)\
    \ init();\n    assert(i <= int(xs.size()) && i >= 1);\n    return xs[i-1];\n \
    \ }\n  int size()  {\n    if(!initialized) init();\n    return xs.size();\n  }\n\
    };\n\n//\u70B9\u306E\u5EA7\u6A19\u304C\u30DE\u30A4\u30CA\u30B9\u3067\u3082\u884C\
    \u3051\u308B\u3068\u601D\u3044\u307E\u3059(\u5EA7\u6A19\u5727\u7E2E\u3067\u6B63\
    \u306B\u306A\u308B\u306E\u3067\uFF09\n//depend on CC library(\u5EA7\u6A19\u5727\
    \u7E2E)\nstruct static2Drectunglesum {\n    //ref : https://onedrive.live.com/view.aspx?resid=CD510BE428DBA1E7%21106&authkey=!AFD6EO1-AReoPBk\n\
    \n    vector<long long> xs;//\u70B9\u306E\u60C5\u5831(index\u30D9\u30FC\u30B9\u3067\
    \u6271\u3046\u3068\u4FBF\u5229)\n    vector<long long> ys;//\u70B9\u306E\u60C5\
    \u5831\n    vector<long long> ws;//\u70B9\u306E\u91CD\u307F\n    vector<vector<long\
    \ long>> sum;//\u5404\u9802\u70B9\u306E\u7D2F\u7A4D\u548C\n    CC<long long> nxs;//xs\u306E\
    \u5EA7\u6A19\u5727\u7E2E\n    int N;//\u5EA7\u6A19\u5727\u7E2E\u3057\u305F\u306E\
    \u3061\u306Ex\u306E\u9802\u70B9\u6570\u306E2\u51AA\n\n\n    vector<vector<pair<long\
    \ long, long long>>> dat;//(y\u5EA7\u6A19\u3001\u91CD\u307F)\n    vector<vector<int>>\
    \ L;//L[i][k] := dat[i][k]\u306E\u3001\u5DE6\u306E\u5B50\u3067\u306E\u6DFB\u3048\
    \u5B57(dat[i][k]\u304C\u53F3\u306E\u5B50\u7531\u6765\u306E\u6642\u306F\u3001dat[i]\u5185\
    \u306E\u6B21\u306E\u5DE6\u306E\u5B50\u306E\u3084\u3064\u3068\u4E00\u81F4\u3055\
    \u305B\u308B)\n    vector<vector<int>> R;//R[i][k] := dat[i][k]\u306E\u3001\u53F3\
    \u306E\u5B50\u3067\u306E\u6DFB\u3048\u5B57(L, R\u5171\u306B\u534A\u958B\u533A\u9593\
    )\n\n     /*\n        L[i][k] \u306B\u306F\u3001\u300Cdat[i]\u3067k\u756A\u76EE\
    \u306E\u5024\u306F\u3001\n            \u5DE6\u306E\u5B50\u306B\u5B58\u5728\u3059\
    \u308B : \u305D\u306Eindex (\u8907\u6570\u305D\u306E\u5024\u304C\u5B58\u5728\u3059\
    \u308B\u306E\u306A\u3089\u3070\u3001\u4E00\u756A\u5DE6\u304C\u5B50\u3067\u3082\
    \u4E00\u756A\u5DE6\u306E\u3092\u6307\u3057\u3066\u3044\u308C\u3070\u5F8C\u306F\
    \u3069\u3046\u3067\u3082\u826F\u3044\u3002)\n            \u5B58\u5728\u3057\u306A\
    \u3044 : \u300C\u521D\u3081\u3066k\u756A\u76EE\u306E\u5024\u3092\u8D85\u3048\u308B\
    \u5024\u300D\u306Eindex(\u5B58\u5728\u3057\u306A\u3044\u306A\u3089\u914D\u5217\
    \u306E\u30B5\u30A4\u30BA\u3092\u5165\u308C\u3068\u304F)\n         \u3092\u53CE\
    \u3081\u308C\u3070\u826F\u3044\u3002\uFF08\u3053\u3046\u3059\u308B\u3068\u3001\
    \u4E8C\u5206\u63A2\u7D22\u3057\u305F\u7D50\u679C\u306E\u7BC4\u56F2\u304C\u6B63\
    \u3057\u304F\u5B50\u306B\u5F15\u304D\u7D99\u304C\u308C\u308B\u3002\n         R\u3082\
    \u540C\u69D8\u3002\n     */\n\n    private:\n        void init__() {\n       \
    \     nxs.init();\n            int n = nxs.size();\n            N = 1; \n    \
    \        while(N < n) {\n              N <<= 1;\n            }\n            dat.resize(2\
    \ * N);\n            sum.resize(2 * N);\n            L.resize(N);\n          \
    \  R.resize(N);\n            \n            //\u4E00\u756A\u4E0B\u306E\u6BB5\u306B\
    \u5165\u308C\u308B\u3002O(NlogN)\n            for(int i = 0; i < int(xs.size());\
    \ i++) {\n                int id = nxs(xs[i]);//xs[i]\u306E\u5EA7\u6A19\u5727\u7E2E\
    \u5F8C\u306E\u5024 1-indexed\u3067\u3042\u308B\u3002\n                int pos\
    \ = id + N - 1;\n                dat[pos].emplace_back(ys[i], ws[i]);//\u7D2F\u7A4D\
    \u548C\u3092\u53D6\u308B\u70BA\u306B\u3001\u91CD\u307F\u3082\u30DA\u30A2\u3067\
    \u5165\u308C\u3066\u304A\u304F\u3002\n            }\n\n            //\u3082\u3046\
    xs, ys, ws\u306F\u5FC5\u8981\u7121\u3044\u306E\u3067\u6368\u3066\u308B(\u30E1\u30E2\
    \u30EA\u524A\u6E1B)\n            xs.clear();\n            ys.clear();\n      \
    \      ws.clear();\n\n\n            //\u8449\u306E\u4E2D\u8EAB\u306B\u3064\u3044\
    \u3066\u3001y\u5EA7\u6A19\u6607\u9806\u3067sort\u3059\u308B\u3002\u8A08\u7B97\u91CF\
    \u306FO(NlogN)\u3067\u6291\u3048\u3089\u308C\u308B\u3002\n            for(int\
    \ i = 1 + N - 1; i < int(dat.size()); i++) {\n                sort(dat[i].begin(),\
    \ dat[i].end());\n            }\n\n            //\u30DC\u30C8\u30E0\u30A2\u30C3\
    \u30D7\u306B\u30DE\u30FC\u30B8\u3057\u3066\u3044\u304F\u3002\n            for(int\
    \ i = N - 1; i >= 1; i--) {\n                dat[i].resize(dat[i*2].size() + dat[i*2+1].size());\n\
    \                merge(begin(dat[i*2]), end(dat[i*2]), begin(dat[i*2+1]), end(dat[i*2+1]),\
    \ begin(dat[i]));\n            }\n        \n            //\u3053\u3053\u307E\u3067\
    \u304C\u666E\u901A\u306Erange tree\n  \n\n            //\u8449\u4EE5\u5916\u306E\
    \u9802\u70B9\u306B\u3064\u3044\u3066\u3001L\u3068R\u3092\u57CB\u3081\u3066\u3044\
    \u304F\u3002\n            for(int i = 1; i <= N-1; i++) {\n                L[i].resize(dat[i].size()\
    \ + 1);//\u5F8C\u3005\u534A\u958B\u533A\u9593\u3068\u3057\u3066\u6271\u3046\u306E\
    \u3067\u3001\u4E00\u3064\u591A\u304F\u53D6\u3063\u3066\u304A\u304F\u3068\u4FBF\
    \u5229\n                R[i].resize(dat[i].size() + 1);\n\n                int\
    \ li = 0, ri = 0;\n                //\u30A4\u30E1\u30FC\u30B8 : [1]li, ri\u5171\
    \u306B\u6B63\u3057\u3044( =0, =0\u306E\u521D\u671F\u5316\uFF09\u3002 [2]\u91CD\
    \u8907\u306A\u3057\u306E\u5024\u304C\u3042\u308B\u306A\u3089\u3001\u5B58\u5728\
    \u3059\u308B\u65B9\u3092\u4E00\u3064\u9032\u3081\u308C\u3070\u6B63\u3057\u3044\
    \u3002  [3]\u91CD\u8907\u3042\u308A\u306E\u5024\u304C\u3042\u308B\u306A\u3089\u3001\
    \u305D\u306E\u5024\u304C\u5B58\u5728\u3059\u308B\u500B\u6570\u5206li, ri\u3092\
    \u305D\u308C\u305E\u308C\u9032\u3081\u308C\u3070\u6B63\u3057\u3044\u3002\u3053\
    \u306E\u6642\u3001\u6700\u521D\u306E\u4EE3\u5165\u3067\u6B63\u3057\u3044index\u304C\
    \u633F\u5165\u3055\u308C\u3066\u304A\u308A\u3001\u305D\u306E\u5F8C\u308D\u306E\
    \u540C\u3058\u5024\u306Eindex\u306F\u4F7F\u308F\u308C\u306A\u3044\u306E\u3067\u3069\
    \u3046\u3067\u3082\u826F\u3044\u3002\uFF08\u3064\u307E\u308A\u6B63\u3057\u3044\
    \uFF09\n                for(int j = 0; j < int(dat[i].size()); j++) {\n      \
    \              L[i][j] = li, R[i][j] = ri;\n                    if(li < int(dat[2*i].size())\
    \ && dat[2*i][li].first == dat[i][j].first) {\n                      li++;\n \
    \                   }\n                    else {\n                      //\u5DE6\
    \u306B\u5B58\u5728\u3057\u306A\u3044\u306A\u3089\u53F3\u306B\u5B58\u5728\u3059\
    \u308B\n                      ri++;\n                    }\n                }\n\
    \                L[i][dat[i].size()] = dat[2*i].size();\n                R[i][dat[i].size()]\
    \ = dat[2*i+1].size();\n            }\n\n            //\u5168\u3066\u306E\u9802\
    \u70B9\u306B\u3064\u3044\u3066\u3001\u7D2F\u7A4D\u548C\u3092\u6C42\u3081\u308B\
    \u3002\n            for(int i = 1; i < int(dat.size()); i++) {\n             \
    \   if(int(dat[i].size()) == 0) continue;//\u9802\u70B9\u304C\u7A7A\u306A\u3089\
    \u30B9\u30AD\u30C3\u30D7\n\n                sum[i].resize(dat[i].size(), 0);\n\
    \                sum[i][0] = dat[i][0].second;\n                for(int j = 1;\
    \ j < int(dat[i].size()); j++) {\n                  sum[i][j] = sum[i][j-1] +\
    \ dat[i][j].second;\n                }\n            }\n\n        }\n        \n\
    \n        long long query(long long sx, long long tx, long long sy, long long\
    \ ty, int now, long long a, long long b) {//[sx, tx) * [sy, ty)\u306E\u7BC4\u56F2\
    \u306B\u3064\u3044\u3066\u7B54\u3048\u308B\u3002\u4ECA\u306E\u9802\u70B9\u756A\
    \u53F7\u304Cnow\u3067\u3001\u4ECA\u56DE\u306Fx = [a, b)\u306E\u533A\u9593\u306B\
    \u3064\u3044\u3066\u7B54\u3048\u308B\u3002\u306A\u304A\u3001y\u306F\u3001\u5143\
    \u306E\u5EA7\u6A19\u304B\u3089\u4ECA\u898B\u3066\u3044\u308B\u9802\u70B9\u306B\
    \u304A\u3051\u308B\u6DFB\u3048\u5B57\u306B\u5909\u63DB\u3055\u308C\u3066\u3044\
    \u308B\u3002\n            if(b <= sx || tx <= a) return 0LL;\n            else\
    \ if(sx <= a && b <= tx) {\n                if(ty == 0) return 0LL;\n        \
    \        long long res = sum[now][ty-1];//\u534A\u958B\u533A\u9593\u3067\u6E21\
    \u3055\u308C\u308B\u306E\u3067, ty-1\n                if(sy != 0) res -= sum[now][sy-1];\n\
    \                return res;\n            }\n            else {\n            \
    \    return query(sx, tx, L[now][sy], L[now][ty], now << 1, a, (a+b) >> 1) + query(sx,\
    \ tx, R[now][sy], R[now][ty], (now << 1)+1, (a+b)>>1, b);\n            }\n   \
    \     }\n  \n  \n    public:\n        void add(long long y, long long x, long\
    \ long w) {\n            xs.push_back(x);\n            ys.push_back(y);\n    \
    \        ws.push_back(w);\n            nxs.add(x);\n        }\n\n        void\
    \ init() {//before query\n            init__();\n        }\n\n        long long\
    \ get(long long sy, long long ty, long long sx, long long tx) {//[sx, tx] \u2716\
    \uFE0F [tx, ty] \n            tx++, ty++;//\u534A\u958B\u533A\u9593\u306B\u5909\
    \u66F4\u3002\n            //lower_bound\u3067\u533A\u9593\u3092\u6DFB\u5B57\u306B\
    \u5909\u3048\u308B\u969B\u3001\u534A\u958B\u533A\u9593\u3067\u306Fl, r\u5171\u306B\
    \u5927\u304D\u3044\u65B9\u306B\u4E38\u3081\u308C\u3070\u826F\u3044\u3002\n   \
    \         sy = lower_bound(dat[1].begin(), dat[1].end(), make_pair(sy, -LLONG_MAX))\
    \ - dat[1].begin();//y\u5EA7\u6A19\u3092dat[1]\u306B\u304A\u3051\u308B\u6DFB\u5B57\
    \u306B\u5909\u63DB\u3002\u3053\u306E\u6642\u3001\u540C\u3058y\u5EA7\u6A19\u304C\
    \u305F\u304F\u3055\u3093\u3042\u308B\u306A\u3089\u3070\u3001\u305D\u306E\u4E2D\
    \u3067\u4E00\u756A\u5DE6\u3092\u6307\u3057\u3066\u307B\u3057\u3044\u306E\u3067\
    \u91CD\u307F\u306F-LLONG_MAX\n            ty = lower_bound(dat[1].begin(), dat[1].end(),\
    \ make_pair(ty, -LLONG_MAX)) - dat[1].begin();//\u540C\u69D8\u3002\n         \
    \   sx = nxs(sx);//x\u5EA7\u6A19\u3092\u5EA7\u6A19\u5727\u7E2E\u5F8C\u306B\u5909\
    \u63DB\n            tx = nxs(tx);//\u540C\u69D8\u3002\n            return query(sx,\
    \ tx, sy, ty, 1, 1, N+1);\n        }\n        \n};//init\u5FD8\u308C\u305A\u306B\
    \n"
  code: "template<typename T>\nstruct CC {\n  bool initialized;\n  vector<T> xs;\n\
    \  CC () : initialized(false) {}\n  void add(T x) {xs.push_back(x);}\n  void init()\
    \ {\n    sort(xs.begin(), xs.end());\n    xs.erase(unique(xs.begin(), xs.end()),\
    \ xs.end());\n    initialized = true;\n  }\n\n  int operator()(T x) {//\u5024\
    (x)\u306E\u5727\u7E2E\u5F8C\u306E\u5024\uFF08\u4F55\u756A\u76EE\u306B\u5927\u304D\
    \u304B\u3063\u305F\uFF1F\uFF09 O(logN)\n    if(!initialized) init();\n    return\
    \ lower_bound(xs.begin(), xs.end(), x) - xs.begin() + 1;\n    //1-indexed\u3067\
    \u3042\u308B\u3002\n    //\u5927\u304D\u3044\u65B9\u306B\u4E38\u3081\u3066\u3044\
    \u308B\u3002{10,  15}\u306E\u6642\u3001(13) = (15) = 2\u3002\u3053\u308C\u306F\
    \u3001\u534A\u958B\u533A\u9593\u3092\u610F\u8B58\u3057\u3066\u3044\u308B\u3002\
    \n  }\n  T operator[](int i)  {//[i]\u756A\u76EE\u306B\u5927\u304D\u3044\u5024\
    \u3000\uFF08\u5727\u7E2E\u5F8C\u306Bi\u306B\u306A\u308B\u306E\u306F\u5024\u306A\
    \u3093\u3060\uFF09 O(1)\n    if(!initialized) init();\n    assert(i <= int(xs.size())\
    \ && i >= 1);\n    return xs[i-1];\n  }\n  int size()  {\n    if(!initialized)\
    \ init();\n    return xs.size();\n  }\n};\n\n//\u70B9\u306E\u5EA7\u6A19\u304C\u30DE\
    \u30A4\u30CA\u30B9\u3067\u3082\u884C\u3051\u308B\u3068\u601D\u3044\u307E\u3059\
    (\u5EA7\u6A19\u5727\u7E2E\u3067\u6B63\u306B\u306A\u308B\u306E\u3067\uFF09\n//depend\
    \ on CC library(\u5EA7\u6A19\u5727\u7E2E)\nstruct static2Drectunglesum {\n   \
    \ //ref : https://onedrive.live.com/view.aspx?resid=CD510BE428DBA1E7%21106&authkey=!AFD6EO1-AReoPBk\n\
    \n    vector<long long> xs;//\u70B9\u306E\u60C5\u5831(index\u30D9\u30FC\u30B9\u3067\
    \u6271\u3046\u3068\u4FBF\u5229)\n    vector<long long> ys;//\u70B9\u306E\u60C5\
    \u5831\n    vector<long long> ws;//\u70B9\u306E\u91CD\u307F\n    vector<vector<long\
    \ long>> sum;//\u5404\u9802\u70B9\u306E\u7D2F\u7A4D\u548C\n    CC<long long> nxs;//xs\u306E\
    \u5EA7\u6A19\u5727\u7E2E\n    int N;//\u5EA7\u6A19\u5727\u7E2E\u3057\u305F\u306E\
    \u3061\u306Ex\u306E\u9802\u70B9\u6570\u306E2\u51AA\n\n\n    vector<vector<pair<long\
    \ long, long long>>> dat;//(y\u5EA7\u6A19\u3001\u91CD\u307F)\n    vector<vector<int>>\
    \ L;//L[i][k] := dat[i][k]\u306E\u3001\u5DE6\u306E\u5B50\u3067\u306E\u6DFB\u3048\
    \u5B57(dat[i][k]\u304C\u53F3\u306E\u5B50\u7531\u6765\u306E\u6642\u306F\u3001dat[i]\u5185\
    \u306E\u6B21\u306E\u5DE6\u306E\u5B50\u306E\u3084\u3064\u3068\u4E00\u81F4\u3055\
    \u305B\u308B)\n    vector<vector<int>> R;//R[i][k] := dat[i][k]\u306E\u3001\u53F3\
    \u306E\u5B50\u3067\u306E\u6DFB\u3048\u5B57(L, R\u5171\u306B\u534A\u958B\u533A\u9593\
    )\n\n     /*\n        L[i][k] \u306B\u306F\u3001\u300Cdat[i]\u3067k\u756A\u76EE\
    \u306E\u5024\u306F\u3001\n            \u5DE6\u306E\u5B50\u306B\u5B58\u5728\u3059\
    \u308B : \u305D\u306Eindex (\u8907\u6570\u305D\u306E\u5024\u304C\u5B58\u5728\u3059\
    \u308B\u306E\u306A\u3089\u3070\u3001\u4E00\u756A\u5DE6\u304C\u5B50\u3067\u3082\
    \u4E00\u756A\u5DE6\u306E\u3092\u6307\u3057\u3066\u3044\u308C\u3070\u5F8C\u306F\
    \u3069\u3046\u3067\u3082\u826F\u3044\u3002)\n            \u5B58\u5728\u3057\u306A\
    \u3044 : \u300C\u521D\u3081\u3066k\u756A\u76EE\u306E\u5024\u3092\u8D85\u3048\u308B\
    \u5024\u300D\u306Eindex(\u5B58\u5728\u3057\u306A\u3044\u306A\u3089\u914D\u5217\
    \u306E\u30B5\u30A4\u30BA\u3092\u5165\u308C\u3068\u304F)\n         \u3092\u53CE\
    \u3081\u308C\u3070\u826F\u3044\u3002\uFF08\u3053\u3046\u3059\u308B\u3068\u3001\
    \u4E8C\u5206\u63A2\u7D22\u3057\u305F\u7D50\u679C\u306E\u7BC4\u56F2\u304C\u6B63\
    \u3057\u304F\u5B50\u306B\u5F15\u304D\u7D99\u304C\u308C\u308B\u3002\n         R\u3082\
    \u540C\u69D8\u3002\n     */\n\n    private:\n        void init__() {\n       \
    \     nxs.init();\n            int n = nxs.size();\n            N = 1; \n    \
    \        while(N < n) {\n              N <<= 1;\n            }\n            dat.resize(2\
    \ * N);\n            sum.resize(2 * N);\n            L.resize(N);\n          \
    \  R.resize(N);\n            \n            //\u4E00\u756A\u4E0B\u306E\u6BB5\u306B\
    \u5165\u308C\u308B\u3002O(NlogN)\n            for(int i = 0; i < int(xs.size());\
    \ i++) {\n                int id = nxs(xs[i]);//xs[i]\u306E\u5EA7\u6A19\u5727\u7E2E\
    \u5F8C\u306E\u5024 1-indexed\u3067\u3042\u308B\u3002\n                int pos\
    \ = id + N - 1;\n                dat[pos].emplace_back(ys[i], ws[i]);//\u7D2F\u7A4D\
    \u548C\u3092\u53D6\u308B\u70BA\u306B\u3001\u91CD\u307F\u3082\u30DA\u30A2\u3067\
    \u5165\u308C\u3066\u304A\u304F\u3002\n            }\n\n            //\u3082\u3046\
    xs, ys, ws\u306F\u5FC5\u8981\u7121\u3044\u306E\u3067\u6368\u3066\u308B(\u30E1\u30E2\
    \u30EA\u524A\u6E1B)\n            xs.clear();\n            ys.clear();\n      \
    \      ws.clear();\n\n\n            //\u8449\u306E\u4E2D\u8EAB\u306B\u3064\u3044\
    \u3066\u3001y\u5EA7\u6A19\u6607\u9806\u3067sort\u3059\u308B\u3002\u8A08\u7B97\u91CF\
    \u306FO(NlogN)\u3067\u6291\u3048\u3089\u308C\u308B\u3002\n            for(int\
    \ i = 1 + N - 1; i < int(dat.size()); i++) {\n                sort(dat[i].begin(),\
    \ dat[i].end());\n            }\n\n            //\u30DC\u30C8\u30E0\u30A2\u30C3\
    \u30D7\u306B\u30DE\u30FC\u30B8\u3057\u3066\u3044\u304F\u3002\n            for(int\
    \ i = N - 1; i >= 1; i--) {\n                dat[i].resize(dat[i*2].size() + dat[i*2+1].size());\n\
    \                merge(begin(dat[i*2]), end(dat[i*2]), begin(dat[i*2+1]), end(dat[i*2+1]),\
    \ begin(dat[i]));\n            }\n        \n            //\u3053\u3053\u307E\u3067\
    \u304C\u666E\u901A\u306Erange tree\n  \n\n            //\u8449\u4EE5\u5916\u306E\
    \u9802\u70B9\u306B\u3064\u3044\u3066\u3001L\u3068R\u3092\u57CB\u3081\u3066\u3044\
    \u304F\u3002\n            for(int i = 1; i <= N-1; i++) {\n                L[i].resize(dat[i].size()\
    \ + 1);//\u5F8C\u3005\u534A\u958B\u533A\u9593\u3068\u3057\u3066\u6271\u3046\u306E\
    \u3067\u3001\u4E00\u3064\u591A\u304F\u53D6\u3063\u3066\u304A\u304F\u3068\u4FBF\
    \u5229\n                R[i].resize(dat[i].size() + 1);\n\n                int\
    \ li = 0, ri = 0;\n                //\u30A4\u30E1\u30FC\u30B8 : [1]li, ri\u5171\
    \u306B\u6B63\u3057\u3044( =0, =0\u306E\u521D\u671F\u5316\uFF09\u3002 [2]\u91CD\
    \u8907\u306A\u3057\u306E\u5024\u304C\u3042\u308B\u306A\u3089\u3001\u5B58\u5728\
    \u3059\u308B\u65B9\u3092\u4E00\u3064\u9032\u3081\u308C\u3070\u6B63\u3057\u3044\
    \u3002  [3]\u91CD\u8907\u3042\u308A\u306E\u5024\u304C\u3042\u308B\u306A\u3089\u3001\
    \u305D\u306E\u5024\u304C\u5B58\u5728\u3059\u308B\u500B\u6570\u5206li, ri\u3092\
    \u305D\u308C\u305E\u308C\u9032\u3081\u308C\u3070\u6B63\u3057\u3044\u3002\u3053\
    \u306E\u6642\u3001\u6700\u521D\u306E\u4EE3\u5165\u3067\u6B63\u3057\u3044index\u304C\
    \u633F\u5165\u3055\u308C\u3066\u304A\u308A\u3001\u305D\u306E\u5F8C\u308D\u306E\
    \u540C\u3058\u5024\u306Eindex\u306F\u4F7F\u308F\u308C\u306A\u3044\u306E\u3067\u3069\
    \u3046\u3067\u3082\u826F\u3044\u3002\uFF08\u3064\u307E\u308A\u6B63\u3057\u3044\
    \uFF09\n                for(int j = 0; j < int(dat[i].size()); j++) {\n      \
    \              L[i][j] = li, R[i][j] = ri;\n                    if(li < int(dat[2*i].size())\
    \ && dat[2*i][li].first == dat[i][j].first) {\n                      li++;\n \
    \                   }\n                    else {\n                      //\u5DE6\
    \u306B\u5B58\u5728\u3057\u306A\u3044\u306A\u3089\u53F3\u306B\u5B58\u5728\u3059\
    \u308B\n                      ri++;\n                    }\n                }\n\
    \                L[i][dat[i].size()] = dat[2*i].size();\n                R[i][dat[i].size()]\
    \ = dat[2*i+1].size();\n            }\n\n            //\u5168\u3066\u306E\u9802\
    \u70B9\u306B\u3064\u3044\u3066\u3001\u7D2F\u7A4D\u548C\u3092\u6C42\u3081\u308B\
    \u3002\n            for(int i = 1; i < int(dat.size()); i++) {\n             \
    \   if(int(dat[i].size()) == 0) continue;//\u9802\u70B9\u304C\u7A7A\u306A\u3089\
    \u30B9\u30AD\u30C3\u30D7\n\n                sum[i].resize(dat[i].size(), 0);\n\
    \                sum[i][0] = dat[i][0].second;\n                for(int j = 1;\
    \ j < int(dat[i].size()); j++) {\n                  sum[i][j] = sum[i][j-1] +\
    \ dat[i][j].second;\n                }\n            }\n\n        }\n        \n\
    \n        long long query(long long sx, long long tx, long long sy, long long\
    \ ty, int now, long long a, long long b) {//[sx, tx) * [sy, ty)\u306E\u7BC4\u56F2\
    \u306B\u3064\u3044\u3066\u7B54\u3048\u308B\u3002\u4ECA\u306E\u9802\u70B9\u756A\
    \u53F7\u304Cnow\u3067\u3001\u4ECA\u56DE\u306Fx = [a, b)\u306E\u533A\u9593\u306B\
    \u3064\u3044\u3066\u7B54\u3048\u308B\u3002\u306A\u304A\u3001y\u306F\u3001\u5143\
    \u306E\u5EA7\u6A19\u304B\u3089\u4ECA\u898B\u3066\u3044\u308B\u9802\u70B9\u306B\
    \u304A\u3051\u308B\u6DFB\u3048\u5B57\u306B\u5909\u63DB\u3055\u308C\u3066\u3044\
    \u308B\u3002\n            if(b <= sx || tx <= a) return 0LL;\n            else\
    \ if(sx <= a && b <= tx) {\n                if(ty == 0) return 0LL;\n        \
    \        long long res = sum[now][ty-1];//\u534A\u958B\u533A\u9593\u3067\u6E21\
    \u3055\u308C\u308B\u306E\u3067, ty-1\n                if(sy != 0) res -= sum[now][sy-1];\n\
    \                return res;\n            }\n            else {\n            \
    \    return query(sx, tx, L[now][sy], L[now][ty], now << 1, a, (a+b) >> 1) + query(sx,\
    \ tx, R[now][sy], R[now][ty], (now << 1)+1, (a+b)>>1, b);\n            }\n   \
    \     }\n  \n  \n    public:\n        void add(long long y, long long x, long\
    \ long w) {\n            xs.push_back(x);\n            ys.push_back(y);\n    \
    \        ws.push_back(w);\n            nxs.add(x);\n        }\n\n        void\
    \ init() {//before query\n            init__();\n        }\n\n        long long\
    \ get(long long sy, long long ty, long long sx, long long tx) {//[sx, tx] \u2716\
    \uFE0F [tx, ty] \n            tx++, ty++;//\u534A\u958B\u533A\u9593\u306B\u5909\
    \u66F4\u3002\n            //lower_bound\u3067\u533A\u9593\u3092\u6DFB\u5B57\u306B\
    \u5909\u3048\u308B\u969B\u3001\u534A\u958B\u533A\u9593\u3067\u306Fl, r\u5171\u306B\
    \u5927\u304D\u3044\u65B9\u306B\u4E38\u3081\u308C\u3070\u826F\u3044\u3002\n   \
    \         sy = lower_bound(dat[1].begin(), dat[1].end(), make_pair(sy, -LLONG_MAX))\
    \ - dat[1].begin();//y\u5EA7\u6A19\u3092dat[1]\u306B\u304A\u3051\u308B\u6DFB\u5B57\
    \u306B\u5909\u63DB\u3002\u3053\u306E\u6642\u3001\u540C\u3058y\u5EA7\u6A19\u304C\
    \u305F\u304F\u3055\u3093\u3042\u308B\u306A\u3089\u3070\u3001\u305D\u306E\u4E2D\
    \u3067\u4E00\u756A\u5DE6\u3092\u6307\u3057\u3066\u307B\u3057\u3044\u306E\u3067\
    \u91CD\u307F\u306F-LLONG_MAX\n            ty = lower_bound(dat[1].begin(), dat[1].end(),\
    \ make_pair(ty, -LLONG_MAX)) - dat[1].begin();//\u540C\u69D8\u3002\n         \
    \   sx = nxs(sx);//x\u5EA7\u6A19\u3092\u5EA7\u6A19\u5727\u7E2E\u5F8C\u306B\u5909\
    \u63DB\n            tx = nxs(tx);//\u540C\u69D8\u3002\n            return query(sx,\
    \ tx, sy, ty, 1, 1, N+1);\n        }\n        \n};//init\u5FD8\u308C\u305A\u306B"
  dependsOn: []
  isVerificationFile: false
  path: DetaStructures/static2Drectanglesum.cpp
  requiredBy: []
  timestamp: '2024-05-10 22:23:09+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DetaStructures/static2Drectanglesum.cpp
layout: document
redirect_from:
- /library/DetaStructures/static2Drectanglesum.cpp
- /library/DetaStructures/static2Drectanglesum.cpp.html
title: DetaStructures/static2Drectanglesum.cpp
---
