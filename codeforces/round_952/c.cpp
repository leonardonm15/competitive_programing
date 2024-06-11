#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    int sum = 0;
    int curr = 0;
    int resp = 0;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        sum += num;
        curr = max(curr, num);
        if (sum - curr == curr) resp++;
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
