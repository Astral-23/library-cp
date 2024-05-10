---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: Timer
    links: []
  bundledCode: "#line 1 \"Utilities/timer.cpp\"\nstruct Timer {\n\tchrono::system_clock::time_point\
    \ s;\n\tchrono::system_clock::time_point pre;\n\tbool active = false;\n\n\tTimer(){active\
    \ = false;}\n\n\tvoid start() {\n\t\tassert(!active);\n\t\tactive = true;\n\t\t\
    s = chrono::system_clock::now();\n\t}\n\n\tvoid stop() {\n\t\tpre = chrono::system_clock::now();\n\
    \t\tassert(active);\n\t\tactive = false;\n\t}\n\n\tvoid restart() {//non_active\u306E\
    \u6642\u9593\u5206\u3001\u59CB\u70B9\u3092\u305A\u3089\u3059\n\t    assert(!active);\n\
    \t\tactive = true;\n\t\ts += chrono::system_clock::now() - pre;\n\t}\n\n\n\tdouble\
    \ now() {\n\t\tif(active) {\n\t\t    chrono::system_clock::time_point t = chrono::system_clock::now();\n\
    \t\t    return chrono::duration<double>(t - s).count();\n\t\t}\n\t\telse {\n\t\
    \t\treturn chrono::duration<double>(pre - s).count();\n\t\t}\n\t}\n\n\tvoid out()\
    \ {\n\t\tcout << now() << \" sec\" << endl;\n\t}\n};\nTimer tim;\n/*\n@brief Timer\n\
    */\n"
  code: "struct Timer {\n\tchrono::system_clock::time_point s;\n\tchrono::system_clock::time_point\
    \ pre;\n\tbool active = false;\n\n\tTimer(){active = false;}\n\n\tvoid start()\
    \ {\n\t\tassert(!active);\n\t\tactive = true;\n\t\ts = chrono::system_clock::now();\n\
    \t}\n\n\tvoid stop() {\n\t\tpre = chrono::system_clock::now();\n\t\tassert(active);\n\
    \t\tactive = false;\n\t}\n\n\tvoid restart() {//non_active\u306E\u6642\u9593\u5206\
    \u3001\u59CB\u70B9\u3092\u305A\u3089\u3059\n\t    assert(!active);\n\t\tactive\
    \ = true;\n\t\ts += chrono::system_clock::now() - pre;\n\t}\n\n\n\tdouble now()\
    \ {\n\t\tif(active) {\n\t\t    chrono::system_clock::time_point t = chrono::system_clock::now();\n\
    \t\t    return chrono::duration<double>(t - s).count();\n\t\t}\n\t\telse {\n\t\
    \t\treturn chrono::duration<double>(pre - s).count();\n\t\t}\n\t}\n\n\tvoid out()\
    \ {\n\t\tcout << now() << \" sec\" << endl;\n\t}\n};\nTimer tim;\n/*\n@brief Timer\n\
    */"
  dependsOn: []
  isVerificationFile: false
  path: Utilities/timer.cpp
  requiredBy: []
  timestamp: '2024-05-10 23:25:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: Utilities/timer.cpp
layout: document
redirect_from:
- /library/Utilities/timer.cpp
- /library/Utilities/timer.cpp.html
title: Timer
---
