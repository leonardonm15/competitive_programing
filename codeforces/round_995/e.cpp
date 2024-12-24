#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// Função c1
bool c1(vector<int>& arr, int mid, int k) {
    return arr[mid] >= k;
}

// Função de busca binária
int bb(vector<int>& arr, int k, bool (*check)(vector<int>&, int, int)) {
    int n = arr.size();
    int l = 0;
    int r = n - 1;
    int ans = n;

    while (l <= r) {
        int mid = (l + r) >> 1;

        if (check(arr, mid, k)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return ans;
}

// Função solve
void solve() {
    int n, k; 
    cin >> n >> k;

    vector<int> a(n), b(n), sa(n), sb(n), all;

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    sa = a;
    sb = b;

    for (int i = 0; i < n; i++) {
        all.push_back(a[i]);
        all.push_back(b[i]);
    }

    sort(sa.begin(), sa.end());
    sort(sb.begin(), sb.end());
    sort(all.begin(), all.end());

    int resp = -1;
    for (auto val : all) {
        int quantos_compraram = n - bb(sb, val, c1); // quantos caras pra direita
        int good_review = n - bb(sa, val, c1);

        if (quantos_compraram - good_review > k) continue;

        resp = max(resp, quantos_compraram * val);
    }

    cout << resp << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int TC = 1;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
