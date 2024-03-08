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
    if (n&1) {
        cout << -1 << endl;
        return;
    }

    for (int i=0; i <= n / 2; i++) {
        if (s[i] == 0 && s[n - i - 1] == 1) swap(s[i], s[n - i - 1]);
    }

    int k = 0;
    vector<int> pos;
    for (int i=0; i <= ((int) s.size() / 2); i++) {
        if (k > 300) {
            cout << -1 << endl;
            return;
        }
        /* cout << "--------------" << endl; */
        if (s[i] == '0' && s[s.size() - i - 1] == '0') {
            pos.push_back(s.size() - i);
            s.insert(s.size() - i, "01");
            /* cout << "s -> " << s << endl; */
            /* cout << "s[i] -> " << i << endl; */
            /* cout << "s[n - i - 1] -> " << n - i - 1 << endl; */
            i = 0;
            k++;
            continue;
        } else if (s[i] == '1' && s[s.size() - i - 1] == '1') {
            pos.push_back(i);
            s.insert(i, "01");
            i = 0;
            k++;
        }
    }

    for (int i=0; i <= (s.size() / 2); i++) {
        if (s[i] == s[s.size() - i - 1]) {
            cout << -1 << endl;
            return;
        }
    }

    cout << pos.size() << endl;
    for (auto c: pos) cout << c << " ";
    cout << endl;
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
