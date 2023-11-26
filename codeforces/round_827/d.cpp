#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    map<int, int> map;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        if (!map[num] || map[num] < i + 1) {
            map[num] = i + 1;
        }
    }
    int resp = -1;
    for (auto [cara, i]: map) {
        /* cout << "cara -> " << cara << " - " << i << endl; */
        for (auto [filho, j]: map) {
            if (__gcd(cara, filho) == 1 && i + j > resp) {
                resp = i + j;
            }
        }
    }
    cout << resp << endl;
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
