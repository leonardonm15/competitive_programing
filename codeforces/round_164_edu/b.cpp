#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i=0; i < n; i++) cin >> arr[i];
    int k = 0;
    for (int i=0; i < n; i++) {
        if (arr[i] != arr[n - 1]) {
            k = i;
            break;
        }
    }

    for (int i=n - 1; i >= 0; i--) {
        if (arr[i] != arr[0]) {
            k = min(k, (n - 1) - i);
            break;
        }
    }

    cout << (k == 0 ? -1: k) << endl;
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
