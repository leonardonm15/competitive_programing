#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n = 8;
    vector<string> arr(n);
    for (int i=0; i < n; i++) cin >> arr[i];

    for (int i=0; i < n; i++) {
        int c = 0;
        for (int j=0; j < n; j++) {
            if (arr[i][j] == 'R') c++;
        }
        if (c == 8) {
            cout << "R" << endl;
            return;
        } else c = 0;
    }

    for (int i=0; i < n; i++) {
        int c = 0;
        for (int j=0; j < n; j++) {
            if (arr[j][i] == 'B') c++;
        }
        if (c == 8) {
            cout << "B" << endl;
            return;
        } else c = 0;
    }
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
