#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    string s; cin >> s;
    map<pair<char, char>, int> map;
    pair<char, char> lp = {'~', '~'};
    int resp = 0;
    for (int i=0; i < n - 1; i++) {
        /* pair<char, char> p = {s[i], s[i + 1]}; */
        if (i < n - 2 && s[i] == s[i + 2]) continue;
        resp++;
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
