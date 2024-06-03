#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    map<int, int> tenho;
    map<int, int> preciso;

    for (int i=0; i < n; i++) cin >> a[i];

    for (int i=0; i < n; i++) cin >> b[i];

    for (int i=0; i < n; i++) {
        if (a[i] != b[i]) preciso[b[i]]++;
        if (a[i] == b[i]) tenho[b[i]]++;
    }

    int q; cin >> q;
    int dm = 0;
    for (int i=0; i < q; i++) {
        int num; cin >> num;
        if (preciso[num]) { // se eu preciso do cara
            tenho[num]++;
            preciso[num]--;
            dm = 0;
            continue;
        }
        if (!preciso[num] && tenho[num]) { //  se eu nao preiciso mas tenho ele
            dm = 0;
            continue;
        }
        if (!preciso[num] && !tenho[num]) dm++; // se eu nao preciso do numero
                                                // e nao tenho ele
    }

    for (auto [c, v]: preciso) dm += v;

    cout << (dm ? "NO" : "YES") << endl;
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
