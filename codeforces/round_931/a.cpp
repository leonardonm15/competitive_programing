#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    vector<int> a(n);
    for (int i=0; i < n; i++) cin >> a[i];
    int resp = -1;
    sort(a.begin(), a.end()); 
    /* cout << "a -> "; */
    /* for (auto cara: a) cout << cara << " "; */
    /* cout << endl; */
    int i = 0;
    int j = n - 1;
    while (i != j) {
        int k = i + 1;
        int l = j - 1;
        int z = abs(a[i] - a[j]) + abs(a[j] - a[k]) + abs(a[k] - a[l]) + abs(a[l] - a[i]);
        cout << z << endl;
        return;
        i++;
        j--;
        resp = min(resp, z);
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
