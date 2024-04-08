#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, c, d; cin >> n >> c >> d;
    map<int, int> map;
    vector<int> arr;
    for (int i=0; i < n * n; i++) {
        int num; cin >> num;
        arr.push_back(num);
        map[num]++;
    }

    sort(arr.begin(), arr.end());

    int init = arr[0];
    for (int i=0; i < n; i++) {
        int k = init;
        for (int j=0; j < n; j++) {
            map[k]--;
            k += d;
        }
        init += c;
    }

    for (auto [cara, f]: map) {
        if (f != 0) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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
