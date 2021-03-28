#pragma once
#include <algorithm>
#include <vector>
#include <cassert>

class UnionFind {
private:
    int n;
    std::vector<int> par;
public:
    UnionFind(int n = 0) : n(n), par(n, -1) {}

    int root(int x) {
        assert(0 <= x && x < n);
        if(par[x] < 0)
            return x;
        else
            return par[x] = root(par[x]);
    }

    bool same(int x, int y) {
        assert(0 <= x && x < n);
        assert(0 <= y && y < n);
        return root(x) == root(y);
    }

    bool unite(int x, int y) {
        assert(0 <= x && x < n);
        assert(0 <= y && y < n);
        x = root(x), y = root(y);
        if(x == y) return false;
        if(par[x] > par[y]) std::swap(x, y);
        par[x] += par[y], par[y] = x;
        return true;
    }

    int size(int x) {
        assert(0 <= x && x < n);
        return -par[root(x)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> roots_num(n, -1);
        std::vector<std::vector<int>> res;
        int now = 0;
        for(int i = 0; i < n; i++) {
            int now_root = root(i);
            if(roots_num[now_root] == -1) {
                roots_num[now_root] = now;
                now++;
                res.push_back(std::vector<int>());
            }
            res[roots_num[now_root]].push_back(i);
        }
        return res;
    }
};
