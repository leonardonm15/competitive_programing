#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    vector<int> c(n);
    vector<pair<int, int>> arr;

    for (int i=0; i < n; i++) {
        int num; cin >> num;
        arr.push_back({num, 0});
    }

    for (int i=0; i < n; i++) {
        int num; cin >> num;
        arr.push_back({num, 1});
    }

    for (int i=0; i < n; i++) cin >> c[i];

    sort(c.rbegin(), c.rend());
    sort(arr.begin(), arr.end());
    vector<int> stc;
    vector<int> diff;
    int ans = 0;
    int ci = 0;

    /* for (auto [i, t]: arr) { */
    /*     cout << "( " << i << ", " << t << ") " << " "; */
    /* } */
    /* cout << endl; */

    for (auto [i, t]: arr) {
        if (!(t&1)) stc.push_back(i);
        else {
            diff.push_back(i - stc.back());
            ci++;
            stc.pop_back();
        }
    }

    sort(diff.begin(), diff.end());
    /* for (auto cara: diff) cout << cara << " "; */
    /* cout << endl; */

    for (int i=0; i < diff.size(); i++) ans += diff[i] * c[i];

    cout << ans << endl;
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
