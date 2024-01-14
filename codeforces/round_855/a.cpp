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
    string m = "meow";
    string resp;
    for (int i=0; i < n; ) {
        char c = (char) tolower(s[i]);
        /* cout << "c -> " << c << endl; */
        resp.push_back((char) tolower(s[i]));
        while (i < n && (char) tolower(s[i]) == c) i++;
    }
    /* cout << "resp -> " << resp << endl; */
    if (resp == m) cout << "YES" << endl;
    else cout << "NO" << endl;
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
