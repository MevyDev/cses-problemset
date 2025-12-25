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
    ll n; cin >> n;

    ll sum = n*(n+1)/2;

    // can't do shit when it's odd
    if (sum % 2 == 1) {
        cout << "NO\n";
        return;
    }
    // otherwise, we can prove it's always possible
    cout << "YES\n";

    // greedily choose the largest number possible
    // always works here
    ll needed = sum/2;
    vector<int> first_set;
    for (int k = n; k > 0; k--) {
        if (needed == 0)
            break;
        if (needed >= k) {
            first_set.pb(k);
            needed -= k;
        }
    }
    cout << first_set.size() << '\n';
    for (int num : first_set) {
        cout << num << ' ';
    }
    cout << '\n' << n-first_set.size() << '\n';
    // second set is the rest
    int first_set_idx = 0;
    for (int k = n; k > 0; k--) {
        if (first_set_idx != first_set.size() && first_set[first_set_idx] == k) {
            first_set_idx++;
            continue;
        }
        cout << k << ' ';
    }
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
