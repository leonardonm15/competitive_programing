#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

int n;
vector<int> seg;

int merge(int a, int b) {
    return a + b;
}

int query (int u, int l, int r, int L, int R) {
    // ve o meu range
    // ve o range das minhas metades
    int mid = (l + r) >> 1;
    if (l >= L && r <= R) return seg[u];
    else if (l > R || r < L) return 0;
    else return merge(query(2 * u, l, mid, L, R), query(2 * u + 1, mid + 1, r, L, R));
}
int query(int l, int r) {
    return query(1, 0, n - 1, l, r);
}

void update(int u, int l, int r, int i, int x) {
    if (l == r) {
        seg[u] = x;
        return;
    }

    int mid = (l + r) >> 1;
    // l mid | mid + 1 r
    if (i <= mid) update(2 * u, l, mid, i, x);
    else update(2 * u + 1, mid + 1, r, i, x);
    seg[u] = merge(seg[2 * u], seg[2 * u + 1]);
}
void update(int i, int x) {
    update(1, 0, n - 1, i, x);
}

void build(int u, int l, int r, vector<int> &v) {
    if (l == r) {
        seg[u] = v[l];
        return;
    }
    
    // quebra no meio
    int mid = (l + r) >> 1;
    build(2 * u, l, mid, v);
    build(2 * u + 1, mid + 1, r, v);
    seg[u] = merge(seg[2 * u], seg[2 * u + 1]);
} 
void build(vector<int> &v) {
    seg.resize(4 * v.size());
    build(1, 0, v.size() - 1, v);
}

void solve () {
    cin >> n;
    vector<int> arr(n);
    for (int i=0; i < n; i++) cin >> arr[i];
    // build
    // update pontual
    // query range
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
