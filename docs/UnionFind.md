---
title: Union Find
documentation_of: ../datastructure/UnionFind.cpp
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