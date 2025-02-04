#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    string a = "intus";
    string b = "rcazuawx";
    string c = "arca";
    string test = "abdcefgh";

    for (int i = 0; i <= 26; i++) {
        string a2, b2, c2, t2;
        for (auto v: a) a2.push_back(((v - 'a' + i) % 26) + 'a');
        for (auto v: b) b2.push_back(((v - 'a' + i) % 26) + 'a');
        for (auto v: c) c2.push_back(((v - 'a' + i) % 26) + 'a');
        for (auto v: test) t2.push_back(((v - 'a' + i) % 26) + 'a');

        cout << "----------- i - " << i << " ------" << endl;
        cout << a2 << endl;
        cout << b2 << endl;
        cout << c2 << endl;
        cout << t2 << endl;
    }
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
