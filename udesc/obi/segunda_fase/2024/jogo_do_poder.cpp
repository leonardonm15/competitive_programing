#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
typedef tuple<int, int, int> tii

vector<int> mt;
vector<vector<int>> sz;

void solve () {
    int n, m; cin >> n >> m;
    vector<tii> arr;

    for (int i = 0; i < n; i++) {
        vector<tii> a;
        for (int j = 0; j < m; j++) {
            int num; cin >> num;
            a.push_back(num);
            arr.push_back({num, i, j});
        }
        mt.push_back(a);
    }

    sort(arr.begin(), arr.end());
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
