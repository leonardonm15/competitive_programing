#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    int n; cin >> n;
    int sa = 0;
    int sb = 0;
    int resp =  -2e9;
    vector<int> sperm;
    vector<int> pa(n);
    vector<int> pb(n);
    vector<int> a;
    vector<int> b;
    vector<pair<int, int>> diff;

    // recebe os caras
    for (int i=0; i < n; i++) cin >> pa[i];
    for (int i=0; i < n; i++) cin >> pb[i];
    
    // tira os caras = 0 e incorpora na soma
    for (int i=0; i < n; i++) {
        if (pb[i] == 0) sa += pa[i];
        else if (pa[i] == 0) sb += pb[i];
        else {
            a.push_back(pa[i]);
            b.push_back(pb[i]);
            diff.push_back({pa[i] + pb[i], i});
        }
    }
    
    sort(diff.rbegin(), diff.rend());
    /* cout << "diff -> "; */
    for (int i=0; i < diff.size(); i++) {
        /* cout << "(" << diff[i].first << ", " << diff[i].second << ") - "; */
        if (i&1) {
            sb += b[diff[i].second] - 1;
        } else {
            sa += a[diff[i].second] - 1;
        }
    }
    /* cout << endl; */
    cout << sa - sb << endl;
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

