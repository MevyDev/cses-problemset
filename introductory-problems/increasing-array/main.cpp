#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(x) cerr << #x << R"(: )" << x << '\n';
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) x.begin(), x.end()
#define pb push_back
#define fi first
#define se second

void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for(auto &A : a) {
        cin >> A;
    }

    ll res = 0;
    for(int i = 1; i < n; i++) {
        res += max(0, a[i-1]-a[i]);
        a[i] = max(a[i-1], a[i]);
    }
    cout << res << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
