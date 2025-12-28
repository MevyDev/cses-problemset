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
    ll n; cin >> n;
    ll cnum = 0;
    ll cjump = 9;
    ll cdigits = 1;
    while (n >= cjump*cdigits) {
        cnum += cjump;
        n -= cjump*cdigits;
        cdigits++;
        cjump *= 10;
    }
    ll full_move = n/cdigits;
    n %= cdigits;
    cnum += full_move;
    if (n == 0) {
        cout << cnum%10 << '\n';
        return;
    }
    string num_str = to_string(cnum+1);
    cout << num_str[n-1] << '\n';
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        test_n++;
        solve();
    }
}
