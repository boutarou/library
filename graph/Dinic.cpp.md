---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/Dinic.test.cpp
    title: test/Dinic.test.cpp
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/Dinic.cpp\"\n#include <vector>\n#include <queue>\n\
    #include <limits>\n#include <algorithm>\n#include <cassert>\n\ntemplate <typename\
    \ T>\nclass Dinic {\npublic:\n    struct edge {\n        int to;\n        T cap;\n\
    \        int rev;\n    };\n\n    int n;\n    std::vector<std::vector<edge>> g;\n\
    \    std::vector<int> level;\n    std::vector<int> iter;\n    Dinic(int n = 0)\n\
    \        : n(n), g(n), level(n), iter(n) {\n    }\n    void add_edge(int from,\
    \ int to, T cap) {\n        assert(0 <= from && from < n);\n        assert(0 <=\
    \ to && to < n);\n        assert(0 <= cap);\n        g[from].push_back((edge){to,\
    \ cap, int(g[to].size())});\n        g[to].push_back((edge){from, 0LL, int(g[from].size()\
    \ - 1)});\n    }\n    void bfs(int s) {\n        level = std::vector<int>(n, -1);\n\
    \        std::queue<int> que;\n        level[s] = 0;\n        que.push(s);\n \
    \       while(!que.empty()) {\n            int v = que.front();\n            que.pop();\n\
    \            for(int i = 0; i < (int)g[v].size(); i++) {\n                edge\
    \ &e = g[v][i];\n                if(e.cap > 0 && level[e.to] < 0) {\n        \
    \            level[e.to] = level[v] + 1;\n                    que.push(e.to);\n\
    \                }\n            }\n        }\n    }\n    T dfs(int v, int t, T\
    \ f) {\n        if(v == t) return f;\n        for(int &i = iter[v]; i < (int)g[v].size();\
    \ i++) {\n            edge &e = g[v][i];\n            if(e.cap > 0 && level[v]\
    \ < level[e.to]) {\n                T d = dfs(e.to, t, std::min(f, e.cap));\n\
    \                if(d > 0) {\n                    e.cap -= d;\n              \
    \      g[e.to][e.rev].cap += d;\n                    return d;\n             \
    \   }\n            }\n        }\n        return 0;\n    }\n    T max_flow(int\
    \ s, int t) {\n        assert(0 <= s && s < n);\n        assert(0 <= t && t <\
    \ n);\n        T flow = 0;\n        while(1) {\n            bfs(s);\n        \
    \    if(level[t] < 0) return flow;\n            iter = std::vector<int>(n, 0);\n\
    \            T f;\n            while((f = dfs(s, t, std::numeric_limits<T>::max()))\
    \ > 0) {\n                flow += f;\n            }\n        }\n    }\n};\n"
  code: "#pragma once\n#include <vector>\n#include <queue>\n#include <limits>\n#include\
    \ <algorithm>\n#include <cassert>\n\ntemplate <typename T>\nclass Dinic {\npublic:\n\
    \    struct edge {\n        int to;\n        T cap;\n        int rev;\n    };\n\
    \n    int n;\n    std::vector<std::vector<edge>> g;\n    std::vector<int> level;\n\
    \    std::vector<int> iter;\n    Dinic(int n = 0)\n        : n(n), g(n), level(n),\
    \ iter(n) {\n    }\n    void add_edge(int from, int to, T cap) {\n        assert(0\
    \ <= from && from < n);\n        assert(0 <= to && to < n);\n        assert(0\
    \ <= cap);\n        g[from].push_back((edge){to, cap, int(g[to].size())});\n \
    \       g[to].push_back((edge){from, 0LL, int(g[from].size() - 1)});\n    }\n\
    \    void bfs(int s) {\n        level = std::vector<int>(n, -1);\n        std::queue<int>\
    \ que;\n        level[s] = 0;\n        que.push(s);\n        while(!que.empty())\
    \ {\n            int v = que.front();\n            que.pop();\n            for(int\
    \ i = 0; i < (int)g[v].size(); i++) {\n                edge &e = g[v][i];\n  \
    \              if(e.cap > 0 && level[e.to] < 0) {\n                    level[e.to]\
    \ = level[v] + 1;\n                    que.push(e.to);\n                }\n  \
    \          }\n        }\n    }\n    T dfs(int v, int t, T f) {\n        if(v ==\
    \ t) return f;\n        for(int &i = iter[v]; i < (int)g[v].size(); i++) {\n \
    \           edge &e = g[v][i];\n            if(e.cap > 0 && level[v] < level[e.to])\
    \ {\n                T d = dfs(e.to, t, std::min(f, e.cap));\n               \
    \ if(d > 0) {\n                    e.cap -= d;\n                    g[e.to][e.rev].cap\
    \ += d;\n                    return d;\n                }\n            }\n   \
    \     }\n        return 0;\n    }\n    T max_flow(int s, int t) {\n        assert(0\
    \ <= s && s < n);\n        assert(0 <= t && t < n);\n        T flow = 0;\n   \
    \     while(1) {\n            bfs(s);\n            if(level[t] < 0) return flow;\n\
    \            iter = std::vector<int>(n, 0);\n            T f;\n            while((f\
    \ = dfs(s, t, std::numeric_limits<T>::max())) > 0) {\n                flow +=\
    \ f;\n            }\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: graph/Dinic.cpp
  requiredBy: []
  timestamp: '2021-12-19 11:01:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/Dinic.test.cpp
documentation_of: graph/Dinic.cpp
layout: document
title: Dinic
---

## 概要
最大流(Dinic法)

## 関数
* `Dinic<T> graph(int n)` コンストラクタ. `n` 頂点 `0` 辺のグラフを作る. `T` は辺容量の型
* `void graph.add_edge(int from, int to, T cap)` `from` -> `to` に容量 `cap` の辺を追加する
* `T graph.max_flow(int s, int t)` `s` -> `t` の最大流を返す

## 制約
* $0 \leq from, to < n$
* $0 \leq s, t < n$
* $0 \leq cap$

## 計算量
* `Dinic` : $\mathcal{O}(n)$
* `add_edge` $\mathcal{O}(1)$
* `max_flow` $\mathcal{O}(n^{2}m)$
