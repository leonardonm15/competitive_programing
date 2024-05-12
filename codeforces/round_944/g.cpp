#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, priority_queue<int>> mp;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        mp[a[i]>>2].push(-a[i]);
    }
    for(int i = 0; i < n; i++)
    {
        cout << -mp[a[i]>>2].top() << " ";
        mp[a[i]>>2].pop();
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
