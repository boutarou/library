---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/UnionFind.test.cpp
    title: test/UnionFind.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/UnionFind.md
    document_title: Union Find
    links: []
  bundledCode: "#line 2 \"datastructure/UnionFind.cpp\"\n#include <algorithm>\n#include\
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
    \        }\n        return res;\n    }\n};\n\n/*\n@brief Union Find\n@docs docs/UnionFind.md\n\
    */\n"
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
    \        }\n        return res;\n    }\n};\n\n/*\n@brief Union Find\n@docs docs/UnionFind.md\n\
    */\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/UnionFind.cpp
  requiredBy: []
  timestamp: '2021-03-28 11:59:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/UnionFind.test.cpp
documentation_of: datastructure/UnionFind.cpp
layout: document
title: Union Find
---

## 概要

素集合データ構造(acl参考)

集合のマージ、同じ集合に属するかの判定などを行う

## 関数
* `UnionFind(int n)` : それぞれの要素数が `1` の `n` 個の集合を作る.
* `int root(int x)` : `x` が属する集合の代表を返す.
* `bool same(int x, int y)` : `x` と `y` が同じ集合に属するかを返す.
* `bool unite(int x, int y)` : `x` が属する集合と `y` が属する集合をマージする.  返り値は `x` と `y` が違う集合に属していたときに `true`.
* `int size(int x)` : `x` が属する集合の要素数を返す.
* `vector<vector<int>> groups()` : 「それぞれの集合の要素のリスト」のリストを返す.

## 制約
* $0 \leq x, y < n$

## 計算量
* `UnionFind, groups` : $O(n)$
* `size` : $O(1)$
* `others` : ならし $O(\alpha(n))$