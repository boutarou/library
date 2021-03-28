---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.2/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../datastructure/UnionFind.cpp:\
    \ line -1: no such header\n"
  code: "#include <iostream>\n#include <vector>\n#include \"../datastructure/UnionFind.cpp\"\
    \nusing namespace std;\n#define rep(i, n) for(int i = 0; i < int(n); i++)\nusing\
    \ ll = long long;\nusing P = pair<int, int>;\n\n#define PROBLEM \"https://judge.yosupo.jp/problem/unionfind\"\
    \n\nint main() {\n    int n, q;\n    cin >> n >> q;\n    vector<int> t(q), u(q),\
    \ v(q);\n    rep(i, q) {\n        cin >> t[i] >> u[i] >> v[i];\n    }\n    UnionFind\
    \ uf(n);\n    rep(i, q) {\n        if (t[i] == 0) {\n            uf.unite(u[i],\
    \ v[i]);\n        }\n        else {\n            cout << (uf.same(u[i], v[i])\
    \ ? 1 : 0) << endl;\n        }\n    }\n    return 0;\n}\n"
  dependsOn: []
  isVerificationFile: true
  path: test/OnionFind.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/OnionFind.test.cpp
layout: document
redirect_from:
- /verify/test/OnionFind.test.cpp
- /verify/test/OnionFind.test.cpp.html
title: test/OnionFind.test.cpp
---
