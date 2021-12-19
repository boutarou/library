---
title: Dinic
documentation_of: ../graph/Dinic.cpp
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
