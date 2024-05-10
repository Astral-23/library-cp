---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: ': SWAG'
    links: []
  bundledCode: "#line 1 \"DetaStructures/SWAG.cpp\"\ntemplate<typename T>\nstruct\
    \ SWAG {\n    struct foldable_stack {\n        stack<T> data;\n        stack<T>\
    \ res;\n        foldable_stack(){}\n\n        void push(T a, int type) {//type\
    \ == 1 : \u914D\u5217\u306E\u53F3\u306B\u8FFD\u52A0\u3001\u3064\u307E\u308AR \
    \ type == 0 : \u914D\u5217\u306E\u5DE6\u306B\u8FFD\u52A0\u3001\u3064\u307E\u308A\
    L  \u306A\u305C\u3053\u3093\u306A\u4E8B : \u4EA4\u63DB\u6CD5\u5247\n         \
    \   data.push(a);\n            if(!res.empty()) {\n               if(type == 0)\
    \ res.push(op(a, res.top()));//res\u304C\u7A7A\u306A\u3089\u305D\u308C\u3092\u5165\
    \u308C\u308B\n               else res.push(op(res.top(), a));\n            }\n\
    \            else res.push(a);\n            return;\n        }\n\n        void\
    \ pop() {\n            assert(!data.empty());\n            data.pop();\n     \
    \       res.pop();\n            return;\n        }\n\n        T top() const {\n\
    \            assert(!data.empty());\n            return data.top(); \n       \
    \ }\n\n        T get() const { \n            assert(!data.empty());\n        \
    \    return res.top(); \n        }\n\n        bool empty() {return data.empty();}\n\
    \        size_t size() {return data.size();}\n    };\n\n    \n    SWAG() {}\n\
    \    foldable_stack L, R;\n    private:\n\n      void move(foldable_stack& s,\
    \ foldable_stack& t, int type) {//s\u306E\u8981\u7D20\u3092\u534A\u5206t\u306E\
    \u8981\u7D20\u306B\u79FB\u3059 type == 0 : s = L, t = R  type == 1 s = R, t =\
    \ L\n        assert(t.empty());\n        int oth = 1 - type;\n        stack<T>\
    \ tmp;\n        while(int(s.size()) - int(tmp.size()) > 1) tmp.push(s.top()),\
    \ s.pop();//R\u306E\u5F8C\u534A\u534A\u5206\u3092\u53D6\u308A\u51FA\u3059\n  \
    \      while(!s.empty()) t.push(s.top(), oth), s.pop(); //R\u306E\u524D\u534A\u3092\
    L\u306B\u8A70\u3081\u308B\n        while(!tmp.empty()) s.push(tmp.top(), type),\
    \ tmp.pop(); \n      }\n    \n    public:\n      void push_front(T a) {\n    \
    \      L.push(a, 0);\n      }\n  \n      void push_back(T a) {\n          R.push(a,\
    \ 1);\n      }\n  \n      void pop_front() {\n          assert(!L.empty() || !R.empty());\n\
    \          if(L.empty()) move(R, L, 1);\n          L.pop();\n      }\n  \n   \
    \   void pop_back() {\n          assert(!L.empty() || !R.empty());\n         \
    \ if(R.empty()) move(L, R, 0);\n          R.pop();\n      }\n  \n      T front()\
    \ const {\n        assert(!L.empty() || !R.empty());\n        if(L.empty())move(R,\
    \ L, 1);\n        return L.top();\n      }\n\n      \n      T back() const {\n\
    \        assert(!L.empty() || !R.empty());\n        if(R.empty())move(L, R, 0);\n\
    \        return R.top();\n      }\n\n      T get()  {\n        assert(!L.empty()\
    \ || !R.empty());\n        //if(L.empty() && R.empty()) return T::ide();  //\u7A7A\
    \u3067\u3082\u5358\u4F4D\u5143\u3092\u8FD4\u3057\u3066\u6B32\u3057\u3044\u6642\
    \u30B3\u30E1\u30F3\u30C8\u30A2\u30A6\u30C8\u3092\u6D88\u3057\u3001\u4E0A\u306E\
    \u884C\u3092\u6D88\u3059\u3002\n        if(L.empty()) return R.get();\n      \
    \  if(R.empty()) return L.get();\n        return op(L.get(), R.get());\n     \
    \ }\n};\n\n\nstruct Monoid {\n    //\u3053\u306E\u8FBA\u306E\u30B9\u30DA\u30FC\
    \u30B9\u306B\u4E2D\u8EAB\u3092\u66F8\u304F\n    ll a;\n    \n\t\n\tMonoid(ll _a)\
    \ : a(_a) {}\n\n    friend Monoid op(const Monoid& l, const  Monoid& r) {\n  \
    \      return l;\n    } \n\n\tstatic Monoid ide() {\n\t\treturn 0LL;\n\t}\n};\n\
    \n/*\n@brief : SWAG\n\n*/\n"
  code: "template<typename T>\nstruct SWAG {\n    struct foldable_stack {\n      \
    \  stack<T> data;\n        stack<T> res;\n        foldable_stack(){}\n\n     \
    \   void push(T a, int type) {//type == 1 : \u914D\u5217\u306E\u53F3\u306B\u8FFD\
    \u52A0\u3001\u3064\u307E\u308AR  type == 0 : \u914D\u5217\u306E\u5DE6\u306B\u8FFD\
    \u52A0\u3001\u3064\u307E\u308AL  \u306A\u305C\u3053\u3093\u306A\u4E8B : \u4EA4\
    \u63DB\u6CD5\u5247\n            data.push(a);\n            if(!res.empty()) {\n\
    \               if(type == 0) res.push(op(a, res.top()));//res\u304C\u7A7A\u306A\
    \u3089\u305D\u308C\u3092\u5165\u308C\u308B\n               else res.push(op(res.top(),\
    \ a));\n            }\n            else res.push(a);\n            return;\n  \
    \      }\n\n        void pop() {\n            assert(!data.empty());\n       \
    \     data.pop();\n            res.pop();\n            return;\n        }\n\n\
    \        T top() const {\n            assert(!data.empty());\n            return\
    \ data.top(); \n        }\n\n        T get() const { \n            assert(!data.empty());\n\
    \            return res.top(); \n        }\n\n        bool empty() {return data.empty();}\n\
    \        size_t size() {return data.size();}\n    };\n\n    \n    SWAG() {}\n\
    \    foldable_stack L, R;\n    private:\n\n      void move(foldable_stack& s,\
    \ foldable_stack& t, int type) {//s\u306E\u8981\u7D20\u3092\u534A\u5206t\u306E\
    \u8981\u7D20\u306B\u79FB\u3059 type == 0 : s = L, t = R  type == 1 s = R, t =\
    \ L\n        assert(t.empty());\n        int oth = 1 - type;\n        stack<T>\
    \ tmp;\n        while(int(s.size()) - int(tmp.size()) > 1) tmp.push(s.top()),\
    \ s.pop();//R\u306E\u5F8C\u534A\u534A\u5206\u3092\u53D6\u308A\u51FA\u3059\n  \
    \      while(!s.empty()) t.push(s.top(), oth), s.pop(); //R\u306E\u524D\u534A\u3092\
    L\u306B\u8A70\u3081\u308B\n        while(!tmp.empty()) s.push(tmp.top(), type),\
    \ tmp.pop(); \n      }\n    \n    public:\n      void push_front(T a) {\n    \
    \      L.push(a, 0);\n      }\n  \n      void push_back(T a) {\n          R.push(a,\
    \ 1);\n      }\n  \n      void pop_front() {\n          assert(!L.empty() || !R.empty());\n\
    \          if(L.empty()) move(R, L, 1);\n          L.pop();\n      }\n  \n   \
    \   void pop_back() {\n          assert(!L.empty() || !R.empty());\n         \
    \ if(R.empty()) move(L, R, 0);\n          R.pop();\n      }\n  \n      T front()\
    \ const {\n        assert(!L.empty() || !R.empty());\n        if(L.empty())move(R,\
    \ L, 1);\n        return L.top();\n      }\n\n      \n      T back() const {\n\
    \        assert(!L.empty() || !R.empty());\n        if(R.empty())move(L, R, 0);\n\
    \        return R.top();\n      }\n\n      T get()  {\n        assert(!L.empty()\
    \ || !R.empty());\n        //if(L.empty() && R.empty()) return T::ide();  //\u7A7A\
    \u3067\u3082\u5358\u4F4D\u5143\u3092\u8FD4\u3057\u3066\u6B32\u3057\u3044\u6642\
    \u30B3\u30E1\u30F3\u30C8\u30A2\u30A6\u30C8\u3092\u6D88\u3057\u3001\u4E0A\u306E\
    \u884C\u3092\u6D88\u3059\u3002\n        if(L.empty()) return R.get();\n      \
    \  if(R.empty()) return L.get();\n        return op(L.get(), R.get());\n     \
    \ }\n};\n\n\nstruct Monoid {\n    //\u3053\u306E\u8FBA\u306E\u30B9\u30DA\u30FC\
    \u30B9\u306B\u4E2D\u8EAB\u3092\u66F8\u304F\n    ll a;\n    \n\t\n\tMonoid(ll _a)\
    \ : a(_a) {}\n\n    friend Monoid op(const Monoid& l, const  Monoid& r) {\n  \
    \      return l;\n    } \n\n\tstatic Monoid ide() {\n\t\treturn 0LL;\n\t}\n};\n\
    \n/*\n@brief : SWAG\n\n*/"
  dependsOn: []
  isVerificationFile: false
  path: DetaStructures/SWAG.cpp
  requiredBy: []
  timestamp: '2024-05-10 22:34:07+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: DetaStructures/SWAG.cpp
layout: document
redirect_from:
- /library/DetaStructures/SWAG.cpp
- /library/DetaStructures/SWAG.cpp.html
title: ': SWAG'
---
