#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, l, r; cin >> n >> l >> r;
    vector<int> arr(n);
    for (int i=0; i < n; i++) cin >> arr[i];
    for (auto cara: arr) {
        if (cara <= l) {
            cout << l << " ";
        } else if (cara >= r) {
            cout << r << " ";
        } else {
            cout << cara << " ";
        }
    }
    cout << endl;
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
