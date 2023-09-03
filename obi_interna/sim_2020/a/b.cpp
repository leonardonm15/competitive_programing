#include <bits/stdc++.h>

using namespace std;
const int mx = 505;
vector<string> arr;

void dfs (int i, int j, int start) {
    vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (auto pair: moves) {
        if ( arr[i + pair.first][j + pair.second] != '*' && arr[i + pair.first][j + pair.second] - '0' <= start) {
            arr[i + pair.first][j + pair.second] = '*';
            dfs(i + pair.first, j + pair.second, start);
        }
    }
}

int main() {
    int n, m; cin >> n >> m;
    string l;
    for (int i=0; i < n + 3; i++) l.push_back('*');
    arr.push_back(l);
    for (int k=0; k < n; k++) { 
        string e; cin >> e;
        e.push_back('*');
        e.insert(e.begin(), 1, '*');
        arr.push_back(e);
    }
    arr.push_back(l);
    if (arr[1][1] - '0' <= m) {
        arr[1][1] = '*';
        dfs(1, 1, m);
    }
    for (int i=1; i < n + 1; i++) {
        for (int j=1; j < n + 1; j++) {
            cout << arr[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
