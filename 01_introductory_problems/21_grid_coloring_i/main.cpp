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

typedef struct CanBe {
    bool a = true;
    bool b = true;
    bool c = true;
    bool d = true;
} CanBe;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<char>> cant(n, vector<char>(m));
    REP(i, n) {
        FILL(cant[i]);
    }

    // I think it should be always possible no?


    vector<vector<CanBe>> can_be(n, vector<CanBe>(m));

    vector<vector<char>> res(n, vector<char>(m, 0));

    REP(i, n) {
        REP(j, m) {
            if (cant[i][j] == 'A')
                can_be[i][j].a = false;
            if (cant[i][j] == 'B')
                can_be[i][j].b = false;
            if (cant[i][j] == 'C')
                can_be[i][j].c = false;
            if (cant[i][j] == 'D')
                can_be[i][j].d = false;
        }
    }

    REP(i, n) {
        REP(j, m) {
            if (can_be[i][j].a) {
                res[i][j] = 'A';
                if (i != n-1) {
                    can_be[i+1][j].a = false;
                }
                if (j != m-1) {
                    can_be[i][j+1].a = false;
                }
            }
            else if (can_be[i][j].b) {
                res[i][j] = 'B';
                if (i != n-1) {
                    can_be[i+1][j].b = false;
                }
                if (j != m-1) {
                    can_be[i][j+1].b = false;
                }
            }
            else if (can_be[i][j].c) {
                res[i][j] = 'C';
                if (i != n-1) {
                    can_be[i+1][j].c = false;
                }
                if (j != m-1) {
                    can_be[i][j+1].c = false;
                }
            }
            else if (can_be[i][j].d) {
                res[i][j] = 'D';
                if (i != n-1) {
                    can_be[i+1][j].d = false;
                }
                if (j != m-1) {
                    can_be[i][j+1].d = false;
                }
            }
            else {
                res[i][j] = 'X';
            }
        }
    }
    REP(i, n) {
        REP(j, m) {
            cout << res[i][j];
        }
        cout << '\n';
    }

}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
