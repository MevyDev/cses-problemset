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

vector<string> strings;

void rec(multiset<char> &char_set, string &cur_string) {
    if (char_set.size() == 0) {
        strings.pb(cur_string);
        return;
    }
    vector<char> chars(char_set.size());
    {
        int i = 0;
        for (char c : char_set) {
            chars[i] = c;
            i++;
        }
    }
    for (char c : chars) {
        char_set.erase(char_set.find(c));
        cur_string.pb(c);
        rec(char_set, cur_string);
        cur_string.pop_back();
        char_set.ins(c);
    }
}

void solve() {
    string s; cin >> s;

    multiset<char> char_set;
    for (char c : s)
        char_set.insert(c);

    string buf_string;
    rec(char_set, buf_string);

    sort(all(strings));

    int real_strings = 1;
    for (int i = 1; i < strings.size(); i++) {
        if (strings[i] != strings[i-1]) {
            real_strings += 1;
        }
    }
    cout << real_strings << '\n';
    cout << strings[0] << '\n';
    for (int i = 1; i < strings.size(); i++) {
        if (strings[i] != strings[i-1]) {
            cout << strings[i] << '\n';
        }
    }
}

signed main() {
    // ios::sync_with_stdio(false); cin.tie(nullptr);
    solve();
}
