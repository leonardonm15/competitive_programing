#include <bits/stdc++.h>

using namespace std;

#define int long long
#define tii tuple<int, int, int>
#define endl '\n'

const int N = 1e6 + 5;
vector<pair<int, int>> timeline[N];
int dp[N];

int bb(int k, vector<int>& arr) {
    int l = 0;
    int r = arr.size() - 1;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (k < arr[mid]) {
            r = mid - 1;
        } else if (k > arr[mid]) {
            l = mid + 1;
        } else {
            return ans = mid;
        }
    }

    return ans;
}

void solve() {
    int n; cin >> n;
    vector<int> nums;
    vector<tii> inp;

    for (int i = 0; i < n; i++) {
        int l, r, w; cin >> l >> r >> w;
        inp.push_back({l, r, w});
        nums.push_back(l);
        nums.push_back(r);
    }

    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    for(auto [l, r, w]: inp) {
        int tl = bb(l, nums) + 1;
        int tr = bb(r, nums) + 1;

        timeline[tl].push_back({tr, w});
    }

    for (int t = 0; t < N - 1; t++) {
        for (auto [r, w]: timeline[t]) {
            dp[r + 1] = max(dp[r + 1], dp[t] + w);
        }
        dp[t + 1] = max(dp[t + 1], dp[t]);
    }

    cout << dp[N - 1] << endl;
    // cout << calc(0) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
}
