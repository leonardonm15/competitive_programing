#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    // After each operation, determine if it is possible to rearrange the characters of s and t 
    // s < t
    map<char, int> ms;
    map<char, int> mt;
    ms['a']++;
    mt['a']++;
    int sl = 1;
    int tl = 1;
    while (n--) {
        int op, t; cin >> op >> t;
        string s; cin >> s;
        for (auto cara: s) {
            if (op == 1) {
                ms[cara] += t;
                sl += t;
            } else {
                mt[cara] += t;
                tl += t;
            }
        }
        cout << "letras s -> " << sl << endl;
        cout << "letras t -> " << tl << endl;
        for (auto [letra, f]: ms) {
            // aaab s 
            // aabb
            if (mt[letra] < f) {
                cout << "YES" << endl;
                break;
            } else if (mt[letra] > f) {
                cout << "NO" << endl;
                break;
            } 
        }
        if (ms == mt) cout << "NO" << endl;
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
