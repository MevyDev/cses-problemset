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
    ll n; cin >> n;
    ll sum = (n*(n+1))/2;
    for(int i = 0; i < n-1; i++) {
        int k; cin >> k;
        sum -= k;
    }
    cout << sum << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
