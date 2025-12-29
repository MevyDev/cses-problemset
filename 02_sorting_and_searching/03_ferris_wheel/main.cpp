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
    int n, x; cin >> n >> x;
    vi a(n); FILL(a);
    sort(rall(a));

    int smol = n-1;
    int res = 0;
    for (int i = 0; i <= smol; i++) {
        if (a[smol] + a[i] <= x) {
            res += 1;
            smol--;
        }
        else {
            res += 1;
        }
    }
    cout << res << '\n';
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
