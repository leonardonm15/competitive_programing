#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    map<int, int> map;
    vector<int> arr(n);
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        arr[i] = num;
        map[num]++;
    }

    for (int i=0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (map[arr[i]] > 1 && map[arr[j]] > 1 && arr[i] != arr[j]) {
                map[arr[i]]--;
                map[arr[j]]--;
                arr[i] = -1;
                arr[j] = -1;
            }
        }
    }

    int resp = 0;
    for (auto [i, j]: map) {
        /* cout << "i | j ->" << i << " - " << j << endl; */
        if (j % 2 == 1 && i > 0) {
            resp++;
        }
    }

    cout << resp << endl;
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
