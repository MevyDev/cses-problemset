#include <bits/stdc++.h>
//#define int long long
using namespace std;
using ll = long long;
using vb = vector<bool>;
using vi = vector<int>;
using vpi = vector<pair<int, int>>;
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
    ll x; cin >> x;
    ll MOD = 1e9+7;
    vl coins(n); fill(coins);
    vl dp(x+1);
    dp[0] = 1;
    for (int i = 1; i <= x; i++) {
        for (ll coin : coins) {
            if (i - coin >= 0) {
                dp[i] += dp[i-coin];
                dp[i] %= MOD;
            }
        }
    }
    cout << dp[x] << '\n';
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
