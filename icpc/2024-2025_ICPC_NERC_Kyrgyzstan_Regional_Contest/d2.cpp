#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int N = 2e6 + 5;

vector<bool> is_prime(N, true);
vector<int> factor[N];
int lpf[N], primes[N], cnt = 0;

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

void factorize(int n) {
    int v = n;
    while (n > 1) {
        if (!factor[v].size() || factor[v][factor[v].size() - 1] != lpf[n]) 
            factor[v].push_back(lpf[n]);
        n /= lpf[n];
    }
}

bool check(pair<int, int> a, pair<int, int> b) {
    return (a.first == b.first ? a.second > b.second : a.first < b.first);
}

void solve () {
    int n; cin >> n;
    vector<pair<int, int>> arr(n);

    for (int i = 0; i < n; i++) arr[i].second = i + 1;
    for (int i = 0; i < n; i++) cin >> arr[i].first;

    sort(arr.begin(), arr.end(), check);

    for (auto [val, idx]: arr) factorize(val);

    vector<int> freq(N);
    vector<vector<pair<int, int>>> possibles(N);
    int now = 1;
    for (int i = n - 1; i >= 0; i--) {
        int greatest = 0;
        for (auto f: factor[arr[i].first]) {
            int b = possibles[freq[f]].size();
            if (possibles[freq[f]].size() > possibles[greatest].size() && possibles[freq[f]][b - 1].first > arr[i].first) {
                greatest = freq[f];
            }
        }

        if (greatest != 0) {
            int b = possibles[greatest].size();
            for (auto f: factor[possibles[greatest][b - 1].first]) {
                freq[f] = 0;
            }

            for (auto f: factor[arr[i].first]) {
                freq[f] = greatest;
            }

            possibles[greatest].push_back(arr[i]);
        } else {
            possibles[now].push_back(arr[i]);
            for (auto f: factor[arr[i].first]) freq[f] = now;
            now++;
        }
    }

    sort(possibles.rbegin(), possibles.rbegin());

    int idx_m = 0;
    int vm = 0;
    for (int i = 0; i <= now; i++) {
        vector<pair<int, int>>& v = possibles[i];
        if (v.empty()) continue;
        if (v.size() > vm) {
            vm = v.size();
            idx_m = i;
        }
    }

    cout << vm << endl;
    reverse(possibles[idx_m].begin(), possibles[idx_m].end());
    for (auto [c, v]: possibles[idx_m]) {
        cout << v << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    build();
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
