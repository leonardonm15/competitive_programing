#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 

const int N = 100 + 5;
const int M = 1e5 + 5;

int dp[N][M];

void solve () {
    int n; cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        int atual = arr[i];
        dp[i][atual]++;
        if (i == 0) continue;

        for (int j = 0; j < M; j++) {
            if (dp[i - 1][j]) {
                dp[i][j]++;
                dp[i][j + atual]++;
            }
        }
    }

    vector<int> resp;
    for (int i = 0; i < M; i++) {
        if (dp[n - 1][i]) resp.push_back(i);
    }

    cout << resp.size() << endl;
    for (auto v: resp) cout << v << " ";
    cout << endl;
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
