#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    vector<int> vis(101);
    vector<int> arr;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        if (vis[num] == 0) {
            arr.push_back(num);
            vis[num]++;
        }
    }
    sort(arr.begin(), arr.end());
    int k = arr.size();
    if (k == 1) cout << arr[0] << endl;
    else cout << arr[k - 2] << endl;
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
