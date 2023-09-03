#include <bits/stdc++.h>

using namespace std;
//#define int long long
// leonardo nunes muniz

void solve () {
    int n; cin >> n;
    vector<int> arr(n + 1);
    for (int i=1; i <= n; i++) {
        int num; cin >> num;
        if (num > 0) arr[num]++;
    }
    for (int i=1; i <= n; i++) {
        if (!arr[i]) {
            cout << i << endl;
            return;
        }
    }
    cout << "TODOS OS NUMEROS DA SEQUENCIA ESTÃO PRESENTES" << endl;
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
