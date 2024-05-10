---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../library-cp/Utilities/modint998.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/pow_of_matrix\"\n#include<bits/stdc++.h>\n\
    using namespace std;\n#include \"../Math/matrix.hpp\"\n#include \"../library-cp/Utilities/modint998.hpp\"\
    \nusing ll = long long;\nusing vvl = vector<vector<ll>>;\nusing vl = vector<ll>;\n\
    #define rep(i, s, f) for(long long i = s; i <= f; i++)\n#define ENDL '\\n'\n\n\
    int main() {\n\n\tint N, K;\n\tcin >> N >> K;\n\tMatrix<mint> A(N, N, 0);\n\t\
    rep(i,0,N-1) rep(j,0,N-1) cin >> A[i][j];\n\tA = A.pow(K);\n\trep(i,0,N-1) {\n\
    \t\trep(j,0,N-1) cout << A[i][j] << \" \";\n\t\tcout << '\\n';\n\t}\n\n    \n\
    }\n\n\n\n\n\n"
  dependsOn: []
  isVerificationFile: true
  path: verify/Matrix.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: verify/Matrix.test.cpp
layout: document
redirect_from:
- /verify/verify/Matrix.test.cpp
- /verify/verify/Matrix.test.cpp.html
title: verify/Matrix.test.cpp
---
