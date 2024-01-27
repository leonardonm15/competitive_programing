#include <bits/stdc++.h>

using namespace std;

/* ###define endl '\n' */ 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

map<string, int> order;
map<string, int> m;

bool cmp(string &a, string &b) {
    return (m[a] == m[b] ? order[a] < order[b] : m[a] > m[b]);
}

void solve () {
    int n; cin >> n;
    set<string> set;
    int k = 1;
    for (int i=0; i < n; i++) {
        string s; cin >> s;
        m[s]++;
        if (!order[s]) {
            order[s] = k;
            k++;
        }
        set.emplace(s);
    }

    vector<string> a;

    for (auto c: set) a.push_back(c);

    sort(a.begin(), a.end(), cmp);

    /* cout << " ---------------- " << endl; */

    for (auto cara: a) cout << cara << " " << endl;

}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
