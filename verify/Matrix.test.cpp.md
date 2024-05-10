---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: Math/matrix.hpp
    title: "\u884C\u5217\u306E\u578B"
  - icon: ':heavy_check_mark:'
    path: Utilities/modint998.hpp
    title: modint998244353
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/pow_of_matrix
    links:
    - https://judge.yosupo.jp/problem/pow_of_matrix
  bundledCode: "#line 1 \"verify/Matrix.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/pow_of_matrix\"\
    \n#include<bits/stdc++.h>\nusing namespace std;\n#line 1 \"Utilities/modint998.hpp\"\
    \n\ntemplate<int mod>\nstruct modint{\n    long long x;\n    modint(long long\
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
    using mint = modint<998244353>;\n/*\n@brief modint998244353\n*/\n#line 1 \"Math/matrix.hpp\"\
    \n\ntemplate<typename T>\nstruct Matrix  {\n  using ll = long long;\n  int h,\
    \ w;\n  vector<vector<T>> d;\n  Matrix() {}\n  Matrix(int h, int w, T val = 0):\
    \ h(h), w(w), d(h, vector<T>(w, val)){}\n  Matrix& unit() {\n    assert(h == w);\n\
    \    for(int i = 0; i < h; i++) {\n      d[i][i] = 1;\n    }\n   return *this;\n\
    \  }\n  const vector<T>& operator[](int i) const{return d[i];}\n  vector<T>& operator[](int\
    \ i) {return d[i];}\n  Matrix operator*(const Matrix&a) const{\n    assert(w ==\
    \ a.h);\n    Matrix r(h, a.w);\n    for(int i = 0; i < h; i++) {\n      for(int\
    \ k = 0; k < w; k++) {\n        for(int j = 0; j < a.w; j++) {\n          r[i][j]\
    \ += d[i][k] * a[k][j];\n        }\n      }\n    }\n    return r;\n  }\n  Matrix\
    \ pow(ll t) const {\n    assert(h == w);\n    if(!t) return Matrix(h, h).unit();\n\
    \    if(t == 1) return *this;\n    Matrix r = pow(t >> 1);\n    r = r * r;\n \
    \   if(t&1) r = r*(*this);\n    return r;\n  }\n};\n/*\n@brief \u884C\u5217\u306E\
    \u578B\n*/\n#line 6 \"verify/Matrix.test.cpp\"\nusing ll = long long;\nusing vvl\
    \ = vector<vector<ll>>;\nusing vl = vector<ll>;\n#define rep(i, s, f) for(long\
    \ long i = s; i <= f; i++)\n#define ENDL '\\n'\n\nint main() {\n\tll N, K;\n\t\
    cin >> N >> K;\n\tMatrix<mint> A(N, N, 0);\n\trep(i,0,N-1) rep(j,0,N-1) cin >>\
    \ A[i][j];\n\tA = A.pow(K);\n\trep(i,0,N-1) {\n\t\trep(j,0,N-1) cout << A[i][j]\
    \ << \" \";\n\t\tcout << '\\n';\n\t}\n\n    \n}\n\n\n\n\n\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/pow_of_matrix\"\n#include<bits/stdc++.h>\n\
    using namespace std;\n#include \"../Utilities/modint998.hpp\"\n#include \"../Math/matrix.hpp\"\
    \nusing ll = long long;\nusing vvl = vector<vector<ll>>;\nusing vl = vector<ll>;\n\
    #define rep(i, s, f) for(long long i = s; i <= f; i++)\n#define ENDL '\\n'\n\n\
    int main() {\n\tll N, K;\n\tcin >> N >> K;\n\tMatrix<mint> A(N, N, 0);\n\trep(i,0,N-1)\
    \ rep(j,0,N-1) cin >> A[i][j];\n\tA = A.pow(K);\n\trep(i,0,N-1) {\n\t\trep(j,0,N-1)\
    \ cout << A[i][j] << \" \";\n\t\tcout << '\\n';\n\t}\n\n    \n}\n\n\n\n\n\n"
  dependsOn:
  - Utilities/modint998.hpp
  - Math/matrix.hpp
  isVerificationFile: true
  path: verify/Matrix.test.cpp
  requiredBy: []
  timestamp: '2024-05-11 01:49:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/Matrix.test.cpp
layout: document
redirect_from:
- /verify/verify/Matrix.test.cpp
- /verify/verify/Matrix.test.cpp.html
title: verify/Matrix.test.cpp
---
