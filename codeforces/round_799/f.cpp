#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    vector<int> v(10, -1);

    for (int i=0; i < n; i++) {
        int num; cin >> num;
        if (v[num % 10] == -1) {
            v[num % 10] = 0;
        }
        v[num % 10]++;
    }

    for (int i=0; i < 10; i++) {
        for (int j=0; j < 10; j++) {
            for (int k=0; k < 10; k++) {
                vector<int> c;
                c = v;
                c[i] -= 1;
                c[j] -= 1;
                c[k] -= 1;
                if (((i + j + k) % 10  == 3) && (c[i] >= 0 && c[j] >= 0 && c[k] >= 0)) {
                    /* cout << "i j k" << i << " " << j << " " << k << endl; */
                    cout << "YES" << endl;
                    return;
                }
            }
        }
    }

    cout << "NO" << endl;
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
