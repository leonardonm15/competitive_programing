#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> stack;

    int resp = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '(') {
            stack.push_back(i + 1);
        } else {
            if (stack.size()) {
                resp += (i + 1) - stack.back();
                stack.pop_back();
            } else {
                stack.push_back(i + 1);
            }
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
