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

const int N = 7;
const array<int, 2> START = {1, N};
const array<int, 2> TARGET = {1, 1};

bool vis[N+2][N+2];
int depth = 1;
int res = 0;
string path;

void dfs(int x, int y) {
    if (vis[x][y])
        return;
    if (x == TARGET[0] && y == TARGET[1]) {
        if (depth == N*N)
            res++;
        return;
    }
    bool l = vis[x-1][y];
    bool d = vis[x][y-1];
    bool u = vis[x][y+1];
    bool r = vis[x+1][y];
    if (l && r && !d && !u)
        return;
    if (!l && !r && d && u)
        return;

    char dir = path[depth-1];

    vis[x][y] = true;
    depth++;
    if (dir == '?' || dir == 'L') dfs(x-1, y);
    if (dir == '?' || dir == 'D') dfs(x, y-1);
    if (dir == '?' || dir == 'U') dfs(x, y+1);
    if (dir == '?' || dir == 'R') dfs(x+1, y);
    vis[x][y] = false;
    depth--;
}

void solve() {
    cin >> path;
    for (int i = 0; i < N+2; i++) {
        vis[i][0] = true;
        vis[0][i] = true;
        vis[i][N+1] = true;
        vis[N+1][i] = true;
    }
    dfs(START[0], START[1]);
    cout << res << '\n';
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
