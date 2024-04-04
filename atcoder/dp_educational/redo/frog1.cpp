#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    vector<int> dp(n);
    for (int i=0; i < n; i++) cin >> arr[i];
    for (int i=1; i < n; i++) {
        int j1 = 1e9 + 5;
        int j2 = 1e9 + 5;
        if (i - 1 >= 0) j1 = dp[i - 1] + abs(arr[i] - dp[i - 1]);
        if (i - 2 >= 0) j2 = dp[i - 2] + abs(arr[i] - dp[i - 2]);
        dp[i] += min(j1, j2);
    }

    cout << "arr -> ";
    for (auto cara: arr) cout << cara << " ";
    cout << endl;

    cout << "dp-> ";
    for (auto cara: dp) cout << cara << " ";
    cout << endl;

    /* cout << dp[n - 1] + arr[n - 1] << endl; */
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
