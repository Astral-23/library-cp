---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: modint1000000007
    links: []
  bundledCode: "#line 1 \"Utilities/modint107.cpp\"\n\ntemplate<int mod>\nstruct modint{\n\
    \    long long x;\n    modint(long long _x=0) noexcept : x((_x%mod+mod)%mod){}\n\
    \    long long val() const noexcept {return x;}\n    modint& operator+=(const\
    \ modint& a) noexcept {if((x += a.x) >= mod) x -= mod;return *this;}\n    modint&\
    \ operator-=(const modint& a) noexcept {if((x += mod - a.x) >= mod) x -= mod;return\
    \ *this;}\n    modint& operator*=(const modint& a) noexcept {(x *= a.x) %= mod;return\
    \ *this;}\n    modint& operator/=(const modint& a) {return (*this) *= a.inv();}\n\
    \    modint& operator++() noexcept {return *this += 1;}\n    modint& operator--()\
    \ noexcept {return *this -= 1;}\n    modint operator++(int) {modint tmp = *this;\
    \ ++*this; return tmp;}\n    modint operator--(int) {modint tmp = *this; --*this;\
    \ return tmp;}\n    modint inv() const {return pow(mod-2);}\n    friend modint\
    \ operator+(const modint&  t, const modint& a)  {modint tmp = t; return tmp +=\
    \ a;}\n    friend modint operator-(const modint&  t, const modint& a)  {modint\
    \ tmp = t; return tmp += (a * -1);}\n    friend modint operator*(const modint&\
    \  t, const modint& a)  {modint tmp = t; return tmp *= a;}\n    friend modint\
    \ operator/(const modint&  t, const modint& a)  {assert(a.x != 0) ; return a.inv()\
    \ *=  t;}\n    modint pow(const long long& y) const {\n        if(!y) return 1;\n\
    \        modint res = pow(y >> 1);\n        res *= res;\n        if(y & 1) res\
    \ *= *this;\n        return res;\n    }\n    friend istream& operator>>(istream&\
    \ is, modint& a) { return is >> a.x;}\n    friend ostream& operator<<(ostream&\
    \ os, const modint& a) { return os << a.x;}\n    bool operator==(const modint&\
    \ a) const {return x == a.x;}\n    bool operator!=(const modint& a) const {return\
    \ x != a.x;}\n    bool operator<(const modint& a) const {return x < a.x;}\n};\n\
    \nusing mint = modint<1000000007>;\n\n/*\n@brief modint1000000007\n*/\n"
  code: "\ntemplate<int mod>\nstruct modint{\n    long long x;\n    modint(long long\
    \ _x=0) noexcept : x((_x%mod+mod)%mod){}\n    long long val() const noexcept {return\
    \ x;}\n    modint& operator+=(const modint& a) noexcept {if((x += a.x) >= mod)\
    \ x -= mod;return *this;}\n    modint& operator-=(const modint& a) noexcept {if((x\
    \ += mod - a.x) >= mod) x -= mod;return *this;}\n    modint& operator*=(const\
    \ modint& a) noexcept {(x *= a.x) %= mod;return *this;}\n    modint& operator/=(const\
    \ modint& a) {return (*this) *= a.inv();}\n    modint& operator++() noexcept {return\
    \ *this += 1;}\n    modint& operator--() noexcept {return *this -= 1;}\n    modint\
    \ operator++(int) {modint tmp = *this; ++*this; return tmp;}\n    modint operator--(int)\
    \ {modint tmp = *this; --*this; return tmp;}\n    modint inv() const {return pow(mod-2);}\n\
    \    friend modint operator+(const modint&  t, const modint& a)  {modint tmp =\
    \ t; return tmp += a;}\n    friend modint operator-(const modint&  t, const modint&\
    \ a)  {modint tmp = t; return tmp += (a * -1);}\n    friend modint operator*(const\
    \ modint&  t, const modint& a)  {modint tmp = t; return tmp *= a;}\n    friend\
    \ modint operator/(const modint&  t, const modint& a)  {assert(a.x != 0) ; return\
    \ a.inv() *=  t;}\n    modint pow(const long long& y) const {\n        if(!y)\
    \ return 1;\n        modint res = pow(y >> 1);\n        res *= res;\n        if(y\
    \ & 1) res *= *this;\n        return res;\n    }\n    friend istream& operator>>(istream&\
    \ is, modint& a) { return is >> a.x;}\n    friend ostream& operator<<(ostream&\
    \ os, const modint& a) { return os << a.x;}\n    bool operator==(const modint&\
    \ a) const {return x == a.x;}\n    bool operator!=(const modint& a) const {return\
    \ x != a.x;}\n    bool operator<(const modint& a) const {return x < a.x;}\n};\n\
    \nusing mint = modint<1000000007>;\n\n/*\n@brief modint1000000007\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Utilities/modint107.cpp
  requiredBy: []
  timestamp: '2024-05-10 23:39:05+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utilities/modint107.cpp
layout: document
redirect_from:
- /library/Utilities/modint107.cpp
- /library/Utilities/modint107.cpp.html
title: modint1000000007
---
