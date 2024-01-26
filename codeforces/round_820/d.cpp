#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    vector<int> x(n), y(n), s;
    for (int i=0; i < n; i++) cin >> x[i];
    for (int i=0; i < n; i++) cin >> y[i];
    for (int i=0; i < n; i++) s.push_back(y[i] - x[i]);

    sort(s.begin(), s.end());

    int l = 0;
    int r = s.size() - 1;
    int resp = 0;
    while (l < r) {
        if (s[r] < abs(s[l])) l++;
        else {
            resp++;
            l++;
            r--;
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
