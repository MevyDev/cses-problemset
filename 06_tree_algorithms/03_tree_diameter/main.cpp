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

array<int, 2> furthest_node(int x, vvi &g) {
    int n = g.size();
    vi vis(n);
    array<int, 2> last;
    queue<array<int, 2>> q;
    q.push({x, 0});
    while (!q.empty()) {
        array<int, 2> v = q.front();
        q.pop();
        if (vis[v[0]])
            continue;
        vis[v[0]] = 1;
        last = v;
        for (int nv : g[v[0]]) {
            q.push({nv, v[1]+1});
        }
    }
    return last;
}

void solve() {
    int n; cin >> n;
    vvi g(n);
    rep(i, n-1) {
        int a, b; cin >> a >> b;
        a--;
        b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    array<int, 2> tmp = furthest_node(0, g);
    array<int, 2> res = furthest_node(tmp[0], g);
    cout << res[1] << '\n';
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
