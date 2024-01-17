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
    map<pair<int, int>, int> f;
    map<int, pair<int, int>> map;
    int resp = 0;
 
    for (int i=0; i < n; i++) {
        string s; cin >> s;
        int sz = s.size();
        int l = 0;
        int p = 0;
        for (auto c: s) {
            int k = c - 'a';
            l |= (1 << k);
            p ^= (1 << k);
        }
 
        for (int i=0; i < 26; i++) {
            int need = p ^ cmp;
            if (((1 << i) & need)) {
                need ^= (1 << i);
                if ((map[need].first && (map[need].second + sz)&1)) {
                    int k = map[need].first | l;
                    int v = 0;
                    for (int i=0; i < 26; i++) {
                        if ((1 << i) & k) continue;
                        else v++;
                    }
                    if (v == 1) {
                        resp += f[{need, map[need].first}];
                    }
                }
            }
        }
        map[p] = {l, sz};
        f[{p, l}]++;
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
