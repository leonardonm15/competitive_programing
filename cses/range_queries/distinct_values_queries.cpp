#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int N = 1e6 + 5;
int n;
int que_saco[N];
bool check(tuple<int, int, int> a, tuple<int, int, int> b) {
    int blq = (int)sqrt(n);
    auto [l1, r1, i1] = a;
    auto [l2, r2, i2] = b;
    return (l1/blq == l2/blq ? r1 < r2 : l1/blq < l2/blq);
}

void solve () {
    int q; cin >> n >> q;
    int arr[n];
    map<int, int> m;
    int resp[q];
    vector<tuple<int, int, int>> inp;

    int k = 1;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        if (!m[num]) m[num] = k++;
        arr[i] = m[num];
    }

    for (int i=0; i < q; i++) {
        int l, r; cin >> l >> r;
        l--; r--;
        inp.push_back({l, r, i});
    }

    sort(inp.begin(), inp.end(), check);

    int l = 0;
    int r = -1;
    int alberto = 0;
    for (auto [L, R, I]: inp) {
        while (r < R) {
            r++;
            if (!que_saco[arr[r]]) alberto++;
            que_saco[arr[r]]++;
        }

        while (l > L) { 
            l--;
            if (!que_saco[arr[l]]) alberto++;
            que_saco[arr[l]]++;
        }

        while (r > R) {
            if (que_saco[arr[r]] == 1) alberto--;
            que_saco[arr[r]]--;
            r--;
        }

        while (l < L) {
            if (que_saco[arr[l]] == 1) alberto--;
            que_saco[arr[l]]--;
            l++;
        }

        resp[I] = alberto;
    }

    for (int i=0; i < q; i++) cout << resp[i] << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}
