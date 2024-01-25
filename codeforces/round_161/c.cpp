#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    vector<int> l(n);
    vector<int> r(n);
    for (int i=0; i < n; i++) cin >> arr[i];
    
    l[1] = 1;
    for (int i=1; i < n - 1; i++) {
        int a = arr[i] - arr[i - 1];
        int b = arr[i + 1] - arr[i];
        l[i] = (a > b ? l[i - 1] + 1 : l[i - 1] + abs(arr[i] - arr[i - 1]));
    }
    l[n - 1]  = l[n - 2] + 1;

    r[n - 2] = 1;
    for (int i= n - 2; i > 1; i--) {
        int a = arr[i] - arr[i + 1];
        int b = arr[i] - arr[i - 1];
        r[i] = (a > b ? r[i + 1] + 1 : r[i + 1] + (abs(arr[i] - arr[i + 1])));
    }
    r[0] = r[1] + 1;


    /* cout << "l -> " << endl; */
    /* for (auto cara: l) cout << cara << " "; */
    /* cout << endl; */

    /* cout << "r -> " << endl; */
    /* for (auto cara: r) cout << cara << " "; */
    /* cout << endl; */

    int q; cin >> q;
    while (q--) {
        int x, y; cin >> x >> y;
        x--; y--;
        if (x < y) {
            cout << l[y] - l[x] << endl;
        } else {
            cout << r[x] - r[y] << endl;
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
