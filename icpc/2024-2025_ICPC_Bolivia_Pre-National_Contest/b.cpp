#include <bits/stdc++.h>

using namespace std;
#define int long long
#define endl '\n'

void solve() {
    int k;
    cin >> k;
    int res = 0;
    for(int i = 0; i < k;i++){
        int a;
        cin >> a;
        res += (1ll<<(a-1));
    }
    cout << res << endl;
}

signed main() {
    int q;
    cin >> q;
    while(q--)
        solve();
}
