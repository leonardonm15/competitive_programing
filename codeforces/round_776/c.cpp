#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    int n, m; cin >> n >> m;
    int soma = 0;

    vector<tuple<int, int, int>> arr; 
    for (int i=1; i <= m; i++) {
        int a, b; cin >> a >> b;
        arr.push_back({b, a, i});
    }
    sort(arr.begin(), arr.end());

    /* vector<tuple<int, int, int>> resp; */
    vector<pair<int, int>> resp;
    for (int i=0; i < 2 * n; i++) {
        auto [b, a, index] = arr[i];
        soma += b;
        resp.push_back({a, index});
    }
    sort(resp.begin(), resp.end());
    
    cout << soma << endl;
    for (int i=0; i < n; i++) {
        auto a = resp.back();
        resp.pop_back();
        cout << resp[i].second << " " << a.second << endl;
    }
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
