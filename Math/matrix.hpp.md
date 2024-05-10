---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/Matrix.test.cpp
    title: verify/Matrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u884C\u5217\u306E\u578B"
    links: []
  bundledCode: "#line 1 \"Math/matrix.hpp\"\n\ntemplate<typename T>\nstruct Matrix\
    \  {\n  using ll = long long;\n  int h, w;\n  vector<vector<T>> d;\n  Matrix()\
    \ {}\n  Matrix(int h, int w, T val = 0): h(h), w(w), d(h, vector<T>(w, val)){}\n\
    \  Matrix& unit() {\n    assert(h == w);\n    for(int i = 0; i < h; i++) {\n \
    \     d[i][i] = 1;\n    }\n   return *this;\n  }\n  const vector<T>& operator[](int\
    \ i) const{return d[i];}\n  vector<T>& operator[](int i) {return d[i];}\n  Matrix\
    \ operator*(const Matrix&a) const{\n    assert(w == a.h);\n    Matrix r(h, a.w);\n\
    \    for(int i = 0; i < h; i++) {\n      for(int k = 0; k < w; k++) {\n      \
    \  for(int j = 0; j < a.w; j++) {\n          r[i][j] += d[i][k] * a[k][j];\n \
    \       }\n      }\n    }\n    return r;\n  }\n  Matrix pow(ll t) const {\n  \
    \  assert(h == w);\n    if(!t) return Matrix(h, h).unit();\n    if(t == 1) return\
    \ *this;\n    Matrix r = pow(t >> 1);\n    r = r * r;\n    if(t&1) r = r*(*this);\n\
    \    return r;\n  }\n};\n/*\n@brief \u884C\u5217\u306E\u578B\n*/\n"
  code: "\ntemplate<typename T>\nstruct Matrix  {\n  using ll = long long;\n  int\
    \ h, w;\n  vector<vector<T>> d;\n  Matrix() {}\n  Matrix(int h, int w, T val =\
    \ 0): h(h), w(w), d(h, vector<T>(w, val)){}\n  Matrix& unit() {\n    assert(h\
    \ == w);\n    for(int i = 0; i < h; i++) {\n      d[i][i] = 1;\n    }\n   return\
    \ *this;\n  }\n  const vector<T>& operator[](int i) const{return d[i];}\n  vector<T>&\
    \ operator[](int i) {return d[i];}\n  Matrix operator*(const Matrix&a) const{\n\
    \    assert(w == a.h);\n    Matrix r(h, a.w);\n    for(int i = 0; i < h; i++)\
    \ {\n      for(int k = 0; k < w; k++) {\n        for(int j = 0; j < a.w; j++)\
    \ {\n          r[i][j] += d[i][k] * a[k][j];\n        }\n      }\n    }\n    return\
    \ r;\n  }\n  Matrix pow(ll t) const {\n    assert(h == w);\n    if(!t) return\
    \ Matrix(h, h).unit();\n    if(t == 1) return *this;\n    Matrix r = pow(t >>\
    \ 1);\n    r = r * r;\n    if(t&1) r = r*(*this);\n    return r;\n  }\n};\n/*\n\
    @brief \u884C\u5217\u306E\u578B\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Math/matrix.hpp
  requiredBy: []
  timestamp: '2024-05-11 01:24:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/Matrix.test.cpp
documentation_of: Math/matrix.hpp
layout: document
redirect_from:
- /library/Math/matrix.hpp
- /library/Math/matrix.hpp.html
title: "\u884C\u5217\u306E\u578B"
---
