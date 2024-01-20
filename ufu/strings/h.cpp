#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    string s;
    getline(std::cin, s);
    int n; cin >> n;

    for (auto& c: s) {
        if ((c - 'a' >= 0 && c - 'a' <= 26)) {
            c = 'a' + (((c - 'a') + n) % 26);
        } else if ((c - 'A' >= 0 && c - 'A' <= 26)) {
            c = 'A' + (((c - 'A') + n) % 26);
        }
    }

    cout << s << endl;
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
