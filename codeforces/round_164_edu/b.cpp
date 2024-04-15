#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

int tc = 0;
void solve () {
    tc++;
    int n; cin >> n;
    vector<int> arr(n);
    for (int i=0; i < n; i++) cin >> arr[i];
    /* if (tc == 824) { */
    /*     cout << n << "#"; */
    /*     for (auto cara: arr) cout << cara << "$"; */
    /*     cout << endl; */
    /* } */
    int k = 0;
    for (int i=0; i < n; i++) {
        if (arr[i] != arr[n - 1]) {
            k = i;
            break;
        }
    }

    for (int i=n - 1; i >= 0; i--) {
        if (arr[i] != arr[0]) {
            k = min(k, (n - 1) - i);
            break;
        }
    }

    vector<int> pos;
    if (arr.size() >= 3) {
        for (int i=1; i < n - 1; i++) {
            if (arr[i] != arr[0]) {
                pos.push_back(i);
            }
        }
    }

    int k2 = 1e9 + 5;
    if (pos.size() >= 2) {
        for (int i=1; i < (int) pos.size(); i++) {
            k2 = min(k2, pos[i] - pos[i - 1] - 1);
        }
    }

    if (k == 0) {
        cout << -1 << endl;
        return;
    }

    cout << min(k, k2) << endl;
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
