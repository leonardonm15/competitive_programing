#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    string s1 = "##";
    string s2 = "..";
    vector<string> arr;
    int acc = 0;
    int plus = 0;
    for (int i=0; i < 2 * n; i++) {
        string r;
        for (int i=0; i < n; i++) {
            if (i&1) r += s2;
            else r += s1;
        }
        acc++;
        if (acc == 2) {
            swap(s1, s2);
            acc = 0;
        }

        arr.push_back(r);
    }

    for (auto cara: arr) cout << cara << endl;
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
