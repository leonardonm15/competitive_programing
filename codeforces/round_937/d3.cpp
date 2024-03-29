#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

const int N = 1e5 + 5;
vector<int> fixo;

void calc() {
    for (int i=2; i <= N; i++) {
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

    reverse(fixo.begin(), fixo.end());
}

void solve () {
    int n; cin >> n;

    for (auto cara: fixo) {
        while (n % cara == 0) {
            n /= cara;
        }
    }

    string resp;
    resp = (n == 1 ? "YES" : "NO");
    cout << resp << endl;
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
