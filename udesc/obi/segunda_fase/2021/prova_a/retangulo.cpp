#include <bits/stdc++.h>

using namespace std;
#define int long long
#define MAXI 2e6 + 2

void solve () {
    int n; cin >> n;
    vector<int> arr(n + 1);
    arr[0] = 0;
    map<int, int> dist_array;
    map<int, int> visitados;
    dist_array[0]++;
    int soma = 0;
    for (int i=1; i <= n; i++) {
        cin >> arr[i];
        soma += arr[i];
        dist_array[soma]++;
    }
    if (soma&1) {
        cout << "N" << endl;
        return;
    }
    int metade = soma / 2;
    int c = 0;
    int ponto = 0;
    for (int i=0; i <= n; i++) {
        ponto += arr[i];
        ponto %= soma;
        int outra_metade = (ponto + metade) % (soma);
        bool visitado = visitados[ponto] && visitados[outra_metade];
        if (dist_array[outra_metade] && !visitado) c++;
        if (c >= 2) {
            cout << "S" << endl;
            return;
        }
        visitados[outra_metade]++;
        visitados[ponto]++;
    }
    cout << "N" << endl;
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
