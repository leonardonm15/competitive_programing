#include <bits/stdc++.h>

using namespace std;

/* #define endl '\n' */ 
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> pref(n + 1);
    pref[0] = -1;
    pref[1] = -1;

    bool flag = true;
    for (int i = 2; i <= n; i++) {
        cout << "? " << 1 << " " << i << endl;
        cin >> pref[i];
        if (pref[i] >= 1) flag = false;
    }

    if (flag) {
        cout << "! IMPOSSIBLE" << endl;
        return;
    }

    string k;
    for (int i = 1; i <= n; i++) {
        k.push_back('1');
        if (i > 1 && pref[i - 1] == 0 && pref[i] > 0) {
            for (int j = 1; j <= pref[i]; j++) {
                k[k.size() - j - 1] = '0';
            }
        }

        if (i > 1 && pref[i] == pref[i - 1]) k[(int) k.size() - 1] = '0';
    }

    cout << "! " << k << endl;

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
