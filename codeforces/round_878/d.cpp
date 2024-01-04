#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> soma(n);
    int cum = 0;

    for (int i=0; i < n; i++) {
        int num; cin >> num;
        cum = abs(cum - num);
        soma[i] = num;
    }
    sort(soma.begin(), soma.end());
    
    cout << "sort soma -> ";
    for (auto cara: soma) cout << cara << " ";
    cout << endl;

    int l = 0;
    int r = 
    int resp = 1e9;
    for (int i=0; i < n - 3; i++) {
        
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
