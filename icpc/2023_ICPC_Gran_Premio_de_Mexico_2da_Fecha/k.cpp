#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, k; cin >> n >> k;
    vector<vector<int>> arr;
    arr.push_back({1});
    for (int i=1; i <= n; i++) {
        vector<int> a;
        for (int j=1; j <= n; j++) {
            int num; cin >> num;
            a.push_back(num);
        }
        arr.push_back(a);
    }

    /* for (auto cara: arr) { */
    /*     for (auto c: cara) { */
    /*         cout << c << " "; */
    /*     } */
    /*     cout << endl; */
    /* } */

    int resp = 0;
    k--;
    for (int i=1; i + k <= n; i++) {
        for (int j=0; j + k < n; j++) {
            int p = arr[i][j]; // esquerda cima
            int c = arr[i][j + k]; // direira cima
            int x = arr[i + k][j]; // esquerda baixo
            int a = arr[i + k][j + k]; // direita baixo
            if (p == x && x == c && c == a && a == p) {
                resp++;
            }
        }
    }

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
