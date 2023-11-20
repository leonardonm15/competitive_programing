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
    int maxi = 0;
    int mini = 1e10;

    for (int i=0; i < n; i++) {
        int num; cin >> num;
        arr[i] = num;
        maxi = max(maxi, num);
        mini = min(mini, num);
    }
    
    int diff = 0;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            vector<int> qs = {i, n/i};
            for (auto cara: qs) {
                int cum = 0;
                int k = n/cara;
                int minik = 1e18;
                int maxik = -1e18;
                for (int j=0; j < n; j++) {
                    cum += arr[j];
                    /* cout << "cum -> " << cum << endl; */
                    /* cout << "arr[j] -> " << arr[j] << endl; */
                    if ((j + 1) % k == 0) {
                        /* cout << "j -> " << j << endl; */
                        /* cout << "cum -> " << cum << endl; */
                        maxik = max(cum, maxik);
                        minik = min(minik, cum);
                        diff = max(diff, abs(maxik - minik));
                        cum = 0;
                    }
                }
            }
        }
    }
    /* cout << "diff -> " << diff << endl; */
    /* cout << "diff unitaria  -> " << abs(maxi - mini) << endl; */
    cout << max(abs(maxi - mini), diff) << endl;
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
