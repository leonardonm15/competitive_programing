#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, k; cin >> n >> k;
    int nk = k;
    vector<int> resp;

    for (int i=1; i <= n; i++) resp.push_back(i);

    reverse(resp.begin(), resp.end());

    int h = 1;
    for (int i=0; i < n; i++) {
        resp[i] = max(resp[i], k);
        k -= h;
        h++;
    }

    reverse(resp.begin(), resp.end());

    for (auto c: resp) cout << c << " ";
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
