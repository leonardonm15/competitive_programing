#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 

const int INF = 1e9 + 5;
const int MX_MSK = (1 << 21);
const int N = 20;

int n, k;
int weights[N];
pair<int, int> dp[MX_MSK]; // 20 * 1e5

/* int o; */
/* pair<int, int> calc(int u, int msk) { */
/*     if (dp[u][msk].first != INF) return dp[u][msk]; */
/*     o++; */
/*     if (msk == 0) { */
/*         return dp[u][msk] = {1, weights[u]}; */
/*     } */

/*     pair<int, int> p = {INF, INF}; */
/*     for (int i = 0; i < n; i++) { */
/*         if (msk & (1 << i)) { */
/*             pair<int, int> q = calc(i, msk ^ (1 << i)); */

/*             if (q.second + weights[u] > k) { */
/*                 q.second = weights[u]; */
/*                 q.first++; */
/*             } else q.second += weights[u]; */


/*             if ((p.first > q.first) || ((p.first == q.first) && (p.second > q.second))) p = q; */
/*         } */
/*     } */

/*      // cout << "u ->"  << u << " - " << "w -> " << p.second << " - " << "msk ->"  << bitset<4>(msk) << endl; */

/*     return dp[u][msk] = p; */
/* } */

pair<int, int> cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first > b.first) return b;
    if (a.first == b.first && a.second > b.second) return b;
    return a;
}

pair<int, int> pluh(pair<int, int> a, int w) {
    if (a.second + w > k) {
        a.second = w;
        a.first++;
    } else a.second += w;

    return a;
}

void solve () {
    cin >> n >> k;

    for (int i = 0; i < n; i++) cin >> weights[i];

    for (int j = 0; j < MX_MSK; j++) {
        dp[j] = {INF, INF};
    }
    for (int i = 0; i < n; i++) {
        dp[(1 << i)] = {1, weights[i]};
    }

    for (int msk = 0; msk < MX_MSK; msk++) {
        if (dp[msk].first == INF) continue;

        for (int j = 0; j < n; j++) {
            if ((msk & (1 << j)) == 0) {
                pair<int, int> new_val = pluh(dp[msk], weights[j]);
                dp[msk ^ (1 << j)] = cmp(dp[msk ^ (1 << j)], new_val);
            }
        }
    }

    cout << dp[(1 << n) - 1].first << endl;


    /* for (int i = 0; i < n; i++) { */
    /*     pair<int, int> val = calc(i, ((1 << n) - 1) ^ (1 << i)); */
    /*     resp = min(resp, val.first); */
    /* } */

    /* cout << resp << endl; */
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
