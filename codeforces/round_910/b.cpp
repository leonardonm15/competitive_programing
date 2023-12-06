#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    int n; cin >> n;
    int c = 0;
    int resp;
    vector<int> arr(n);
    for (int i=0; i < n; i++) cin >> arr[(n - 1) - i];
    resp = arr[0];
    int i = 1;
    while (i < n) {
        if (arr[i] > resp) {
            if ((arr[i] - (arr[i] / 2)) <= resp) {
                c++;
                resp = arr[i] / 2;
            }
        } else {
            resp = arr[i];
            i++;
        }
    }
    // se metade do cara for menor doq o da direita marcha, else tira so
    // o cara da direita
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
