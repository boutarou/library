#include <iostream>
#include <vector>
#include "../datastructure/unionfind.cpp"
using namespace std;
#define rep(i, n) for(int i = 0; i < int(n); i++)
using ll = long long;
using P = pair<int, int>;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> t(q), u(q), v(q);
    rep(i, q) {
        cin >> t[i] >> u[i] >> v[i];
    }
    UnionFind uf(n);
    rep(i, q) {
        if (t[i] == 0) {
            uf.unite(u[i], v[i]);
        }
        else {
            cout << (uf.same(u[i], v[i]) ? 1 : 0) << endl;
        }
    }
    return 0;
}
