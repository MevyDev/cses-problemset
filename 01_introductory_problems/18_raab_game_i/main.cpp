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
int test_n;

void solve() {
    int n, a, b; cin >> n >> a >> b;

    // make a always bigger
    bool flipped = false;
    if (a < b) {
        swap(a, b);
        flipped = true;
    }

    if (a + b > n) {
        cout << "NO\n";
        return;
    }

    if (a != 0 && b == 0) {
        cout << "NO\n";
        return;
    }

    // possible now

    vector<int> a_moves(n);
    vector<int> b_moves(n);
    if (a == b) {
        REP(i, a*2) {
            a_moves[i] = i;
            b_moves[i] = a*2-i-1;
        }
        for(int i = a*2; i < n; i++) {
            a_moves[i] = i;
            b_moves[i] = i;
        }
    }
    else {
        int eql = n-a-b;
        REP(i, eql) {
            a_moves[i] = n-i-1;
            b_moves[i] = n-i-1;
        }
        REP(i, a) {
            a_moves[i+eql] = n-eql-i-1;
            b_moves[i+eql] = n-eql-i-1-b;
        }
        REP(i, b) {
            a_moves[i+eql+a] = n-eql-i-1-a;
            b_moves[i+eql+a] = n-eql-i-1;
        }
    }


    cout << "YES\n";
    if (flipped) {
        REP(i, n) {
            cout << 1+b_moves[i] << ' ';
        }
        cout << '\n';
        REP(i, n) {
            cout << 1+a_moves[i] << ' ';
        }
        cout << '\n';
    }
    else {
        REP(i, n) {
            cout << 1+a_moves[i] << ' ';
        }
        cout << '\n';
        REP(i, n) {
            cout << 1+b_moves[i] << ' ';
        }
        cout << '\n';
    }
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        test_n++;
        solve();
    }
}
