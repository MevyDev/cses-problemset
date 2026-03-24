#include <cassert>
#include <cstdio>
#include <iomanip>
#include <iostream>

#include <sstream>
#include <string>

#include <array>
#include <bitset>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <limits>
#include <numeric>
#include <utility>

// #define int long long

using namespace std;
using ll = long long;
using vb = vector<bool>;
using vi = vector<int>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define debug(x) cerr << #x << R"(: )" << x << '\n';
#define rep(i, a) for (int i = 0; i < a; ++i)
#define fill(a) for (auto &A : a) cin >> A;
#define rall(x) (x).rbegin(), (x).rend()
#define all(x) x.begin(), x.end()
#define pb push_back
#define ins insert
#define fi first
#define se second
int test_n;


ll rec(const string lim, int pos, int last, bool smaller, bool non_zero) {
    assert(pos >= 0);
    assert(pos <= lim.size());
    if (pos == lim.size()) return 1;

    ll res = 0;
    int mx_dig = (smaller) ? 9 : lim[pos]-'0';
    for (int dig = 0; dig <= mx_dig; dig++) {
        if (last == dig && non_zero) continue;
        bool next_smaller = dig != mx_dig || smaller;
        res += rec(lim, pos+1, dig, next_smaller, non_zero || dig != 0);
    }

    return res;
}

void solve() {
    ll l, r; cin >> l >> r;
    ll to_r = rec(to_string(r), 0, 10, false, false);
    ll sub = 0;
    if (l >= 1) {
        sub = rec(to_string(l-1), 0, 10, false, false);
    }
    cout << to_r-sub << '\n';
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    int t = 1;
    while (t--) {
        test_n++;
        solve();
    }
}
