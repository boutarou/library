---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/modint.cpp
    title: modint
  _extendedRequiredBy: []
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
    \ {\n        return x;\n    }\n};\n#line 2 \"math/comb.cpp\"\n#include <vector>\n\
    #include <cassert>\n\ntemplate<long long MOD>\nclass combination {\nprivate:\n\
    \    using mint = modint<MOD>;\n    int _n;\n    std::vector<mint> fact, ifact;\n\
    public:\n    combination(int n)\n        : _n(n), fact(n + 1), ifact(n + 1) {\n\
    \        assert(n < MOD);\n        fact[0] = 1;\n        for(int i = 1; i <= n;\
    \ i++) fact[i] = fact[i - 1] * i;\n        ifact[n] = fact[n].inv();\n       \
    \ for(int i = n; i >= 1; i--) ifact[i - 1] = ifact[i] * i;\n    }\n    mint operator()(int\
    \ n, int k) {\n        assert(0 <= n && n <= _n);\n        if(k < 0 || k > n)\
    \ return 0;\n        return fact[n] * ifact[k] * ifact[n - k];\n    }\n};\n\n\
    template<long long MOD>\nclass permutation {\nprivate:\n    using mint = modint<MOD>;\n\
    \    int _n;\n    std::vector<mint> fact, ifact;\npublic:\n    permutation(int\
    \ n)\n        : _n(n), fact(n + 1), ifact(n + 1) {\n        assert(n < MOD);\n\
    \        fact[0] = 1;\n        for(int i = 1; i <= n; i++) fact[i] = fact[i -\
    \ 1] * i;\n        ifact[n] = fact[n].inv();\n        for(int i = n; i >= 1; i--)\
    \ ifact[i - 1] = ifact[i] * i;\n    }\n    mint operator()(int n, int k) {\n \
    \       assert(0 <= n && n <= _n);\n        if(k < 0 || k > n) return 0;\n   \
    \     return fact[n] * ifact[n - k];\n    }\n};\n"
  code: "#include \"modint.cpp\"\n#include <vector>\n#include <cassert>\n\ntemplate<long\
    \ long MOD>\nclass combination {\nprivate:\n    using mint = modint<MOD>;\n  \
    \  int _n;\n    std::vector<mint> fact, ifact;\npublic:\n    combination(int n)\n\
    \        : _n(n), fact(n + 1), ifact(n + 1) {\n        assert(n < MOD);\n    \
    \    fact[0] = 1;\n        for(int i = 1; i <= n; i++) fact[i] = fact[i - 1] *\
    \ i;\n        ifact[n] = fact[n].inv();\n        for(int i = n; i >= 1; i--) ifact[i\
    \ - 1] = ifact[i] * i;\n    }\n    mint operator()(int n, int k) {\n        assert(0\
    \ <= n && n <= _n);\n        if(k < 0 || k > n) return 0;\n        return fact[n]\
    \ * ifact[k] * ifact[n - k];\n    }\n};\n\ntemplate<long long MOD>\nclass permutation\
    \ {\nprivate:\n    using mint = modint<MOD>;\n    int _n;\n    std::vector<mint>\
    \ fact, ifact;\npublic:\n    permutation(int n)\n        : _n(n), fact(n + 1),\
    \ ifact(n + 1) {\n        assert(n < MOD);\n        fact[0] = 1;\n        for(int\
    \ i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;\n        ifact[n] = fact[n].inv();\n\
    \        for(int i = n; i >= 1; i--) ifact[i - 1] = ifact[i] * i;\n    }\n   \
    \ mint operator()(int n, int k) {\n        assert(0 <= n && n <= _n);\n      \
    \  if(k < 0 || k > n) return 0;\n        return fact[n] * ifact[n - k];\n    }\n\
    };\n"
  dependsOn:
  - math/modint.cpp
  isVerificationFile: false
  path: math/comb.cpp
  requiredBy: []
  timestamp: '2021-04-04 15:55:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/comb.test.cpp
documentation_of: math/comb.cpp
layout: document
title: combination
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
* `コンストラクタ` : $\mathcal{O}(n)$
* `operator()` : $\mathcal{O}(1)$