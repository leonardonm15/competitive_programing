#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, f, a, b; cin >> n >> f >> a >> b;
    vector<int> arr(n);
    vector<int> pref;
    
    for (int i=0; i < n; i++) cin >> arr[i];

    int lc = 0;
    for (int i=0; i < n; i++) {
        f -= min(b, (arr[i] - lc) * a);
        lc = arr[i];
    }

    /* cout << "f -> " << f << endl; */
    cout << (f > 0 ? "YES" : "NO") << endl;
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
