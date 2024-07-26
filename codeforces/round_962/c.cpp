#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, q; cin >> n >> q;
    string s, r; cin >> s >> r;
    
    vector<vector<int>> lets(n + 1, vector<int>(26));
    vector<vector<int>> letr(n + 1, vector<int>(26));

    vector<int> nows(26);
    vector<int> nowr(26);
    for (int i = 0; i < n; i++) {
        nows[s[i] - 'a']++;
        lets[i + 1] = nows;

        nowr[r[i] - 'a']++;
        letr[i + 1] = nowr;
    }

    while (q--) {
        int l, r; cin >> l >> r;

        vector<int> news(26);
        vector<int> newr(26);

        int resp = 0;
        for (int i = 0; i < 26; i++) {
            news[i] = lets[r][i] - lets[l - 1][i];
            newr[i] = letr[r][i] - letr[l - 1][i];

            resp += abs(news[i] - newr[i]);
        }

        /* cout << "news -> "; */
        /* for (auto c: news) cout << c << " "; */
        /* cout << endl; */

        /* cout << "newr -> "; */
        /* for (auto c: newr) cout << c << " "; */
        /* cout << endl; */

        cout << (resp) / 2 << endl;
    }
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
