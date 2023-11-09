#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    string s; cin >> s;
    int n = s.size();
    vector<int> arr;
    for (int i=0; i < n; i++) {
        if (s[i] == '0') continue;
        int k = pow(10, n - i - 1);
        int num = (s[i] - '0') * k;
        arr.push_back(num);
    }
    cout << arr.size() << endl;
    for (auto cara: arr) cout << cara << " ";
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
