---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u884C\u5217\u306E\u578B"
    links: []
  bundledCode: "#line 1 \"Math/matrix.cpp\"\ntemplate<typename T>\nstruct Matrix \
    \ {\n  int h, w;\n  vector<vector<T>> d;\n  Matrix() {}\n  Matrix(int h, int w,\
    \ T val = 0): h(h), w(w), d(h, vector<T>(w, val)){}\n  Matrix& unit() {\n    assert(h\
    \ == w);\n    rep(i, 0, h-1) {\n      d[i][i] = 1;\n    }\n   return *this;\n\
    \  }\n  const vector<T>& operator[](int i) const{return d[i];}\n  vector<T>& operator[](int\
    \ i) {return d[i];}\n  Matrix operator*(const Matrix&a) const{\n    assert(w ==\
    \ a.h);\n    Matrix r(h, a.w);\n    rep(i, 0, h-1) {\n      rep(k, 0, w-1) {\n\
    \        rep(j, 0, a.w-1) {\n          r[i][j] += d[i][k] * a[k][j];\n       \
    \ }\n      }\n    }\n    return r;\n  }\n  Matrix pow(ll t) const {\n    assert(h\
    \ == w);\n    if(!t) return Matrix(h, h).unit();\n    if(t == 1) return *this;\n\
    \    Matrix r = pow(t >> 1);\n    r = r * r;\n    if(t&1) r = r*(*this);\n   \
    \ return r;\n  }\n};\n/*\n@brief \u884C\u5217\u306E\u578B\n*/\n"
  code: "template<typename T>\nstruct Matrix  {\n  int h, w;\n  vector<vector<T>>\
    \ d;\n  Matrix() {}\n  Matrix(int h, int w, T val = 0): h(h), w(w), d(h, vector<T>(w,\
    \ val)){}\n  Matrix& unit() {\n    assert(h == w);\n    rep(i, 0, h-1) {\n   \
    \   d[i][i] = 1;\n    }\n   return *this;\n  }\n  const vector<T>& operator[](int\
    \ i) const{return d[i];}\n  vector<T>& operator[](int i) {return d[i];}\n  Matrix\
    \ operator*(const Matrix&a) const{\n    assert(w == a.h);\n    Matrix r(h, a.w);\n\
    \    rep(i, 0, h-1) {\n      rep(k, 0, w-1) {\n        rep(j, 0, a.w-1) {\n  \
    \        r[i][j] += d[i][k] * a[k][j];\n        }\n      }\n    }\n    return\
    \ r;\n  }\n  Matrix pow(ll t) const {\n    assert(h == w);\n    if(!t) return\
    \ Matrix(h, h).unit();\n    if(t == 1) return *this;\n    Matrix r = pow(t >>\
    \ 1);\n    r = r * r;\n    if(t&1) r = r*(*this);\n    return r;\n  }\n};\n/*\n\
    @brief \u884C\u5217\u306E\u578B\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Math/matrix.cpp
  requiredBy: []
  timestamp: '2024-05-10 23:19:42+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Math/matrix.cpp
layout: document
redirect_from:
- /library/Math/matrix.cpp
- /library/Math/matrix.cpp.html
title: "\u884C\u5217\u306E\u578B"
---
