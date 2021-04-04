---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/comb.cpp
    title: combination
  - icon: ':heavy_check_mark:'
    path: math/modint.cpp
    title: modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_E
  bundledCode: "#line 1 \"test/comb.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_E\"\
    \n#line 1 \"math/modint.cpp\"\ntemplate <long long MOD>\nclass modint {\nprivate:\n\
    \    long long x;\n\npublic:\n    modint(long long x = 0)\n        : x((x % MOD\
    \ + MOD) % MOD) {\n    }\n    modint operator-() const {\n        return modint(-x);\n\
    \    }\n    modint &operator+=(const modint a) {\n        if((x += a.x) >= MOD)\
    \ x -= MOD;\n        return *this;\n    }\n    modint &operator-=(const modint\
    \ a) {\n        if((x += MOD - a.x) >= MOD) x -= MOD;\n        return *this;\n\
    \    }\n    modint &operator*=(const modint a) {\n        (x *= a.x) %= MOD;\n\
    \        return *this;\n    }\n    modint &operator/=(const modint a) {\n    \
    \    return *this *= a.inv();\n    }\n    modint operator+(const modint a) const\
    \ {\n        return modint(*this) += a;\n    }\n    modint operator-(const modint\
    \ a) const {\n        return modint(*this) -= a;\n    }\n    modint operator*(const\
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
    \     return fact[n] * ifact[n - k];\n    }\n};\n#line 3 \"test/comb.test.cpp\"\
    \n#include <iostream>\nusing namespace std;\n\nconst long long MOD = 1e9 + 7;\n\
    \nint main() {\n    int n, k;\n    cin >> n >> k;\n    combination<MOD> comb(1e6);\n\
    \    cout << comb(k, n).val() << endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_E\"\
    \n#include \"../math/comb.cpp\"\n#include <iostream>\nusing namespace std;\n\n\
    const long long MOD = 1e9 + 7;\n\nint main() {\n    int n, k;\n    cin >> n >>\
    \ k;\n    combination<MOD> comb(1e6);\n    cout << comb(k, n).val() << endl;\n\
    }"
  dependsOn:
  - math/comb.cpp
  - math/modint.cpp
  isVerificationFile: true
  path: test/comb.test.cpp
  requiredBy: []
  timestamp: '2021-04-04 15:55:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/comb.test.cpp
layout: document
redirect_from:
- /verify/test/comb.test.cpp
- /verify/test/comb.test.cpp.html
title: test/comb.test.cpp
---
