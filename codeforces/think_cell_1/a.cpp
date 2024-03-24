#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    int resp = 0;
    vector<int> arr(2 * n);
    for (int i=0; i < 2 * n; i++) cin >> arr[i];

    sort(arr.rbegin(), arr.rend());


    for (int i=0; i < (2 * n) - 1; i+= 2) {
        resp += min(arr[i], arr[i + 1]);
    }

    cout << resp << endl;
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
