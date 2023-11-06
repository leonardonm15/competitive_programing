#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, s, r; cin >> n >> s >> r;
    int mx = s - r;
    vector<int> arr;
    arr.push_back(mx);
    if (r % mx != 0) arr.push_back(r % mx);
    for (int i=0; i < r / mx; i++) arr.push_back(mx);
    int i = 1;
    while (arr.size() < n) {
        if (arr[i] > 1){
            arr[i]--;
            arr.push_back(1);
        } else i++;
    }
    for (auto cara: arr) {
        cout << cara << " ";
    }
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
