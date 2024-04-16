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
    string resp;
    for (int i=n - 1; i >= 0; i--) {
        if (s[i] != '0') {
            resp.push_back(('a' - 1) + (s[i] - '0'));
        } else {
            string c;
            c += s[i - 2];
            c += s[i - 1];
            int num = stoi(c);
            /* cout << "num -> " << num << endl; */
            resp.push_back('a' + num - 1);
            i -= 2;
        }
    }

    reverse(resp.begin(), resp.end());
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
