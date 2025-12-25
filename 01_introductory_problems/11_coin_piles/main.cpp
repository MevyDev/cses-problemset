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
    int a, b; cin >> a >> b;

    // a always >= than b
    if (a < b)
        swap(a, b);

    if ((a + b) % 3 != 0) {
        cout << "NO\n";
        return;
    }

    if (b*2 < a) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        test_n++;
        solve();
    }
}
