#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 

const int N = 2e6 + 5;
const int M = 5000 + 5;
const int INF = 1e9;

int n, m;
int arr[N];
int dp[M][M]; // aonde eu to, por L
vector<int> test[M][2];

int bb(vector<int>& arr, int tg) {
    int l = 0;
    int r = (int) arr.size() - 1;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;

        if (arr[mid] <= tg) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
    }

    /* cout << "------------------" << endl; */
    /* cout << "ans -> " << ans << endl; */
    /* /1* if (ans > -1) cout << "arr[ans] -> " << arr[ans] << endl; *1/ */
    /* cout << "tg -> "  << tg << endl; */

    return ans + 1;
}

void solve () {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            dp[i][j] = -INF;
        }
    }

    dp[1][0] = 0;
    dp[1][1] = 0;

    int zc = 1;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0) test[zc - 1][0].push_back(arr[i]);
        if (arr[i] < 0) test[zc - 1][1].push_back(abs(arr[i]));
        if (arr[i] == 0) zc++;
    }

    for (int i = 1; i <= zc; i++) {
        sort(test[i][0].begin(), test[i][0].end());
        sort(test[i][1].begin(), test[i][1].end());
    }

    for (int zc = 1; zc <= m; zc++) {
        for (int l = 0; l <= zc; l++) {
            int score = 0;
            int r = zc - l;
            if (test[zc][0].size()) score += bb(test[zc][0], l);
            if (test[zc][1].size()) score += bb(test[zc][1], r);
            /* cout <<"score  -> " << score << endl; */
            dp[zc + 1][l] = max(dp[zc + 1][l], dp[zc][l] + score);
            dp[zc + 1][l + 1] = max(dp[zc + 1][l + 1], dp[zc][l] + score);
        }
    }

    int resp = 0;
    for (int l = 0; l <= m + 1; l++) {
        resp = max(resp, dp[m + 1][l]);
    }

    cout << resp << endl;

    /* for (int i = 0; i <= m + 1; i++) { */
    /*     test[i].clear(); */
    /*     for (int j = 0; j <= m + 1; j++) { */
    /*         dp[i][j] = 0; */
    /*     } */
    /* } */
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
