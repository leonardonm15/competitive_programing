#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

vector<int> nums = {-1,-100,3,99};
int k = 5;
int n = nums.size();

void dfs(int u, int lc, int p, int l) {
    cout << "u -> " << u << endl;
    if (l != 0 && u == p) return;
    dfs((u + k) % n, u, p, l + 1);
    swap(nums[u], nums[lc]);
}

void solve () {
    cin >> k;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        arr[(i + k) % n] = nums[i];
    }

    if (gcd(n, k) != 1) {
        int v = gcd(n, k);

        for (int i = 0; i < v; i++) {
            dfs(i, i, i, 0);
        }

    }
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
