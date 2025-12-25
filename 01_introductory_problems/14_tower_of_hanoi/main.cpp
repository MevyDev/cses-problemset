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

vector<array<int, 2>> moves;

void rec(int n, int start_pile, int end_pile) {
    int buf_pile = 6-start_pile-end_pile;
    if (n == 1) {
        moves.pb({start_pile, end_pile});
        return;
    }
    rec(n-1, start_pile, buf_pile);
    moves.pb({start_pile, end_pile});
    rec(n-1, buf_pile, end_pile);
}


void solve() {
    int n; cin >> n;

    rec(n, 1, 3);

    cout << moves.size() << '\n';
    for (auto move : moves) {
        cout << move[0] << ' ' << move[1] << '\n';
    }
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
