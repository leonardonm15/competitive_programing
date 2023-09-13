#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    int n, k; cin >> n >> k;
    vector<int> pref(n+1);
    map<int, int> sum;
    sum[0] = 1;
    int resp = 0;
    int soma = 0;
    for (int i=1; i <= n; i++) {
        int num; cin >> num;
        soma += num;
        if (sum.find(soma - k) != sum.end()){
            resp += sum[soma - k];
        } 
        sum[soma]++;
    }
    cout << resp << endl;
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
