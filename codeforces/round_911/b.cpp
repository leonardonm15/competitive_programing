#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int a, b, c; cin >> a >> b >> c;
    vector<int> resp(3);

    if ((b + c) % 2 == 0) resp[0]++;
    if ((a + c) % 2 == 0) resp[1]++;
    if ((a + b) % 2 == 0) resp[2]++;

    for (auto cara: resp) cout << cara << " ";
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
