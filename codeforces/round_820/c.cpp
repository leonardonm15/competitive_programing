#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    string s; cin >> s;
    int n = s.size();
    int cost = 0;
    vector<int> resp;
    vector<pair<char, int>> t;

    if (n == 2) {
        cout << abs(s[0] - s[1]) << " " << 2 << endl;
        cout << 1 << " " << 2 << endl;
        return;
    }

    for (int j=0; j < n; j++) {
        t.push_back({s[j], j});
    }

    resp.push_back(1);
    if (s[0] <= s[n - 1]) {
        int i = 1;
        char lc  = s[0];
        sort(t.begin() + 1, t.end());
        while (i < n) {
            if (t[i].first < s[0] || t[i].first > s[n - 1]) {
                i++;
                continue;
            }
            cost += abs(t[i].first - lc);
            resp.push_back(t[i].second + 1);
            lc = t[i].first;
            i++;
        }
    } else {
        sort(t.rbegin() + 1, t.rend() - 1);
        char lc = s[0];
        int i = 1;
        while (i < n) {
            if (t[i].first > s[0] || t[i].first < s[n - 1]) {
                i++;
                continue;
            }
            cost += abs(t[i].first - lc);
            resp.push_back(t[i].second + 1);
            lc = t[i].first;
            i++;
        }
        /* cost += abs(t[i - 1].first - t[n - 1].first); */
    }

    /* cout << "t -> "; */
    /* for (auto &c: t) cout << c.first << " "; */
    /* cout << endl; */

    cout << cost << " " << resp.size() << endl;
    for (auto c: resp) cout << c << " ";
    cout << endl;

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
