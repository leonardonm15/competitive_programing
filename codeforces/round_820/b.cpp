#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    string s, resp; cin >> s;
    reverse(s.begin(), s.end());

    for (int i=0; i < n;){
        if (s[i] - '0' > 0) {
            resp.push_back((s[i] - '0')  + 'a' - 1);
            i++;
        }
        else {
            resp.push_back((((s[i + 2] - '0') * 10) + (s[i + 1] - '0')) + 'a' - 1);
            i += 3;
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
