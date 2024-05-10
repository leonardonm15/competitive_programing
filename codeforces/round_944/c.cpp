#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int a, b, c, d; cin >> a >> b >> c >> d;
    a--;
    b--;
    c--;
    d--;
    int x = max(a, b);
    int y = min(a, b);
    int u = max(c, d);
    int v = min(c, d);

    vector<int> arr(13);
    int i = 0;
    while (((y + i - 1) % 12) != x) {
        cout << "b + i -> " <<  y + i << endl;
        arr[(y + i) % 12] = 1;
        i++;
    }

    /* for (int i=0; i < (int)arr.size(); i++) { */
    /*     cout << arr[i] << " "; */
    /* } */
    /* cout << endl; */

    cout << (arr[u] == arr[v] ? "NO" : "YES") << endl;
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
