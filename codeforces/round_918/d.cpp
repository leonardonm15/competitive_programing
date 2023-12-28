#include <bits/stdc++.h>

using namespace std;
//#define int long long

bool check_v(char a) {
    if (a == 'a' || a == 'e') return true;
    else return false;
}

void solve () {
    int n; cin >> n;
    string s; cin >> s;
    vector<string> resp;
    for (int i=n - 1; i > 0; i--) {
        string k;
        if (check_v(s[i])) {
            k.push_back(s[i - 1]);
            k.push_back(s[i]);
            resp.push_back(k);
            if ((i - 1) == 0) break;
            i -= 1;
        } else {
            k.push_back(s[i - 2]);
            k.push_back(s[i - 1]);
            k.push_back(s[i]);
            resp.push_back(k);
            if ((i - 2) == 0) break;
            i -= 2;
        }
        k.clear();
    }
    
    reverse(resp.begin(), resp.end());
    for (int i=0; i < resp.size(); i++) {
        if (i == 0) cout << resp[i];
        else {
            cout << '.' << resp[i];
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
