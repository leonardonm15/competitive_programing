#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, d, k; cin >> n >> d >> k;
    vector<int> soma(n + 50);
    vector<int> sub(n + 50);
    for (int i = 0; i < k; i++) {
        int l, r; cin >> l >> r;
        soma[l]++;
        sub[r + 1]--;
    }

    int curr = 0;
    int l = 0;
    int r = 0;
    int brother = 1;
    int respbrother = 0;
    for (int i = 0; i <= n; i++) {
        if (r - l + 1 < d) {
            r++;
            curr += soma[r];
        } 
        if (r - l + 1 == d) {
            curr += sub[l];
            if (curr > respbrother && l > 0 && r <= n) {
                respbrother = curr;
                brother = l;
            }
            l++;
        }
    }

    curr = 0;
    l = 0;
    r = 0;
    int mom = 1;
    int respmom = 1e18;
    for (int i = 0; i <= n; i++) {
        if (r - l + 1 < d) {
            r++;
            curr += soma[r];
        }
        if (r - l + 1 == d) {
            curr += sub[l];
            if (curr < respmom && l > 0 && r <= n) {
                respmom = curr;
                mom = l;
            }
            l++;
        }
    }

    cout << brother << " " << mom << endl;
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
