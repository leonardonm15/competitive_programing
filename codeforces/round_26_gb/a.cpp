#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    for (int i = 0; i < n; i++) {
        if ((sum - arr[i]) != arr[i]) {
            string resp;
            cout << "YES" << endl;
            for (int j = 0; j < n; j++) {
                if (j == i) resp.push_back('R');
                else resp.push_back('B');
            }
            return;
        }
    }

    cout << "NO" << endl;

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
