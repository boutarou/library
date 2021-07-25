---
title: modint
documentation_of: ../math/modint.cpp
---

## 概要

自動でmodを取る構造体

~~~cpp
using mint = modint<MOD>;
// ex.) mod 998244353
using mint = modint<998244353>;
~~~
のようにして使う

## 関数
* `+=, -=, *=, /=, +, -, *, /` : 各種演算
* `modint x.pow(ll n)` : $x^n$ を返す
* `modint x.inv()` : $xy = 1$ なる $y$ を返す
* `int x.val()` : $x$ に格納されている値を返す

## 計算量
* `加算, 減算, 乗算, val` : \mathcal{O}(1)
* `除算, inv` : \mathcal{O}(\log MOD)
* `pow` : \mathcal{O}(\log n)