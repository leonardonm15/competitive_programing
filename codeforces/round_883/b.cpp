#include <bits/stdc++.h>

using namespace std;
//#define int long long


int dfs(char tg, vector<string>& arr) {
    if ((arr[1][1] == tg && arr[1][2] == tg && arr[1][3] == tg) ||
        (arr[1][1] == tg && arr[2][1] == tg && arr[3][1] == tg) ||
        (arr[3][1] == tg && arr[3][2] == tg && arr[3][3] == tg) ||
        (arr[3][3] == tg && arr[2][3] == tg && arr[1][3] == tg) ||
        (arr[1][1] == tg && arr[2][2] == tg && arr[3][3] == tg) ||
        (arr[1][3] == tg && arr[2][2] == tg && arr[3][1] == tg) ||
        (arr[1][2] == tg && arr[2][2] == tg && arr[3][2] == tg) ||
        (arr[2][1] == tg && arr[2][2] == tg && arr[2][3] == tg)
        ) return 1;
    else return 0;
}

void solve () {
    vector<string> arr;
    for (int i=0; i <= 4; i++) {
        string aux = ".....";
        arr.push_back(aux);
    }

    for (int i=1; i < 4; i++) {
        for (int j=1; j < 4; j++) {
            char aux2; cin >> aux2;
            arr[i][j] = aux2;
        }
    }

    char valores[3] = {'+', 'O', 'X'};
    for (int i=0; i < 3; i++) {
        int aux = dfs(valores[i], arr);
        if (aux == 1) {
            cout << valores[i] << endl;
            return;
        }
    }
    cout << "DRAW" << endl;
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
