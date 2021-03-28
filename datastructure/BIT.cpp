#pragma once
#include <cassert>
#include <vector>

template <typename T>
class BIT {
private:
    int n;
    std::vector<T> data;

public:
    BIT(int n = 0)
        : n(n), data(n, 0) {
    }

    void add(int p, T x) {
        assert(0 <= p && p < n);
        p++;
        while(p <= n) {
            data[p - 1] += x;
            p += p & -p;
        }
        return;
    }

    T sum(int p) {
        assert(0 <= p && p <= n);
        T res = 0;
        while(p > 0) {
            res += data[p - 1];
            p -= p & -p;
        }
        return res;
    }

    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= n);
        T res = sum(r) - sum(l);
        return res;
    }
};