---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u7D20\u6570\u7BE9"
    links: []
  bundledCode: "#line 1 \"Math/sieve.cpp\"\nstruct notlinear_sieve {\n    int N;\n\
    \n    notlinear_sieve(int _N) : N(_N) {\n        assert(1 <= N);\n        large.resize(N\
    \ + 1);\n        iota(large.begin(), large.end(), 0);\n        large_res.resize(N\
    \ + 1);\n    \n        for(int i = 2; i * i <= N; i++) {\n            if(large[i]\
    \ != i) continue;\n            for(int j = i * 2; j <= N; j += i) {\n        \
    \        if(large[j] == j) large[j] = i;\n            }\n        }\n        //O(NloglogN)\n\
    \    }\n\n\n    private:\n        vector<int> large;//\u5272\u308A\u5207\u308B\
    \u6700\u5C0F\u306E\u7D20\u56E0\u6570\n        vector<vector<pair<int, int>>> large_res;//\u7D20\
    \u56E0\u6570\u5206\u89E3\u306E\u7D50\u679C\uFF08conduct\u3057\u3066\u521D\u3081\
    \u3066\u57CB\u307E\u308B\uFF09\n        vector<int> div_cnt;\n        bool conducted\
    \ = false;\n        bool divcntinited = false;\n    \n        void conduct() {\n\
    \            conducted = true;\n            for(long long i = 2; i <= N; i++)\
    \ {\n                long long num = i;\n                while(large[num] != num)\
    \ {\n                    long long tmp = num;\n                    long long cnt\
    \ = 0;\n                    while(tmp % large[num] == 0) cnt++, tmp /= large[num];\n\
    \                    large_res[i].emplace_back(large[num], cnt);\n           \
    \         num = tmp;\n                }\n                if(num != 1) large_res[i].emplace_back(num,\
    \ 1LL);\n            }\n            //\u3053\u306E\u51E6\u7406\u306BO(NlogN)\n\
    \        }\n        \n        int divcnt__(int x) {\n            if(!conducted)\
    \ conduct();\n            auto ps = get(x);\n            int res = 1;\n      \
    \      for(auto [p, c] : ps) res *= (c+1);\n            return res;\n        }\n\
    \n        vector<int> divs__(int x) {\n            if(!conducted) conduct();\n\
    \            vector<int> res;\n            auto ps = get(x);\n\n            auto\
    \ dfs = [&](auto dfs, long long id, long long val) -> void {\n               \
    \ if(id == ps.size()) {\n                    res.push_back(val);\n           \
    \         return;\n                }\n\n                auto [p, c] = ps[id];\n\
    \                for(int i = 0; i <= c; i++) {\n                    dfs(dfs, id+1,\
    \ val);\n                    val *= p;\n                }\n            };\n\n\
    \            dfs(dfs, 0, 1);\n            return res;\n        }\n    \n\n   \
    \ public:\n\n        vector<int> primes(int r) {//[2, r]\u306B\u53CE\u307E\u308B\
    \u7D20\u6570\u304C\u6607\u9806\u3067\u5165\u3063\u305F\u914D\u5217\u3092\u8FD4\
    \u3059\u3002\n            vector<int> res;\n            for(long long i = 2; i\
    \ <= r; i++) if(isprime(i)) res.push_back(i);  \n            return res;\n   \
    \     }//O(r)\n\n\n        bool isprime(int x) {//x\u306F\u7D20\u6570\u304B \n\
    \            if(x <= 1) return false;\n            return large[x] == x;\n   \
    \     }//O(1)\n\n\n        int divcnt(int x) {//x\u306E\u7D04\u6570\u306E\u500B\
    \u6570\u3092\u8FD4\u3059\u3002\n            return divcnt__(x);\n        }//O(logN)\
    \ \u6CE8\uFF1A\u521D\u56DEO(NlogN)\n\n        vector<int> divs(int x) {//x\u306E\
    \u7D04\u6570\u3092\u9069\u5F53\u306A\u9806\u3067\u5165\u308C\u305F\u914D\u5217\
    \u3092\u8FD4\u3059\u3002\n            return divs__(x);\n        }//O(\u7D04\u6570\
    \u306E\u500B\u6570)  x <= 10^18\u3067\u5927\u51E1 O(x ^ (1/3))  \u6CE8 : \u521D\
    \u56DEO(NlogN)\n      \n\n        vector<pair<int, int>> get(int x) {//x\u3092\
    \u7D20\u56E0\u6570\u5206\u89E3\u3057\u305F\u7D50\u679C {\u7D20\u56E0\u6570, \u6B21\
    \u6570}\u306E\u30DA\u30A2\u304C\u5165\u3063\u305F\u914D\u5217\n            if(!conducted)\
    \ conduct();\n            return large_res[x];\n        }//O(1) \u6CE8\uFF1A \u521D\
    \u56DEO(NlogN)\n  \n\n    //@brief \u7D20\u6570\u7BE9\n    //\u8C46\u77E5\u8B58\
    :X\u306E\u7D04\u6570\u306E\u500B\u6570\u306F\u7CBE\u3005X^(1/3)\u7A0B\u5EA6\u3002\
    (X>=10^18\u4EE5\u964D\u306F\u69D8\u76F8\u304C\u5909\u308F\u308B\u304C)\n    //\u7D20\
    \u56E0\u6570\u5206\u89E3\u306B\u3064\u3044\u3066\u3001\u7279\u5B9A\u306E\u6570\
    \u5B57x\u306B\u3064\u3044\u3066\u306E\u307Flog(x)\u3067\u5B9F\u884C\u3059\u308B\
    \u3053\u3068\u3082\u3067\u304D\u308B\u3002\n\n};notlinear_sieve sieve();\n"
  code: "struct notlinear_sieve {\n    int N;\n\n    notlinear_sieve(int _N) : N(_N)\
    \ {\n        assert(1 <= N);\n        large.resize(N + 1);\n        iota(large.begin(),\
    \ large.end(), 0);\n        large_res.resize(N + 1);\n    \n        for(int i\
    \ = 2; i * i <= N; i++) {\n            if(large[i] != i) continue;\n         \
    \   for(int j = i * 2; j <= N; j += i) {\n                if(large[j] == j) large[j]\
    \ = i;\n            }\n        }\n        //O(NloglogN)\n    }\n\n\n    private:\n\
    \        vector<int> large;//\u5272\u308A\u5207\u308B\u6700\u5C0F\u306E\u7D20\u56E0\
    \u6570\n        vector<vector<pair<int, int>>> large_res;//\u7D20\u56E0\u6570\u5206\
    \u89E3\u306E\u7D50\u679C\uFF08conduct\u3057\u3066\u521D\u3081\u3066\u57CB\u307E\
    \u308B\uFF09\n        vector<int> div_cnt;\n        bool conducted = false;\n\
    \        bool divcntinited = false;\n    \n        void conduct() {\n        \
    \    conducted = true;\n            for(long long i = 2; i <= N; i++) {\n    \
    \            long long num = i;\n                while(large[num] != num) {\n\
    \                    long long tmp = num;\n                    long long cnt =\
    \ 0;\n                    while(tmp % large[num] == 0) cnt++, tmp /= large[num];\n\
    \                    large_res[i].emplace_back(large[num], cnt);\n           \
    \         num = tmp;\n                }\n                if(num != 1) large_res[i].emplace_back(num,\
    \ 1LL);\n            }\n            //\u3053\u306E\u51E6\u7406\u306BO(NlogN)\n\
    \        }\n        \n        int divcnt__(int x) {\n            if(!conducted)\
    \ conduct();\n            auto ps = get(x);\n            int res = 1;\n      \
    \      for(auto [p, c] : ps) res *= (c+1);\n            return res;\n        }\n\
    \n        vector<int> divs__(int x) {\n            if(!conducted) conduct();\n\
    \            vector<int> res;\n            auto ps = get(x);\n\n            auto\
    \ dfs = [&](auto dfs, long long id, long long val) -> void {\n               \
    \ if(id == ps.size()) {\n                    res.push_back(val);\n           \
    \         return;\n                }\n\n                auto [p, c] = ps[id];\n\
    \                for(int i = 0; i <= c; i++) {\n                    dfs(dfs, id+1,\
    \ val);\n                    val *= p;\n                }\n            };\n\n\
    \            dfs(dfs, 0, 1);\n            return res;\n        }\n    \n\n   \
    \ public:\n\n        vector<int> primes(int r) {//[2, r]\u306B\u53CE\u307E\u308B\
    \u7D20\u6570\u304C\u6607\u9806\u3067\u5165\u3063\u305F\u914D\u5217\u3092\u8FD4\
    \u3059\u3002\n            vector<int> res;\n            for(long long i = 2; i\
    \ <= r; i++) if(isprime(i)) res.push_back(i);  \n            return res;\n   \
    \     }//O(r)\n\n\n        bool isprime(int x) {//x\u306F\u7D20\u6570\u304B \n\
    \            if(x <= 1) return false;\n            return large[x] == x;\n   \
    \     }//O(1)\n\n\n        int divcnt(int x) {//x\u306E\u7D04\u6570\u306E\u500B\
    \u6570\u3092\u8FD4\u3059\u3002\n            return divcnt__(x);\n        }//O(logN)\
    \ \u6CE8\uFF1A\u521D\u56DEO(NlogN)\n\n        vector<int> divs(int x) {//x\u306E\
    \u7D04\u6570\u3092\u9069\u5F53\u306A\u9806\u3067\u5165\u308C\u305F\u914D\u5217\
    \u3092\u8FD4\u3059\u3002\n            return divs__(x);\n        }//O(\u7D04\u6570\
    \u306E\u500B\u6570)  x <= 10^18\u3067\u5927\u51E1 O(x ^ (1/3))  \u6CE8 : \u521D\
    \u56DEO(NlogN)\n      \n\n        vector<pair<int, int>> get(int x) {//x\u3092\
    \u7D20\u56E0\u6570\u5206\u89E3\u3057\u305F\u7D50\u679C {\u7D20\u56E0\u6570, \u6B21\
    \u6570}\u306E\u30DA\u30A2\u304C\u5165\u3063\u305F\u914D\u5217\n            if(!conducted)\
    \ conduct();\n            return large_res[x];\n        }//O(1) \u6CE8\uFF1A \u521D\
    \u56DEO(NlogN)\n  \n\n    //@brief \u7D20\u6570\u7BE9\n    //\u8C46\u77E5\u8B58\
    :X\u306E\u7D04\u6570\u306E\u500B\u6570\u306F\u7CBE\u3005X^(1/3)\u7A0B\u5EA6\u3002\
    (X>=10^18\u4EE5\u964D\u306F\u69D8\u76F8\u304C\u5909\u308F\u308B\u304C)\n    //\u7D20\
    \u56E0\u6570\u5206\u89E3\u306B\u3064\u3044\u3066\u3001\u7279\u5B9A\u306E\u6570\
    \u5B57x\u306B\u3064\u3044\u3066\u306E\u307Flog(x)\u3067\u5B9F\u884C\u3059\u308B\
    \u3053\u3068\u3082\u3067\u304D\u308B\u3002\n\n};notlinear_sieve sieve();"
  dependsOn: []
  isVerificationFile: false
  path: Math/sieve.cpp
  requiredBy: []
  timestamp: '2024-05-10 23:19:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/sieve.cpp
layout: document
redirect_from:
- /library/Math/sieve.cpp
- /library/Math/sieve.cpp.html
title: "\u7D20\u6570\u7BE9"
---
