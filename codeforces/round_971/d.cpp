#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    vector<vector<int>> arr(2, vector<int>(n + 1, 0));

    int cima_frente = 0;
    int baixo_frente = 0;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;

        if (y == 1) cima_frente++;
        else baixo_frente++;

        arr[y][x]++;
    }


    int resp = 0;
    int cima_passou = 0;
    int baixo_passou = 0;
    for (int x = 0; x <= n; x++) {
        if (arr[0][x]) baixo_frente--;
        if (arr[1][x]) cima_frente--;

        if (x > 0 && x < n && arr[0][x] && arr[1][x + 1] && arr[1][x - 1]) resp++;
        if (x > 0 && x < n && arr[1][x] && arr[0][x + 1] && arr[0][x - 1]) resp++;

        if (arr[0][x] && arr[1][x]) {
            resp += cima_frente + baixo_frente;
            resp += cima_passou + baixo_passou;
        }

        if (arr[0][x]) baixo_passou++;
        if (arr[1][x]) cima_passou++;
    }

    cout << resp << endl;
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
