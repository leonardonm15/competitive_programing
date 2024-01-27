#include <bits/stdc++.h>

using namespace std;

/* #define endl '\n' */ 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    vector<vector<int>> arr(n);
    for (int i=0; i < n; i++) {
        int m; cin >> m;
        vector<int> a;
        for (int j=0; j < m; j++) {
            int num; cin >> num;
            a.push_back(num);
        }
        arr[i] = a;
    }

    for (int i=0; i < n; i++) {
        for (int j=i; j < n; j++) {
        }
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
