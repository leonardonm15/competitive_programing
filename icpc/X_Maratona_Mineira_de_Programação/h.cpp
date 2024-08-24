#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
/* #define int long long */

void solve () {
    int n; cin >> n;
    string s; cin >> s;

    vector<int> conv(20);
    vector<int> mp(7e7);
    
    char let = 'a';
    for (int i = 0; i < 20; i++) {
        while (let == 'a' || let == 'e' || let == 'i' || let == 'o' || let == 'u' || let == 'y') let++;
        conv[i] = (int)let++;
    }

    mp[0]++;
    int k = 0;
    long long resp = 0;

    for (auto c: s) {
        k ^= (1 << (c - 'a'));
        resp += mp[k];
        for (int i = 0; i < 20; i++) {
            int quero = k ^ (1 << (conv[i] - ((int) 'a')) );
            resp += mp[quero];
        }
        mp[k]++;
    }

    cout << resp << endl;
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
