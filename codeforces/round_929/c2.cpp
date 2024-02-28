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

    sort(arr.begin(), arr.end());

    if ((arr[0] == 1) && (arr[1] == 1)) {
        cout << "NO" << endl;
        return;
    } 

    bool flag = true;
    if (arr[0] != 1) {
        for (int i=1; i < n; i++) {
            if (arr[i] % arr[0] == 0) continue;
            else flag = false;
        }
    }

    if (flag && arr[0] != 1) {
        cout << "NO" << endl;
        return;
    } else {
        cout << "YES" << endl;
        return;
    }

    for (int i=1; i < n; i++) {
        if ((arr[i] % arr[i - 1]) == 0 && (arr[i - 1] % arr[i]) == 0) continue;
        else {
            cout << "arr[i] -> " << arr[i] << endl;
            cout << "arr[i - 1] -> " << arr[i - 1] << endl;
            cout << (arr[i - 1] % arr[i]) << endl;
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
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
