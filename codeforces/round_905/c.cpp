#include <bits/stdc++.h>

using namespace std;
//#define int long long
const int inf = 1e7;

void solve () {
    int n, k; cin >> n >> k;
    int ko = k;
    int resp = inf;
    multiset<int> arr;
    arr.emplace(inf);
    arr.emplace(inf);
    if (k == 4) k /= 2;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        int c = 0;
        int ne = inf;
        while (num % k != 0) {
            num++;
            c++;
        }
        if (num == 4 || num == 8 && ko == 4) ne = min(c, ne);
        arr.emplace(c);
        int pe = *(arr.begin());
        int se = *(next(arr.begin(), 1));
        // cout << se << endl;
        if (ko == 4) resp = min({resp, (pe + se), ne});
        else resp = min(c, resp);
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
