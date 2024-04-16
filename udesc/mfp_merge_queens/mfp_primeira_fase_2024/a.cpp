#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for (int i=0; i < n; i++) cin >> arr[i];
    int l = 1;
    int r = 1e9 + 1;
    int resp = 1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        int a = 0;
        for (int i=0; i < n; i++) {
            a += mid / arr[i];
        }
        if (a >= k) {
            resp = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << resp << endl;
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
