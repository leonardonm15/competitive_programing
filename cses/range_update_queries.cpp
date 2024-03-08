#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

vector<int> seg;
int n;
void build(int u, int l, int r, vector<int> &v) {
    if (l == r) {
        seg[u] = v[l];
        return;
    }

    int mid = (l + r) >> 1;
    build(2 * u, l, mid, v);
    build(2 * u + 1, mid + 1, r, v);
}

int query(int u, int l, int r, int k, int add) {
    if (l == r) return seg[u] + add;
    else add += seg[u];
    int mid = (l + r) >> 1;
    if (k <= mid) return query(2 * u, l, mid, k, add);
    else return query(2 * u + 1, mid + 1, r, k, add);
}

int query(int k) {
    return query(1, 0, n - 1, k, 0);
}

void update(int u, int l, int r, int L, int R, int k) {
    int mid = (l + r) >> 1;
    if (l >= L && r <= R) {
        seg[u] += k;
        return;
    }

    else if (r < R || l > R) return;
    else {
        update(2 * u, l, mid, L, R, k);
        update(2 * u + 1, mid + 1, r, L, R, k);
    }
}

void update(int l, int r, int k) {
    update(1, 0, n - 1, l, r, k);
}

void build(vector<int> &v) {
    seg.resize((int)v.size() * 4, 0);
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
            int l, r, k; cin >> l >> r >> k;
            l--; r--;
            update(l, r, k);
        } else {
            int k; cin >> k;
            k--;
            cout << query(k) << endl;
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
