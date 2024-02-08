#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, k; cin >> n >> k;
    vector<int> resp(n);
    int mn = 1;
    int mx = n;

    for (int i=0; i < k; i++) {
        if (i&1) for (int j=i; j < n; j += k) resp[j] = mx--;
        else for (int j=i; j < n; j += k) resp[j] = mn++;
    }

    for (auto cara: resp) cout << cara << " ";
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
