#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    string a, b; cin >> a >> b;
    bool flag = false;
    for (int i=0; i < a.size(); i++) {
        if (!flag && a[i] != b[i]) {
            if (a[i] < b[i]) swap(b[i], a[i]);
            flag = true;
            continue;
        }
        if (flag && b[i] < a[i]) swap(a[i], b[i]);
    }

    cout << a << endl;
    cout << b << endl;
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
