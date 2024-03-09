#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, m; cin >> n >> m;

    vector<pair<int, int>> arr;
    for (int i=0; i < m; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        arr.push_back({a, b});
    }

    int t = 0;
    int k = 1;
    while (k <= (1 << n) - 1) {
        bool flag = false;
        for (auto [a, b]: arr) {
            if ((k & (1 << a)) && (k & (1 << b))) {
                /* cout << "K -> " << k << endl; */
                flag = true;
            }
        }
        if (!flag) t++;
        k++;
    }

    cout << t << endl;
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
