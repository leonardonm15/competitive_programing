#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    string s; cin >> s;
    int n = s.size();
    for (int k = 1; k < n; k++) {
        string num;
        // ao inves de fazer de fazer isso pega o primeiro numero
        // vai até o final vendo se tem primo com o segundo
        // se nao tiver, pega 2 numeros e vai fazendo isso
        for (int j = 0; j < k; j++) num.push_back(s[j]);
        // iterar primeiro 
        for (int i=k + 1; i < n; i++) {
            string resp = num;
            num.push_back(s[i]);
            bool flag = true;
            int r = stoll(num);
            for (int l = 2; l * l <= r; l++) {
                if (r % l == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                cout << r << endl;
                return;
            }
        }
    }
    cout << -1 << endl;
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
