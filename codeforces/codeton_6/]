#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, m; cin >> n >> m;
    vector<int> arr;
    int x = 0;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        arr.push_back(num);
        if (i == 0) x = num;
        else x ^= num;
    }

    int q = 0;
    for (int i=0; i < m; i++) {
        int num; cin >> num;
        q |= num;
    }
    
    for (int i=0; i < n; i++) {
        arr[i] |= q;
    }

    int x2 = 0;
    for (int i=0; i < n; i++) {
        if (i == 0) x2 = arr[i];
        else {
            x2 ^= arr[i];
        }
    }
    cout << min(x2, x) << " " << max(x2, x) << endl;
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
