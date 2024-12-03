#include <bits/stdc++.h>

using namespace std;
 
#define endl '\n' 
#define int long long
 
void solve () {
    int n, k; cin >> n >> k;
    
    vector<int> p(k + 1);
    vector<int> sz((1 << k) + 5); //
 
    for (int i = 0; i < k; i++) cin >> p[i];
 
    for (int i = 0; i < k; i++) {
        sz[(1 << i)] = n / p[i];
    }
 
 
    for (int i = 1; i < (1 << k); i++) {
        int bits_acesos = __builtin_popcount(i);
 
        int u = 1;
 
        bool flag = false;
        for (int j = 0; j < k; j++) {
            if (i & (1 << j)) {
                if (u <= n / p[j]) u *= p[j];
                else flag = true;
            }
        }
 
        if (flag) continue;

        int multiplos = n / u;
 
        if (!multiplos) continue;
 
        if (bits_acesos&1) sz[i] = multiplos;
        else sz[i] = -1 * multiplos;
    }
 
    int resp = 0;

    for (auto c: sz) if (c != 0) resp += c;

    cout << resp << endl;
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
