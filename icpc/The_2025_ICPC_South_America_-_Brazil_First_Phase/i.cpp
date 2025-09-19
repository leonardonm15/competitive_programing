#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

int dist(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void solve () {
    int n; cin >> n;
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        arr.push_back({a, b});
    }

    int l = 1;
    int r = dist(arr[n - 2], arr[n - 1]) - 1;
    for (int i = n - 3; i >= 0; i--) {
        int d = dist(arr[i], arr[i + 1]);
        int pr = d - l;
        int pl = d - min(r, d - 1);
        l = pl;
        r = pr;
    }


    cout << (l > r ? -1 : r) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
