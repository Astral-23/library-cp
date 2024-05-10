---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/SegTree.test.cpp
    title: verify/SegTree.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    document_title: modint998244353
    links: []
  bundledCode: "#line 1 \"Utilities/modint998.hpp\"\n\ntemplate<int mod>\nstruct modint{\n\
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
    using mint = modint<998244353>;\n/*\n@brief modint998244353\n*/\n"
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
    using mint = modint<998244353>;\n/*\n@brief modint998244353\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Utilities/modint998.hpp
  requiredBy: []
  timestamp: '2024-05-11 00:52:36+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/SegTree.test.cpp
documentation_of: Utilities/modint998.hpp
layout: document
redirect_from:
- /library/Utilities/modint998.hpp
- /library/Utilities/modint998.hpp.html
title: modint998244353
---
