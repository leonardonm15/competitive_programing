#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> arr;

void vol(int i, int j, long long *soma) {
    vector<pair<int, int>> moves  = {{0, 0}, {-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    for (auto pair: moves) {
        if (arr[i + pair.first][j + pair.second] > 0) {
            *soma += arr[i + pair.first][j + pair.second];
            arr[i + pair.first][j + pair.second] = 0;
            vol(i + pair.first, j + pair.second, soma);
        } 
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        long long mv = 0;
        long long soma = 0;
        cout << endl;
        arr.assign(n + 2, vector<int>(m + 2));
        for (int i=1; i < n + 1; i++) {
            for (int j=1; j < m + 1; j++) {
                cin >> arr[i][j];
            }
        }
        for (int i=1; i < n + 1; i++) {
            for (int j=1; j < m + 1; j++) {
                if (arr[i][j] > 0) { 
                    vol(i, j, &soma);
                    mv = max(mv, soma);
                    soma = 0;
                }
            }
        }
        cout << mv << endl;
    }
}
