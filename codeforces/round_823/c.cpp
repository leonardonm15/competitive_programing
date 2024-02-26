#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    string s; cin >> s;
    vector<int> freq(9);
    for (auto cara: s) freq[cara - '0']++;

    string resp;
    multiset<char> stc;
    string e;
    int i = 0;
    for (auto cara: s) {
        while (freq[i] == 0) i++;
        if (cara == ('0' + i) && cara != '9') {
            /* cout << "-----------" << endl; */
            stc.emplace(cara);
            /* cout << "e -> " << e << endl; */
            for (auto c: e) stc.emplace(min((int)'9', c + 1));
            /* cout << "stc -> " << stc << endl; */
            e.clear();
            freq[i]--;
        } else {
            e.push_back(cara);
            freq[cara - '0']--;
        }
    }

    /* cout << "stc -> " << stc << endl; */
    /* cout << "e -> " << e << endl; */

    for (auto cara: stc) resp.push_back(cara);
    for (auto cara: e) resp.push_back(cara);

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
