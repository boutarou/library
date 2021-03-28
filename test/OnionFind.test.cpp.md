---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: datastructure/UnionFind.cpp
    title: datastructure/UnionFind.cpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/unionfind
    links:
    - https://judge.yosupo.jp/problem/unionfind
  bundledCode: "#line 1 \"test/OnionFind.test.cpp\"\n#include <iostream>\n#include\
    \ <vector>\n#line 2 \"datastructure/UnionFind.cpp\"\n#include <algorithm>\n#line\
    \ 4 \"datastructure/UnionFind.cpp\"\n#include <cassert>\n\nclass UnionFind {\n\
    private:\n    int n;\n    std::vector<int> par;\npublic:\n    UnionFind(int n\
    \ = 0) : n(n), par(n, -1) {}\n\n    int root(int x) {\n        assert(0 <= x &&\
    \ x < n);\n        if(par[x] < 0)\n            return x;\n        else\n     \
    \       return par[x] = root(par[x]);\n    }\n\n    bool same(int x, int y) {\n\
    \        assert(0 <= x && x < n);\n        assert(0 <= y && y < n);\n        return\
    \ root(x) == root(y);\n    }\n\n    bool unite(int x, int y) {\n        assert(0\
    \ <= x && x < n);\n        assert(0 <= y && y < n);\n        x = root(x), y =\
    \ root(y);\n        if(x == y) return false;\n        if(par[x] > par[y]) std::swap(x,\
    \ y);\n        par[x] += par[y], par[y] = x;\n        return true;\n    }\n\n\
    \    int size(int x) {\n        assert(0 <= x && x < n);\n        return -par[root(x)];\n\
    \    }\n\n    std::vector<std::vector<int>> groups() {\n        std::vector<int>\
    \ roots_num(n, -1);\n        std::vector<std::vector<int>> res;\n        int now\
    \ = 0;\n        for(int i = 0; i < n; i++) {\n            int now_root = root(i);\n\
    \            if(roots_num[now_root] == -1) {\n                roots_num[now_root]\
    \ = now;\n                now++;\n                res.push_back(std::vector<int>());\n\
    \            }\n            res[roots_num[now_root]].push_back(i);\n        }\n\
    \        return res;\n    }\n};\n#line 4 \"test/OnionFind.test.cpp\"\nusing namespace\
    \ std;\n#define rep(i, n) for(int i = 0; i < int(n); i++)\nusing ll = long long;\n\
    using P = pair<int, int>;\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    vector<int> t(q), u(q),\
    \ v(q);\n    rep(i, q) {\n        cin >> t[i] >> u[i] >> v[i];\n    }\n    UnionFind\
    \ uf(n);\n    rep(i, q) {\n        if (t[i] == 0) {\n            uf.unite(u[i],\
    \ v[i]);\n        }\n        else {\n            cout << (uf.same(u[i], v[i])\
    \ ? 1 : 0) << endl;\n        }\n    }\n    return 0;\n}\n"
  code: "#include <iostream>\n#include <vector>\n#include \"../datastructure/UnionFind.cpp\"\
    \nusing namespace std;\n#define rep(i, n) for(int i = 0; i < int(n); i++)\nusing\
    \ ll = long long;\nusing P = pair<int, int>;\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    vector<int> t(q), u(q),\
    \ v(q);\n    rep(i, q) {\n        cin >> t[i] >> u[i] >> v[i];\n    }\n    UnionFind\
    \ uf(n);\n    rep(i, q) {\n        if (t[i] == 0) {\n            uf.unite(u[i],\
    \ v[i]);\n        }\n        else {\n            cout << (uf.same(u[i], v[i])\
    \ ? 1 : 0) << endl;\n        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - datastructure/UnionFind.cpp
  isVerificationFile: true
  path: test/OnionFind.test.cpp
  requiredBy: []
  timestamp: '2021-03-28 10:31:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/OnionFind.test.cpp
layout: document
redirect_from:
- /verify/test/OnionFind.test.cpp
- /verify/test/OnionFind.test.cpp.html
title: test/OnionFind.test.cpp
---
