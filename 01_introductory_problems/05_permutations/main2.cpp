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
    int n; cin >> n;
    if (n == 1) {
        cout << 1;
        return;
    }
    if (n <= 3) {
        cout << "NO SOLUTION\n";
        return;
    }
    for (int i = 2; i <= n; i+=2) {
        cout << i << ' ';
    }
    for (int i = 1; i <= n; i+=2) {
        cout << i << ' ';
    }
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
