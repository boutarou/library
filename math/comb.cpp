#include "modint.cpp"
#include <vector>
#include <cassert>

template<long long MOD>
class combination {
private:
    using mint = modint<MOD>;
    int _n;
    std::vector<mint> fact, ifact;
public:
    combination(int n)
        : _n(n), fact(n + 1), ifact(n + 1) {
        assert(n < MOD);
        fact[0] = 1;
        for(int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
        ifact[n] = fact[n].inv();
        for(int i = n; i >= 1; i--) ifact[i - 1] = ifact[i] * i;
    }
    mint operator()(int n, int k) {
        assert(0 <= n && n <= _n);
        if(k < 0 || k > n) return 0;
        return fact[n] * ifact[k] * ifact[n - k];
    }
};

template<long long MOD>
class permutation {
private:
    using mint = modint<MOD>;
    int _n;
    std::vector<mint> fact, ifact;
public:
    permutation(int n)
        : _n(n), fact(n + 1), ifact(n + 1) {
        assert(n < MOD);
        fact[0] = 1;
        for(int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
        ifact[n] = fact[n].inv();
        for(int i = n; i >= 1; i--) ifact[i - 1] = ifact[i] * i;
    }
    mint operator()(int n, int k) {
        assert(0 <= n && n <= _n);
        if(k < 0 || k > n) return 0;
        return fact[n] * ifact[n - k];
    }
};
