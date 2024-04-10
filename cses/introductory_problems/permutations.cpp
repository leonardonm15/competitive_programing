#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () { 
    int n; cin >> n;
    vector<int> arr;
    arr.push_back(-1);
    for (int i=2; i <= n; i += 2) arr.push_back(i);
    for (int i=1; i <= n; i += 2) arr.push_back(i);
    for (int i=1; i <= n; i++) {
        if (arr[i - 1] == arr[i] - 1 || arr[i - 1] == arr[i] + 1 || n == 2) {
            cout << "NO SOLUTION" << endl;
            return;
        }
    }
    for (int i=1; i <= n; i++) {
        cout << arr[i] << " ";
    }
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
