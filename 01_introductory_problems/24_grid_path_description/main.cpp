#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
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
const array<int, 2> start = {0, N-1};
const array<int, 2> target = {0, 0};
const array<int, 2> dirs[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
bool vis[N][N];
int depth = 1;
int path_count = 0;
vector<string> paths;
void dfs(int x, int y);
string buf_str = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";

inline void call_dfs(int x, int y, array<int, 2> dir) {
    if (dir == array<int, 2>{-1, 0})
        buf_str[depth-1] = 'L';
    if (dir == array<int, 2>{0, -1})
        buf_str[depth-1] = 'D';
    if (dir == array<int, 2>{0, 1})
        buf_str[depth-1] = 'U';
    if (dir == array<int, 2>{1, 0})
        buf_str[depth-1] = 'R';
    depth++;
    vis[x][y] = true;
    dfs(x, y);
    depth--;
    vis[x][y] = false;
}

inline bool in_bounds(int x, int y) {
    if (x < 0 || x >= N)
        return false;
    if (y < 0 || y >= N)
        return false;
    return true;
}

void dfs(int x, int y) {
    if (depth == N*N) {
        if (x == target[0] && y == target[1]) {
            path_count++;
            paths.pb(buf_str);
        }
        return;
    }
    if (x == target[0] && y == target[1])
        return;
    for (auto dir : dirs) {
        int nx = x + dir[0];
        int ny = y + dir[1];
        int jx = x + dir[0] + dir[0];
        int jy = y + dir[1] + dir[1];
        if (in_bounds(nx, ny) && !vis[nx][ny]) {
            if (!in_bounds(jx, jy) || vis[jx][jy]) {
                int mx1 = nx+dir[1];
                int mx2 = nx-dir[1];
                int my1 = ny+dir[0];
                int my2 = ny-dir[0];
                if (in_bounds(mx1, my1) && in_bounds(mx2, my2) && !vis[mx1][my1] && !vis[mx2][my2])
                    continue;
            }
            call_dfs(nx, ny, dir);
        }
    }
}

void solve() {
    string s; cin >> s;
    paths.reserve(88418);
    vis[start[0]][start[1]] = true;
    dfs(start[0], start[1]);
    int res = 0;
    for (string path : paths) {
        for (int i = 0; i < path.size(); i++) {
            if (s[i] != '?' && s[i] != path[i])
                break;
            if (i == path.size()-1)
                res++;
        }
    }
    cout << res << '\n';
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
