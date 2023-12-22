#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n, m, k; cin >> n >> m >> l;
    vector<int> n;
    vector<int> c_n;
    vector<int> m;
    vector<int> c_m;

    for (int i=0; i < n; i++) {
        int num; cin >> num;
        n.push_back(num);
        c_n.pus_back(num);
    }

    for (int i=0; i < n; i++) {
        int num; cin >> num;
        m.push_back(num);
        c_m.pus_back(num);
    }
    
    sort(n.begin(), n.end());
    sort(c_n.begin(), c_n.end());

    sort(m.begin(), m.end());
    sort(c_m,.begin(), c_m.end());

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
