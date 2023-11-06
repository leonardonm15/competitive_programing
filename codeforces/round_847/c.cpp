#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n; cin >> n;
    vector<vector<int>> arr(n, vector<int>(n - 1));
    vector<int> r;
    for (int i=0; i < n; i++) {
        for (int j=0; j < n - 1; j++) {
            cin >> arr[i][j];
        }
    }
    map<int, int> f;
    vector<pair<int, int>> u;
    for (int i=0; i < n - 1; i++) {
        f.clear();
        u.clear();
        for (int j=0; j < n; j++) f[arr[j][i]]++;
        for (auto [cara, freq]: f) {
            u.push_back({freq, cara});
        }
        sort(u.rbegin(), u.rend());
        /* for (auto [freq, cara]: u) { */
        /*     cout << "(" << freq << " - " << cara << ")" << " "; */
        /* } */
        /* cout << endl; */
        int un = r.size();
        int lc;
        if (un > 0) lc = r[un - 1];
        else lc = -1;
        /* cout << "last char -> " << lc << endl; */
        if (lc != u[0].second) r.push_back(u[0].second);
        if (lc != u[1].second) r.push_back(u[1].second);
    }
    for (auto cara: r) cout << cara << " ";
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
