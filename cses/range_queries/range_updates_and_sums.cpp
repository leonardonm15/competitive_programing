#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

struct SegLazy {
    int n;
    vector<int> seg;
    vector<int> lreplace;
    vector<int> lsoma;

    int merge (int u, int v) { return u + v; }

    int lc (int u) { return 2 * u; }
    int rc (int u) { return 2 * u + 1; }


    void update_soma(int u, int l, int r, int x) {
        push(u);
    }
    void update_soma(int l, int r, int x) {

    }

    void build (int u, int l, int r, const vector<int>& vec) {
        if (l == r) {
            seg[u] = vec[l];
            return;
        }

        int mid = (l + r) >> 1;
        build(lc(u), l, mid, vec);
        build(rc(u), mid + 1, r, vec);
        seg[u] = merge(lc(u), rc(u));
    }
    void build (const vector<int>& vec) {
        n = vec.size();
        seg.resize(4 * n);
        lreplace(4 * n);
        lsoma(4 * n);
        build(1, 0, n - 1, vec);
    }
}

void solve () {
    int n, q; cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    while (q--) {
        int t; cin >> t;

        if (t == 1) { // soma em range l r x
        }

        if (t == 2) { // assign em range l, r, x
        }

        if (t == 3) { // soma dos valores em range l r
        }
    }

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
