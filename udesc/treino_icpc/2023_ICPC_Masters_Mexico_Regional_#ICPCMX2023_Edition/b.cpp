#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

const int N = 20;
vector<int> t(N);

void solve () {
    t[0] = 1;
    t[1] = 2;
    t[2] = 3;
    for (int i=3; i < N; i++) {
        t[i] = (3 * t[i - 1]) + (2 * t[i - 2]) + t[i - 3] + 3;
        cout << i << " -> " << t[i] << endl;
    }

    for (int i=3; i < N - 5; i++) {
        cout << i << " -> ";
        for (int k=0; k < i; k++) cout << "  ";
        for (int j=i + 1; j < N - 5; j++) {
            cout << t[j] - t[i] << " ";
        }
        cout << endl;
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
