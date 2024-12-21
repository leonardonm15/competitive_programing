#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;

    vector<int> arr(n);
    vector<pair<int, int>> sarr(n);
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sarr[i].first = arr[i];
        sarr[i].second = i;
        mp[arr[i]].push_back(i);
    }

    sort(sarr.begin(), sarr.end());

    vector<int> a;
    vector<pair<int, int>> b;
    int p = 0;
    for (int i = 0; i < n; i++) {
        if (sarr[p].first == arr[i]) {
            a.push_back(arr[i]);
            p++;
        } else {
            b.push_back({arr[i], i});
        }
    }

    sort(b.begin(), b.end());

    cout << "a -> ";
    for (auto c: a) cout << c << " ";
    cout << endl;

    cout << "b -> ";
    for (auto [f, s]: b) {
        cout << f << " ";
        a.push_back(f + 1);
    }
    cout << endl;


    cout << "a -> ";
    for (auto c: a) cout << c << " ";
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
