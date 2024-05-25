#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
vector<string> arr;

int calc(int i, int j, int k, int l, int n, int m) {
    int resp = 0;
    // cout << "-------------------" << endl;
    // cout << "i -> " << i << endl;
    // cout << "j -> " << j << endl;
    // cout << "K -> " << k << endl;
    //  1 1
    if ((i + k < n) && (j + l < m)) resp += (arr[i + k][j + l] == '*');
    // - 1 1
    if ((i - k >= 0) && (j + l < m)) resp += (arr[i - k][j + l] == '*');
    // 1 -1
    if ((i + k < n) && (j - l >= 0)) resp += (arr[i + k][j - l] == '*');
    // -1 - 1
    if ((i - k >= 0) && (j - l >= 0)) resp += (arr[i - k][j - l] == '*');

    if (k != l || (l == 0 || k == 0)) {
        //  1 1
        if ((i + l < n) && (j + k < m)) resp += (arr[i + l][j + k] == '*');
        // - 1 1
        if ((i - l >= 0) && (j + k < m)) resp += (arr[i - l][j + k] == '*');
        // 1 -1
        if ((i + l < n) && (j - k >= 0)) resp += (arr[i + l][j - k] == '*');
        // -1 - 1
        if ((i - l >= 0) && (j - k >= 0)) resp += (arr[i - l][j - k] == '*');
    }

    return resp;
}

void solve () {
    int n, m; cin >> n >> m;
    int ka, l; cin >> ka >> l;
    ka--;
    l--;
    for (int i=0; i < n; i++) {
        string s; cin >> s;
        arr.push_back(s);
    }

    int resp = -1;
    int r1 = -1;
    int r2 = -1;
    
    for (int i=0; i < n; i++) {
        for (int j=0; j < m; j++) {
            if (arr[i][j] == '*') continue;

            int k = calc(i, j, ka, l, n, m);
            // cout << "k -> " << k << endl;
            if (k > resp) {
                r1 = i;
                r2 = j;
                resp = k;
            }
        }
    }

    cout << r1 + 1 << " " << r2 + 1 << endl;
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

