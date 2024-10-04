#include <bits/stdc++.h>
#define endl '\n'

using namespace std;
using ll = long long;

struct segment {
    int l, r;
};

bool cmp(segment a, segment b) {
    if (a.l < b.l) return true;
    if (b.l < a.l) return false;
    if (a.r > b.r) return true;
    return false;
}

vector<segment> compress(vector<segment> a) { 
    sort(begin(a), end(a), cmp);

    vector<segment> ret;

    int n = (int)a.size();

    if (n == 0) return ret;
    
    for (int i = 0; i < n; i++) {
        auto [l, r] = a[i];

        segment now;
        now.l = l;
        now.r = r;

        if (!ret.size()) {
            ret.push_back(now);
        }

        auto &[cur_l, cur_r] = ret.back();

        if (l > cur_r) {
            ret.push_back(a[i]);
        } else {
            cur_r = max(cur_r, r);
        }
    }

    return ret;
}

struct DSU {
    vector<int> dad;
    vector<int> sz;

    void initialize(int n) {
        dad.resize(n + 5);
        for (int i = 0; i < (int) dad.size(); i++) dad[i] = i;
        sz.assign((int) dad.size(), 1);
    }

    int fp(int a) {
        if (dad[a] != a) return dad[a] = fp(dad[a]);
        else return a;
    }

    void join(int u, int v) {
        int pu = fp(u);
        int pv = fp(v);

        if (pu == pv) return;

        if (sz[pv] > sz[pu]) swap(pv, pu); // pv é menor
        
        sz[pu] += sz[pv];
        dad[pv] = pu;
    }
};

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<vector<int>>> arr;

    arr.emplace_back();

    for (int i = 1; i <= 10; i++) {
        vector<vector<int>> a(i);

        for (int k = 1; k <= n; k++) { a[k % i].push_back(k); }

        arr.push_back(a);
    }

    // for (int i = 1; i <= 10; i++) {
    //     cout << i << ": " << endl;
    //     for (auto k: arr[i]) {
    //         cout << "{ ";
    //         for (auto num: k) {
    //             cout << num << " ";
    //         }
    //         cout << "} ";
    //     }
    //     cout << endl;
    // }

    DSU dsu;
    dsu.initialize(n);

    vector s(11, vector<vector<segment>>(11)); // [ [[], [], []], [[], [], []] ]

    for (int i = 0; i < m; i++) {
        int a, d, k; cin >> a >> d >> k;
        segment p;
        p.l = a;
        p.r = a + d * k;
        s[d][a % d].push_back(p);
    }

    for (int i = 1; i <= 10; i++) { // pra cada pulo
        
        for (int j = 0; j < i; j++) { // pra cada mod
            if (s[i][j].empty()) continue;
            s[i][j] = compress(s[i][j]);
            for (auto [l, r]: s[i][j]) { // pra cada range
                for (int k = l; k <= r; k += i) {
                    dsu.join(r, k);
                }
            }
        }
    }
    
    set<int> st;
    for (int i = 1; i <= n; i++) st.emplace(dsu.fp(i));

    cout << st.size() << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}

