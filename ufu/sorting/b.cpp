#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

bool check(tuple<int, int, int, int> &a, tuple<int, int, int, int> &b) {
    return (get<0>(a) == get<0>(b) ? get<3>(a) > get<3>(b) : get<0>(a) > get<0>(b));
}

void solve () {
    int n; cin >> n;
    vector<tuple<int, int, int, int>> arr;

    for (int i=0; i < n; i++) {
        int a, b; cin >> a >> b;
        int r = (int) sqrt((a * a) + (b * b));
        arr.push_back({r, a, b, i});
    }

    sort(arr.rbegin(), arr.rend(), check);
    for (auto [a, b, c, d]: arr) cout << b << " " << c << endl;
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
