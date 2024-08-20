#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    int resp = 0;
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> gd(100);
    for (int i = 0; i < 50; i++) {
        vector<int> mex(100);
        for (int j = i - 1; j >= 0; j--) {
            if (gcd(i, i - j) == 1) {
                mex[gd[j]]++;
            }
        }

        int mx = 0;
        while (mex[mx]) mx++;

        /* if (mx == 2) cout << i << " "; */
        gd[i] = mx;
    }

    cout << "GD -> ";
    for (int i = 0; i <= 10; i++) cout << gd[i] << " ";
    cout << endl;

    for (int num = 0; num < 40; num++) {
        int k = 0;
        if (num > 3 && (num % 3 == 0 && num&1) || num % 2 == 0) {
            k = 0;
        } else {
            k = num % 6;
            /* if (num > 3) { */
            /*     int aux = (num - 3) / 6; */
            /*     aux++; */
            /*     k = (num - aux + 1) / 2; */
            /* } else { */
            /*     k = (num + 1) / 2; */
            /* } */
        }

        if (k != gd[num]) {
            cout << "num errado -> " << gd[num] << " VS " << k << endl;
            cout << "num -> " << num << endl;
            return;
        }
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
