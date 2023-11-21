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
    int acc = 0;
    int resp = -1e18;
    for (int i=0; i < n; i++) {
        acc += arr[i];
        resp = max(resp, acc);
        /* cout << "acc -> " << acc << endl; */
        if (acc < 0 || abs(arr[i + 1] % 2) == abs(arr[i] % 2)) acc = 0;
    }
    resp = max(resp, *max_element(arr.begin(), arr.end()));
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
