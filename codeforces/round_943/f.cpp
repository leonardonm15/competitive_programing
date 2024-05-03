#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

struct merge_sort_tree { // separate_shuffle_tornado
    vector<vector<pair<int, int>>> mseg;
    int n;

    vector<pair<int, int>> merge(vector<pair<int, int>> a, vector<pair<int, int>> b) {
        int x = 0;
        int y = 0;
        vector<pair<int, int>> c;

        while (x < a.size() || y < b.size()) {
            if (x < a.size() && y < b.size()) {
                if (a[x].first < b[y].first) c.push_back(a[x++]);
                if (a[x].first == b[y].first) {
                    if (a[x].second < b[y].second) c.push_back((((((a[x++]))))));
                    else c.push_back(b[y++]);
                }
                else c.push_back(b[y++].first);
            }

            if (x < a.size() && y >= b.size()) {
                c.push_back(a[x++]);
            }

            if (y < b.size() && x >= a.size()) {
                c.push_Back(b[y++]);
            }
        }

        return c;
    }

    void query(int u, int l, int r, int L, int R, int k) {
        
    }
    void query(int l, int r, int k) {
        query(1

    }

    void build(int u, int l, int r, vector<int>& arr) {
        if (l == r) {
            mseg[u].push_back(arr[l]);
            return;
        }

        int mid = (l + r) >> 1;
        build(2 * u, l, mid, arr);
        build(2 * u + 1, mid + 1, r, arr);
        mseg[u] = merge(mseg[2 * u], mseg[2 * u + 1]);
    }

    void build(vector<int>& arr) {
        n = arr.size();
        mseg.resize(4 * n);
        build(1, 0, n - 1, arr);
    }
}



void solve () {
    int n, q; cin >> n >> q;

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
