#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, a, k; cin >> n >> a >> k;
    vector<int> arr(n);
    for (int i=0; i < n; i++) cin >> arr[i];

    int resp = 0;
    for (int i=0; i < n; i++) {
        if (arr[i] <= k) {
            int sz = 0;
            while (x < n && arr[i] <= k) {
                sz++;
                x++;
                i++;
            }

            if (sz >= a) {
                if (sz == a) resp++;
                else {
                    int b = sz - a + 1;
                    resp += (b * (b + 1)) / 2;
                }
            }
        }
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
