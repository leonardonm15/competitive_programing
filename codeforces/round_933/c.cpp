#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    string s; cin >> s;
    int resp = 0;
    
    for (int i=0; i < n - 4; i++) {
        string k; 
        k += s[i];
        k += s[i + 1];
        k += s[i + 2];
        k += s[i + 3];
        k += s[i + 4];
        if (k == "mapie") resp--;
    }

    for (int i=0; i < n - 2; i++) {
        string k;
        k += s[i];
        k += s[i + 1];
        k += s[i + 2];
        if (k == "pie" || k == "map") resp++;
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
