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
    bool flag = false;
    for (int i=0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    for (int i=0; i < n - 1; i++) {
        if (arr[i] >= arr[i + 1]) {
            flag = true;
        }
    }
    if (flag) cout << "NO" << endl;
    else cout << "YES" << endl;
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
