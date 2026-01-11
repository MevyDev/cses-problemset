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

int rec(int n) {
    if (n == 0) return dp[n] = 0;
    if (n < 0) return 1e9;
    if (dp[n] != -1) return dp[n];
    string nstr = to_string(n);
    int res = 1e9;
    for (char c : nstr) {
        if (c == '0')
            continue;
        res = min(rec(n-(c-'0')), res);
    }
    return dp[n] = res+1;
}

void solve() {
    int n; cin >> n;
    dp.resize(n+1, -1);
    cout << rec(n);
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
