#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    int a = 0, b = 0;
    for (int i = 0; i < 2 * n; i++) {
        int num; cin >> num;
        if (num) a++;
        else b++;
    }


    /* cout << "a -> " << a << endl; */
    /* cout << "b -> " << b << endl; */
    if (b - a == b) {
        cout << 0 << " "<< 0 << endl;
        return;
    }
    if (!(a&1) && !(b&1)) {
        cout << 0 <<  " " << min(a, b) << endl;
    } else {
        cout << 1 << " " << (int)(min(a, b)) << endl;
    }

    /* else (!(a&1) && (b&1) || !(b&1) && (a&1)) { */
    /*     cout << 1 << " " << (int)(min(a, b)) << endl; */
    /* } */

    /* if (a&1 && b&1) { */
    /*     cout << 1 << " " << min( */
    /* } */




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
