---
title: combination
documentation_of: ../math/comb.cpp
---

## 概要

combination, permutationをMODで割った余りを返す

## 関数
* `combination<ll MOD> comb(int n), pemutation<MOD> perm(int n)` : コンストラクタ
* `operator() comb(int x, int y), perm(int x, int y)` : xCy, xPyをMODで割った余りを返す
* $y < 0$ または $y > x$ のときは $0$ を返す

## 制約
* $n < MOD$
* $0 \leq x \leq n$

## 計算量
* `コンストラクタ` : \mathcal{O}(n)
* `operator()` : \mathcal{O}(1)