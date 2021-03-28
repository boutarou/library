#include "../datastructure/BIT.cpp"
#include <iostream>
#include <vector>
using namespace std;

#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

int main() {
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    BIT<long long> bit(n);
    for(int i = 0; i < n; i++) bit.add(i, a[i]);
    vector<long long> ans;
    for(int i = 0; i < q; i++) {
        int query; cin >> query;
        if (query == 0) {
            int p;
            long long x;
            cin >> p >> x;
            bit.add(p, x);
        }
        else {
            int l, r; cin >> l >> r;
            ans.push_back(bit.sum(l, r));
        }
    }
    for(int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] << endl;
    }
}