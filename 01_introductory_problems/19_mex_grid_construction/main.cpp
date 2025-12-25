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
    int n; cin >> n;

    vector<set<int>> col_st(n);
    vector<set<int>> row_st(n);
    for (int i = 0; i < n*2; i++) {
        for (int j = 0; j < n; j++) {
            col_st[j].ins(i);
            row_st[j].ins(i);
        }
    }

    vector<vi> a(n, vi(n));

    REP(i, n) {
        REP(j, n) {
            auto cur_row = row_st[i].begin();
            auto cur_col = col_st[j].begin();
            while (*cur_row != *cur_col) {
                if (*cur_row < *cur_col) {
                    cur_row = next(cur_row);
                }
                else {
                    cur_col = next(cur_col);
                }
            }
            a[i][j] = *cur_row;
            row_st[i].erase(cur_row);
            col_st[j].erase(cur_col);
        }
    }
    cout << a[n-1][n-1];
    // REP(i, n) {
    //     cout << '\n';
    //     REP(j, n) {
    //         cout << a[i][j] << ' ';
    //     }
    // }
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
