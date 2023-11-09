#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    int n; cin >> n;
    string s; cin >> s;
    reverse(s.begin(), s.end());

    int a = 0;
    if (n == 1 && s[0] == '1') {
        cout << -1 << endl;
        return;
    }

    if (s[0] == '1') {
        int f = 1;
        while (s[f] != '0' && f < n) f++;
        if (s[f]&1) {
            for (int i=1; i <= n; i++) cout << -1 << " ";
            cout << endl;
            return;
        } else {
            swap(s[f], s[0]);
            a = f;
            cout << f << " ";
        }
    } else if (s[0] == '0') cout << 0 << " ";

    int resp = a;
    for (int i=1; i <= n; i++) {
        int j = i + 1;
        cout << "j -> " << j << endl;
        if (i == n) {
            cout << -1 << " ";
            continue;
        }
        while (s[j] != '1' && s[i] == '1' && j < n) j++;
        cout << "sj -> " << s[j] << " - si -> " << s[i] << endl;
        if (s[j] == '0' && s[i] == '1') {
            swap(s[j], s[i]);
            resp += j - i;
            cout << resp << " ";
        } else {
            while (i < n) {
                cout << -1 << " ";
                i++;
            }
        }
    }
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
