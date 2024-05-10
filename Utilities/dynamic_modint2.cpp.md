---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u4EFB\u610Fmod\u306Emodint(mod < 2 ^ 64)"
    links: []
  bundledCode: "#line 1 \"Utilities/dynamic_modint2.cpp\"\nstruct mint{//mint for\
    \ big mod\n    long long x;\n    mint(long long _x=0) : x((_x%mod+mod)%mod){}\n\
    \    long long val()  {return x;}\n    mint& operator+=(const mint& a)  {if((x\
    \ += a.x) >= mod) x -= mod;return *this;}\n    mint& operator-=(const mint& a)\
    \  {if((x += mod - a.x) >= mod) x -= mod;return *this;}\n    mint& operator*=(const\
    \ mint& a)  {\n        __int128_t t = (__int128_t)(this -> x) * a.x;\n       \
    \ t %= mod; if(t < 0) t += mod;\n        *this = t;\n        return *this;\n \
    \   }\n    mint& operator/=(const mint& a) {return (*this) *= a.inv();}\n    mint&\
    \ operator++() noexcept {return *this += 1;}\n    mint& operator--() noexcept\
    \ {return *this -= 1;}\n    mint operator++(int) {mint tmp = *this; ++*this; return\
    \ tmp;}\n    mint operator--(int) {mint tmp = *this; --*this; return tmp;}\n \
    \   mint inv() const {return pow(mod-2);}\n    friend mint operator+(const mint&\
    \  t, const mint& a)  {mint tmp = t; return tmp += a;}\n    friend mint operator-(const\
    \ mint&  t, const mint& a)  {mint tmp = t; return tmp += (a * -1);}\n    friend\
    \ mint operator*(const mint&  t, const mint& a)  {mint tmp = t; return tmp *=\
    \ a;}\n    friend mint operator/(const mint&  t, const mint& a)  {assert(a.x !=\
    \ 0) ; return a.inv() *=  t;}\n    mint pow(const long long& y) const {\n    \
    \    assert(y >= 0);\n        if(!y) return 1;\n        mint res = pow(y >> 1);\n\
    \        res *= res;\n        if(y & 1) res *= *this;\n        return res;\n \
    \   }\n   friend istream& operator>>(istream& is, mint& a) { return is >> a.x;}\n\
    \   friend ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}\n\
    \   bool operator==(const mint& a) const {return x == a.x;}\n   bool operator!=(const\
    \ mint& a) const {return x != a.x;}\n   bool operator<(const mint& a) const {return\
    \ x < a.x;}\n};\n\n/*\n@brief \u4EFB\u610Fmod\u306Emodint(mod < 2 ^ 64)\n*/\n"
  code: "struct mint{//mint for big mod\n    long long x;\n    mint(long long _x=0)\
    \ : x((_x%mod+mod)%mod){}\n    long long val()  {return x;}\n    mint& operator+=(const\
    \ mint& a)  {if((x += a.x) >= mod) x -= mod;return *this;}\n    mint& operator-=(const\
    \ mint& a)  {if((x += mod - a.x) >= mod) x -= mod;return *this;}\n    mint& operator*=(const\
    \ mint& a)  {\n        __int128_t t = (__int128_t)(this -> x) * a.x;\n       \
    \ t %= mod; if(t < 0) t += mod;\n        *this = t;\n        return *this;\n \
    \   }\n    mint& operator/=(const mint& a) {return (*this) *= a.inv();}\n    mint&\
    \ operator++() noexcept {return *this += 1;}\n    mint& operator--() noexcept\
    \ {return *this -= 1;}\n    mint operator++(int) {mint tmp = *this; ++*this; return\
    \ tmp;}\n    mint operator--(int) {mint tmp = *this; --*this; return tmp;}\n \
    \   mint inv() const {return pow(mod-2);}\n    friend mint operator+(const mint&\
    \  t, const mint& a)  {mint tmp = t; return tmp += a;}\n    friend mint operator-(const\
    \ mint&  t, const mint& a)  {mint tmp = t; return tmp += (a * -1);}\n    friend\
    \ mint operator*(const mint&  t, const mint& a)  {mint tmp = t; return tmp *=\
    \ a;}\n    friend mint operator/(const mint&  t, const mint& a)  {assert(a.x !=\
    \ 0) ; return a.inv() *=  t;}\n    mint pow(const long long& y) const {\n    \
    \    assert(y >= 0);\n        if(!y) return 1;\n        mint res = pow(y >> 1);\n\
    \        res *= res;\n        if(y & 1) res *= *this;\n        return res;\n \
    \   }\n   friend istream& operator>>(istream& is, mint& a) { return is >> a.x;}\n\
    \   friend ostream& operator<<(ostream& os, const mint& a) { return os << a.x;}\n\
    \   bool operator==(const mint& a) const {return x == a.x;}\n   bool operator!=(const\
    \ mint& a) const {return x != a.x;}\n   bool operator<(const mint& a) const {return\
    \ x < a.x;}\n};\n\n/*\n@brief \u4EFB\u610Fmod\u306Emodint(mod < 2 ^ 64)\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Utilities/dynamic_modint2.cpp
  requiredBy: []
  timestamp: '2024-05-10 23:39:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utilities/dynamic_modint2.cpp
layout: document
redirect_from:
- /library/Utilities/dynamic_modint2.cpp
- /library/Utilities/dynamic_modint2.cpp.html
title: "\u4EFB\u610Fmod\u306Emodint(mod < 2 ^ 64)"
---
