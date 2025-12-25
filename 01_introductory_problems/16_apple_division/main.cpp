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
int n;
vi a;
ll sum = 0;

ll rec(int i, ll c) {
    if (i == n) {
        return abs(sum-c*2);
    }
    return min(rec(i+1, c), rec(i+1, c+a[i]));
}

void solve() {
    cin >> n;
    a.resize(n);
    FILL(a);
    for (int num : a) {
        sum += num;
    }
    cout << rec(0, 0);
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
