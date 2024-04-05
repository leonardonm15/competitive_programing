#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i=0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    if (arr[n - 1] == arr[0]) {
        cout << - 1 << endl;
    } else {
        int it = 0;
        while (arr[it] == arr[0]) it++;
        cout << it << " " << n - it << endl;
        for(int i=0; i < it; i++) cout << arr[i] << " ";
        cout << endl;
        for (int i=it; i < n; i++) cout << arr[i] << " ";
        cout << endl;
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
