#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
typedef long long ll;

const int N = 2e4;

int gfat[N];
int sfat[N];

void calc() {
    gfat[0] = 0;
    sfat[0] = 0;

    gfat[1] = 1;
    for (int i = 2; i < N; i++) {
        int mx = 1;
        int num = i;
        int s = 0;
        for (int j = 2; j * j <= num; j++) {
            while (num % j == 0) {
                mx = j;
                s += j;
                num /= j;
            }
        }

        if (num > 1) s += num;
        sfat[i] = s;
        gfat[i] = max(mx, num);
    }
}

struct SegTree {
    ll merge(ll a, ll b) { return a + b; }
    const ll neutral = 0;

    int n;
    vector<ll> t, lazy;
    vector<bool> replace;

    inline int lc(int p) { return p * 2; }
    inline int rc(int p) { return p * 2 + 1; }

    void push(int p, int l, int r) {
        if (replace[p]) {
            t[p] = lazy[p] * (r - l + 1);
            if (l != r) {
                lazy[lc(p)] = lazy[p];
                lazy[rc(p)] = lazy[p];
                replace[lc(p)] = replace[p];
                replace[rc(p)] = replace[p];
            }
        } else if (lazy[p] != 0) {
            t[p] += lazy[p] * (r - l + 1);
            if (l != r) {
                lazy[lc(p)] += lazy[p];
                lazy[rc(p)] += lazy[p];
            }
        }

        replace[p] = false;
        lazy[p] = 0;
    }

    void build(int p, int l, int r, const vector<ll> &v) {
        if (l == r) {
            t[p] = v[l];
        } else {
            int mid = (l + r) / 2;
            build(lc(p), l, mid, v);
            build(rc(p), mid + 1, r, v);
            t[p] = merge(t[lc(p)], t[rc(p)]);
        }
    }

    void build(int _n) { // pra construir com tamanho, mas vazia
        n = _n;
        t.assign(n * 4, neutral);
        lazy.assign(n * 4, 0);
        replace.assign(n * 4, false);
    }

    void build(const vector<ll> &v) { // pra construir com vector
        n = (int)v.size();
        t.assign(n * 4, neutral);
        lazy.assign(n * 4, 0);
        replace.assign(n * 4, false);
        build(1, 0, n - 1, v);
    }
    void build(ll *bg, ll *en) { // pra construir com array de C
        build(vector<ll>(bg, en));
    }

    ll query(int p, int l, int r, int L, int R) {
        push(p, l, r);
        if (l > R || r < L) return neutral;
        if (l >= L && r <= R) return t[p];
        int mid = (l + r) / 2;
        auto ql = query(lc(p), l, mid, L, R);
        auto qr = query(rc(p), mid + 1, r, L, R);
        return merge(ql, qr);
    }
    ll query(int l, int r) { return query(1, 0, n - 1, l, r); }

    void update(int p, int l, int r, int L, int R, ll val, bool repl) {
        push(p, l, r);
        if (l > R || r < L) return;
        if (l >= L && r <= R) {
            lazy[p] = val;
            replace[p] = repl;
            push(p, l, r);
        } else {
            int mid = (l + r) / 2;
            update(lc(p), l, mid, L, R, val, repl);
            update(rc(p), mid + 1, r, L, R, val, repl);
            t[p] = merge(t[lc(p)], t[rc(p)]);
        }
    }
    void update(int l, int r, ll val, bool repl = false) {
        update(1, 0, n - 1, l, r, val, repl);
    }
};

void solve () {
    int n; cin >> n;

    vector<int> arr(n);
    vector<int> somas;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        somas.push_back(sfat[arr[i]]);
    }

    SegTree seg_soma, seg_numero_atual;

    seg_soma.build(somas);
    seg_numero_atual.build(arr);
    
    int q; cin >> q;
    while (q--) {
        int t; cin >> t;

        if (t == 1) { // tirar primo da fatoração
            int i; cin >> i;
            i--;
            int num = seg_numero_atual.query(i, i);
            if (num == 1) continue;
            seg_soma.update(i, i, sfat[num] - gfat[num], true);
            seg_numero_atual.update(i, i, num / gfat[num], true);
        }
        if (t == 2) { // min soma
            int l, r; cin >> l >> r;
            l--; r--;
            cout << seg_soma.query(l, r) << endl;
        }
        if (t == 3) { // assign
            int l, r, x; cin >> l >> r >> x;
            l--, r--;
            seg_soma.update(l, r, sfat[x], true);
            seg_numero_atual.update(l, r, x, true);
        }
    }

}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    calc();
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
