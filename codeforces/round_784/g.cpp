#include <bits/stdc++.h>

using namespace std;

void desce(vector<char> arr[], int id, int jd) {
    // tamo recebendo de baixo pra cima
    while(arr[id + 1][jd] == '.') {
        arr[id + 1][jd] = '*';
        arr[id][jd] = '.';
        id++;
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<char> arr[n + 1];
        for (int i=0; i < n; i++) {
            for (int j=0; j < m; j++) {
                char coisa; cin >> coisa;
                arr[i].push_back(coisa);
            }
        }
        // fazendo chaozinho poggers 
        for (int i=0; i < m; i++) arr[n].push_back('o');

        // chamando
        for (int i=n - 1; i >= 0; i--){
            for (int j=m - 1; j >= 0; j--) {
                // pra cada cara, se ele for pedra, chama desce
                if (arr[i][j] == '*') desce(arr, i, j);
            }
        }
        for (int i=0; i < n; i++) {
            for (int j=0; j < m; j++) {
                cout << arr[i][j];
            }
            cout << endl;
        }
    }
}
