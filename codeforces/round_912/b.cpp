#include <bits/stdc++.h>

using namespace std;
// #define int long long

void solve () {
    int n; cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));

    for (int i=0; i < n; i++) {
        for (int j=0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    if (n == 1) {
        cout << "YES" << endl;
        cout << 1 << endl;
        return;
    }

    vector<int> resp(n);
    for (int i=0; i < n; i++) {
        resp[i] = (i << 30) - 1;
    }

    for (int i=0; i < n; i++) {
        for (int j=0; j < n; j++) {
            if (i != j) {
                resp[i] &= arr[i][j];
                resp[j] &= arr[i][j];
            }
        }
    }

    for (int i=0; i < n; i++) {
        for (int j=0; j < n; j++) {
            if (i == j) continue;
            if ((resp[i] | resp[j]) != arr[i][j]) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
    for (auto cara: resp) cout << cara << " ";
    cout << endl;
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
