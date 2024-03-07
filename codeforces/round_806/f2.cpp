#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    int k = 0;
    vector<int> pref(n + 1);
    for (int i=1; i <= n; i++) {
        int num; cin >> num;
        if (num < i) {
            pref[i] = pref[i - 2] + 1;
        } else {
            pref[i] = pref[i - 1];
        }
    }

    for (auto cara: pref) cout << cara << " ";
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
