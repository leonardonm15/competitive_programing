#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

/* int bb(vector<int>& arr, int tg) { */
/*     int l = 0; */
/*     int r = arr.size() - 1; */
/*     int ans = -1; */

/*     while (l <= r) { */
/*         int mid = (l + r) >> 1; */
/*         if (arr[mid] < tg) { */
/*             l = mid + 1; */
/*         } else { */
/*             ans = arr[mid]; */
/*             r = mid - 1; */
/*         } */
/*     } */

/*     return ans; */
/* } */

void solve () {
    int n, m; cin >> n >> m;

    vector<int> a(n), b(m);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    vector<int> a2 = a;

    sort(b.begin(), b.end());

    if (b[0] - a[0] < a[0]) a[0] = b[0] - a[0];

    for (int i = 1; i < n; i++) {
        int tg = b[0] - a[i];
        if (tg >= a[i - 1]) {
            if (a[i] < a[i - 1]) a[i] = tg;
            else if (a[i] > a[i - 1] && tg < a[i])  a[i] = tg;
        }
    }

    /* cout << "v -> "; */
    /* for (auto v: a) cout << v << " "; */
    /* cout << endl; */

    bool r1 = true;
    for (int i = 1; i < n; i++) {
        if (a[i - 1] > a[i]) r1 = false;
    }

    cout << (r1 ? "YES": "NO") << endl;
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
