#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    string s; cin >> s;
    map<char, int> map;
    int resp = 0;
    int l = 0;
    int r = 0;
    while (r <= n - 1) {
        while (s[l] == s[r]) {
            if ((r - l) + 1 > map[s[r]]) map[s[r]]++;
            r++;
        }
        if (s[l] != s[r]) l = r;
    }
    for (auto [cara, f]: map) {
        resp += f;
    }
    cout << resp << endl;
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
