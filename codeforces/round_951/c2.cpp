#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long


int lcm (int a, int b) {
    return ((a * b) / gcd(a, b));
}
void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int soma = 0;
    int mmc = 1;
    for (int i = 0; i < n; i++) {
        mmc = lcm(mmc, arr[i]);
    }

    for (int i = 0; i < n; i++) { // 
        soma += mmc/arr[i];
    }

    if (soma < mmc) {
        for (int i = 0; i < n; i++) {
            cout << mmc/arr[i] << " ";
        }
        cout << endl;
    } else cout << -1 << endl;

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
