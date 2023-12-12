#include <bits/stdc++.h>

using namespace std;
//#define int long long

int ur (vector<vector<int>> &arr, int i, int j) {
    int resp = 0;
    i++;
    j++;
    while (arr[i][j] != -1) {
        resp += arr[i][j];
        i++;
        j++;
    }
    return resp;
}

int dr (vector<vector<int>> &arr, int i, int j) {
    int resp = 0;
    i++;
    j--;
    while (arr[i][j] != -1) {
        resp += arr[i][j];
        i++;
        j--;
    }
    return resp;
}

int ul (vector<vector<int>> &arr, int i, int j) {
    int resp = 0;
    i--;
    j++;
    while (arr[i][j] != -1) {
        resp += arr[i][j];
        i--;
        j++;
    }
    return resp;
}

int dl (vector<vector<int>> &arr, int i, int j) {
    int resp = 0;
    i--;
    j--;
    while (arr[i][j] != -1) {
        resp += arr[i][j];
        i--;
        j--;
    }
    return resp;
}


void solve () {
    int n, m; cin >> n >> m;
    vector<vector<int>> arr(n + 2, vector<int>(m + 2, -1));

    for (int i=1; i <= n; i++) {
        for (int j=1; j <= m; j++) {
            cin >> arr[i][j];
        }
    }

    int answ = 0;
    for (int i=1; i <= n; i++) {
        for (int j=1; j <= m; j++) {
            int k = ul(arr, i, j) + ur(arr, i, j) + dl(arr, i, j) + dr(arr, i, j);
            answ = max(answ, arr[i][j] + k);
        }
    }
    cout << answ << endl;
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

