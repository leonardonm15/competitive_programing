#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for (int i=0; i < n; i++) cin >> arr[i];
    int l = 0;
    int r = n - 1;
    int resp = 0;

    while (l < r) {
        int x = min(arr[l], arr[r]);
        // se l for menor
        if (arr[l] <= arr[r] && k >= (2 * x) - 1) {
            arr[r] -= (arr[l] - 1); //2 2 3
            k -= (2 * x) - 1;
            resp++;
            l++;
            if (k >= 1) {
                k--;
                arr[r]--;
            }
            if (arr[r] == 0) {
                resp++;
                r--;
            }
        } else if (arr[r] < arr[l] && k >= (2 * arr[r])) {
            arr[l] -= arr[r];
            k -= 2 * arr[r];
            resp++;
            r--;
        } else break;
    }

    // check l == r
    if (l == r && k > 0) {
        k -= arr[r];
        if (k >= 0) resp++;
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
