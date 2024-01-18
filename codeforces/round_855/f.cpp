#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     
//

int cmp = 0b000000000011111111111111111111111111;

void solve () {
    int n; cin >> n;
    map<int, int> miss[26][2];
    int resp = 0;

    for (int i=0; i < n; i++) {
        string s; cin >> s;
        int l = 0;
        int p = 0;
        for (auto c: s) {
            int k = c - 'a';
            l |= (1 << k);
            p ^= (1 << k);
        }
        int sz = s.size() & 1;

        for (int i=0; i < 26; i++) {
            int nao_tenho = l ^ cmp;
            int need_p = p ^ cmp;
            if ((1 << i) & nao_tenho) {
                need_p &= ~(1 << i);
                auto it = miss[i][!sz].find(need_p);
                if (it != miss[i][!sz].end()) resp += it->second;
            }
        }

        int nao_tenho = l ^ cmp;
        for (int i=0; i < 26; i++) {
            if (nao_tenho & (1 << i)) miss[i][sz][p]++;
        }
    }
    cout << resp << endl;
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
