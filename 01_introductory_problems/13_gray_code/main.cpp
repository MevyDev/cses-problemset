// HELP
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

vector<string> rec(int n) {
    if (n == 1)
        return {"0", "1"};

    vector<string> a = rec(n-1);
    vector<string> b = a;
    reverse(all(b));

    REP(i, a.size()) {
        a[i] += '0';
    }
    REP(i, a.size()) {
        b[i] += '1';
    }
    a.insert(a.end(), b.begin(), b.end());
    return a;
}

void solve() {
    int n; cin >> n;
    for (string s : rec(n)) {
        cout << s << '\n';
    }
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
