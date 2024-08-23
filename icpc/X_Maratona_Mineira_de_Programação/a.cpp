#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
// #define int long long

void solve(){
    vector<int> a(4);
    for(auto &i : a) cin >> i;

    if(a[1] == 1 && a[2] == 2 && a[3] == 3) cout << 1 << endl;
    if(a[0] == 1 && a[2] == 1 && a[3] == 2) cout << 2 << endl;
    if(a[0] == 2 && a[1] == 1 && a[3] == 1) cout << 3 << endl;
    if(a[0] == 3 && a[1] == 2 && a[2] == 1) cout << 4 << endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
