#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    char c; cin >> c;
    map<char, multiset<int>> map;

    for (int i=0; i < n * 2; i++){
        string s; cin >> s;
        map[s[0]].emplace(s[1] - '0');
    }


    cout << "arr -> ";
    for (auto cara: arr) cout << cara << " ";
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
