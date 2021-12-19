#pragma once
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <cassert>

template <typename T>
class Dinic {
public:
    struct edge {
        int to;
        T cap;
        int rev;
    };

    int n;
    std::vector<std::vector<edge>> g;
    std::vector<int> level;
    std::vector<int> iter;
    Dinic(int n = 0)
        : n(n), g(n), level(n), iter(n) {
    }
    void add_edge(int from, int to, T cap) {
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        assert(0 <= cap);
        g[from].push_back((edge){to, cap, int(g[to].size())});
        g[to].push_back((edge){from, 0LL, int(g[from].size() - 1)});
    }
    void bfs(int s) {
        level = std::vector<int>(n, -1);
        std::queue<int> que;
        level[s] = 0;
        que.push(s);
        while(!que.empty()) {
            int v = que.front();
            que.pop();
            for(int i = 0; i < (int)g[v].size(); i++) {
                edge &e = g[v][i];
                if(e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }
    T dfs(int v, int t, T f) {
        if(v == t) return f;
        for(int &i = iter[v]; i < (int)g[v].size(); i++) {
            edge &e = g[v][i];
            if(e.cap > 0 && level[v] < level[e.to]) {
                T d = dfs(e.to, t, std::min(f, e.cap));
                if(d > 0) {
                    e.cap -= d;
                    g[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    T max_flow(int s, int t) {
        assert(0 <= s && s < n);
        assert(0 <= t && t < n);
        T flow = 0;
        while(1) {
            bfs(s);
            if(level[t] < 0) return flow;
            iter = std::vector<int>(n, 0);
            T f;
            while((f = dfs(s, t, std::numeric_limits<T>::max())) > 0) {
                flow += f;
            }
        }
    }
};
