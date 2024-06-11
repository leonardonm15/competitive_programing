#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, m; cin >> n >> m;
    vector<string> grid;
    int resp = -1;
    int x = 0;
    int y = 0;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        int l = -1;
        int r = -1;
        bool flag = false;
        for (int j = 0; j < m; j++) {
            while (j < m && s[j] == '#') {
                if (!flag) {
                    flag = true;
                    l = j;
                }
                r = j++;
            }
        }

        /* cout << "l -> " << l << endl; */
        /* cout << "r -> " << r << endl; */
        if (l > -1 && r > -1) {
            if (r - l + 1 > resp) {
                x = i + 1;
                y = l + ((r - l + 1) / 2) + 1;
                resp = r - l + 1;
            }
        }
    }

    cout << x << " " << y << endl;
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
