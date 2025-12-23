#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(x) cerr << #x << R"(: )" << x << '\n';
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) x.begin(), x.end()
#define pb push_back
#define fi first
#define se second

ll solve_for_k(ll k) {
    // if (k == 1) {
    //     return 0;
    // }
    // if (k == 2) {
    //     return 6;
    // }
    // if (k == 3) {
    //     return 28;
    // }
    // if (k == 4) {
    //     return 96;
    // }
    ll total_ways = ((k*k)*(k*k-1))/2;
    ll bad_ways = 0;
    bad_ways += 2 * 4;
    bad_ways += 3 * 8;
    bad_ways += 4 * (k-4) * 4;
    bad_ways += 4 * 4;
    bad_ways += 6 * (k-4) * 4;
    bad_ways += 8 * (k-4) * (k-4);
    return total_ways - bad_ways/2;
}

void solve() {
    int n; cin >> n;
    for(ll k = 1; k <= n; k++) {
        cout << solve_for_k(k) << '\n';
    }
    return;
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
