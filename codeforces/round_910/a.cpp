#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n, k; cin >> n >> k;
    string s; cin >> s;
    map<char, int> map;

    int nb = 0;
    for (auto cara: s) map[cara]++;
    /* cout << "b -> " << map['B'] << endl; */
    /* cout << "a -> " << map['A'] << endl; */

    if (map['B'] == k) {
        cout << 0 << endl;
        return;
    }

    /* if (k == 0) { */
    /*     cout << 1 << endl; */
    /*     cout << map['B'] << " " <<  'A' << endl; */
    /*     return; */
    /* } */
    int i = 1;
    for (auto cara: s) {
    /* cout << "quantidade de b - > " << map['B'] - nb << endl; */
        if (cara == 'B') {
            nb++;
        }
        if (map['B'] - nb == k) {
            cout << 1 << endl;
            cout << i << " " << 'A' << endl;
            return;
        }
        i++;
    }

    nb = 0;
    i = 1;
    for (auto cara: s) {
        if (cara == 'A') {
            nb++;
        }
        if (map['B'] + nb == k) {
            cout << 1 << endl;
            cout << i << " " << 'B' << endl;
            return;
        }
        i++;
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
