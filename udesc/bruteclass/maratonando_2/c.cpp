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
    map<int, int> f;
    for (int i=0; i < n; i++) cin >> arr[i];

    reverse(arr.begin(), arr.end());
    int resp = n;
    for (int i=0; i < n; i++) {
        if (!f[arr[i]]) f[arr[i]]++;
        else {
            resp = i;
            break;
        }
    }

    cout << n - resp << endl;
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
