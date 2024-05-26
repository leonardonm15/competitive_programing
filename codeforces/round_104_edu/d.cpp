#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
#define int long long
#define buliano bool
 
int calc(int N) {
    int resp = 0;
    for (int a=1; (int)(a * a) <= 2 * N + 1; a+=2) {
        int aa = a * a;
        int b = (aa - 1) / 2;
        int k2 = aa - b;
 
        if (k2 <= N) resp++;
    }
    
    return resp;
}
 
void solve () {
    int n; cin >> n;
    cout << calc(n) - 1 << endl;
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
