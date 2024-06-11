#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    int resp = 0;
    int msum = 0;
    for (int i = 2; i <= n; i++) {
        int sum = 0;
        int k = 0;
        while (k * i <= n) {
            sum += k * i;
            k++;
        }

        if (sum >= msum) {
            resp = i;
            msum = sum;
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
