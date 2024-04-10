#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, c, p1, p2; cin >> n >> c >> p1 >> p2;
    vector<int> arr(n);

    for (int i=0; i < n; i++) cin >> arr[i];

    for (int i=0; i < n; i++) arr.push_back(arr[i] + c);
    // 2 5 8 10 15 | 22 25 28 30 35

    int resp = 1e9 + 5;
    for (int i=0; i < n; i++) {
        for (int j = i; j < i + n; j++) {
            
        }
    }
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
