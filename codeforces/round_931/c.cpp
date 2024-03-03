#include <bits/stdc++.h>

using namespace std;

/* #define endl '\n' */ 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, m; cin >> n >> m;
    cout << "? " << 1 << " " << 1 << endl;
    int num;
    cin >> num;

    if (num == 1 && n == 1 && m == 2) {
        cout << "! " << 1 << " " << 2 << endl;
        return;
    }
    if (num == 1 && n == 2 && m == 1) {
        cout << "! " << 2 << " " << 1 << endl;
        return;
    }

    if (num > 1) {
        cout << "? " << 1 + num << " " << 1 << endl;
        int down; cin >> down;
        cout << "? " << 1 << " " << 1 + num << endl;
        int side; cin >> side;

        cout << "? " << 1 + (side / 2) << " " << (1 + num) - (side - (side / 2)) << endl;
        int c1; cin >> c1;

        if (!c1) cout << "! " << 1 + (side / 2) << " " << (1 + num) - (side - (side / 2)) << endl;
        else cout << "! " << (1 + num) - (down - (down / 2)) << " " << 1 + (down / 2) << endl;
    } else if (num == 0) {
        cout << "! " << 1 << " " << 1 << endl;
    } else {
        cout << "? " << 2 << " " << 1 << endl;
        int num; cin >> num;
        if (!num) {
            cout << "! " << 2 << " " << 1 << endl;
        } else {
            cout << "! " << 1 << " " << 2 << endl;
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
