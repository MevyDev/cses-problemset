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

typedef enum {
    Leave,
    Enter,
} Status;

void solve() {
    int n; cin >> n;
    vector<pair<int, Status>> a(n*2);
    for (int i = 0; i < n*2; i++) {
        cin >> a[i].fi;
        if (i%2 == 0) a[i].se = Enter;
        else a[i].se = Leave;
    }
    sort(all(a));
    int cur_idx = 0;
    int count = 0;
    int res = 0;
    while (cur_idx < n*2) {
        if (a[cur_idx].second == Leave)
            count--;
        else
            count++;
        res = max(count, res);
        cur_idx++;
    }
    cout << res << '\n';
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
