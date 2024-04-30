#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int N = 3000 + 5;
vector<vector<int>> dp(N, vector<int>(N, -1));
string a, b;
string resp;

void get_resp(int x, int y) {
    if (x < 0 || y < 0) return;
    if (a[x] == b[y]) {
        resp.push_back(a[x]);
        get_resp(x - 1, y - 1);
    } else {
        if (x == 0 || y == 0) {
            if (x == 0 && y > 0) get_resp(x, y - 1);
            else if (x > 0 && y == 0) get_resp(x - 1, y);
            return;
        }
    
        if (dp[x - 1][y] >= dp[x][y - 1]) get_resp(x - 1, y);
        else get_resp(x, y - 1);
    }
}

int calc(int x, int y) {
    if (x == -1 || y == -1) return 0;
    if (dp[x][y] != -1) return dp[x][y];
    if (a[x] == b[y]) dp[x][y] = calc(x - 1, y - 1) + 1;
    else dp[x][y] = max(calc(x - 1, y), calc(x, y - 1));
    return dp[x][y];
}

void solve () {
    cin >> a >> b;
    calc(a.size() - 1, b.size() - 1);

    /* for (int i=0; i <= (int)a.size(); i++) { */
    /*     for (int j=0; j <= (int)b.size(); j++) { */
    /*         cout << dp[i][j] << " "; */
    /*     } */
    /*     cout << endl; */
    /* } */

    get_resp(a.size() - 1, b.size() - 1);
    reverse(resp.begin(), resp.end());
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
