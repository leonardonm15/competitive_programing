#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

map<int, vector<int>> mod;

void solve () {
    int n, k; cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        mod[num % k].push_back(num);
    }

    int resp = 0;
    int counter = 0;
    for (auto& [m, vec]: mod) {
        if (!(vec.size()&1)) {
            for (int i = 1; i < vec.size(); i += 2) resp += arr[i] - arr[i - 1];
        } else {
            c++;
            if (c == 2) {
                cout << -1 << endl;
                return;
            }

            if (vec.size() == 1) continue;
            vector<int> dp(vec.size(), 1e18);
            dp[0] = 0;
            dp[1] = arr[0] - arr[1];
            for (int i = 1; i < dp.size(); i++) {
                
            }
            sort(vec.rbegin(), vec.rend());

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
