#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

/* pair<int, int> mv[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}; */

/* void dfs(int u, int layer, int color) { */
/*     arr[layer][u] = '0' + (int)color; */

/*     for (auto [x, y]: mv) { */
/*         if (arr[layer + x][u + y] == '.') dfs(u + y, layer + x, color); */
/*     } */
/* } */

void solve () {
    int n; cin >> n;
    vector<string> arr;
    string barr, l1, l2, r;

    l1 += 'x';
    cin >> r;
    l1 += r;
    l1 += 'x';

    l2 += 'x';
    cin >> r;
    l2 += r;
    l2 += 'x';

    for (int i = 1; i <= n + 2; i++) barr += 'x';

    arr.push_back(barr);
    arr.push_back(l1);
    arr.push_back(l2);
    arr.push_back(barr);

    /* int color = 1; */
    /* for (int l = 1; l <= 2; l++) { */
    /*     for (int i = 1; i <= n; i++) { */
    /*         if (arr[l][i] == '.') dfs(i, l, color++); */
    /*     } */
    /* } */

    int resp = 0;
    for (int i = 3; i <= n + 1; i++) {
        string s1, s2;
        s1 += arr[1][i - 2];
        s1 += arr[1][i - 1];
        s1 += arr[1][i];

        s2 += arr[2][i - 2];
        s2 += arr[2][i - 1];
        s2 += arr[2][i];

        /* cout << "_------------------" << endl; */
        /* cout << "s1 -> " << s1 << endl; */
        /* cout << "s2 -> " << s2 << endl; */

        if ((s1 == "x.x" && s2 == "...") || (s1 == "..." && s2 == "x.x")) {
            resp++;
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
