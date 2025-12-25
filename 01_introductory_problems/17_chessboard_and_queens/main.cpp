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

vector<unsigned long long> opts;

void rec(
    int depth,
    unsigned long long forbidden_board,
    vector<bool> &col,
    vector<bool> &diag1,
    vector<bool> &diag2,
    unsigned long long board
) {
    if (depth == 8) {
        opts.pb(board);
        return;
    }
    for (int i = 0; i < 8; i++) {
        if (col[i])
            continue;
        if (diag1[i+depth])
            continue;
        if (diag2[7-i+depth])
            continue;
        if (forbidden_board & (1LL << (i + depth*8)))
            continue;
        col[i] = true;
        diag1[i+depth] = true;
        diag2[7-i+depth] = true;
        rec(depth+1, forbidden_board, col, diag1, diag2, board | (1LL << (i + depth*8)));
        col[i] = false;
        diag1[i+depth] = false;
        diag2[7-i+depth] = false;
    }
}

void solve() {
    unsigned long long forbidden_board = 0;
    REP(i, 64) {
        char tmp; cin >> tmp;
        if (tmp == '.')
            continue;
        forbidden_board |= (1LL << i);
    }
    vector<bool> col(8, false);
    vector<bool> diag1(15, false);
    vector<bool> diag2(15, false);
    unsigned long long board = 0;
    rec(0, forbidden_board, col, diag1, diag2, board);
    cout << opts.size();
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
