---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/FordFulkerson.cpp
    title: Ford Fulkerson
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
  bundledCode: "#line 1 \"test/FordFulkerson.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\
    \n#line 2 \"graph/FordFulkerson.cpp\"\n#include <vector>\n#include <limits>\n\
    #include <algorithm>\n#include <cassert>\n\ntemplate <typename T>\nclass FordFulkerson\
    \ {\npublic:\n    struct edge {\n        int to;\n        T cap;\n        int\
    \ rev;\n    };\n\n    int n;\n    std::vector<std::vector<edge>> g;\n    std::vector<bool>\
    \ used;\n    FordFulkerson(int n = 0)\n        : n(n), g(n), used(n) {\n    }\n\
    \    void add_edge(int from, int to, T cap) {\n        assert(0 <= from && from\
    \ < n);\n        assert(0 <= to && to < n);\n        assert(0 <= cap);\n     \
    \   g[from].push_back((edge){to, cap, int(g[to].size())});\n        g[to].push_back((edge){from,\
    \ 0LL, int(g[from].size() - 1)});\n    }\n    T dfs(int v, int goal_v, T flow)\
    \ {\n        if(v == goal_v) return flow;\n        used[v] = true;\n        for(int\
    \ i = 0; i < (int)g[v].size(); i++) {\n            edge &e = g[v][i];\n      \
    \      if(!used[e.to] && e.cap > 0) {\n                T next_flow = dfs(e.to,\
    \ goal_v, std::min(flow, e.cap));\n                if(next_flow > 0) {\n     \
    \               e.cap -= next_flow;\n                    g[e.to][e.rev].cap +=\
    \ next_flow;\n                    return next_flow;\n                }\n     \
    \       }\n        }\n        return 0;\n    }\n    T max_flow(int s, int t, T\
    \ ma = std::numeric_limits<T>::max()) {\n        assert(0 <= s && s < n);\n  \
    \      assert(0 <= t && t < n);\n        T flow = 0;\n        while(1) {\n   \
    \         used = std::vector<bool>(n, false);\n            T f = dfs(s, t, ma);\n\
    \            if(f == 0) return flow;\n            flow += f;\n        }\n    }\n\
    };\n#line 3 \"test/FordFulkerson.test.cpp\"\n#include <iostream>\n#line 5 \"test/FordFulkerson.test.cpp\"\
    \n\nint main() {\n    int V, E;\n    std::cin >> V >> E;\n    FordFulkerson<int>\
    \ graph(V);\n    for(int i = 0; i < E; i++) {\n        int u, v, c;\n        std::cin\
    \ >> u >> v >> c;\n        graph.add_edge(u, v, c);\n    }\n    std::cout << graph.max_flow(0,\
    \ V - 1) << std::endl;\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\
    \n#include \"../graph/FordFulkerson.cpp\"\n#include <iostream>\n#include <vector>\n\
    \nint main() {\n    int V, E;\n    std::cin >> V >> E;\n    FordFulkerson<int>\
    \ graph(V);\n    for(int i = 0; i < E; i++) {\n        int u, v, c;\n        std::cin\
    \ >> u >> v >> c;\n        graph.add_edge(u, v, c);\n    }\n    std::cout << graph.max_flow(0,\
    \ V - 1) << std::endl;\n    return 0;\n}"
  dependsOn:
  - graph/FordFulkerson.cpp
  isVerificationFile: true
  path: test/FordFulkerson.test.cpp
  requiredBy: []
  timestamp: '2021-12-19 11:01:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/FordFulkerson.test.cpp
layout: document
redirect_from:
- /verify/test/FordFulkerson.test.cpp
- /verify/test/FordFulkerson.test.cpp.html
title: test/FordFulkerson.test.cpp
---
