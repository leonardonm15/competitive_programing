#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

const int maxn = 2e5 + 5;
vector<int> resp(maxn);
void solve () {
    int n, m, q; cin >> n >> m >> q;
    vector<int> d1(1e5 + 5);
    vector<int> d2(1e5 + 5);

    for (int i=0; i < n; i++) {
        int num; cin >> num;
        d1[num]++;
    }
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        d2[num]++;
    }


    for (int i=0; i < d1.size(); i++) {
        for (int j=0; j < d2.size(); j++) { 
            resp[i + j] += (d1[i] * d2[j]);
        }
    }

    while (q--) {
        int k; cin >> k;
        cout << resp[k] << endl;
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
