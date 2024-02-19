#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    vector<string> arr(n);
    for (int i=0; i < n; i++) cin >> arr[i];

    for (int i=0; i < n; i++) {
        int a = 0;
        for (int j=0; j < n; j++) {
            if (arr[i][j] == '1') a++;
        }
        if (a == 1) {
            cout << "TRIANGLE" << endl;
            return;
        }
    }

    cout << "SQUARE" << endl;
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
