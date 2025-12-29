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
    int n, m; cin >> n >> m;
    multiset<int> st;
    REP(i, n) {
        int tmp; cin >> tmp;
        st.ins(tmp);
    }

    vi queries(m); FILL(queries);

    for (int q : queries) {
        auto it = st.upper_bound(q);
        if (it == st.begin()) {
            cout << "-1\n";
            continue;
        }
        --it;
        cout << *it << '\n';
        st.erase(it);
    }
}

signed main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
