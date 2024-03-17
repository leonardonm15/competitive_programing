#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, k; cin >> n >> k;
    vector<int> arr(2 * n);
    for (int i=0; i < 2 * n; i++) cin >> arr[i];

    sort(arr.begin(), arr.begin() + n);
    sort(arr.begin() + n, arr.end());

    map<int, set<pair<int, int>>> map;
    int curr = 0;
    for (int i=0; i < n; i++) {
        curr ^= arr[i];
        if (i < (2 * k) - 1) continue;
        else {
            map[curr].emplace(make_pair(i - ((2 * k) - 1), i));
            curr ^= arr[i - (2 * k) - 1];
            cout << "curr -> " << curr << endl;
        }
    }

    cout << "arr -> ";
    for (auto cara: arr) cout << cara << " ";
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
