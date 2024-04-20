#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
const int N = 100;
const int MOD = 1e9 + 7;
int resp = 0;
int k;

void calc(int c, int lc, vector<int>& v) {
    if (c == k) {
        resp++;
        resp %= MOD;
    }
    for (auto cara: v) {
        if (c + cara <= k && cara >= lc) {
            calc(c + cara, cara, v);
        }
    }
}

void solve () {
    int n; cin >> n >> k;
    vector<int> arr(n);
    for (int i=0; i < n; i++) cin >> arr[i];

    for (int i=0; i < n; i++) {
        calc(arr[i], arr[i], arr);
    }

    cout << resp << endl;
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
