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
int n;
vector<string> grid;
vvl dp;
const ll MOD = 1e9+7;

void solve() {
    cin >> n;
    grid.resize(n);
    dp.resize(n, vl(n));
    fill(grid);
    dp[0][0] = 1;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            if (grid[x][y] == '*') {
                dp[x][y] = 0;
                continue;
            }
            if (x == 0 && y == 0)
                continue;
            int res = 0;
            if (y != 0) {
                res += dp[x][y-1];
            }
            if (x != 0) {
                res += dp[x-1][y];
            }
            dp[x][y] = res % MOD;
        }
    }
    cout << dp[n-1][n-1];
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
