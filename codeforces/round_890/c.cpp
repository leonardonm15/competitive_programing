#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i=0; i < n; i++) cin >> arr[i];
    // zaabaabz
    int resp = 0;
    for (int i=0; i < n; i++) {
        int k = i;
        int counter = 0;
        for (int j = i + 1; j < n; j++) {

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