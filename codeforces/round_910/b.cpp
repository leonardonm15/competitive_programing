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
        // partir e colocar resto
        if (arr[i] > resp) {
            int p = (arr[i] / resp);
            int x = (p + ((arr[i] % resp) > 0 ? 1 : 0));
            /* cout << "arr[i] -> " << arr[i] << endl; */
            /* cout << "x - > " << x << endl; */
            // se tiver extra soma se tiver espaço no primero cara
            /* while (p + ((arr[i] % resp) > 0 ? 1 : 0) > resp) { */
            /*     x++; */
            /*     p = arr[i] / x; */
            /* } */
            resp = arr[i] / x;
            i++;
            c += (x - 1);
        } else {
            resp = arr[i];
            i++;
        }
    }
    cout << c << endl;
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
