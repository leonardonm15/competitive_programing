#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int INF = 1e9;

bool valid(int u, int v, int n) {
    if (u <= n - 1 && v <= n - 1) return true;
    else return false;
}

void solve () {
    int n; cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num; cin >> num;
            arr[i][j] = num;
        }
    }

    int resp = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == INF) continue;
            int u = i;
            int v = j;

            int s = 0;
            while (valid(u, v, n)) {
                s = min(s, arr[u][v]);
                arr[u][v] = INF;
                u++;
                v++;
            }

            resp += abs(s);
        }
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
