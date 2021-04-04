---
title: BIT(Fenwick Tree)
documentation_of: ../datastructure/BIT.cpp
---

## 概要

BIT(Binary Indexed Tree), Fenwick Tree

長さ `N` の配列について、一点更新と区間総和取得を $O(log n)$ で行うデータ構造

## 関数
* `BIT<T> bit(int n)` : 長さ $N$ の配列 $a_0, a_1, a_2, \ldots a_{n-1}$ を作る, 初期値は $0$
* `void bit.add(int p, int x)` : $a_p += x$
* `T bit.sum(int l, int r)` : $a_l + a_{l + 1} + a_{l + 2} \ldots + a_{r - 1}$ を返す

## 制約
* `add` : **$0 \leq p < n$**
* `sum` : **$0 \leq l \leq r \leq n$**

## 計算量
* `コンストラクタ` : $O(n)$
* `add, sum` : $O(log n)$