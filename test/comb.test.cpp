#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_E"
#include "../math/comb.cpp"
#include <iostream>
using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    int n, k;
    cin >> n >> k;
    combination<MOD> comb(1e6);
    cout << comb(k, n).val() << endl;
}