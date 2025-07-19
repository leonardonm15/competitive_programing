#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int N = 1e5 + 5;

struct merge_sort_tree {
    /* vector<int> mst[4 * N]; */
    vector<vector<int>> mst;

    void merge(int p, int pl, int pr) {
        vector<int> &v3 = mst[p];
        vector<int> &v1 = mst[pl];
        vector<int> &v2 = mst[pr];
        
        int l1 = 0;
        int l2 = 0;
        while (v3.size() != (v1.size() + v2.size())) {

            while (l1 < (int) v1.size() && l2 < (int) v2.size() && v1[l1] <= v2[l2]) v3.push_back(v1[l1++]);

            while (l1 < (int) v1.size() && l2 < (int) v2.size() && v2[l2] < v1[l1]) v3.push_back(v2[l2++]);

            while (l1 == (int) v1.size() && l2 < (int) v2.size()) v3.push_back(v2[l2++]);

            while (l2 == (int) v2.size() && l1 < (int) v1.size()) v3.push_back(v1[l1++]);
        }

        cout << "v3 -> ";
        for (auto v: v3) cout << v << " ";
        cout << endl;
    }

    void build(int n, vector<int>& v) {
        mst.assign(n * 4, vector<int>());
        build(1, 0, v.size() - 1, v);
    }

    void build(int p, int l, int r, vector<int>& v) {
        if (l == r) {
            mst[p].push_back(v[l]);
        } else {
            int mid = (l + r) >> 1;
            build(2 * p, l, mid, v);
            build(2 * p + 1, mid + 1, r, v);
            merge(p, 2 * p, 2 * p + 1);
        }
    }
};

void solve () {
    int n; cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    /* vector<int> a = {2, 4}; */
    /* vector<int> b = {1, 3, 5, 7}; */

    /* vector<int> c = merge(a, b); */
    
    merge_sort_tree a;

    a.build(4 * N, arr);
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
