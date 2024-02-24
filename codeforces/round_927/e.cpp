#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> a(n);

    reverse(s.begin(), s.end());

    int k = 0;
    for (int i=n - 1; i >= 0; i--){
        k += (s[i] - '0');
        a[i] = k;
    }

    int carry = 0;
    for (int i=0; i < n; i++) {
        a[i] += carry;
        carry = a[i] / 10;
        a[i] %= 10;
    }

    while (carry > 0){
        a.push_back(carry % 10);
        carry /= 10;
    }

    while (a.back() == 0) a.pop_back();

    reverse(a.begin(), a.end());
    for (auto c: a) cout << c;
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
