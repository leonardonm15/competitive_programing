#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

vector<int> fixo;

void calc() {
    for (int i=2; i <= 1e5 + 5; i++) {
        int k = i;
        bool flag = true;
        while (k) {
            int aux = k % 10;
            if (aux != 0 && aux != 1) {
                flag = false;
            }
            k /= 10;
        }
        if (flag) fixo.push_back(i);
    }
}

void solve () {
    int n; cin >> n;

    reverse(fixo.begin(), fixo.end());
    while (n > 1) {
        /* cout << "n -> " << n << endl; */
        bool flag = true;
        for (auto cara: fixo) {
            if (n % cara == 0) {
                n /= cara;
                flag = false;
                break;
            }
        }
        if (flag) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    calc();
    int TC = 1;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
