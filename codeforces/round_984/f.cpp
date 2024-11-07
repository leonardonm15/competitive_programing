#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long


vector<int> bits_counter(int x) {
    cout << "---------------------" << endl;
    cout << "x -> " << x << endl;
    vector<int> bits(60);
    bits[0] = (x + 1) / 2;
    int i = 1;
    while ((1 << i) <= x) {
        int d = (1 << i);
        int v = (x >> (i + 1));
        cout << "-----" << endl;
        cout << "d -> " << d << endl;
        cout << "v -> " << v << endl;
        bits[i] = d * v + (x & (1 << i) ? d : 0);
        i++;
    }

    return bits;
}

void solve () {
    int l, r, i, k; cin >> l >> r >> i >> k;

    vector<int> vl = bits_counter(l);
    vector<int> vr = bits_counter(r);
    
    cout << "vl -> ";
    for (int i = 59; i >= 0; i--) cout << vl[i] << " ";
    cout << endl;

    cout << "vr -> ";
    for (int i = 59; i >= 0; i--) cout << vr[i] << " ";
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
