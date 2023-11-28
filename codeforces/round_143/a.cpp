#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr[n];
    for (int i=0; i < n; i++) {
        for (int j=0; j < 3; j++) {
                int num; cin >> num;
            arr[i].push_back(num);
        }
    }
    int resp = 0;
    for (int i = 0; i < n; i++) {
        int soma = arr[i][0] + arr[i][1] + arr[i][2];
        if (soma > 1) resp++;
    }
    /* cout << arr[1][0] << " " << arr[1][1] << " " << arr[1][2] << endl; */
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
