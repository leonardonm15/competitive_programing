#include <bits/stdc++.h>

using namespace std;

#define endl '\n';

const int N = 2e6 + 5;
vector<int> factor[N];
vector<bool> is_prime(N, true);
vector<pair<int, int>> multiplos_do_primo[N];
int lpf[N], primes[N], cnt = 0;
int vis[N];
pair<int, int> arr[N];

pair<int, int> bb(vector<pair<int, int>> arr, int tg) {
    int l = 0;
    int r = arr.size() - 1;
    int ans = -1;
    int idx = -1;

    while (l <= r) {
        int mid = (l + r) >> 1;
        if (arr[mid].first >= tg) {
            r = mid - 1;
        } else {
            ans = arr[mid].first;
            idx = arr[mid].second;
            l = mid + 1;
        }
    }

    return {ans, idx};
}

int index_do_arr_do_cara_mais_profundo = 0;
int folha_mais_profunda = 0;
int k_do_cara = 0;
int dfs(int ai, int i, int d, int k) {
    vis[i] = k;
    int resp = d;
    for (auto f: factor[ai]) {
        auto [val, idx] = bb(multiplos_do_primo[f], ai);
        if (val != -1) resp = max(resp, dfs(val, idx, d + 1, k));
    }

    if (resp > opa) {
        fdv = i;
        opa = resp;
        k_do_cara = k;
    }
    return resp;
}

bool dfs2(int ai, int i, int d, int tg) {
    if (d == tg) {
        cout << arr[i].second + 1 << " ";
        return true;
    }

    for (auto f: factor[ai]) {
        auto [val, idx] = bb(multiplos_do_primo[f], ai);
        if (val != -1 && dfs2(val, idx, d + 1, tg)) {
            cout << arr[i].second + 1 << " ";
            return true;
        }
    }

    return false;
}

void build() {
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i < N; i++) {
        if (is_prime[i]) {
            lpf[i] = i;
            primes[cnt++] = i;
        }
        for (int j = 0; j < cnt && i * primes[j] < N; j++) {
            is_prime[i * primes[j]] = 0;
            lpf[i * primes[j]] = primes[j];
            if (i % primes[j] == 0) break;
        }
    }
}

void factorize(int n, int i) {
    int v = n;
    while (n > 1) {
        if (!factor[v].size() || factor[v][factor[v].size() - 1] != lpf[n]) 
            factor[v].push_back(lpf[n]);
        if (!multiplos_do_primo[lpf[n]].size() || multiplos_do_primo[lpf[n]][multiplos_do_primo[lpf[n]].size() - 1].first != v) 
            multiplos_do_primo[lpf[n]].push_back({v, i});
        n /= lpf[n];
    }
}

void solve() {
    int n; cin >> n;

    for (int i = 0; i < n; i++) arr[i].second = i;

    for (int i = 0; i < n; i++) cin >> arr[i].first;

    sort(arr, arr + n);

    int g = 0;
    for (auto c: arr) {
        factorize(c.first, g++);
    }
    
    int counter = 1;
    int resposta = 0;
    int idx_mr = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (!vis[i]) {
             int vg = dfs(arr[i].first, i, 1, counter++);
             if (vg > resposta) {
                idx_mr = i;
                resposta = vg;
             }
        }

        /* cout << i << " -> "; */
        /* for (auto [f, g]: multiplos_do_primo[i]) { */
        /*     cout << "(" << f  << "," << g << ")" << " "; */
        /* } */
        /* cout << endl; */
    }

    cout << "vis -> ";
    for (int i = 0; i < n; i++) {
        cout << vis[i] << " ";
    }
    cout << endl;

    cout << arr[index_do_arr_do_cara_mais_profundo].second + 1 << " ";
    for (int i = index_do_arr_do_cara_mais_profundo; i < n; i++) {
        if (vis[i] == k && gcd(pc, arr[i].first) > 1) {
            cout << arr[i].second  + 1 << " ";
            lc = arr[i].first;
        }
    }

    cout << resposta << endl;
    dfs2(arr[idx_mr].first, idx_mr, 1, resposta);
    cout << endl;
}


signed main() {
    cin.tie(0)->sync_with_stdio(0);
    build();
    solve();
}
