#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    map<int, int> mp;
    vector<int> visa(n + 1);
    vector<int> visb(n + 1);



    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    for (int i = 0; i < n; i++) {
        if (visa[i]) continue;
        for (int j = 0; j < n; j++) {
            if (visb[j]) continue;
            if (!mp[a[i] + b[j]]) {
                mp[a[i] + b[j]]++;
                visa[i]++;
                visb[j]++;
            }
        }
    }

    if (mp.size() < 3) cout << "NO" << endl;
    else cout << "YES" << endl;
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
