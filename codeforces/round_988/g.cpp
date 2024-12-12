#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int N = 2e5 + 5;
const int A = 1e6 + 5;
const int zap = 998244353;

vector<int> fact[A];
vector<int> nums[A];
int dp[N];
int vis[A];

int calc(int i, vector<int>& arr) {
    if (dp[i] != -1) return dp[i];
    cout << "--------------" << endl;
    cout << "arr[i] -> " << arr[i] << endl;
    cout << "I -> " << i << endl;

    int soma = 0;
    dp[i] = 0;
    for (auto p: nums[i]) {
        /* cout << "p -> " << p << endl; */
        for (auto j: fact[p]) {
            if (j >= i || vis[j] == i) continue;
            soma += calc(j, arr);
            soma %= zap;
            vis[j] = i;
        }
    }

    return dp[i] = soma;
}

void solve () {
    int n; cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    dp[0] = 1;
    vis[0] = -1;

    for (int i = 1; i < n; i++) {
        dp[i] = -1;
        vis[i] = -1;
    }

    for (int i = 0; i < n; i++) {
        int k = arr[i];

        for (int j = 2; j * j <= k; j++) {
            while (k % j == 0) {
                k /= j;
            }

            fact[j].push_back(i); // o jtézimo primo tem o index i
            nums[i].push_back(j); // fatoração do arr[i]
        }

        if (k > 1) {
            fact[k].push_back(i);
            nums[i].push_back(k);
        }

        /* cout << "----------------" << endl; */
    }

    for (int i = 0; i < 500; i++) {
        if (fact[i].size() > 0) {
            cout << "I -> " << i << " | ";
            for (auto c: fact[i]) cout << c << " ";
            cout << endl;
        }
    }


    cout << calc(n - 1, arr) % zap << endl;
}

signed main() {
    /* ios_base::sync_with_stdio(0);cin.tie(0); */
    int TC = 1;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
