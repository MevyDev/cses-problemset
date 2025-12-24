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
int test_n;

void solve() {
    ll x, y; cin >> y >> x;
    ll res;
    if (x > y) {
        if (x % 2 == 0) {
            res = (x-1)*(x-1)+y;
        }
        if (x % 2 == 1) {
            res = x*x+1-y;
        }
    }
    else {
        if (y % 2 == 1) {
            res = (y-1)*(y-1)+x;
        }
        if (y % 2 == 0) {
            res = y*y+1-x;
        }
    }
    cout << res << '\n';
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        test_n++;
        solve();
    }
}
