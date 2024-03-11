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

    for (int i=1; i < n - 1; i++) {
        if (arr[i - 1] >= 1 && arr[i] >= 2 && arr[i + 1] >= 1) {
            int p2 = arr[i] / 2;
            int p1 = arr[i - 1];
            int p3 = arr[i + 1];
            arr[i] -= (2 * (min({p2, p1, p3})));
            arr[i - 1] -= min({p2, p1, p3});
            arr[i + 1] -= min({p2, p1, p3});
        }
    }

    for (int i=0; i < n; i++) {
        if (arr[i] > 0) {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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
