#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(x) cerr << #x << R"(: )" << x << '\n';
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) x.begin(), x.end()
#define pb push_back
#define fi first
#define se second

void solve() {
    ll n; cin >> n;
    while(true) {
        cout << n << ' ';
        if(n == 1) {
            cout << '\n';
            return;
        }
        if(n % 2 == 0) {
            n /= 2;
        }
        else if(n % 2 == 1) {
            n = n * 3 + 1;
        }
    }
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
