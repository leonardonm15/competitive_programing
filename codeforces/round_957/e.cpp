#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;

    string num = to_string(n);
    int sz = num.size();
    vector<pair<int, int>> resp;
    string acc = num;
    acc += acc, acc += acc, acc += acc;

    for (int a = 1; a <= 10000; a++) {
        string nacc;
        for (int i = 1; i <= 6; i++) {
            nacc.push_back(acc[i - 1]);
            int fake = stoll(nacc);
            int b = sz * a - i;
            if (n * a - b == fake && b != 0) resp.push_back({a, b});
        }
    }
    
    cout << resp.size() << endl;
    for (auto [a, b]: resp) {
        cout << a << " " << b << endl;
    }
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
