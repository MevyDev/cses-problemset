#include <bits/stdc++.h>
//#define int long long
using namespace std;
using ll = long long;
using vb = vector<bool>;
using vi = vector<int>;
using vpi = vector<pair<int, int>>;
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

void solve() {
    int x, n; cin >> x >> n;
    vi a(n); fill(a);

    set<int> points;
    multiset<int> dists;
    points.ins(0);
    points.ins(x);
    dists.ins(x);
    rep(i, n) {
        int cur = a[i];
        int last = *prev(points.lower_bound(cur));
        int next = *points.upper_bound(cur);
        dists.erase(dists.find(next-last));
        points.ins(cur);
        dists.ins(cur-last);
        dists.ins(next-cur);
        cout << *dists.rbegin() << ' '; 
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
