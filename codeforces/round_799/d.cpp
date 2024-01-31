#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    string s; cin >> s;
    int k; cin >> k;
    map<pair<int, int>, int> map;
    int resp = 0;
    int h, m; 

    h = (s[0] - '0') * 10 + (s[1] - '0');
    m = (s[3] - '0') * 10 + (s[4] - '0');

    int v = h * 60 + m;
    while (true) {
        int ch = (v / 60) % 24;
        int cm = v % 60;
        cout << ch << ":" << cm << endl;
        if (ch % 10 == cm / 10 && ch / 10 == cm % 10 && !map[{ch, cm}]) resp++;
        if (cm == m && ch == h) break;
        v += k;
        v %= 24 * 60;
    }

    cout << resp << endl;
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
