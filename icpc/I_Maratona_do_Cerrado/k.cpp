#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
 
int uniform(int l, int r) { return uniform_int_distribution<int>(l, r)(rng); }

const int N = 1e5 + 5;

vector<pair<int, int>> arr(N);
vector<int> narr[N];

bool bb(int k, vector<int>& arr) {
    for (auto v: arr) if (v == k) return true;

    return false;
}

vector<int> resp;
vector<int> stck;
int cant[30][30];
const int MX_MSK = (1 << 21);
int have_seen[22][MX_MSK];
void calc(int u, int msk, int N) {
    stck.push_back(u);
    have_seen[u][msk]++;
    if (stck.size() - 1 == N && resp.size() == 0) {
        resp = stck;
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (i == u) continue;
        int have_gone = (1 << i) & msk;
        if (!have_gone && !cant[u][i] && !have_seen[i][msk | (1 << i)]) {
            calc(i, msk | (1 << i), N);
        }
    }

    stck.pop_back();
}

void solve2(int n, int m) {

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        cant[u][v]++;
        cant[v][u]++;
    }

    calc(0, 0, n);

    if (resp.size() != n + 1) {
        cout << -1 << endl;
    } else {
        for (int i = 1; i <= n; i++) {
            cout << resp[i] << " ";
        }
        cout << endl;
    }

    return;
}

vector<int> brute(int TRIES, int n) {
    vector<int> vis(n + 1);
    int u = uniform(1, n);
    vis[u]++;
    vector<int> path;
    path.push_back(u);
    while(TRIES--) {
        int v = uniform(1, n);
        if (v == u) continue;
        bool flag = bb(v, narr[u]);
        if (!flag && !vis[v]) {
            vis[v]++;
            path.push_back(v);
            u = v;
        }

        if ((int) path.size() == n) break;
    }

    if (path.size() == n) return path;
    else return {0};
}

void solve() {
    int n, m; cin >> n >> m;

    if (n < 20) {
        solve2(n, m);
        return;
    }

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;

        arr[u].first--;
        arr[v].first--;
        narr[v].push_back(u);
        narr[u].push_back(v);
    }

    for (int i = 0; i < N; i++) {
        arr[i].second = i;
    }

    sort(arr.begin(), arr.end());

    int start_node = -1;

    for (int i = 0; i <= n; i++) {
        if (arr[i].second == 0) continue;

        if (-arr[i].first >= n) continue;

        start_node = arr[i].second;
        break;
    }

    for (int i = 0; i < 10; i++) {
        vector<int> b = brute(3e6, n);
        if (b.size() == n) {
            for (auto v: b) cout << v << " ";
            cout << endl;
            return;
        }
    }


    cout << -1 << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
}
