---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u7D20\u6570\u7BE9(\u5DE6\u7AEF\u4EFB\u610F)"
    links: []
  bundledCode: "#line 1 \"Math/sieve2.cpp\"\n\nstruct sectional_primes {\n    /*\n\
    \    [L, R]\u306E\u6574\u6570\u3092\u7D20\u6570\u5224\u5B9A\uFF1A\u7D20\u56E0\u6570\
    \u5206\u89E3\u3059\u308B\u3002\n    \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\
    \uFF1A\u7D20\u6570\u5224\u5B9A\n    O(\u221ARloglog\u221AR + (R - L)loglog(R-L))\uFF1F\
    \n    [1, 10^6]\u3067134ms [10^12, 10^12 + 10^6]\u3067350ms\u7A0B\n  \n    conduct()\u3092\
    \u5B9F\u884C\u3059\u308B\u3068\u3001\u7D20\u56E0\u6570\u5206\u89E3\u304C\u5B9F\
    \u884C\u3055\u308C\u308B\u3002\n    O((R - L)log(R))\n    \u53C2\u8003 : \u533A\
    \u9593\u9577\u3068R\u306E\u5927\u304D\u3055\u304C\u901F\u5EA6\u306B\u5F71\u97FF\
    \u3002\n    [1, 10^6]\u3067300ms, [10^12, 10^12 + 10^6]\u3067550ms\u7A0B\n   \
    \ isprime[i]\u3067\u3001i\u304C\u7D20\u6570\u304B\u3069\u3046\u304B\u304C\u308F\
    \u304B\u308B\u3002  L <= i <= R || 1 <= i <= \u221AR O(1)\n    get[i]\u3067\u3001\
    i\u306E\u7D20\u56E0\u6570\u5206\u89E3\u306E\u7D50\u679C\u304C\u5F97\u3089\u308C\
    \u308B  L <= i <= R  O(log(i))\n    */\n    long long L, R, M;\n    bool conducted\
    \ = false;\n    vector<bool> small;//small[i] := i\u304C\u7D20\u6570\u304B\u3069\
    \u3046\u304B i <= \u221AR\n    vector<vector<long long>> large;//large[i] := i+L\
    \ \u306E\u76F8\u7570\u306A\u308B\u7D20\u56E0\u6570\u306E\u96C6\u5408\n    vector<vector<pair<long\
    \ long, long long>>> large_res;\n    vector<vector<long long>> aux;// aux[i] :=\
    \ large[i]\u306E\u7D20\u56E0\u6570\u306E\u7A4D\u3001\u3064\u307E\u308Ai + L\u306E\
    \u7D20\u56E0\u6570\u306E\u7A4D\uFF08\u7D20\u6570\u5224\u5B9A\u7528\uFF09\n  \n\
    \    sectional_primes(long long _L, long long _R) : L(_L), R(_R) {\n        assert(R\
    \ >= 1 && L <= R);\n        M = sqrt(R);\n        small.resize(M + 1, true);\n\
    \        small[0] = false;\n        small[1] = false;\n        large.resize(R\
    \ - L + 1);\n        large_res.resize(R - L + 1);\n    \n        for(long long\
    \ i = 2; i * i <= R; i++) {\n            if(!small[i]) continue;\n           \
    \ for(long long j = i * 2; j <= M; j += i) {\n                small[j] = false;\n\
    \            }\n            for(long long j = (L + i - 1)/i * i; j <= R; j +=\
    \ i) {\n                large[j - L].push_back(i);\n            }\n        }\n\
    \    //\u221AR\u4EE5\u4E0B\u306E\u7D20\u56E0\u6570\u306F\u5168\u3066\u5217\u6319\
    \u3057\u7D42\u3048\u305F\u3002\u3053\u3053\u304B\u3089\u306F\u221AR\u4EE5\u4E0A\
    \u306E\u7D20\u56E0\u6570\u3092\u5217\u6319\u3002\u3061\u306A\u307F\u306B\u3001\
    \u221AR\u4EE5\u4E0A\u306E\u7D20\u56E0\u6570\u306F\u5404\u6570\u306B\u3064\u304D\
    \u6700\u5927\u30661\u3064\u3002\n    //\u3053\u3053\u307E\u3067O(\u221ARloglog\u221A\
    R + (R - L)loglog(R-L))\n    }\n    \n\n    private:\n\n        void conduct()\
    \ {\n            for(long long i = L; i <= R; i++) {\n                long long\
    \ num = i;\n                for(long long x : large[i - L]) {\n              \
    \      if(num < x) break;\n                    long long cnt = 0;\n          \
    \          while(num % x == 0) num /= x, cnt++;\n                    large_res[i\
    \ - L].emplace_back(x, cnt);\n                }\n                if(num != 1)\
    \ large[i-L].push_back(num), large_res[i-L].emplace_back(num, 1);\n          \
    \  }\n          //O((R - L)log(R))\n        }\n        \n    \n\n    public:\n\
    \n        bool isprime(long long x) {//[-\u7121\u9650, \u221AR] \u307E\u305F\u306F\
    \ [L, R]\u306B\u3064\u3044\u3066\u3001\u7D20\u6570\u5224\u5B9A  \u305D\u308C\u4EE5\
    \u5916\u306F\u672A\u5B9A\u7FA9\n          if(x <= 1) return false;\n         \
    \ if(x <= M) return small[x];\n          if(!conducted) return large[x - L].size()\
    \ == 0;//\u221AR\u4EE5\u4E0B\u306E\u7D20\u56E0\u6570\u304C\u306A\u3044\u21D4x\u304C\
    \u7D20\u6570\n          else return large[x - L].size() == 1;//\u7D20\u56E0\u6570\
    \u5206\u89E3\u6E08\u307F\u3002\n        }//O(1)  \n      \n        vector<pair<long\
    \ long, long long>> get(long long x) {//[L, R]\u306B\u3064\u3044\u3066\u3001\u7D20\
    \u56E0\u6570\u5206\u89E3\u306E\u7D50\u679C\u3092\u8FD4\u3059 {\u7D20\u56E0\u6570\
    , \u6307\u6570}\u306E\u914D\u5217\n            if(!conducted) conduct();\n   \
    \         return large_res[x - L];\n        }//\u521D\u56DE\u3044\u3063\u3071\u3044\
    \ \u4EE5\u964DO(1)\n};\n\n/*\n@brief \u7D20\u6570\u7BE9(\u5DE6\u7AEF\u4EFB\u610F\
    )\n*/\n"
  code: "\nstruct sectional_primes {\n    /*\n    [L, R]\u306E\u6574\u6570\u3092\u7D20\
    \u6570\u5224\u5B9A\uFF1A\u7D20\u56E0\u6570\u5206\u89E3\u3059\u308B\u3002\n   \
    \ \u30B3\u30F3\u30B9\u30C8\u30E9\u30AF\u30BF\uFF1A\u7D20\u6570\u5224\u5B9A\n \
    \   O(\u221ARloglog\u221AR + (R - L)loglog(R-L))\uFF1F\n    [1, 10^6]\u3067134ms\
    \ [10^12, 10^12 + 10^6]\u3067350ms\u7A0B\n  \n    conduct()\u3092\u5B9F\u884C\u3059\
    \u308B\u3068\u3001\u7D20\u56E0\u6570\u5206\u89E3\u304C\u5B9F\u884C\u3055\u308C\
    \u308B\u3002\n    O((R - L)log(R))\n    \u53C2\u8003 : \u533A\u9593\u9577\u3068\
    R\u306E\u5927\u304D\u3055\u304C\u901F\u5EA6\u306B\u5F71\u97FF\u3002\n    [1, 10^6]\u3067\
    300ms, [10^12, 10^12 + 10^6]\u3067550ms\u7A0B\n    isprime[i]\u3067\u3001i\u304C\
    \u7D20\u6570\u304B\u3069\u3046\u304B\u304C\u308F\u304B\u308B\u3002  L <= i <=\
    \ R || 1 <= i <= \u221AR O(1)\n    get[i]\u3067\u3001i\u306E\u7D20\u56E0\u6570\
    \u5206\u89E3\u306E\u7D50\u679C\u304C\u5F97\u3089\u308C\u308B  L <= i <= R  O(log(i))\n\
    \    */\n    long long L, R, M;\n    bool conducted = false;\n    vector<bool>\
    \ small;//small[i] := i\u304C\u7D20\u6570\u304B\u3069\u3046\u304B i <= \u221A\
    R\n    vector<vector<long long>> large;//large[i] := i+L \u306E\u76F8\u7570\u306A\
    \u308B\u7D20\u56E0\u6570\u306E\u96C6\u5408\n    vector<vector<pair<long long,\
    \ long long>>> large_res;\n    vector<vector<long long>> aux;// aux[i] := large[i]\u306E\
    \u7D20\u56E0\u6570\u306E\u7A4D\u3001\u3064\u307E\u308Ai + L\u306E\u7D20\u56E0\u6570\
    \u306E\u7A4D\uFF08\u7D20\u6570\u5224\u5B9A\u7528\uFF09\n  \n    sectional_primes(long\
    \ long _L, long long _R) : L(_L), R(_R) {\n        assert(R >= 1 && L <= R);\n\
    \        M = sqrt(R);\n        small.resize(M + 1, true);\n        small[0] =\
    \ false;\n        small[1] = false;\n        large.resize(R - L + 1);\n      \
    \  large_res.resize(R - L + 1);\n    \n        for(long long i = 2; i * i <= R;\
    \ i++) {\n            if(!small[i]) continue;\n            for(long long j = i\
    \ * 2; j <= M; j += i) {\n                small[j] = false;\n            }\n \
    \           for(long long j = (L + i - 1)/i * i; j <= R; j += i) {\n         \
    \       large[j - L].push_back(i);\n            }\n        }\n    //\u221AR\u4EE5\
    \u4E0B\u306E\u7D20\u56E0\u6570\u306F\u5168\u3066\u5217\u6319\u3057\u7D42\u3048\
    \u305F\u3002\u3053\u3053\u304B\u3089\u306F\u221AR\u4EE5\u4E0A\u306E\u7D20\u56E0\
    \u6570\u3092\u5217\u6319\u3002\u3061\u306A\u307F\u306B\u3001\u221AR\u4EE5\u4E0A\
    \u306E\u7D20\u56E0\u6570\u306F\u5404\u6570\u306B\u3064\u304D\u6700\u5927\u3066\
    1\u3064\u3002\n    //\u3053\u3053\u307E\u3067O(\u221ARloglog\u221AR + (R - L)loglog(R-L))\n\
    \    }\n    \n\n    private:\n\n        void conduct() {\n            for(long\
    \ long i = L; i <= R; i++) {\n                long long num = i;\n           \
    \     for(long long x : large[i - L]) {\n                    if(num < x) break;\n\
    \                    long long cnt = 0;\n                    while(num % x ==\
    \ 0) num /= x, cnt++;\n                    large_res[i - L].emplace_back(x, cnt);\n\
    \                }\n                if(num != 1) large[i-L].push_back(num), large_res[i-L].emplace_back(num,\
    \ 1);\n            }\n          //O((R - L)log(R))\n        }\n        \n    \n\
    \n    public:\n\n        bool isprime(long long x) {//[-\u7121\u9650, \u221AR]\
    \ \u307E\u305F\u306F [L, R]\u306B\u3064\u3044\u3066\u3001\u7D20\u6570\u5224\u5B9A\
    \  \u305D\u308C\u4EE5\u5916\u306F\u672A\u5B9A\u7FA9\n          if(x <= 1) return\
    \ false;\n          if(x <= M) return small[x];\n          if(!conducted) return\
    \ large[x - L].size() == 0;//\u221AR\u4EE5\u4E0B\u306E\u7D20\u56E0\u6570\u304C\
    \u306A\u3044\u21D4x\u304C\u7D20\u6570\n          else return large[x - L].size()\
    \ == 1;//\u7D20\u56E0\u6570\u5206\u89E3\u6E08\u307F\u3002\n        }//O(1)  \n\
    \      \n        vector<pair<long long, long long>> get(long long x) {//[L, R]\u306B\
    \u3064\u3044\u3066\u3001\u7D20\u56E0\u6570\u5206\u89E3\u306E\u7D50\u679C\u3092\
    \u8FD4\u3059 {\u7D20\u56E0\u6570, \u6307\u6570}\u306E\u914D\u5217\n          \
    \  if(!conducted) conduct();\n            return large_res[x - L];\n        }//\u521D\
    \u56DE\u3044\u3063\u3071\u3044 \u4EE5\u964DO(1)\n};\n\n/*\n@brief \u7D20\u6570\
    \u7BE9(\u5DE6\u7AEF\u4EFB\u610F)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Math/sieve2.cpp
  requiredBy: []
  timestamp: '2024-05-10 23:19:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/sieve2.cpp
layout: document
redirect_from:
- /library/Math/sieve2.cpp
- /library/Math/sieve2.cpp.html
title: "\u7D20\u6570\u7BE9(\u5DE6\u7AEF\u4EFB\u610F)"
---
