#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    string s; cin >> s;
    string resp;
    bool app = false;
    for (int i = 1; i < (int) s.size(); i++) {
        resp += s[i - 1];
        if (s[i] == s[i - 1] && !app) {
            char ch;
            if (s[i] == 'z') ch = s[i] - 1;
            else ch = s[i] + 1;
            app = true;
            resp += ch;
        }
    }

    resp += s[s.size() - 1];
    if (!app) {
        s[s.size() - 1] == 'z' ? resp.push_back(s[s.size() - 1] - 1) : resp.push_back(s[s.size() - 1] + 1);
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
