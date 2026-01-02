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
    int n, x; cin >> n >> x;
    vector<array<int, 2>> a(n);
    rep(i, n) {
        cin >> a[i][0];
        a[i][1] = i;
    }
    sort(all(a));

    int l = 0;
    int r = n-1;
    array<int, 2> res = {-1, -1};
    while (l < r) {
        int cur_sum = a[l][0] + a[r][0];
        if (cur_sum == x) {
            res[0] = a[l][1];
            res[1] = a[r][1];
            break;
        }
        if (cur_sum > x) {
            r--;
        }
        if (cur_sum < x) {
            l++;
        }
    }
    if (res[0] == -1) {
        cout << "IMPOSSIBLE\n";
        return;
    }
    cout << res[0]+1 << ' ' << res[1]+1 << '\n';
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
