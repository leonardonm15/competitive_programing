#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
#define ll long long
#define pii pair<ll, bool>
const ll INF = 1e9;

struct SegTree {
    pii merge(pii a, pii b) { 
        /* cout << "-----------------" << endl; */
        /* cout << "a -> " << a.first << endl; */
        /* cout << "b -> " << b.first << endl; */
        if (a.first == neutral) return b;
        if (b.first == neutral) return a;
        pii c;
        c.first = max(a.first, b.first);
        if (b.second == 1 || a.second == 1) c.second = 1;
        else c.second = (b.first < a.first);
        /* cout << "resposta merge -> " << c.second << endl; */
        return c;
    }
    const ll neutral = INF;
    inline int lc(int p) { return p * 2; }
    inline int rc(int p) { return p * 2 + 1; }
    int n;
    vector<pii> t;

    bool resp() {
        return t[1].second;
    }

    void build(int p, int l, int r, const vector<ll> &v) {
        if (l == r) {
            t[p].first = v[l];
            t[p].second = v[l] < 0;
        } else {
            int mid = (l + r) / 2;
            build(lc(p), l, mid, v);
            build(rc(p), mid + 1, r, v);
            t[p] = merge(t[lc(p)], t[rc(p)]);
        }
    }
    void build(const vector<ll> &v) { // pra construir com vector
        n = (ll)v.size();
        t.assign(n * 4, {neutral, false});
        build(1, 0, n - 1, v);
    }
    pii query(int p, int l, int r, int L, int R) {
        if (l > R || r < L) return {neutral, false};
        if (l >= L && r <= R) return t[p];
        int mid = (l + r) / 2;
        auto ql = query(lc(p), l, mid, L, R);
        auto qr = query(rc(p), mid + 1, r, L, R);
        return merge(ql, qr);
    }
    pii query(int l, int r) { return query(1, 0, n - 1, l, r); }
    void update(int p, int l, int r, int i, ll x, bool repl = 0) {
        if (l == r) {
            t[p] = {x, x > 0}; // substitui
        } else {
            int mid = (l + r) / 2;
            if (i <= mid) update(lc(p), l, mid, i, x, repl);
            else update(rc(p), mid + 1, r, i, x, repl);
            t[p] = merge(t[lc(p)], t[rc(p)]);
        }
    }
    void update(int i, ll x, bool repl) { update(1, 0, n - 1, i, x, repl); }
    void sumUpdate(int i, ll x) { update(i, x, 0); }
    void setUpdate(int i, ll x) { update(i, x, 1); }
} seg;

int tc = 0;
void solve () {
    tc++;
    int n, m, q; cin >> n >> m >> q;
    vector<pair<int, int>> arr(n); // after i see one guy i can reorder him wherever i want
    vector<int> s(m);
    vector<ll> ft(n, 1e9);

    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        arr[i] = {num, i};
    }

    sort(arr.begin(), arr.end());

    int mn = INF;
    int mx = -1;
    for (int i = 0; i < m; i++) {
        int num; cin >> num;
        s[i] = arr[num - 1].second;
        ft[s[i]] = min(ft[s[i]], i);
        mn = min(mn, s[i]);
        mx = max(mx, s[i]);
    }

    for (int i = mn; i <= mx; i++) {
        if (ft[i] == INF) ft[i] = -1;
    }

    /* cout << "ft -> "; */
    /* for (auto c: ft) cout << c << " "; */
    /* cout << endl; */

    /* cout << "s -> "; */
    /* for (auto c: s) cout << c << " "; */
    /* cout << endl; */

    SegTree segtree;

    segtree.build(ft);
    cout << (segtree.resp() ? "TIDAK" : "YA") << endl;

    while (q--) {
        int si, p; cin >> si >> p;
    }
    return;
    


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
