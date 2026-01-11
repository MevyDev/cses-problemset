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

vi dp;

void solve() {
    int n; cin >> n;
    dp.resize(n+1, 1e9);
    dp[0] = 0;
    for (int i = 1; i <= n; i++) {
        string nstr = to_string(i);
        for (char c : nstr) {
            if (c == '0')
                continue;
            dp[i] = min(dp[i-(c-'0')] + 1, dp[i]);
        }
    }
    cout << dp[n];
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
