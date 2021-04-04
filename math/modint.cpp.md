---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/comb.cpp
    title: combination
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/comb.test.cpp
    title: test/comb.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"math/modint.cpp\"\ntemplate <long long MOD>\nclass modint\
    \ {\nprivate:\n    long long x;\n\npublic:\n    modint(long long x = 0)\n    \
    \    : x((x % MOD + MOD) % MOD) {\n    }\n    modint operator-() const {\n   \
    \     return modint(-x);\n    }\n    modint &operator+=(const modint a) {\n  \
    \      if((x += a.x) >= MOD) x -= MOD;\n        return *this;\n    }\n    modint\
    \ &operator-=(const modint a) {\n        if((x += MOD - a.x) >= MOD) x -= MOD;\n\
    \        return *this;\n    }\n    modint &operator*=(const modint a) {\n    \
    \    (x *= a.x) %= MOD;\n        return *this;\n    }\n    modint &operator/=(const\
    \ modint a) {\n        return *this *= a.inv();\n    }\n    modint operator+(const\
    \ modint a) const {\n        return modint(*this) += a;\n    }\n    modint operator-(const\
    \ modint a) const {\n        return modint(*this) -= a;\n    }\n    modint operator*(const\
    \ modint a) const {\n        return modint(*this) *= a;\n    }\n    modint operator/(const\
    \ modint a) const {\n        return modint(*this) /= a;\n    }\n    modint pow(long\
    \ long t) const {\n        if(!t) return 1;\n        modint a = pow(t >> 1);\n\
    \        a *= a;\n        if(t & 1) a *= *this;\n        return a;\n    }\n  \
    \  modint inv() const {\n        return pow(MOD - 2);\n    }\n    int val() const\
    \ {\n        return x;\n    }\n};\n"
  code: "template <long long MOD>\nclass modint {\nprivate:\n    long long x;\n\n\
    public:\n    modint(long long x = 0)\n        : x((x % MOD + MOD) % MOD) {\n \
    \   }\n    modint operator-() const {\n        return modint(-x);\n    }\n   \
    \ modint &operator+=(const modint a) {\n        if((x += a.x) >= MOD) x -= MOD;\n\
    \        return *this;\n    }\n    modint &operator-=(const modint a) {\n    \
    \    if((x += MOD - a.x) >= MOD) x -= MOD;\n        return *this;\n    }\n   \
    \ modint &operator*=(const modint a) {\n        (x *= a.x) %= MOD;\n        return\
    \ *this;\n    }\n    modint &operator/=(const modint a) {\n        return *this\
    \ *= a.inv();\n    }\n    modint operator+(const modint a) const {\n        return\
    \ modint(*this) += a;\n    }\n    modint operator-(const modint a) const {\n \
    \       return modint(*this) -= a;\n    }\n    modint operator*(const modint a)\
    \ const {\n        return modint(*this) *= a;\n    }\n    modint operator/(const\
    \ modint a) const {\n        return modint(*this) /= a;\n    }\n    modint pow(long\
    \ long t) const {\n        if(!t) return 1;\n        modint a = pow(t >> 1);\n\
    \        a *= a;\n        if(t & 1) a *= *this;\n        return a;\n    }\n  \
    \  modint inv() const {\n        return pow(MOD - 2);\n    }\n    int val() const\
    \ {\n        return x;\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/modint.cpp
  requiredBy:
  - math/comb.cpp
  timestamp: '2021-04-04 15:55:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/comb.test.cpp
documentation_of: math/modint.cpp
layout: document
title: modint
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
* `加算, 減算, 乗算, val` : $O(1)$
* `除算, inv` : $O(log MOD)$
* `pow` : $O(log n)$