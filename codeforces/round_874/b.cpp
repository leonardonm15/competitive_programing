#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n, k; cin >> n >> k;
    vector<int> resp(n);
    vector<pair<int, int>> a;
    vector<int> b;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        a.push_back({num, i});
    }
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        b.push_back(num);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    for (int i=0; i < n; i++) {
        resp[a[i].second] = b[i];
        /* resp[a[i].second] = abs(b[i] - a[i].first); */
    }
    for (auto cara: resp) cout << cara << " ";
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
