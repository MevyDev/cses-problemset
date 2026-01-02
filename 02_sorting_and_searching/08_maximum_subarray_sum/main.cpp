#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vb = vector<bool>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define debug(x) cerr << #x << R"(: )" << x << '\n';
#define rep(i,a) for (int i = 0; i < a; ++i)
#define fill(a) for (auto &A : a) cin >> A;
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) x.begin(), x.end()
#define pb push_back
#define ins insert
#define fi first
#define se second

void solve() {
    int n; cin >> n;
    vi a(n); fill(a);

    ll cur = INT_MIN;
    ll res = INT_MIN;
    rep(i, n) {
        cur = max(cur+a[i], (ll)a[i]);
        res = max(cur, res);
    }
    cout << res << '\n';
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
