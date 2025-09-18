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
    ll y, x; cin >> y >> x;
    ll res = (max(x, y)-1) * (max(x, y)-1);

    if(x > y) {
        if(x % 2 == 0) {
            res += y;
        }
        else {
            res += x*2 - y;
        }
    }
    else {
        if(y % 2 == 1) {
            res += x;
        }
        else {
            res += y*2 - x;
        }
    }
    cout << res << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
}
