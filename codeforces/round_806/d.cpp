#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    map<string, int> map;
    vector<string> arr(n);
    for (int i=0; i < n; i++) {
        cin >> arr[i];
        map[arr[i]]++;
    }

    string resp;
    for (auto s: arr) {
        bool flag = false;
        string k;
        for (int i=0; i < s.size() - 1; i++) {
            k.push_back(s[i]);
            string v;
            for (int j = i + 1; j < s.size(); j++) {
                v.push_back(s[j]);
            }
            if (map[k] && map[v]) flag = true;
        }

        if (flag) resp.push_back('1');
        else resp.push_back('0');
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
