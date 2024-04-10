#include <bits/stdc++.h>

using namespace std;

/* #define endl '\n' */ 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int a, b; cin >> a >> b;
    vector<int> arr[a];

    for (int i=0; i < a; i++) {
        for (int j=0; j < b; j++) {
            int num; cin >> num;
            num--;
            arr[i].push_back(num);
        }
    }

    /* cout << "-0---------" << endl; */
    /* for (auto v: arr) { */
    /*     for (auto c: v) cout << c << " "; */
    /*     cout << endl; */
    /* } */
    /* return; */

    for (int i = 0; i < b; i++) {
        int k = arr[0][i] % b;
        /* cout << "arr[0][i] -> " <<  << endl; */
        for (int j=0; j < a; j++) {
            if ((arr[j][i] % b) != k) {
                /* cout << "j -> " << j << endl; */
                /* cout << "I -> " << i << endl; */
                /* cout << "k -> " << k << endl; */
                /* cout << "arr[j][i] -> " << arr[j][i] << endl; */
                cout << '*' << endl;
                return;
            }
        }
    }

    for (int i=0; i < a; i++) {
        int k = arr[i][0] / b;
        for (int j=0; j < b; j++) {
            if ((arr[i][j] / b) != k) {
                /* cout << "arr[i][j] -> " << arr[i][j] << endl; */
                cout << '*' << endl;
                return;
            }
        }

    }

    int resp = 0;
    vector<pair<int, int>> coluna;
    for (int i=0; i < a; i++) {
        coluna.push_back({arr[i][0], i});
    }

    sort(coluna.begin(), coluna.end());

    int k = 0;
    for (int i=0; i < coluna.size(); i++) { 
        if (coluna[i].second == i) continue;
        else {
            swap(coluna[coluna[i].second], coluna[i]);
            k++;
            i = 0;
        }
    }

    resp += k;

    vector<pair<int, int>> linha;
    for (int i=0; i < b; i++) {
        linha.push_back({arr[0][i], i});
    }

    sort(linha.begin(), linha.end());

    k = 0;
    for (int i=0; i < linha.size(); i++) { 
        if (linha[i].second == i) continue;
        else {
            swap(linha[linha[i].second], linha[i]);
            k++;
            i = 0;
        }
    }

    resp += k;

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
