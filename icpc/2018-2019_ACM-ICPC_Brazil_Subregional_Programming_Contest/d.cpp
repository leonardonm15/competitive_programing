#include <bits/stdc++.h>

#define endl '\n'
#define int long long

using namespace std;

void solve() {
    int n; cin >> n;
    int k = 0;
    while (n--) {
        int num; cin >> num;
        if (num != 1) k++;
    }

    cout << k << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}


