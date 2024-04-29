#include <bits/stdc++.h>

#define endl '\n'
#define int long long

using namespace std;

void solve() {
    string s, p, k; cin >> s >> p;
    int n = s.size();
    int m = p.size();

    int resp = 0;
    int l = 0;
    int r = m - 1;

    while (r < n) {
        bool flag = true;
        for (int i=0; i < m; i++) {
            if (p[i] == s[l + i]) {
                flag = false;
            }
        }

        if (flag) resp++;
        l++;
        r++;
    }


    cout << resp << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
}


