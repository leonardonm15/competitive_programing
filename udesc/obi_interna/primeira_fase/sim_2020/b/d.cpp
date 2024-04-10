#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    string a, b; cin >> a >> b;
    vector<int> freq(100);
    int sc = 0;
    for (auto letra: a) {
        int idx = letra - 'a';
        freq[idx]++;
    }
    for (auto letra: b) {
        int idx = letra - 'a';
        if (letra == '*') {
             sc++;
             continue;
        }
        freq[idx]--;
    }
    int soma = 0;
    for (int i=0; i < 100; i++) {
        if (freq[i] < 0) {
            soma = -100000;
            break;
        } 
        soma += freq[i];
    }
    soma -= sc;
    if (soma != 0) cout << "N" << endl;
    else cout << "S" << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
