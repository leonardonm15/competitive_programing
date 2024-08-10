#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

struct SegTree {
    int merge(int a, int b) { return a + b; }

    inline int lc (int p) { return p * 2; }
    inline int rc (int p) { return p * 2 + 1; }

    const int neutral = 0;
    int n;
    vector<int> t;

    void build(int p, int l, int r, const vector<int>& v) {
        if (l == r)  {
            t[p] = v[l];
        } else {
            int mid = (l + r) / 2;
            build(lc(p), l, mid, v);
            build(rc(p), mid + 1, r, v);
        }
    }

    void build(const vector<int> &v) {
        n = (int) v.size();
        t.assign(n * 4, neutral);
        build(1, 0, n - 1, v);
    }

    void update (int p, int l, int r, int L, int R, int val) {
        if (l > R || r < L) return;
        if (l >= L && r <= R) {
            t[p] += val;
            return;
        }
        int mid = (l + r) >> 1;
        update(lc(p), l, mid, L, R, val);
        update(rc(p), mid + 1, r, L, R, val);
    }
    void update(int l, int r, int val) { update(1, 0, n - 1, l, r, val); }

    int query(int p, int l, int r, int i, int x) {
        if (l == r) return t[p] + x;
        else {
            int mid = (l + r) >> 1;
            if (i <= mid) return query(lc(p), l, mid, i, x + t[p]);
            else return query(rc(p), mid + 1, r, i, x + t[p]);
        }
    }
    int query(int i) { return query(1ll, 0ll, n - 1, i, 0); }
};

void solve() {
    int q, n, t; cin >> q >> n >> t;

    vector<pair<int, int>> probs;
    for (int i = 0; i < q; i++) {
        int d, t; cin >> d >> t;
        probs.push_back({t, d});
    }

    vector<int> a(2e5 + 5);
    SegTree dificuldade;
    dificuldade.build(a);

    SegTree tempo;
    tempo.build(a);

    sort(probs.begin(), probs.end());

    for (auto [T, d]: probs) {
        int l = d;
        int r = 2e5;
        int ans = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            int res = tempo.query(mid);
            if ((t - res) >= T) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }

        }

        if (ans >= d) {
            dificuldade.update(d, ans, 1);
            tempo.update(d, ans, T);
        }

    }


    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        cout << dificuldade.query(num) << endl;
    }
}

signed main() {
    solve();
    return 0;
}
