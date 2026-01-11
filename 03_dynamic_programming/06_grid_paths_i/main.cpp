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

ll rec(int x, int y) {
    if (min(x, y) < 0)
        return 0;
    if (grid[x][y] == '*')
        return 0;
    if (max(x, y) == 0)
        return dp[x][y] = 1;
    if (dp[x][y] != -1) return dp[x][y];
    return dp[x][y] = (rec(x-1, y) + rec(x, y-1)) % MOD;
}

void solve() {
    cin >> n;
    grid.resize(n);
    dp.resize(n, vl(n, -1));
    fill(grid);
    cout << rec(n-1, n-1);
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
