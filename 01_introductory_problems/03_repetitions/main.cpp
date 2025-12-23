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
    string s; cin >> s;
    int n = s.size();
    int res = 0;
    int cur = 1;
    for(int i = 1; i < n; i++) {
        if(s[i] != s[i-1]) {
            res = max(res, cur);
            cur = 0;
        }
        cur++;
    }
    res = max(res, cur);
    cout << res << '\n';
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
