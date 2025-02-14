#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, m, k; cin >> n >> m >> k;
    int a = n, b = m;
    bool flag = false;

    if (b > a) flag = true;
    string s;
    for (int i = 0; i < k; i++) {
        if (flag) {
            s.push_back('1');
            b--;
        }
        else {
            a--;
            s.push_back('0');
        }
    }

    if (a < 0 || b < 0) {
        cout << -1 << endl;
        return;
    }
    

    for (int i = k; i < n + m; i++) {
        if (s[i - 1] == '0') {
            if (b > 0) {
                s.push_back('1');
                b--;
            } else {
                s.push_back('0');
                a--;
            }
        }

        if (s[i - 1] == '1') {
            if (a > 0) {
                s.push_back('0');
                a--;
            } else {
                s.push_back('1');
                b--;
            }

        }
    }

    int ws = 0;
    int qa = 0;
    int qb = 0;
    int mx = 0;
    for (int i = 0; i < n + m; i++) {
        if (s[i] == '1') {
            qb++;
        } else {
            qa++;
        }
        ws++;

        if (ws > k) {
            if (s[i - k] == '1') {
                qb--;
            } else {
                qa--;
            }
        }
        ws--;

        mx = max(mx, abs(qa - qb));
    }

    cout << s << endl;

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
