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
    vector<int> f1(n);
    vector<int> mc1(n + 1);
    vector<int> f2(n);
    vector<int> mc2(n + 1);

    for (int i=0; i < n; i++) cin >> arr[i];

    int k = 0;
    for (int i=0; i < n; i++) {
        f1[arr[i]]++;
        while(k < n && f1[k]) k++;
        mc1[i] = k;
    }

    k = 0;
    for (int i=n - 1; i >= 0; i--) {
        f2[arr[i]]++;
        while (k < n && f2[k]) k++;
        mc2[i] = k;
    }

    for (int i=0; i < n; i++) {
        if (mc1[i] == mc2[i + 1]) {
            cout << 2 << endl;
            cout << 1 << " " << i + 1 << endl;
            cout << i + 2 << " " << n << endl;
            return;
        }
    }

    cout << -1 << endl;
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
