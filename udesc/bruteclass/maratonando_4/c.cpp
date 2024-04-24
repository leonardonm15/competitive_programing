#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    string s; cin >> s;
    int resp = 0;
    int malvadao = 0;
    vector<int> freq(2);
    for (auto cara: s) {
        if (cara == '0') freq[0]++;
        else freq[1]++;

        if ((cara - '0') == malvadao && freq[1] > 0) {
            resp++;
            malvadao ^= 1;
        }
    }

    cout << resp << endl;
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
