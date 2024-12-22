#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int N = 3e5 + 5;

vector<int> freq(N);

void solve () {
    int n, m, k; cin >> n >> m >> k;

    vector<int> p(m);

    for (int i = 0; i < m; i++) {
        cin >> p[i];
    }

    vector<int> sei(k);

    for (int i = 0; i < k; i++) {
        cin >> sei[i];
        freq[sei[i]]++;
    }

    string resp;

    sort(p.begin(), p.end());

    for (auto prova: p) {
        if (k < n - 1) {
            resp.push_back('0');
            continue;
        }

        if (k >= n) {
            resp.push_back('1');
            continue;
        }

        if (freq[prova]) resp.push_back('0');
        else resp.push_back('1');
    }

    cout << resp << endl;

    for (int i = 0; i <= n; i++) freq[i] = 0;
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
