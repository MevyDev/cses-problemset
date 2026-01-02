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
int n;
vi a;

ll cost(int len) {
    ll res = 0;
    rep(i, n) {
        res += abs(a[i]-len);
    }
    return res;
}

void solve() {
    cin >> n;
    a.resize(n);
    fill(a);
    int l = *min_element(all(a));
    int r = *max_element(all(a));
    ll res = 0;
    while (l <= r) {
        int m1 = l+(r-l)/3;
        int m2 = r-(r-l)/3;
        ll cost1 = cost(m1);
        ll cost2 = cost(m2);
        if (cost1 == cost2) {
            l++;
            r--;
            res = cost1;
        }
        if (cost1 < cost2) {
            r = m2-1;
            res = cost1;
        }
        if (cost1 > cost2) {
            l = m1+1;
            res = cost2;
        }
    }
    cout << res << '\n';
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
