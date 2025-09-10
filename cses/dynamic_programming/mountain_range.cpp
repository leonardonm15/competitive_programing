#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
#define pii pair<int, int>

const int N = 2e5 + 5;
const int INF = 1e9 + 5;

vector<int> pos[N];

struct SegTree {
    int merge(int a, int b) { return max(a, b); }
    const int neutral = 0;
    inline int lc(int p) { return p * 2; }
    inline int rc(int p) { return p * 2 + 1; }
    int n;
    vector<int> t;
    void build(int _n) { // pra construir com tamanho, mas vazia
        n = _n;
        t.assign(n * 2, neutral);
    }
    void build(const vector<int> &v) { // pra construir com vector
        n = (int)v.size();
        t.assign(n * 2, neutral);
        for (int i = 0; i < n; i++) t[i + n] = v[i];
        for (int i = n - 1; i > 0; i--) t[i] = merge(t[lc(i)], t[rc(i)]);
    }
    void build(int *bg, int *en) { // pra construir com array de C
        build(vector<int>(bg, en));
    }
    int query(int l, int r) {
        int ansl = neutral, ansr = neutral;
        for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) ansl = merge(ansl, t[l++]);
            if (r & 1) ansr = merge(t[--r], ansr);
        }
        return merge(ansl, ansr);
    }
    void update(int i, int x, bool replace) {
        i += n;
        t[i] = replace ? x : merge(t[i], x);
        for (i >>= 1; i > 0; i >>= 1) t[i] = merge(t[lc(i)], t[rc(i)]);
    }
    void sumUpdate(int i, int x) { update(i, x, 0); }
    void setUpdate(int i, int x) { update(i, x, 1); }
} seg;

int bb(vector<int>& a, int k) {
    int l = 0;
    int r = a.size() - 1;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (a[mid] > k) {
            r = mid - 1;
        } else if (a[mid] < k) {
            l = mid + 1;
        } else {
            ans = mid;
            break;
        }
    }

    return ans;
}

int lb(vector<int>& a, int k) {
    int l = 0;
    int r = a.size() - 1;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (a[mid] >= k) {
            r = mid - 1;
            ans = mid;
        } else if (a[mid] < k) {
            l = mid + 1;
        }
    }

    return ans;
}

map<pii, int> dp;
int calc(int l, int r, vector<int>& arr, SegTree& seg) {
    if (dp.count({l, r})) return dp[{l, r}];
    if (l > r) return 0;
    if (l == r) return 1;

    int mx = seg.query(l, r);

    int fa_al = lb(pos[mx], l); // first apearance after L

    int last_pos = l - 1;
                   
    for (int i = fa_al; i < pos[mx].size() && pos[mx][i] <= r; i++) {
        dp[{l, r}] = max(dp[{l, r}], calc(last_pos + 1, pos[mx][i] - 1, arr, seg) + 1);
        last_pos = pos[mx][i]; // 5
    }

    if (last_pos != r) dp[{l, r}] = max(dp[{l, r}], calc(last_pos + 1, r, arr, seg) + 1);

    return dp[{l, r}];
}


void solve () {
    int n; cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];
    vector<int> st = arr;

    sort(st.begin(), st.end());

    st.erase(unique(st.begin(), st.end()), st.end());

    vector<int> v; // compressed vector;

    for (int i = 0; i < n; i++) {
        int idx = bb(st, arr[i]);
        v.push_back(idx);
        pos[idx].push_back(i);
    }

    SegTree seg;
    seg.build(v);

    cout << calc(0ll, n - 1, v, seg) << endl;
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
