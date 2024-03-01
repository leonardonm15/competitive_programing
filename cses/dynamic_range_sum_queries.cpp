#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

vector<int> seg;
int n;
const int neutral = 0;

int merge(int a, int b) {
    return a + b;
}

int query(int u, int l, int r, int L, int R) {
    int mid = (l + r) >> 1;
    if (l >= L && r <= R) return seg[u];
    else if (r < L || l > R) return neutral;
    else return merge(query(2 * u, l, mid, L, R), query(2 * u + 1, mid + 1, r, L, R));
}

int query(int l, int r) {
    return query(1, 0, n - 1, l, r);
}

void update(int u, int l, int r, int i, int v) {
    if (l == r) {
        seg[u] = v;
        return;
    }

    int mid = (l + r) >> 1;
    if (i <= mid) update(2 * u, l, mid, i, v);
    else update(2 * u + 1, mid + 1, r, i, v);
    seg[u] = merge(seg[2 * u], seg[2 * u + 1]);
}

void update(int u, int v) {
    update(1, 0, n - 1, u, v);
}

void build(int u, int l, int r, vector<int> &v) {
    if (l == r) {
        seg[u] = v[l];
        return;
    }

    int mid = (l + r) >> 1;
    build(2 * u, l, mid, v);
    build(2 * u + 1, mid + 1, r, v);
    seg[u] = merge(seg[2 * u], seg[2 * u + 1]);
}

void build(vector<int> &v) {
    seg.resize(4 * n, neutral);
    build(1, 0, n - 1, v);
}

void solve () {
    int q; cin >> n >> q;
    vector<int> arr(n);
    for (int i=0; i < n; i++) cin >> arr[i];
    build(arr);

    while (q--) {
        int t; cin >> t;
        if (t&1) {
            int i, v; cin >> i >> v;
            i--;
            update(i, v);
        } else {
            int l, r; cin >> l >> r;
            l--; r--;
            cout << query(l, r) << endl;
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
