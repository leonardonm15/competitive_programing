#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    int n; cin >> n;
    int soma = 0;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        soma += num;
    }
    
    bool flag = false;
    for (int i=1; i * i <= soma; i++) {
        if ((i * i) == soma) {
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
