#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    vector<int> arr(27 + 1);

    arr[27]++;
    arr[27 - 9]++;
    arr[27 - 25]++;

    int k = 1;
    /* for (int i = 1; i <= 27; i++) { */
    /*     if (!arr[i]) arr[i] = k++; */
    /*     else k = 1; */
    /* } */

    for (int i = 1; i <= 27; i++) cout << arr[i] << " ";
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
