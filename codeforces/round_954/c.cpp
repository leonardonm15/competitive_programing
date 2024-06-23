#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int N = 1e5 + 5;

void solve () {
    int n, m; cin >> n >> m;
    string s; cin >> s;
    set<int> set;
    /* vector<bool> swpd(m); */
    /* map<int, int> freq; */

    for (int i = 0; i < m; i++) {
        int num; cin >> num;
        set.emplace(num);
    }

    string r; cin >> r;
    sort(r.begin(), r.end());
    
    int i = 0;
    for (auto c: set) {
        swap(s[c - 1], r[i++]);
    }

    cout << s << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
