#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

const int N = 1e7 + 5;
vector<int> dp(N, -1);
vector<int> arr;

int calc(int i, int sz) {
    /* cout << "I -> " << i << endl; */
    if (i > sz) return 0;
    /* cout << "I -> " << i << endl; */
    if (dp[i] != -1) return dp[i];
    /* cout << "I -> " << i << endl; */
    dp[i] = arr[i] + max(calc(2 * i, sz), calc(2 * i + 1, sz));
    /* cout << "dp[i] -> " << dp[i] << endl; */
    return dp[i];
}

void solve () {
    int n; cin >> n;
    int k = 1;
    for (int i=0; i < n; i++) k *= 2;
    arr.resize(k);
    for (int i=1; i < k; i++) cin >> arr[i];

    calc(1, arr.size() - 1);
    cout << dp[1] << endl;
}

signed main() {
    /* ios_base::sync_with_stdio(0);cin.tie(0); */
    int TC = 0;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
