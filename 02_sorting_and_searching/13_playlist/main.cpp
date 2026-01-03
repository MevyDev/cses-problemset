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
    int n; cin >> n;
    vi a(n); fill(a);

    int best = 0;
    int l = 0; int r = 0;
    // fucking unordered data structures bruh, never using them again
    set<int> st;
    while (r < n) {
        while (st.count(a[r])) {
            st.erase(a[l]);
            l++;
        }
        st.ins(a[r]);
        r++;
        best = max(r-l, best);
    }
    cout << best << '\n';
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
