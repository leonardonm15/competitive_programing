#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

// varios caras negativos enfileirados, itera
/* trata primeiro todos os caras negativos */

/* dps vai fazendo arr[i + 1] += arr[i] while < arr[i]; */
/* caso o cara da frente seja positivo, é so somar vc nele que ele ja vai ser maior que vc, */

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i=0; i < n; i++) cin >> arr[i];
    for (int i=0; i < n; i++) {
        if (arr[i] == arr[i + 1]) continue;
        if (arr[i] < 0)
        while (arr[i + 1] > arr[i] && arr[i] > 0) {
            arr[i] *= 2;
            cout << i << " " << i << endl;
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
