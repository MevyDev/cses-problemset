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
    int x; cin >> x;
    vi coins(n); fill(coins);
    vi dp(x+1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= x; i++) {
        for (int coin : coins) {
            if (i - coin < 0) {
                continue;
            }
            dp[i] = min(dp[i-coin]+1, dp[i]);
        }
    }
    if (dp[x] >= 1e9) {
        cout << "-1\n";
    }
    else {
        cout << dp[x] << '\n';
    }
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
