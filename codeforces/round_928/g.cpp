#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    vector<int> adj(n + 5);

    int k = 2;
    for (int i=0; i < n - 1; i++) cin >> adj[k++];

    string v, z; cin >> z;
    v += '_';
    v += z;

    k = 0;
    int resp = 0;
    char c = 'C';
    char s = 'S';
    char p = 'P';
    for (int i=2; i <= n; i++) {
        cout << "------------------" << endl;
        cout << "v[adj[i]] -> " << v[adj[i]] << endl;
        cout << "v[i] -> " << v[i] << endl;
        if (v[adj[i]] == c && v[i] == s) v[adj[i]] = s;
        if (v[adj[i]] == s && v[i] == c) v[i] = s;

        if (v[adj[i]] == c && v[i] == p) v[adj[i]] = p;
        if (v[adj[i]] == p && v[i] == c) v[i] = p;

        if (v[adj[i]] == s && v[i] == p) resp++; 
        if (v[adj[i]] == p && v[i] == s) resp++; 
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
