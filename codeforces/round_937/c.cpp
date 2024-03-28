#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    string s; cin >> s;
    string horas;
    horas += s[0];
    horas += s[1];
    int k = stoll(horas);
    bool flag = false;
    if (k > 12) {
        k -= 12;
        flag = true;
    }

    if (k == 0) {
        s[0] = '1';
        s[1] = '2';
    }

    if (flag) {
        string resp;
        if (k < 10) resp += '0';
        resp += to_string(k);
        resp += ":";
        resp += s[3];
        resp += s[4];
        resp += " PM";
        cout << resp << endl;
    } else {
        if (k != 12) s += " AM";
        else s += " PM";
        cout << s << endl;
    }




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
