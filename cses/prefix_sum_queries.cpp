#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

vector<int> seg;
int n;

int merge(int a, int b) return a + b;

void update(int u, int l, int r, int k, int ) {
    if (l == r) seg[u] = k;
    int mid = 

}

void update(int u) {
    update(1, 0, n - 1, u);
}

void build(int u, int l, int r, vector<int>& v) {
    if (l == r) seg[u] = v[l];
    int mid = (l + r) >> 1;
    build(u * 2, l, mid, v);
    build(u * 2 + 1, mid + 1, r, v);
    seg[u] = merge(seg[u * 2], seg[u * 2 + 1]);
}
void build(vector<int> &v) {
    seg.assign(4 * n);
    build(1, 0, n - 1, v);
}

void solve () {
    int q; cin >> n >> q;
    vector<int> arr(n);

    for (int i=0; i < n; i++) cin >> arr[i];

    build(arr);
    while (q--) {
        int t; cin >> t;
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
