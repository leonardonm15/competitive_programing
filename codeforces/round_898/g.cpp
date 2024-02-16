#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     


pair<string, string> cmp = {"BA", "AB"};
pair<string, string> resp = {"CB", "BC"};

void calc(int i, char c, int coin, string &s) {
    char proximo = '_';
    resp = max(resp, coin);
    if (i == 0) return;
    if (i - 1 > n) {
        string k;
        k += c;
        k += s[i + 1];
        if (k == u) {
            proximo = 'B';
        }
        if (k == v) {
            proximo = 'C';
        }
    }
    if (proximo != '_') {
        calc(i + 1, proximo, coin + 1, s);
    }
 
    calc(i + 1, s[i + 1], coin, s);
}

// cada vez que bate chama o calc
void solve () {
    string s; cin >> s;
    int n = s.size();

    string stack;

    for (int i=0; i < n; i++) {
        string k;
        if (stack.size() < 2) stack.push_back(s[i]);
        else {
            
        }
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
