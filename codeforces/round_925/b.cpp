#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    int s = 0;
    int soma = 0;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        arr[i] = num;
        soma += num;
    }

    int k = soma / n;
    for (int i=0; i < n; i++) {
        s += arr[i] - k;
        if (s < 0) {
            cout << "NO" << endl;
            return;
        }
    }

    if (s != 0) cout << "NO" << endl;
    else cout << "YES" << endl;
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
