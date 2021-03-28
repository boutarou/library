---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/unionfind.test.cpp
    title: test/unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/unionfind.cpp\"\n#include <algorithm>\n#include\
    \ <vector>\n#include <cassert>\n\nclass UnionFind {\nprivate:\n    int n;\n  \
    \  std::vector<int> par;\npublic:\n    UnionFind(int n = 0) : n(n), par(n, -1)\
    \ {}\n\n    int root(int x) {\n        assert(0 <= x && x < n);\n        if(par[x]\
    \ < 0)\n            return x;\n        else\n            return par[x] = root(par[x]);\n\
    \    }\n\n    bool same(int x, int y) {\n        assert(0 <= x && x < n);\n  \
    \      assert(0 <= y && y < n);\n        return root(x) == root(y);\n    }\n\n\
    \    bool unite(int x, int y) {\n        assert(0 <= x && x < n);\n        assert(0\
    \ <= y && y < n);\n        x = root(x), y = root(y);\n        if(x == y) return\
    \ false;\n        if(par[x] > par[y]) std::swap(x, y);\n        par[x] += par[y],\
    \ par[y] = x;\n        return true;\n    }\n\n    int size(int x) {\n        assert(0\
    \ <= x && x < n);\n        return -par[root(x)];\n    }\n\n    std::vector<std::vector<int>>\
    \ groups() {\n        std::vector<int> roots_num(n, -1);\n        std::vector<std::vector<int>>\
    \ res;\n        int now = 0;\n        for(int i = 0; i < n; i++) {\n         \
    \   int now_root = root(i);\n            if(roots_num[now_root] == -1) {\n   \
    \             roots_num[now_root] = now;\n                now++;\n           \
    \     res.push_back(std::vector<int>());\n            }\n            res[roots_num[now_root]].push_back(i);\n\
    \        }\n        return res;\n    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <vector>\n#include <cassert>\n\
    \nclass UnionFind {\nprivate:\n    int n;\n    std::vector<int> par;\npublic:\n\
    \    UnionFind(int n = 0) : n(n), par(n, -1) {}\n\n    int root(int x) {\n   \
    \     assert(0 <= x && x < n);\n        if(par[x] < 0)\n            return x;\n\
    \        else\n            return par[x] = root(par[x]);\n    }\n\n    bool same(int\
    \ x, int y) {\n        assert(0 <= x && x < n);\n        assert(0 <= y && y <\
    \ n);\n        return root(x) == root(y);\n    }\n\n    bool unite(int x, int\
    \ y) {\n        assert(0 <= x && x < n);\n        assert(0 <= y && y < n);\n \
    \       x = root(x), y = root(y);\n        if(x == y) return false;\n        if(par[x]\
    \ > par[y]) std::swap(x, y);\n        par[x] += par[y], par[y] = x;\n        return\
    \ true;\n    }\n\n    int size(int x) {\n        assert(0 <= x && x < n);\n  \
    \      return -par[root(x)];\n    }\n\n    std::vector<std::vector<int>> groups()\
    \ {\n        std::vector<int> roots_num(n, -1);\n        std::vector<std::vector<int>>\
    \ res;\n        int now = 0;\n        for(int i = 0; i < n; i++) {\n         \
    \   int now_root = root(i);\n            if(roots_num[now_root] == -1) {\n   \
    \             roots_num[now_root] = now;\n                now++;\n           \
    \     res.push_back(std::vector<int>());\n            }\n            res[roots_num[now_root]].push_back(i);\n\
    \        }\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/unionfind.cpp
  requiredBy: []
  timestamp: '2021-03-28 10:14:29+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/unionfind.test.cpp
documentation_of: datastructure/unionfind.cpp
layout: document
redirect_from:
- /library/datastructure/unionfind.cpp
- /library/datastructure/unionfind.cpp.html
title: datastructure/unionfind.cpp
---