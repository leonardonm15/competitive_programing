#include <bits/stdc++.h>
using namespace std;
# define int long long
void solve () {
    int n; cin >> n;
    cout << 0 << endl;
    if (n >= 3) {
        cout << 6 << endl;
        for (int i=3; i <= n; i++) {
            int k = (i * i) - 1;
            int somatorio = ((1 + k) * k) / 2; // soma de 1 até o o quadrado do n
            int soma_row = (i - 2) * (6 + (4 * (i - 3)));
            // n - 2 é pq esse somatorio vai até n - 2;
            // 6 é o caso base a partir do n = 3
            // vai aumentando de 4 em 4 a partir do n = 3
            int last_row = (2 + (2 * (i - 3)));
            // 2 é o caso base a partir do n = 3
            // vai aumentando de 2 em 2 a partir do n = 3
            /* cout << " i->  " << i << endl; */
            /* cout << "somatorio -> " << somatorio << endl; */
            /* cout << "soma_row -> " << soma_row << endl; */
            /* cout << "last_row -> " << last_row << endl; */
            int resp = somatorio - (soma_row + last_row);
            cout << resp << endl;
        }
    } else if (n == 2) cout << 6 << endl;
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
