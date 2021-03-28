---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/BIT.cpp
    title: BIT(Fenwick Tree)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 2 \"datastructure/BIT.cpp\"\n#include <cassert>\n#include <vector>\n\
    \ntemplate <typename T>\nclass BIT {\nprivate:\n    int n;\n    std::vector<T>\
    \ data;\n\npublic:\n    BIT(int n = 0)\n        : n(n), data(n, 0) {\n    }\n\n\
    \    void add(int p, T x) {\n        assert(0 <= p && p < n);\n        p++;\n\
    \        while(p <= n) {\n            data[p - 1] += x;\n            p += p &\
    \ -p;\n        }\n        return;\n    }\n\n    T sum(int p) {\n        assert(0\
    \ <= p && p <= n);\n        T res = 0;\n        while(p > 0) {\n            res\
    \ += data[p - 1];\n            p -= p & -p;\n        }\n        return res;\n\
    \    }\n\n    T sum(int l, int r) {\n        assert(0 <= l && l <= r && r <= n);\n\
    \        T res = sum(r) - sum(l);\n        return res;\n    }\n};\n#line 2 \"\
    test/BIT.test.cpp\"\n#include <iostream>\n#line 4 \"test/BIT.test.cpp\"\nusing\
    \ namespace std;\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\
    \n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    vector<long long> a(n);\n\
    \    for(int i = 0; i < n; i++) cin >> a[i];\n    BIT<long long> bit(n);\n   \
    \ for(int i = 0; i < n; i++) bit.add(i, a[i]);\n    vector<long long> ans;\n \
    \   for(int i = 0; i < q; i++) {\n        int query; cin >> query;\n        if\
    \ (query == 0) {\n            int p;\n            long long x;\n            cin\
    \ >> p >> x;\n            bit.add(p, x);\n        }\n        else {\n        \
    \    int l, r; cin >> l >> r;\n            ans.push_back(bit.sum(l, r));\n   \
    \     }\n    }\n    for(int i = 0; i < (int)ans.size(); i++) {\n        cout <<\
    \ ans[i] << endl;\n    }\n}\n"
  code: "#include \"../datastructure/BIT.cpp\"\n#include <iostream>\n#include <vector>\n\
    using namespace std;\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\
    \n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    vector<long long> a(n);\n\
    \    for(int i = 0; i < n; i++) cin >> a[i];\n    BIT<long long> bit(n);\n   \
    \ for(int i = 0; i < n; i++) bit.add(i, a[i]);\n    vector<long long> ans;\n \
    \   for(int i = 0; i < q; i++) {\n        int query; cin >> query;\n        if\
    \ (query == 0) {\n            int p;\n            long long x;\n            cin\
    \ >> p >> x;\n            bit.add(p, x);\n        }\n        else {\n        \
    \    int l, r; cin >> l >> r;\n            ans.push_back(bit.sum(l, r));\n   \
    \     }\n    }\n    for(int i = 0; i < (int)ans.size(); i++) {\n        cout <<\
    \ ans[i] << endl;\n    }\n}"
  dependsOn:
  - datastructure/BIT.cpp
  isVerificationFile: true
  path: test/BIT.test.cpp
  requiredBy: []
  timestamp: '2021-03-28 14:29:57+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/BIT.test.cpp
layout: document
redirect_from:
- /verify/test/BIT.test.cpp
- /verify/test/BIT.test.cpp.html
title: test/BIT.test.cpp
---
