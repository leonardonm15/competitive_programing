#include <bits/stdc++.h>

using namespace std;
#define int long long

vector<vector<int>> pir(2024, vector<int>(2024));

void resp(int i, int r, long long &soma) {
    for (int j=i; j > 0; j--){
        if (r == 0) return;
        soma += pir[j][r];
        r--;
    }
}

void solve () {
    int n; cin >> n;
    int ui = 1;
    int i=1;
    while (n > i) {
        n -= i;
        i++;
    } 
    /* cout << i << " " << n << endl; */
    /* cout << "primiero cara -> " << pir[i][n] << endl; */
    long long soma = 0;
    resp(i, n, soma);
    cout << soma << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    int c = 2;
    int cg = 1;// current guy 
    for (int i=1; i < 2024; i++) {
        for (int j=1; j < c; j++) {
            pir[i][j] = cg * cg;
            cg++;
        }
        c++;
    }
    for (int i=1; i < 2024; i++) {
        for (int j=1; j < i + 1; j++) {
            pir[i][j]+= pir[i - 1][j];
            /* cout << pir[i][j] << " "; */
        }
        /* cout << endl; */
    }
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
