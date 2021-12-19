#pragma once
#include <vector>
#include <limits>
#include <algorithm>
#include <cassert>

template <typename T>
class FordFulkerson {
public:
    struct edge {
        int to;
        T cap;
        int rev;
    };

    int n;
    std::vector<std::vector<edge>> g;
    std::vector<bool> used;
    FordFulkerson(int n = 0)
        : n(n), g(n), used(n) {
    }
    void add_edge(int from, int to, T cap) {
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        assert(0 <= cap);
        g[from].push_back((edge){to, cap, int(g[to].size())});
        g[to].push_back((edge){from, 0LL, int(g[from].size() - 1)});
    }
    T dfs(int v, int goal_v, T flow) {
        if(v == goal_v) return flow;
        used[v] = true;
        for(int i = 0; i < (int)g[v].size(); i++) {
            edge &e = g[v][i];
            if(!used[e.to] && e.cap > 0) {
                T next_flow = dfs(e.to, goal_v, std::min(flow, e.cap));
                if(next_flow > 0) {
                    e.cap -= next_flow;
                    g[e.to][e.rev].cap += next_flow;
                    return next_flow;
                }
            }
        }
        return 0;
    }
    T max_flow(int s, int t, T ma = std::numeric_limits<T>::max()) {
        assert(0 <= s && s < n);
        assert(0 <= t && t < n);
        T flow = 0;
        while(1) {
            used = std::vector<bool>(n, false);
            T f = dfs(s, t, ma);
            if(f == 0) return flow;
            flow += f;
        }
    }
};
