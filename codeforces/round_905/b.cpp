#include <bits/stdc++.h> 
using namespace std;
//#define int long long

void solve () {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    vector<int> arr(100);
        if ((n - k) == 1) {
        cout << "YES" << endl;
        return;
    }
    for (int i=0; i < n; i++) {
        int num  = s[i] - 'a';
        arr[num]++;
    }
    int imp = 0;
    int par = 0;
    for (int i=0; i < 100; i++) {
        if (arr[i] == 0) continue;
        if (arr[i] % 2 == 1) imp++;
        else par++;
    }
    // diminuir da quantidade de impares
    // se k for >= -1 da certo
    if (k - imp >= -1) cout << "YES" << endl;
    else cout << "NO" << endl;
    // || (imp == 0 && k % 2 == 1)
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
