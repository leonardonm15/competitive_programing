#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
const int MOD = 1e9 + 7;

vector<int> arr;

int calc(int n, int lc) {
    if (n == 0) return 1;
    
    for (auto cara: 
}

void solve () {
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        arr.push_back(num);
    }

    int resp = 0;

    cout << calc(k, ) << endl;

}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
