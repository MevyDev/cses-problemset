#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
#define debug(x) cerr << #x << R"(: )" << x << '\n';
#define REP(i,a) for (int i = 0; i < a; ++i)
#define FILL(a) for (auto &A : a) cin >> A;
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) x.begin(), x.end()
#define pb push_back
#define ins insert
#define fi first
#define se second

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);
    FILL(a);
    FILL(b);
    sort(all(a));
    sort(all(b));
    int res = 0;
    int buyer_idx = 0;
    for (int i = 0; i < m; i++) {
        while (buyer_idx != n && b[i]-k > a[buyer_idx]) {
            buyer_idx++;
        }
        if (buyer_idx == n)
            break;
        if (abs(b[i] - a[buyer_idx]) <= k) {
            buyer_idx++;
            res++;
        }
    }
    cout << res << '\n';
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
