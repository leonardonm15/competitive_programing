#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    if (n&1) {
        vector<int> v1;
        vector<int> v2;
        if (n == 1) {
            cout << 1 << endl;
            return;
        }

        int resp = 1e18 + 100;
        for (int i = 0; i < n; i++) {
            // 1 2 4 6 7
            if (i&1) continue;
            int score = 1;
            for (int j = i - 1; j > 0; j -= 2) {
                score = max(score, arr[j] - arr[j - 1]);
            }

            for (int j = i + 2; j < n; j += 2) {
                score = max(score, arr[j] - arr[j - 1]);
            }

            /* cout << "--------------------" << endl; */
            /* cout << "i -> " << i << endl; */
            /* cout << "score -> " << score << endl; */
            
            resp = min(score, resp);
        }

        cout << resp << endl;

    } else {

        int resp = 1;
        for (int i = 1; i < n; i += 2) {
            resp = max(resp, arr[i] - arr[i - 1]);
        }
        cout << resp << endl;

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
