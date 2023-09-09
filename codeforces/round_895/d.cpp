#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    int n, x, y; cin >> n >> x >> y;
    if (x == y) {
        cout << 0 << endl;
        return;
    }
    int mdc = __gcd(x, y);
    int mmc = (x * y) / mdc;
    int quantidade_mult_mmc = n / mmc;  
    int maiores = n / x;
    int menores = n / y;
    menores -= quantidade_mult_mmc;
    maiores -= quantidade_mult_mmc;
    int soma_menores = ((1 + menores) * menores) / 2;
    int soma_maiores = ((n + (n - maiores + 1)) * maiores) / 2;
    int resp = soma_maiores - soma_menores;
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
