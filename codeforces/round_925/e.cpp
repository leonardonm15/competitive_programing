#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, m; cin >> n >> m;
    multiset<pair<int, int>> s;
    for (int i=0; i < n; i++) {
        string num; cin >> num;
        int k = 0;
        for (int i=num.size() - 1; i > 0; i--) {
            if (num[i] == '0') k++;
            else break;
        }
        
        s.emplace(make_pair(k, num.size()));
    }

    for (auto [t, v]: s) {
        cout << t << " " << v << endl;
    }
    return;

    int i = 0;
    while (true) {
        /* cout << i << endl; */
        if (i > 0 && s.size() <= 1) break;
        if (i % 2 == 0) {
            int a = (*s.begin()).first;
            int b = (*s.begin()).second;
            s.erase(s.begin());
            s.emplace(make_pair(0, b - a));
        } else {
            int c = (*s.rbegin()).first; // tamanho string com menor tamanho
            int u = (*s.begin()).second;

            auto idx = s.lower_bound(make_pair(c, 1e17));

            if (idx == s.begin()) {
                idx++;
            }

            int b = (*idx).first;
            int r = (*idx).second;

            s.erase(idx);
            s.erase(s.begin());
            s.emplace(make_pair(b, r + u));
        }

        i++;
    }

    if ((*s.begin()).second >= m + 1) cout << "Sasha" << endl;
    else cout << "Anna" << endl;
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
