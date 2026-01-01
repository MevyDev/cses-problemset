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
    vector<array<int, 2>> end_start(n);
    for (int i = 0; i < n; i++) {
        cin >> end_start[i][1] >> end_start[i][0];
    }
    sort(all(end_start));
    int cur_time = 0;
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (end_start[i][1] >= cur_time) {
            res++;
            cur_time = end_start[i][0];
        }
    }
    cout << res << '\n';
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
