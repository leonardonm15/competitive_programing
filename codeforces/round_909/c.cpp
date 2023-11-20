#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    int resp = -1e4;
    vector<int> arr(n);
    for (int i=0; i < n; i++) cin >> arr[i];

    int curr = 0;
    for (int i=1; i < n; i++) {
        if (abs(arr[i] % 2) != abs(arr[i - 1] % 2))  {
            if (resp == -1e4) resp = 0;
            curr += arr[i - 1];
            if (i == n - 1) {
                curr += arr[i];
                resp = max(resp, curr);
                break;
            }
        }
        else {
            curr += arr[i];
            resp = max(resp, curr);
            curr = 0;
        }
        cout << curr << endl;
    }

    cout << max(resp, *max_element(arr.begin(), arr.end())) << endl;
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
