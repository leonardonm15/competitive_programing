#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    vector<string> resp;
    string s; cin >> s; // reverse reverse eterno
    resp.push_back(s);
    string v = s;
    string k = s;
    string c = s;

    reverse(c.begin(), c.end());
    v += c;
    reverse(v.begin(), v.end());
    resp.push_back(v);

    reverse(s.begin(), s.end());
    s += k;
    resp.push_back(s);

    sort(resp.begin(), resp.end());
    cout << resp[0] << endl;

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
