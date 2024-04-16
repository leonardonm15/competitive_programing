#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    int a = 0;
    int b = 0;
    for (int i=0; i < n; i++) {
        string s;
        cin >> s >> s;
        int t = s[0] - '0';
        cin >> s;
        if (t == 1) a += s[s.size() - 1] - '0';
        else b += s[s.size() - 1] - '0';
    }

    cout << a << "x" << b << endl;
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
