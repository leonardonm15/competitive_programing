#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    vector<string> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];


    int side = 0;

    int i = 0;
    while (arr[0][i] == '1') i++;
    side = i;

    i = n;
    while (arr[0][i] == '1') i--;
    side = min(side, n - i);
}

signed main() {
    solve();
    return 0;
}
