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

ll calc_knights(ll n) {
    ll invalid = 0;
    if (n == 1) {
        invalid = 0;
    }
    if (n == 2) {
        invalid = 0;
    }
    if (n == 3) {
        invalid = 8;
    }
    if (n >= 4) {
        invalid += 4*2;
        invalid += 8*3;
        invalid += 4*(n-2)*4 - 4*4;
        invalid += 4*(n-4)*6;
        invalid += (n-4)*(n-4)*8;
        invalid /= 2;
    }
    ll total = (n*n)*(n*n-1)/2;
    return total - invalid;
}

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
        cout << calc_knights(i) << '\n';
    }
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
