#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, m, q; cin >> n >> m >> q;

    vector<int> a(n), b(m);

    int sa = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sa += a[i];
    }

    int sb = 0;
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        sb += b[i];
    }

    map<int, int> ma;
    map<int, int> mb;

    for (int i = 0; i < n; i++) ma[sa - a[i]]++;
    for (int i = 0; i < m; i++) mb[sb - b[i]]++;

    int st = sa * sb;
    while (q--) {
        int want; cin >> want;
    
        bool flag = false;
        for (int i = 1; i * i <= abs(want); i++) {
            if (want % i == 0) {
                if (((ma[i] && mb[want/i]) || (ma[-i] && mb[-want/i]) ||
                    (mb[i] && ma[want/i]) || (mb[-i] && ma[-want/i])) && !flag) {
                    cout << "YES" << endl;
                    flag = true;
                }
            }
        }

        if (!flag) cout << "NO" << endl;

    }
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
