#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {

    for (int i=0; i < 3; i++) {
        string s; cin >> s;
        vector<int> arr(3);
        bool flag = false;
        for (auto cara: s) {
            if (cara == 'A' || cara == 'B' || cara == 'C') {
                arr[cara - 'A']++;
            } else {
                flag = true;
            }
        }
        if (flag) {
            for (int i=0; i < 3; i++){
                if (arr[i] == 0) {
                    cout << (char)('A' + i) << endl;
                }
            }
        }
        for (int i=0; i < 3; i++) {
            arr[i] = 0;
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
