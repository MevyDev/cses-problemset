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
using mpi = map<int, int>;
using mpl = map<ll, ll>;
#define debug(x) cerr << #x << R"(: )" << x << '\n';
#define rep(i,a) for (int i = 0; i < a; ++i)
#define fill(a) for (auto &A : a) cin >> A;
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) x.begin(), x.end()
#define pb push_back
#define ins insert
#define fi first
#define se second

const ll MOD = 1e9+7;

void solve() {
    ll n; cin >> n;
    vl a(n); fill(a);
    mpl counts;
    for (ll num : a) {
        counts[num]++;
    }
    ll res = 1;
    for (pair p : counts) {
        res *= (p.se+1);
        res %= MOD;
    }
    cout << res-1 << '\n';
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
