#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    int n; cin >> n;
    map<int, int> map;
    vector<int> pref(n + 1);
    vector<int> arr;
    set<int> set;
    int soma = 0;
    cout << "pref -> ";
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        arr.push_back(num);
        set.emplace(num);
        soma += num;
        pref[i + 1] = soma;
        cout << pref[i + 1] << " ";
    }
    cout << endl;
    
    int p = 0;
    for (int i=1; i <= n; i++) {
        for (int j=2; (i - j) >= 0; j++) {
        /* cout << "i - j -> " << i << " - " << j << endl; */
            int x = pref[i];
            int m = pref[(i - j)];
            /* cout << "_---------------" << endl; */
            /* cout << "map[x - m] -> " << x - m << endl; */
            map[x - m]++;
        }
        /* if (map[arr[i - 1]]) p++; */
    }
    for (auto cara: set) {
        if (map[cara]) p += map[cara];
    }

    cout << p << endl;
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
