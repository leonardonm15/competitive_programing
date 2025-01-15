#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

int mx = 0;
void solve () {
    vector<int> arr(4e5);

    for (int i = 0; i < arr.size(); i++) arr[i]++;
    int q = 1;

    while (!arr[(int)rand() % (int)4e5]) q++;

    /* cout << "q -> " << q << endl; */

    mx = max(mx, q);
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

    cout << "max_total -> " << mx << endl;
    return 0;
}
