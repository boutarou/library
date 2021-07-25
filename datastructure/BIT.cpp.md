---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/BIT.test.cpp
    title: test/BIT.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/BIT.cpp\"\n#include <cassert>\n#include <vector>\n\
    \ntemplate <typename T>\nclass BIT {\nprivate:\n    int n;\n    std::vector<T>\
    \ data;\n\npublic:\n    BIT(int n = 0)\n        : n(n), data(n, 0) {\n    }\n\n\
    \    void add(int p, T x) {\n        assert(0 <= p && p < n);\n        p++;\n\
    \        while(p <= n) {\n            data[p - 1] += x;\n            p += p &\
    \ -p;\n        }\n        return;\n    }\n\n    T sum(int p) {\n        assert(0\
    \ <= p && p <= n);\n        T res = 0;\n        while(p > 0) {\n            res\
    \ += data[p - 1];\n            p -= p & -p;\n        }\n        return res;\n\
    \    }\n\n    T sum(int l, int r) {\n        assert(0 <= l && l <= r && r <= n);\n\
    \        T res = sum(r) - sum(l);\n        return res;\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\ntemplate <typename\
    \ T>\nclass BIT {\nprivate:\n    int n;\n    std::vector<T> data;\n\npublic:\n\
    \    BIT(int n = 0)\n        : n(n), data(n, 0) {\n    }\n\n    void add(int p,\
    \ T x) {\n        assert(0 <= p && p < n);\n        p++;\n        while(p <= n)\
    \ {\n            data[p - 1] += x;\n            p += p & -p;\n        }\n    \
    \    return;\n    }\n\n    T sum(int p) {\n        assert(0 <= p && p <= n);\n\
    \        T res = 0;\n        while(p > 0) {\n            res += data[p - 1];\n\
    \            p -= p & -p;\n        }\n        return res;\n    }\n\n    T sum(int\
    \ l, int r) {\n        assert(0 <= l && l <= r && r <= n);\n        T res = sum(r)\
    \ - sum(l);\n        return res;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/BIT.cpp
  requiredBy: []
  timestamp: '2021-03-28 14:29:57+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/BIT.test.cpp
documentation_of: datastructure/BIT.cpp
layout: document
title: BIT(Fenwick Tree)
---

## 概要

BIT(Binary Indexed Tree), Fenwick Tree

長さ `N` の配列について、一点更新と区間総和取得を \mathcal{O}(\log n) で行うデータ構造

## 関数
* `BIT<T> bit(int n)` : 長さ $N$ の配列 $a_0, a_1, a_2, \ldots a_{n-1}$ を作る, 初期値は $0$
* `void bit.add(int p, int x)` : $a_p += x$
* `T bit.sum(int l, int r)` : $a_l + a_{l + 1} + a_{l + 2} \ldots + a_{r - 1}$ を返す

## 制約
* `add` : **$0 \leq p < n$**
* `sum` : **$0 \leq l \leq r \leq n$**

## 計算量
* `コンストラクタ` : \mathcal{O}(n)
* `add, sum` : \mathcal{O}(\log n)$