#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, b, c; cin >> n >> b >> c;

    if (b == 0 && c + 2 >= n) {
        if (c >= n) cout << n << endl;
        else cout << n - 1 << endl;
        return;
    }

    if (b == 0 && c + 2 < n) {
        cout << -1 << endl;
        return;
    }

    int l = 0;
    int r = n;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        int limite = ((mid - 1) * b + c); // 0 é usar tudo N é usar nada indexado em 1
        int tenho = (limite / b);
        int buracos = limite - tenho;

        int resto = r - (mid - 1);

        if (mid == 0) {
            ans = n;
            r = mid + 1;
            continue;
        }

        if (mid == n) {
             // faz a conta fazendo operação em ninguem
             //

            if (
        }


        if (resto > buracos) {
            r = mid + 1;
        } else if (resto < buracos) {
            r = mid - 1;
        } else {
            ans = resto;
            break;
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
