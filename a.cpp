#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    vector<int> v(26);
    string s; cin >> s;
    int n = s.size(), res = 0;
    for(int i = 0; i < n; i++){
        if(v[s[i] - 'A'] > 0){
            res++;
        }
        else{
            res += 2;
            v[s[i] - 'A']++;
        }
    }
    cout << res << endl;
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
