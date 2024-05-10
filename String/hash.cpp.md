---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\u306E\u578B"
    links: []
  bundledCode: "#line 1 \"String/hash.cpp\"\n\nlong long MOD = (1LL << 61) -1;\nstruct\
    \ hint{//mint for rhash\n    long long x;\n    hint(long long _x=0) : x((_x%MOD+MOD)%MOD){}\n\
    \    long long val()  {return x;}\n    hint& operator+=(const hint& a)  {if((x\
    \ += a.x) >= MOD) x -= MOD;return *this;}\n    hint& operator-=(const hint& a)\
    \  {if((x += MOD - a.x) >= MOD) x -= MOD;return *this;}\n    hint& operator*=(const\
    \ hint& a)  {\n        __int128_t t = (__int128_t)(this -> x) * a.x;//\u30AD\u30E3\
    \u30B9\u30C8\u5FD8\u308C\u304C\u3061\n        t %= MOD; if(t < 0) t += MOD;\n\
    \        *this = t;\n        return *this;\n    }\n    hint& operator/=(const\
    \ hint& a) {return (*this) *= a.inv();}\n    hint& operator++() noexcept {return\
    \ *this += 1;}\n    hint& operator--() noexcept {return *this -= 1;}\n    hint\
    \ operator++(int) {hint tmp = *this; ++*this; return tmp;}\n    hint operator--(int)\
    \ {hint tmp = *this; --*this; return tmp;}\n    hint inv() const {return pow(MOD-2);}\n\
    \    friend hint operator+(const hint&  t, const hint& a)  {hint tmp = t; return\
    \ tmp += a;}\n    friend hint operator-(const hint&  t, const hint& a)  {hint\
    \ tmp = t; return tmp += (a * -1);}\n    friend hint operator*(const hint&  t,\
    \ const hint& a)  {hint tmp = t; return tmp *= a;}\n    friend hint operator/(const\
    \ hint&  t, const hint& a)  {assert(a.x != 0) ; return a.inv() *=  t;}\n    hint\
    \ pow(const long long& y) const {\n        assert(y >= 0);\n        if(!y) return\
    \ 1;\n        hint res = pow(y >> 1);\n        res *= res;\n        if(y & 1)\
    \ res *= *this;\n        return res;\n    }\n   friend istream& operator>>(istream&\
    \ is, hint& a) { return is >> a.x;}\n   friend ostream& operator<<(ostream& os,\
    \ const hint& a) { return os << a.x;}\n   bool operator==(const hint& a) const\
    \ {return x == a.x;}\n   bool operator!=(const hint& a) const {return x != a.x;}\n\
    \   bool operator<(const hint& a) const {return x < a.x;}\n};\n\n\nstruct base_rhash\
    \ {\n    int MAX_TYPE = 100;\n    hint B = rand()%200 + MAX_TYPE;//\u6587\u5B57\
    \u306E\u7A2E\u985E\u6570\u3088\u308A\u5927\u304D\u3051\u308C\u3070\u826F\u3044\
    \u3002\n    vector<hint> pb;\n\n    base_rhash(int siz) {\n        unsigned int\
    \ now = time(NULL);\n        srand(now);\n        pb.resize(siz+1);\n        pb[0]\
    \ = 1;\n        for(int i = 1; i <= siz; i++) {\n            pb[i] = pb[i-1] *\
    \ B;\n        }\n    }\n    //\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\
    \u30E5\u3092\u4F7F\u3046\u305F\u3081\u306EBase\u3068\u305D\u308C\u306E\u7D2F\u4E57\
    \u3092\u8A08\u7B97\u3059\u308B\u3002siz\u306B\u306F\u3001\u6587\u5B57\u5217\u306E\
    \u6700\u5927\u9577\u3092\u5165\u308C\u308B\u3002\n};base_rhash brh(\u6700\u5927\
    \u6587\u5B57\u5217\u9577);\n\n\n\nstruct rhash {\n    //depend on base_rhash\n\
    \    //\u3053\u306E\u307E\u307E\u30BB\u30B0\u6728\u306B\u4E57\u308B\n    hint\
    \ h;\n    int len;\n    rhash() : h(0), len(0){}\n    rhash(hint _h, int _len)\
    \ : h(_h), len(_len){}\n\n    public: \n        friend bool operator==(const rhash&\
    \ l, const rhash& r) {return l.h == r.h && l.len == r.len;}\n        friend bool\
    \ operator!=(const rhash& l, const rhash& r) {return !(l == r);}\n\n        friend\
    \ rhash op(const rhash& l, const rhash& r) {//l\u3068r\u3092\u3053\u306E\u9806\
    \u3067\u7D50\u5408\u3059\u308B\n            rhash res;\n            res.h = l.h*brh.pb.at(r.len)\
    \ + r.h;//brh\u3067\u78BA\u4FDD\u3057\u305F\u6587\u5B57\u5217\u9577\u304C\u8DB3\
    \u308A\u306A\u3044\u6642\u306B\u30A8\u30E9\u30FC\u3092\u5410\u3044\u3066\u6B32\
    \u3057\u3044\n            res.len = l.len + r.len;\n            return res;\n\
    \        }\n    \n        friend rhash update(const rhash& l, const rhash& x)\
    \ {//\u4EE3\u5165\n            return x;\n        }\n\n        static rhash ide()\
    \ {\n            return rhash(0, 0);\n        }\n\n};\n\n\nstruct rhash_string\
    \ {\n    vector<rhash> H;//0-indexed\u3067\u3001res[i] := [0, i]\u6587\u5B57\u76EE\
    \u306E\u6587\u5B57\u5217\u306B\u5BFE\u5FDC\u3059\u308B\u30CF\u30C3\u30B7\u30E5\
    \n    rhash_string(){}\n\n    rhash_string(string& S) {\n        H.resize(S.size(),\
    \ def);\n        H[0].h = S[0] - 'a' + 1;\n        H[0].len = 1;\n        for(int\
    \ i = 1; i < int(S.size()); i++) {\n          H[i].h = H[i-1].h * brh.B + S[i]\
    \ - 'a' + 1;\n          H[i].len = 1 + H[i-1].len;\n        }\n    }\n\n    rhash\
    \ get(int l, int r) {//1-indexed\u3067\u3001[l, r]\u306B\u5BFE\u5FDC\u3059\u308B\
    \u30CF\u30C3\u30B7\u30E5\u3092\u8FD4\u3059\u3002\n        l--, r--;\n        if(l\
    \ > r) return def;\n        rhash res = H[r];\n        if(l != 0) res.h = res.h\
    \ - brh.pb[r-l+1] * H[l-1].h;\n        res.len = r-l+1;\n        return res;\n\
    \    }\n};\n\nrhash cal_rhash(string& S) {\n    rhash res;\n    for(int i = 0;\
    \ i < int(S.size()); i++) {\n        res.h = res.h * brh.B + S[i] - 'a'+1;\n \
    \   }\n    res.len = S.size();\n    return res;\n}\n\nrhash cal_rhash(char s)\
    \ {\n    return rhash(s - 'a' + 1, 1);\n}\n\n/*\n@brief \u30ED\u30FC\u30EA\u30F3\
    \u30B0\u30CF\u30C3\u30B7\u30E5\u306E\u578B\n*/\n"
  code: "\nlong long MOD = (1LL << 61) -1;\nstruct hint{//mint for rhash\n    long\
    \ long x;\n    hint(long long _x=0) : x((_x%MOD+MOD)%MOD){}\n    long long val()\
    \  {return x;}\n    hint& operator+=(const hint& a)  {if((x += a.x) >= MOD) x\
    \ -= MOD;return *this;}\n    hint& operator-=(const hint& a)  {if((x += MOD -\
    \ a.x) >= MOD) x -= MOD;return *this;}\n    hint& operator*=(const hint& a)  {\n\
    \        __int128_t t = (__int128_t)(this -> x) * a.x;//\u30AD\u30E3\u30B9\u30C8\
    \u5FD8\u308C\u304C\u3061\n        t %= MOD; if(t < 0) t += MOD;\n        *this\
    \ = t;\n        return *this;\n    }\n    hint& operator/=(const hint& a) {return\
    \ (*this) *= a.inv();}\n    hint& operator++() noexcept {return *this += 1;}\n\
    \    hint& operator--() noexcept {return *this -= 1;}\n    hint operator++(int)\
    \ {hint tmp = *this; ++*this; return tmp;}\n    hint operator--(int) {hint tmp\
    \ = *this; --*this; return tmp;}\n    hint inv() const {return pow(MOD-2);}\n\
    \    friend hint operator+(const hint&  t, const hint& a)  {hint tmp = t; return\
    \ tmp += a;}\n    friend hint operator-(const hint&  t, const hint& a)  {hint\
    \ tmp = t; return tmp += (a * -1);}\n    friend hint operator*(const hint&  t,\
    \ const hint& a)  {hint tmp = t; return tmp *= a;}\n    friend hint operator/(const\
    \ hint&  t, const hint& a)  {assert(a.x != 0) ; return a.inv() *=  t;}\n    hint\
    \ pow(const long long& y) const {\n        assert(y >= 0);\n        if(!y) return\
    \ 1;\n        hint res = pow(y >> 1);\n        res *= res;\n        if(y & 1)\
    \ res *= *this;\n        return res;\n    }\n   friend istream& operator>>(istream&\
    \ is, hint& a) { return is >> a.x;}\n   friend ostream& operator<<(ostream& os,\
    \ const hint& a) { return os << a.x;}\n   bool operator==(const hint& a) const\
    \ {return x == a.x;}\n   bool operator!=(const hint& a) const {return x != a.x;}\n\
    \   bool operator<(const hint& a) const {return x < a.x;}\n};\n\n\nstruct base_rhash\
    \ {\n    int MAX_TYPE = 100;\n    hint B = rand()%200 + MAX_TYPE;//\u6587\u5B57\
    \u306E\u7A2E\u985E\u6570\u3088\u308A\u5927\u304D\u3051\u308C\u3070\u826F\u3044\
    \u3002\n    vector<hint> pb;\n\n    base_rhash(int siz) {\n        unsigned int\
    \ now = time(NULL);\n        srand(now);\n        pb.resize(siz+1);\n        pb[0]\
    \ = 1;\n        for(int i = 1; i <= siz; i++) {\n            pb[i] = pb[i-1] *\
    \ B;\n        }\n    }\n    //\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\
    \u30E5\u3092\u4F7F\u3046\u305F\u3081\u306EBase\u3068\u305D\u308C\u306E\u7D2F\u4E57\
    \u3092\u8A08\u7B97\u3059\u308B\u3002siz\u306B\u306F\u3001\u6587\u5B57\u5217\u306E\
    \u6700\u5927\u9577\u3092\u5165\u308C\u308B\u3002\n};base_rhash brh(\u6700\u5927\
    \u6587\u5B57\u5217\u9577);\n\n\n\nstruct rhash {\n    //depend on base_rhash\n\
    \    //\u3053\u306E\u307E\u307E\u30BB\u30B0\u6728\u306B\u4E57\u308B\n    hint\
    \ h;\n    int len;\n    rhash() : h(0), len(0){}\n    rhash(hint _h, int _len)\
    \ : h(_h), len(_len){}\n\n    public: \n        friend bool operator==(const rhash&\
    \ l, const rhash& r) {return l.h == r.h && l.len == r.len;}\n        friend bool\
    \ operator!=(const rhash& l, const rhash& r) {return !(l == r);}\n\n        friend\
    \ rhash op(const rhash& l, const rhash& r) {//l\u3068r\u3092\u3053\u306E\u9806\
    \u3067\u7D50\u5408\u3059\u308B\n            rhash res;\n            res.h = l.h*brh.pb.at(r.len)\
    \ + r.h;//brh\u3067\u78BA\u4FDD\u3057\u305F\u6587\u5B57\u5217\u9577\u304C\u8DB3\
    \u308A\u306A\u3044\u6642\u306B\u30A8\u30E9\u30FC\u3092\u5410\u3044\u3066\u6B32\
    \u3057\u3044\n            res.len = l.len + r.len;\n            return res;\n\
    \        }\n    \n        friend rhash update(const rhash& l, const rhash& x)\
    \ {//\u4EE3\u5165\n            return x;\n        }\n\n        static rhash ide()\
    \ {\n            return rhash(0, 0);\n        }\n\n};\n\n\nstruct rhash_string\
    \ {\n    vector<rhash> H;//0-indexed\u3067\u3001res[i] := [0, i]\u6587\u5B57\u76EE\
    \u306E\u6587\u5B57\u5217\u306B\u5BFE\u5FDC\u3059\u308B\u30CF\u30C3\u30B7\u30E5\
    \n    rhash_string(){}\n\n    rhash_string(string& S) {\n        H.resize(S.size(),\
    \ def);\n        H[0].h = S[0] - 'a' + 1;\n        H[0].len = 1;\n        for(int\
    \ i = 1; i < int(S.size()); i++) {\n          H[i].h = H[i-1].h * brh.B + S[i]\
    \ - 'a' + 1;\n          H[i].len = 1 + H[i-1].len;\n        }\n    }\n\n    rhash\
    \ get(int l, int r) {//1-indexed\u3067\u3001[l, r]\u306B\u5BFE\u5FDC\u3059\u308B\
    \u30CF\u30C3\u30B7\u30E5\u3092\u8FD4\u3059\u3002\n        l--, r--;\n        if(l\
    \ > r) return def;\n        rhash res = H[r];\n        if(l != 0) res.h = res.h\
    \ - brh.pb[r-l+1] * H[l-1].h;\n        res.len = r-l+1;\n        return res;\n\
    \    }\n};\n\nrhash cal_rhash(string& S) {\n    rhash res;\n    for(int i = 0;\
    \ i < int(S.size()); i++) {\n        res.h = res.h * brh.B + S[i] - 'a'+1;\n \
    \   }\n    res.len = S.size();\n    return res;\n}\n\nrhash cal_rhash(char s)\
    \ {\n    return rhash(s - 'a' + 1, 1);\n}\n\n/*\n@brief \u30ED\u30FC\u30EA\u30F3\
    \u30B0\u30CF\u30C3\u30B7\u30E5\u306E\u578B\n*/"
  dependsOn: []
  isVerificationFile: false
  path: String/hash.cpp
  requiredBy: []
  timestamp: '2024-05-10 23:14:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: String/hash.cpp
layout: document
redirect_from:
- /library/String/hash.cpp
- /library/String/hash.cpp.html
title: "\u30ED\u30FC\u30EA\u30F3\u30B0\u30CF\u30C3\u30B7\u30E5\u306E\u578B"
---
