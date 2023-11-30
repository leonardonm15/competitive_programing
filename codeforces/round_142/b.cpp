#include <bits/stdc++.hV

using namespace std;
#define int long long

void solve () {
    int n; cin >> n;
    for (int j=0; j < n; j++) {
        int k; cin >> k; 
        int num = k;
        bool flag = false;
        int acc = 1;
        for (int i=2; i * i <= num; i++) {
            if (num % i == 0) {
                flag = true;
                while (num > 1 && num % i == 0) {
                    num /= i;
                    if (k % num == 0 && num * i != k) break;
                }
                /* cout << "num -> " << num << endl; */
                if (num > 1) {
                    cout << "NO" << endl;
                    break;
                }
                else {
                    cout << "YES" << endl;
                    break;
                }
            }
        }
        /* cout << "flag -> " << flag << endl; */
        if (!flag) cout << "NO" << endl;
    }
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
