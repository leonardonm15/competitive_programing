#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    vector<int> vec(365); // assumindo que feriados e fim de semana tem o valor -1e18

    int menor_valor = 1e18;
    int maior_valor = -1e18;

    int media_anual = 0;

    for (int i = 0; i < 365; i++) {
        if (vec[i] > -1e18) {
            min(menor_valor, vec[i]);
            media_anual += vec[i];
        }
        maior_valor = max(maior_valor, vec[i]);
    }

    int dias = 0;
    // 250 são os dias uteis
    // para evitar imprecisão 
    // valor/365 < v
    // valor < v * 365
    for (auto v: vec) {
        if ((v * 250) > media_anual) dias++;
    }
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
