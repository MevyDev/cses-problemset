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
    int n, m; cin >> n >> m;
    int a[200001];
    REP(i, n) {
        cin >> a[i];
    }
    sort(a, a+n);
    int qs[200001];
    REP(i, m) {
        cin >> qs[i];
    }

    int parents[200001];
    REP(i, (n+1)) {
        parents[i] = i;
    }

    for (int qi = 0; qi < m; qi++) {
        const int query = qs[qi];
        int l = -1;
        int r = n;
        while(l+1 < r) {
            const int mid = l+(r-l)/2;

            int mid_idx = mid;
            // DSU like path comdpression
            while (parents[mid_idx] != mid_idx) {
                parents[mid_idx] = parents[parents[mid_idx]];
                mid_idx = parents[mid_idx];
            }
            if (mid_idx >= n) {
                r = mid;
                continue;
            }
            if (a[mid_idx] <= query) {
                l = mid;
            }
            else {
                r = mid;
            }
        }
        if (l == -1) {
            cout << "-1\n";
            continue;
        }
        cout << a[parents[l]] << '\n';
        parents[l] = parents[l+1];
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
