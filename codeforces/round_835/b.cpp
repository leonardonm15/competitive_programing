#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n; cin >> n;
    int maior = 0;
    string s; cin >> s;
    for (int i=0; i < n; i++) {
        int num = s[i] - 'a';
        maior = max(num, maior);
    }
    maior++;
    cout << maior << endl;
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
