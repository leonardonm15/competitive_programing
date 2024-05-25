#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

bool is_prime(int n) {
    if (n == 1) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

void solve () {
    int n; cin >> n;
    for (int i=0; i < n; i++) {
        int a; cin >> a;
        int l = a / 2;
        int r = a - l;
        // cout << "l -> " << l << endl;
        // cout << "r -> " << r << endl;
        bool flag = false;
        while (is_prime(l) || is_prime(r)) {
            // cout << "---------------" << endl;
            // cout << "l -> " << l << endl;
            // cout << "r -> " << r << endl;
            if (l == 0 || r == n) {
                cout << -1 << endl;
                flag = true;
                break;
            }
            l--;
            r++;
        }

        if (!flag) cout << l << " " << r << endl;
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
