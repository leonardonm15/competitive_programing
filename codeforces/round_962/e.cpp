#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int MOD = 1e9 + 7;

void solve () {
    string s; cin >> s;
    int n = s.size();

    vector<int> sum;

    int soma = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] - '0' == 0) soma--;
        else soma++;
        sum.push_back(soma);
    }

    cout << "sum -> ";
    for (auto c: sum) cout << c << " ";
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
