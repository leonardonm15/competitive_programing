#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

struct merge_tree {
    int n;
    vector<vector<int>> mg;

    int query(int u, int l, int r, int L, int R, int k) {
        if (l >= L && r <= R) {
            int qnt = mg[u].end() - upper_bound(mg[u].begin(), mg[u].end(), k);
            return qnt;
        } else if (r < L || l > R) return 0;
        else {
            int mid = (l + r) >> 1;
            return query(2 * u, l, mid, L, R, k) + query(2 * u + 1, mid + 1, r, L, R, k);
        }
    }

    int query(int l, int r, int k) {
        return query(1, 0, n - 1, l, r, k);
    }

    vector<int> merge(vector<int> &a, vector<int> &b) {
        vector<int> c;
        int pa = 0;
        int pb = 0;
        while (pa < a.size() || pb < b.size()) {
            if (pa < a.size() && pb < b.size()) {
                if (a[pa] <= b[pb]) c.push_back(a[pa++]);
                else c.push_back(b[pb++]);
            } 
            else if (pa < a.size() && pb >= b.size()) c.push_back(a[pa++]);
            else if (pa >= a.size() && pb < b.size()) c.push_back(b[pb++]);
        }

        return c;
    }

    void build(int u, int l, int r, vector<int>& arr) {
        if (l == r) {
            mg[u].push_back(arr[l]);
            return;
        }

        int mid = (l + r) >> 1;
        build(2 * u, l, mid, arr);
        build(2 * u + 1, mid + 1, r, arr);
        mg[u] = merge(mg[2 * u], mg[2 * u + 1]);
    }

    void build(vector<int>& arr) {
        n = arr.size();
        mg.resize(4 * n);
        build(1, 0, n - 1, arr);
    }
};

void solve () {
    int x, y; cin >> x >> y;
    int s, a; cin >> s >> a;
    vector<int> ss(s), aa(a);
    vector<pair<int, int>> sss(s), aaa(a);

    for (int i=0; i < s; i++) {
        int u, v; cin >> u >> v;
        sss[i] = {u, v};
    }

    sort(sss.begin(), sss.end());
    for (int i=0; i < s; i++) ss[i] = sss[i].second;

    for (int i=0; i < a; i++) {
        int u, v; cin >> u >> v;
        aaa[i] = {u, v};
    }

    sort(aaa.begin(), aaa.end());
    for (int i=0; i < a; i++) aa[i] = aaa[i].second;

    int add = 0;
    merge_tree hor;
    hor.build(ss);

    merge_tree vert;
    vert.build(aa);

    for (int i=1; i < s; i++) add += hor.query(0, i, ss[i]);
    for (int i=1; i < a; i++) add += vert.query(0, i, aa[i]);

    s++; a++;
    cout << (s * a) + add << endl;
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
