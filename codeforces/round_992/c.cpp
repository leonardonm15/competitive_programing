#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, k; cin >> n >> k;
    k--;

    vector<int> resp(n);

    int l = 0;
    int r = n - 1;
    int num = 1;

    while (l < r) {
        int rs = n - num - 1;

        if (rs > 60) {
            resp[l++] = num;
            num++;
            continue;
        }

        if (k & (1ll << rs)) {
            resp[r--] = num;
            k -= (1ll << rs);
        } else {
            resp[l++] = num;
        }

        num++;
    }
    
    resp[l] = num;

    if (k != 0) {
        cout << -1 << endl;
        return;
    }

    for (auto c: resp) cout << c << " ";
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
