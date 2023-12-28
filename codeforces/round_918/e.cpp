#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> ppar;
    vector<int> pimp;
    int somap = 0;
    int somai = 0;
    pimp.push_back(0);
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        if (i&1) {
            somai += num;
            pimp.push_back(somai);
        } else {
            somap += num;
            ppar.push_back(somap);
        }
    }

    cout << "ppar -> ";
    for (auto cara: ppar) cout << cara << " ";
    cout << endl;

    cout << "pimp -> ";
    for (auto cara: pimp) cout << cara << " ";
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
