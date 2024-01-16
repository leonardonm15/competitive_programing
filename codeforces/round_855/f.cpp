#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     
//

int cmp = 0b000000000011111111111111111111111111;

void solve () {
    int n; cin >> n;
    map<int, int> map;
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

        cout << "-----------------" << endl;
        cout << "l -> " << bitset<26>(l) << endl;
        cout << "p -> " << bitset<26>(p) << endl;

        int z = 0;
        for (int i=0; i < 26; i++) {
            int x = (l ^ cmp);
            if (!((x << i)&1)) continue;
            x <<= (0 << i);
            if (map[
        }
        if (map[p ^ cmp]) {
            int x = (l | map[p ^ cmp]);
            cout << "x -> " << bitset<26>(x) << endl;
            for (int i=0; i < 26; i++) {
                if (!x&1) z++;
                x >>= 1;
            }
        }
        if (z == 1) resp++;
        map[p] = l;
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
