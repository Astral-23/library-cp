---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "Monoid\u3068\u4F5C\u7528\u7D20\u306E\u30C6\u30F3\u30D7\u30EC\u30FC\
      \u30C8"
    links: []
  bundledCode: "#line 1 \"Utilities/Monoid.hpp\"\nstruct Monoid {\n    long long a;\n\
    \   \n    Monoid(){}\n      \n    Monoid(long long _a) : a(_a) {\n      \n   \
    \ }\n\n    friend Monoid op(const Monoid& l, const Monoid& r) {\n      return\
    \ l.a + r.a;\n    }\n\n    friend Monoid update(const Monoid& l, const Monoid&\
    \ r) {\n   \n    }\n\n    static Monoid ide() {\n       return 0LL;\n    }\n \
    \   \n};\n\nstruct E {    \n    mint a, b;\n   \n    E(){}\n      \n    E(mint\
    \ _a, mint _b) : a(_a), b(_b) {}\n\n    friend E op(const E& l, const E& r) {//r\u306E\
    \u304C\u65B0\u3057\u3044\u3002(affine)\n        E res;\n        res.a = l.a *\
    \ r.a;\n        res.b = r.a * l.b + r.b;\n        return res;\n      \n    }\n\
    \    static E ide() {\n       return E(1, 0);\n    }\n   \n    bool operator==(const\
    \ E& x) const {return (a == x.a && b == x.b);}\n    bool operator!=(const E& x)\
    \ const {return !(*this == x);}\n\n};\n\n\n\nMonoid fx(const Monoid& l, const\
    \ E& r, long long len) {\n     return l.a * r.a + r.b * len;\n}\n/*\n@brief Monoid\u3068\
    \u4F5C\u7528\u7D20\u306E\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8\n*/\n"
  code: "struct Monoid {\n    long long a;\n   \n    Monoid(){}\n      \n    Monoid(long\
    \ long _a) : a(_a) {\n      \n    }\n\n    friend Monoid op(const Monoid& l, const\
    \ Monoid& r) {\n      return l.a + r.a;\n    }\n\n    friend Monoid update(const\
    \ Monoid& l, const Monoid& r) {\n   \n    }\n\n    static Monoid ide() {\n   \
    \    return 0LL;\n    }\n    \n};\n\nstruct E {    \n    mint a, b;\n   \n   \
    \ E(){}\n      \n    E(mint _a, mint _b) : a(_a), b(_b) {}\n\n    friend E op(const\
    \ E& l, const E& r) {//r\u306E\u304C\u65B0\u3057\u3044\u3002(affine)\n       \
    \ E res;\n        res.a = l.a * r.a;\n        res.b = r.a * l.b + r.b;\n     \
    \   return res;\n      \n    }\n    static E ide() {\n       return E(1, 0);\n\
    \    }\n   \n    bool operator==(const E& x) const {return (a == x.a && b == x.b);}\n\
    \    bool operator!=(const E& x) const {return !(*this == x);}\n\n};\n\n\n\nMonoid\
    \ fx(const Monoid& l, const E& r, long long len) {\n     return l.a * r.a + r.b\
    \ * len;\n}\n/*\n@brief Monoid\u3068\u4F5C\u7528\u7D20\u306E\u30C6\u30F3\u30D7\
    \u30EC\u30FC\u30C8\n*/"
  dependsOn: []
  isVerificationFile: false
  path: Utilities/Monoid.hpp
  requiredBy: []
  timestamp: '2024-05-11 00:52:36+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utilities/Monoid.hpp
layout: document
redirect_from:
- /library/Utilities/Monoid.hpp
- /library/Utilities/Monoid.hpp.html
title: "Monoid\u3068\u4F5C\u7528\u7D20\u306E\u30C6\u30F3\u30D7\u30EC\u30FC\u30C8"
---
