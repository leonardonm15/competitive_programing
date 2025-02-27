#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, u, v; cin >> n >> u >> v;

    if (v < u) swap(u, v);
    u--;
    v--;

    vector<int> mex(n, -1);
    mex[u] = 0;
    mex[v] = 1;

    int l = (u - 1 + n) % n;
    int r = (u + 1) % n;

    while (true) {
        /* cout << "l -> " << l << endl; */
        /* cout << "r -> " << r << endl; */

        if (mex[(l + 1) % n] != -1 && mex[l] != -1 && mex[(l - 1 + n) % n] != -1 &&
            mex[(r + 1) % n] != -1 && mex[r] != -1 && mex[(r - 1 + n) % n] != -1) break;

        vector<int> ladj(5);
        if (mex[(l + 1) % n] > -1) ladj[mex[(l + 1) % n]]++;
        if (mex[(l - 1 + n) % n] > -1) ladj[mex[(l - 1 + n) % n]]++;
        if (l == u) ladj[mex[v]]++;
        if (l == v) ladj[mex[u]]++;

        int k = 0;
        for (int i = 0; i < 5; i++) {
            if (!ladj[i]) {
                k = i;
                break;
            }
        }

        mex[l] = max(mex[l], k);

        vector<int> radj(5);
        if (mex[(r + 1) % n] > -1) radj[mex[(r + 1) % n]]++;
        if (mex[(r - 1 + n) % n] > -1) radj[mex[(r - 1 + n) % n]]++;
        if (r == u) radj[mex[v]]++;
        if (r == v) radj[mex[u]]++;

        k = 0;
        for (int i = 0; i < 5; i++) {
            if (!radj[i]) {
                k = i;
                break;
            }
        }

        mex[r] = max(mex[r], k);

        r = (r + 1) % n;
        l = (l - 1 + n) % n;
    }

    /* cout << "mex -> "; */
    for (int i = 0; i < n; i++) cout << mex[i] << " ";
    cout << endl;
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
