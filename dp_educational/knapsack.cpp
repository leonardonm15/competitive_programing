#include <bits/stdc++.h>

using namespace std;


int main() {
    int n, w; cin >> n >> w; // w peso máximo
    vector<vector<long long>> tabela(n + 1, vector<long long>(w + 1));
    int pesos[n + 1];
    int valores[n + 1];
    for (int i=0; i < n; i++) cin >> pesos[i + 1] >> valores[i + 1];
    for (int i=1; i <= n; i++) {
        for (int j=1; j <= w; j++) {
            if (pesos[i] <= j) {
                tabela[i][j] = max(tabela[i - 1][j], valores[i] + tabela[i - 1][j - pesos[i]]);
            } else tabela[i][j] = tabela[i - 1][j];
        }
    }
    cout << tabela[n][w] << endl;
}
