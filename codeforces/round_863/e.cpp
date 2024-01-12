#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

vector<int> d = {0, 1, 2, 3, 5, 6, 7, 8, 9};

void solve () {
    long long n; cin >> n;
    string s;
    while (n) {
        s += '0' + d[n % 9];
        n /= 9;
    }
    reverse(s.begin(), s.end());
    cout << s << endl;
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
