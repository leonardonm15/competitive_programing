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

    for (int i=0; i < n; i++) {
        cin >> arr[i];
    }

    int k = arr[0];
    int i = 0;
    while(i < n && arr[i] == k) i++;

    int j = n - 1;
    int q = arr[n - 1];
    while (j > 0 && arr[j] == q) j--;

    if (q == k) {
        /* cout << "i -> " << i << endl; */
        /* cout << "j -> " << j << endl; */
        if (i > j) cout << 0 << endl;
        else {
            cout << j - i + 1 << endl;
        }
    } else {
        cout << min(j - 0 + 1, (n - 1) - i + 1) << endl;
    }
    
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
