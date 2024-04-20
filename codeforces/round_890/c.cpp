#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
const int NINF = -1e14;

int check(int i, int mid, vector<int>& v) {
    if (v[i] >= mid) return 0;
    if (i <= v.size() - 2 && v[i] < mid) {
        return mid - v[i] + check(i + 1, max(1ll, mid - 1), v);
    } else return NINF;
}

void solve () {
    // faz a bb e pra cada cara bruta se da pra fazer aquele numero
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    int ans = 0;

    for (int i=0; i < n; i++) {
        cin >> arr[i];
        ans = max(ans, arr[i]);
    }

    int l = ans + 1;
    int r = 1e16;
    while(l <= r) {
        // se eu consigo deixar todos os caras com um valor x
        // eu consigo deixar 1 cara com o valor x + 1
        vector<int> v = arr;
        int mid = (l + r) >> 1;
        int add = 0;
        bool did = false;
        for (int i=0; i < n - 1; i++) {
            add = check(i, mid, v);
            if (add <= k && add >= 0) did = true;
        }

        if (did) {
            l = mid + 1;
            ans = max(ans, mid);
        } else {
            r = mid - 1;
        }
    }

    cout << ans << endl;
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
