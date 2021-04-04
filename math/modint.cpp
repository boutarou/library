template <long long MOD>
class modint {
private:
    long long x;

public:
    modint(long long x = 0)
        : x((x % MOD + MOD) % MOD) {
    }
    modint operator-() const {
        return modint(-x);
    }
    modint &operator+=(const modint a) {
        if((x += a.x) >= MOD) x -= MOD;
        return *this;
    }
    modint &operator-=(const modint a) {
        if((x += MOD - a.x) >= MOD) x -= MOD;
        return *this;
    }
    modint &operator*=(const modint a) {
        (x *= a.x) %= MOD;
        return *this;
    }
    modint &operator/=(const modint a) {
        return *this *= a.inv();
    }
    modint operator+(const modint a) const {
        return modint(*this) += a;
    }
    modint operator-(const modint a) const {
        return modint(*this) -= a;
    }
    modint operator*(const modint a) const {
        return modint(*this) *= a;
    }
    modint operator/(const modint a) const {
        return modint(*this) /= a;
    }
    modint pow(long long t) const {
        if(!t) return 1;
        modint a = pow(t >> 1);
        a *= a;
        if(t & 1) a *= *this;
        return a;
    }
    modint inv() const {
        return pow(MOD - 2);
    }
    int val() const {
        return x;
    }
};