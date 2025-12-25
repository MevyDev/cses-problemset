#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define debug(x) cerr << #x << R"(: )" << x << '\n';
#define REP(i,a) for (int i = 0; i < a; ++i)
#define FILL(a) for (auto &A : a) cin >> A;
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) x.begin(), x.end()
#define pb push_back
#define ins insert
#define fi first
#define se second

bool check(int x, int n) {
    if (x < 0)
        return false;
    if (x >= n)
        return false;
    return true;
}

void solve() {
    int n; cin >> n;
    vvi a(n, vi(n, -1));

    vector<array<int, 2>> dirs = { {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}, };

    queue<array<int, 3>> q;
    q.push({0, 0, 0});
    while (!q.empty()) {
        int x = q.front()[0];
        int y = q.front()[1];
        int score = q.front()[2];
        q.pop();

        if (a[x][y] != -1)
            continue;
        a[x][y] = score;

        for (auto dir : dirs) {
            int nx = x + dir[0];
            int ny = y + dir[1];
            if (!check(nx, n))
                continue;
            if (!check(ny, n))
                continue;
            q.push({nx, ny, score+1});
        }
    }

    REP(i, n) {
        REP(j, n) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
