#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int N = 1e5 + 5;
const int NEUTRAL = 2 * N + 10;

int counter;
int path_value_now;
vector<int> adj[N];
vector<int> ids_per_value[3 * N + 100];
int sz[N];
int id[N];
int color[N];
int color_id[N];
int path_value[N];

int sz_dfs(int u, int p) {
    for (auto v: adj[u]) { 
        if (v != p) sz[id[u]] += sz_dfs(v, u);
    }

    sz[id[u]]++;
    /* cout << "-------------------" << endl; */
    /* cout << "u -> " << u << endl; */
    /* cout << "idU -> " << id[u] << endl; */
    /* cout << "sz[id[u]] -> " << sz[id[u]] << endl; */

    return sz[id[u]];
}

void path_value_dfs(int u, int p) {
    int idu = id[u];
    int delta = (!color_id[idu] ? -1 : +1);
    path_value_now += delta;
    path_value[idu] = path_value_now;

    ids_per_value[path_value_now + NEUTRAL].push_back(idu);

    for (auto v: adj[u]) if (v != p) path_value_dfs(v, u);

    path_value_now -= delta;
}

void id_dfs(int u, int p) {
    id[u] = counter++;
    for (auto v: adj[u]) if (v != p) id_dfs(v, u);
}

int bb(vector<int>& arr, int k) {
    int l = 0;
    int r = arr.size() - 1;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (arr[mid] >= k) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }

    return ans;
}

int bb2(vector<int>& arr, int k) {
    int l = 0;
    int r = arr.size() - 1;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (arr[mid] <= k) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }

    return ans;
}

int calc(int complement, int l, int r) {
    /* cout << "---------------------" << endl; */
    /* cout << "complement -> " << complement << endl; */
    /* cout << l << " - " << r << endl; */
    complement += NEUTRAL;

    vector<int>& vec = ids_per_value[complement];

    /* cout << "vec -> "; */
    /* for (auto v: vec) cout << v << " "; */
    /* cout << endl; */

    int left = bb(vec, l);
    int right = bb2(vec, r);
    /* cout << "left -> " << left << endl; */
    /* cout << "right -> " << right << endl; */
    if (left == -1 || vec[left] > r) return 0;
    if (right == -1 || vec[right] < l) return 0;

    return right - left + 1;
}

void solve () {
    int n, q; cin >> n >> q;
    counter = 1;
    
    for (int i = 1; i <= n; i++) cin >> color[i];

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    id_dfs(1, 1);
    for (int i = 1; i <= n; i++) {
        color_id[id[i]] = color[i];
    }
    sz_dfs(1, 1);


    path_value_now = 0;
    path_value_dfs(1, 1);

    /* cout << "id -> "; */
    /* for (int i = 1; i <= n; i++) { */
    /*     cout << i << " - " << id[i] << endl; */
    /* } */
    /* cout << endl; */

    /* cout << "sz -> "; */
    /* for (int i = 1; i <= n; i++) { */
    /*     cout << sz[id[i]] << " "; */
    /* } */
    /* cout << endl; */

    /* cout << "color -> "; */
    /* for (int i = 1; i <= n; i++) { */
    /*     cout << color_id[i] << " "; */
    /* } */
    /* cout << endl; */

    /* cout << "path_value -> "; */
    /* for (int i = 1; i <= n; i++) { */
    /*     cout << path_value[id[i]] << " "; */
    /* } */
    /* cout << endl; */

    while (q--) {
        int u; cin >> u;
        int idu = id[u];
        int subtree_size = sz[idu] - 1;
        int delta = (!color_id[idu] ? -1 : +1);
        int complement = path_value[idu] - delta;
        /* cout << "subtree size -> " << subtree_size << endl; */
        int resp = calc(complement, idu + 1, idu + subtree_size);
        cout << resp << endl;
    }

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
