#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    map<int, multiset<pair<int, int>>> map;
    int n, k; cin >> n >> k;
    vector<int> arr(2 * n);
    for (int i=0; i < (2 * n); i++) cin >> arr[i];

    int l = 0;
    int r = 1;
    int curr = 0;
    curr ^= arr[l];
    while (r <= (2 * k) - 1) {
        curr ^= arr[r];
        r++;
    }
    r--;
    map[curr].emplace(make_pair(l, r));
    while (r < n - 1) {
        curr ^= arr[l++];
        /* r++; */
        curr ^= arr[++r];
        /* cout << "l, r -> " << l << " " << r << " - " << curr << endl; */
        map[curr].emplace(make_pair(l, r));
    }

    for (auto [v, vec]: map) {
        if (vec.size() < 2) continue;
        pair<int, int> a = *vec.begin();
        pair<int, int> b = *(vec.rbegin());
        if (a.second >= b.first || a.second > n - 1) continue;
        else {
            /* cout << "v -> " << v << endl; */
            for (int i=a.first; i <= a.second; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;

            for (int i= b.first; i <= b.second; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
            return;
        }
    }
}

signed main() {
    /* ios_base::sync_with_stdio(0);cin.tie(0); */
    int TC = 1;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
