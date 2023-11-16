#include <bits/stdc++.h>

using namespace std;

#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, m, k; cin >> n >> m >> k;

    // faz busca binaria pro valor no X e ve se a soma pra tras dele e pra
    // frente passa
    bool flag = false;
    int l = 1;
    int r = m;
    int mid = (l + r) / 2;
    int resp = 0;
    int soma_antes = 0;
    int soma_dps = 0;
    int somat = 0;
    
    if (n == m) {
        cout << 1 << endl;
        return;
    }
    // tira n de m pra ficar so com a sobra dos travesseiros
    m -= n;
    while (l <= r) {
        if (k == n) {
            // tem que colocar if else em tudo pq se o resto dos travesseiros
            // for menor que n a pa da ruim, ai tem que calcular só até o termo
            // que nao explode a pa
            // fazer isso pra todos os caras
            soma_antes = ((mid + (mid - k + 1)) * k) / 2; // sem tirar o repetido
        } else if (k == 1) {
            cout << mid - (n - 1) << endl;
            soma_dps = ((mid + (mid - (n - 1))) * n) / 2;
        } else {
            soma_antes = (((mid - 1) + (mid - 1 - (k - 2))) * (k - 1)) / 2; // tirando o repetido
            soma_dps = ((mid + (mid - (n - k))) * (((n + 1) - k))) / 2;
        }
        somat = soma_antes + soma_dps;
        /* cout << " ----------------------------- " << endl; */
        /* cout << " l - r  -> " << l  << " - " << r << endl; */
        /* cout << "mid -> " << mid << endl; */
        /* cout << "soma antes -> " << soma_antes << endl; */
        /* cout << "soma dps -> " << soma_dps << endl; */
        /* cout << "soma total -> " << somat << endl; */
        if (somat <= m) {
            resp = mid;
            l = mid + 1;
            mid = (l + r) / 2;
            continue;
        }
        if (somat > m) {
            r = mid - 1;
            mid = (l + r) / 2;
            continue;
        } 
    }
    /* if (somat > m) l--; */
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
