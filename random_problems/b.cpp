#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

vector<vector<int>> mtx(101, vector<int>(101, -1));

void calc() {
    vector<int> mex(301);
    mtx[0][0] = 0;
    mtx[1][1] = 0;

    for (int i=0; i <= 100; i++) {
        for (int j = 0; j <= 100; j++) {
            for (int k=1; k <= 100; k++) {
                if (i - k > 0) mex[mtx[i - k][j]]++;
                if (j - k > 0) mex[mtx[i][j - k]]++;
                if (j - k > 0 && i - k > 0) mex[mtx[i - k][j - k]]++;
            }
            int rmex = 0;
            for (int i=0; i <= 300; i++) {
                if (!mex[i]) {
                    rmex = i;
                    break;
                }
            }

            mtx[i][j] = rmex;
            for (int i=0; i <= 300; i++) mex[i] = 0;
        }
    }
}

void solve () {
    int n; cin >> n;
    int resp = 0;

    for (int i=10; i >= 0; i--){
        for (int j=0; j <= 10; j++){
            cout << mtx[i][j] << " ";
        }
        cout << endl;
    }

    for (int i=0; i < n; i++) {
        int a, b; cin >> a >> b;
        resp ^= mtx[a][b];
    }

    cout << resp << endl;

}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    calc();
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
