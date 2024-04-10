#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

struct seg {
    vector<int> arr;
    int n;
    vector<int> seg;

    int query(int u, int l, int r, int k, int up) {
        up ^= seg[u];
        if (l == r) return up;
        int mid = (l + r) >> 1;
        if (k <= mid) return query(2 * u, l, mid, k, up);
        else return query(2 * u + 1, mid + 1, r, k, up);
    }

    int query(int k) {
        return query(1, 0, n - 1, k, 0);
    }

    void update(int u, int l, int r, int L, int R) {
        if (r < L || l > R) return;
        if (l >= L && r <= R) {
            seg[u] ^= 1;
            return;
        }
        int mid = (l + r) >> 1;
        update(2 * u, l, mid, L, R);
        update(2 * u + 1, mid + 1, r, L, R);
    }

    void update(int l, int r) {
        update(1, 0, n - 1, l, r);
    }

    void build(int u, int l, int r, vector<int>& arr) {
        if (l == r) {
            seg[u] = arr[l];
            return;
        }

        int mid = (l + r) >> 1;
        build(2 * u, l, mid, arr);
        build(2 * u + 1, mid + 1, r, arr);
    }

    void build(vector<int>& vec) {
        n = vec.size();
        seg.assign(4 * n, 0);
        build(1, 0, n - 1, vec);
    }
};

void solve () {
    int n; cin >> n;
    string s; cin >> s;
    vector<int> v;
    for (auto c: s) {
        v.push_back(c == '1' ? 1 : 0);
    }

    int resp = 1;
    for (int i=2; i <= n; i++) {
        seg t;
        t.build(v);
        bool flag = false;
        for (int j=0; j < n; j++) {
            int node = t.query(j);
            if (node == 0) {
                if (j + i > n) {
                    flag = true;
                    break;
                }
                else t.update(j, j + (i - 1));
            }
        }

        /* cout << "i -> " << i << endl; */
        /* cout << "queries -> "; */
        /* for (int i=0; i < n; i++) { */
        /*     int node = t.query(i); */
        /*     cout << node << " "; */
        /* } */
        /* cout << endl; */

        if (flag) continue;
        else resp = i;
    }
    cout << resp << endl;
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
