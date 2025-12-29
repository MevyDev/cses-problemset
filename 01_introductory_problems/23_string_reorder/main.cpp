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

bool possible(vi freq, int last) {
    int mx = 0;
    int sm = 0;
    for (int i = 0; i < 26; i++) {
        sm += freq[i];
        if (freq[mx] < freq[i]) {
            mx = i;
        }
    }
    if (mx == last) {
        return freq[mx] <= (sm-freq[mx]);
    }
    return freq[mx] <= (sm-freq[mx]+1);
}

void solve() {
    string s; cin >> s;
    int n = s.size();
    vi freq(26);
    for (int i = 0; i < n; i++) {
        freq[s[i]-'A']++;
    }
    string res = "";
    int last = -1;
    while (true) {
        bool change = 0;
        for (int j = 0; j < 26; j++) {
            if (freq[j] == 0)
                continue;
            if (last == j)
                continue;
            freq[j]--;
            if (possible(freq, j)) {
                change = 1;
                last = j;
                res.pb(j+'A');
                break;
            }
            freq[j]++;
        }
        if (!change) {
            break;
        }
    }
    if (res.size() != n) {
        cout << "-1\n";
        return;
    }
    cout << res << '\n';
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
