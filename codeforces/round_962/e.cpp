#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int MOD = 1e9 + 7;

void solve () {
    string s; cin >> s;
    int n = s.size();

    int resp = 0;
    map<int, int> map;
    map[0] = 1;

    int soma = 0;
    for (int i = 1; i <= n; i++) {
        int k = s[i - 1] - '0';
        if (k) soma++;
        else soma--;
        
        resp += (n - i + 1) * map[soma];
        resp %= MOD;

        map[soma] += i + 1;
        map[soma] %= MOD;
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
