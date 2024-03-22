#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    vector<int> arr(n + 1);
    for (int i=1; i <= n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());
    int mid = (n + 1) / 2;
    int i = mid;
    int resp = 0;
    while (i <= n && arr[mid] == arr[i]) {
        resp++;
        i++;
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
