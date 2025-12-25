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
    string s; cin >> s;
    int n = s.size();

    string sorted_s = s;
    sort(all(sorted_s));

    vector<int> counts;
    int cur_count = 1;
    for (int i = 1; i < n; i++) {
        if (sorted_s[i] != sorted_s[i-1]) {
            counts.pb(cur_count);
            cur_count = 1;
        }
        else {
            cur_count++;
        }
    }
    counts.pb(cur_count);

    int odd_count = 0;
    for (int count : counts) {
        if (count % 2 == 1)
            odd_count++;
    }

    if (odd_count >= 2) {
        cout << "NO SOLUTION\n";
        return;
    }
    if (odd_count != n%2) {
        cout << "NO SOLUTION\n";
        return;
    }

    string half = "";
    int idx = 0;
    for (int i = 0; i < counts.size(); i++) {
        const int cur_count = counts[i];
        if (cur_count % 2 == 1) {
            idx += cur_count;
            continue;
        }
        for (int j = 0; j < cur_count/2; j++) {
            half += sorted_s[idx];
        }
        idx += cur_count;
    }

    string middle = "";
    idx = 0;
    for (int i = 0; i < counts.size(); i++) {
        const int cur_count = counts[i];
        if (cur_count % 2 == 0) {
            idx += cur_count;
            continue;
        }
        for (int j = 0; j < cur_count; j++) {
            middle += sorted_s[idx];
        }
        break;
    }
    string second_half = half;
    reverse(all(second_half));
    cout << half << middle << second_half << '\n';
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
