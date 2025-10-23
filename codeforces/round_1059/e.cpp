#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int N = 2e5 + 5;

int vis[N];

void solve () {
    int n, k; cin >> n >> k;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        vis[num]++;
        arr[i] = num;
    }


    vector<int> nums;

    for (int i = 1; i <= n; i++) {
        if (!vis[i]) nums.push_back(i);
    }

    vector<int> resp;
    while (k--) {
        if (nums.size()) {
            arr.push_back(nums.back());
            resp.push_back(nums.back());
            vis[nums.back()]++;
            nums.pop_back();
        } else {
            int v = arr.size();
            int a = arr[v - 1];
            int b = arr[v - 2];
            for (int i = 1; i <= n; i++) {
                if (i != a && i != b) {
                    arr.push_back(i);
                    resp.push_back(i);
                    break;
                }
            }
        }
    }

    for (auto v: resp) cout << v << " ";
    cout << endl;

    for (int i = 0; i <= n + 1; i++) vis[i] = 0;
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
