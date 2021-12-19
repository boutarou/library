---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/FordFulkerson.test.cpp
    title: test/FordFulkerson.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/FordFulkerson.cpp\"\n#include <vector>\n#include <limits>\n\
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
    };\n"
  code: "#pragma once\n#include <vector>\n#include <limits>\n#include <algorithm>\n\
    #include <cassert>\n\ntemplate <typename T>\nclass FordFulkerson {\npublic:\n\
    \    struct edge {\n        int to;\n        T cap;\n        int rev;\n    };\n\
    \n    int n;\n    std::vector<std::vector<edge>> g;\n    std::vector<bool> used;\n\
    \    FordFulkerson(int n = 0)\n        : n(n), g(n), used(n) {\n    }\n    void\
    \ add_edge(int from, int to, T cap) {\n        assert(0 <= from && from < n);\n\
    \        assert(0 <= to && to < n);\n        assert(0 <= cap);\n        g[from].push_back((edge){to,\
    \ cap, int(g[to].size())});\n        g[to].push_back((edge){from, 0LL, int(g[from].size()\
    \ - 1)});\n    }\n    T dfs(int v, int goal_v, T flow) {\n        if(v == goal_v)\
    \ return flow;\n        used[v] = true;\n        for(int i = 0; i < (int)g[v].size();\
    \ i++) {\n            edge &e = g[v][i];\n            if(!used[e.to] && e.cap\
    \ > 0) {\n                T next_flow = dfs(e.to, goal_v, std::min(flow, e.cap));\n\
    \                if(next_flow > 0) {\n                    e.cap -= next_flow;\n\
    \                    g[e.to][e.rev].cap += next_flow;\n                    return\
    \ next_flow;\n                }\n            }\n        }\n        return 0;\n\
    \    }\n    T max_flow(int s, int t, T ma = std::numeric_limits<T>::max()) {\n\
    \        assert(0 <= s && s < n);\n        assert(0 <= t && t < n);\n        T\
    \ flow = 0;\n        while(1) {\n            used = std::vector<bool>(n, false);\n\
    \            T f = dfs(s, t, ma);\n            if(f == 0) return flow;\n     \
    \       flow += f;\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/FordFulkerson.cpp
  requiredBy: []
  timestamp: '2021-12-19 11:01:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/FordFulkerson.test.cpp
documentation_of: graph/FordFulkerson.cpp
layout: document
title: Ford Fulkerson
---

## 概要
最大流(Ford-Fulkerson法)

## 関数
* `FordFulkerson<T> graph(int n)` コンストラクタ. `n` 頂点 `0` 辺のグラフを作る. `T` は辺容量の型
* `void graph.add_edge(int from, int to, T cap)` `from` -> `to` に容量 `cap` の辺を追加する
* `T graph.max_flow(int s, int t)` `s` -> `t` の最大流を返す

## 制約
* $0 \leq from, to < n$
* $0 \leq s, t < n$
* $0 \leq cap$

## 計算量
* `Dinic` : $\mathcal{O}(n)$
* `add_edge` $\mathcal{O}(1)$
* `max_flow` $\mathcal{O}(Fm)$ (`m` は辺数, `F` は最大流の流量) 
