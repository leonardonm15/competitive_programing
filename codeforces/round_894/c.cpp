#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr;
    vector<int> rarr;
    vector<int> set;
    map<int, int, greater<int>> map;

    for (int i=0; i < n; i++) {
        int num; cin >> num;
        
        if (set.empty() || num != set[i - 1]) {
            set.push_back(num);
        }

        arr.push_back(num);
        map[num]++;
    }

    if (n == 1) {
        if (arr[0] > 1) cout << "NO" << endl;
        else cout << "YES" << endl;
        return;
    }
    
    // quando é 55533
    // quando é 54321
    int inv = 1;
    int k = n;
    for (auto [cara, f]: map) {
        int c = k;
        k -= map[inv];
        /* cout << "map cara -> " << map[cara] << endl; */
        while (map[cara]--) {
            /* cout << "K -> " << k << endl; */
            rarr.push_back(c);
        }

    }
    for (auto cara: arr) cout << cara << " ";
    cout << endl;

    for (auto cara: rarr) cout << cara << " ";
    cout << endl;
    
    cout << (arr == rarr ? "YES" : "NO") << endl;
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
