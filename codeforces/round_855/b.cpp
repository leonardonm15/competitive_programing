#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    string a = "abcdefghijklmnopqrstuvwxyz";
    string b = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    map<char, int> map;
    
    for (auto c: s) map[c]++;

    int soma = 0;
    for (int i=0; i < a.size(); i++) {
        soma += min(map[a[i]], map[b[i]]);
        int z = abs(map[a[i]] - map[b[i]]);
        z /= 2;
        soma += min(k, z);
        k = max(k - z, 0ll);
    }
    cout << soma << endl;
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
