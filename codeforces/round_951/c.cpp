#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

int lcm (int a, int b) {
    return ((a * b) / gcd(a, b));
}

void solve () {
    int n; cin >> n;
    int G = 1;
    vector<pair<int, int>> arr(n);

    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        G = lcm(G, num);
        arr[i] = {num, i};
    }

    vector<int> resp(n);
    sort(arr.rbegin(), arr.rend());

    int cumm = 0;

    for (int i = 0; i < n; i++) {
        resp[arr[i].second] = G / arr[i].first;
        cumm += G / arr[i].first;
    }

    if (G > cumm) {
        for (auto c: resp) cout << c << " ";
        cout << endl;
    } else cout << -1 << endl;
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
