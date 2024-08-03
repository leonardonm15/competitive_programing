#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    string s; cin >> s;

    int sum = 0;

    for (int i = 1; i < n; i += 2) {
        int c = s[i];
        if (c == '(') sum++;
        else if (c == ')') sum--;
        if (sum < 0) {
            s[i - 1] = '(';
        }
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
