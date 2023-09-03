#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    map <string, char> map; 
    map["ba"] = '0';
    map["aba"] = '1';
    int n; cin >> n;
    int check;
    string m, c, out; cin >> m;
    for (int i=n - 1; i >= 0; i--) {
        c.push_back(m[i]);
        int t = out.size();
        if (map.find(c) != map.end()) {
            out.push_back(map[c]);
        }
        /* cout << "t-> " << t << endl; */
        /* cout << "out.size() - " << out.size() << endl; */
        if (t != out.size()) c.clear();

        /* cout << "c = " << c << endl; */
        /* cout << "output - " << out << endl; */

        if (c.size() > 3) {
            out.clear();
            out.push_back('(');
            out.push_back(':');
            break;
        }
        check = c.size();
    }
    reverse(out.begin(), out.end());
    if (check > 0) out = ":(";
    cout << out << endl;
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
