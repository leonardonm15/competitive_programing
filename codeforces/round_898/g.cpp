#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    string s; cin >> s;
    int n = s.size();

    vector<int> a;

    bool flag = false;
    if (s[0] == 'B' || s[n - 1] == 'B') flag = true;

    for (int i=0; i < n - 1; i++) {
        if (s[i] == s[i + 1] && s[i] == 'B') flag = true;
    }

    int c = 0;
    for (int i=0; i < n; i++) {
        if (s[i] == 'A') c++;
        else {
            if (c > 0) a.push_back(c);
            c = 0;
        }
    }

    if (c > 0) a.push_back(c);

    if (a.size() == 0) {
        cout << 0 << endl;
        return;
    }

    sort(a.begin(), a.end());

    int resp = 0;
    if (flag) resp += a[0];
    for (int i=1; i < a.size(); i++) {
        resp += a[i];
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
