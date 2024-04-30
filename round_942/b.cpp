#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

set<vector<int>> dp[104];
map<vector<int>, int> mp;
void solve () {
    int n; cin >> n;
    string s; cin >> s;

    vector<int> arr;
    for (auto c: s) {
        if (c == 'U') arr.push_back(1);
        else arr.push_back(0);
    }

    dp[0].emplace(arr);
    
    bool win = false;
    for (int i=0; i <= n + 2; i++) {
        cout << " -------- " << i << " ---------" << endl;
        for (auto vec: dp[i]) {

            cout << "vec -> ";
            for (auto cara: vec) cout << cara << " ";
            cout << endl;

            if (vec.size() == 0 && i&1) win = true;
            bool all_z = false;
            for (int j=0; j < (int)vec.size(); j++) {
                if (vec[j] == 1) {
                    vector<int> np = vec;
                    np[(j + 1) % vec.size()] ^= 1;
                    np[((j - 1) + vec.size()) % vec.size()] ^= 1;
                    np.erase(np.begin() + j);
                    dp[i + 1].emplace(np);
                    all_z = false;
                }
            }

            if (all_z && i&1) win = true;
        }
    }

    for (int i = 0; i <= n + 2; i++) {
        dp[i].clear();
    }
    cout << (win ? "YES" : "NO") << endl;
}

signed main() {
    /* ios_base::sync_with_stdio(0);cin.tie(0); */
    int TC = 1;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}

