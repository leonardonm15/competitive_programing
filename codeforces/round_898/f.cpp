#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, k; cin >> n >> k;
    vector<int> v(n);
    vector<int> h(n);
    vector<int> valid(n + 1);
    vector<vector<int>> arr;

    int resp = 0;
    for (int i=0; i < n; i++) {
        cin >> v[i];
        if (v[i] <= k) resp = 1;
    }
    for (int i=0; i < n; i++) cin >> h[i];
    h.push_back(1);

    for (int i=0; i < n; i++) {
        if (h[i] % h[i + 1] == 0) valid[i] = 1;
    }

    vector<int> f;
    f.push_back(0);
    int sum = 0;
    for (int i=0; i <= n; i++) {
        if (valid[i]) {
            sum += v[i];
            f.push_back(sum);
        } else {
            if (i > 0 && i < n && valid[i - 1]) f.push_back(sum + v[i]);
            arr.push_back(f);
            sum = 0;
            f.clear();
            f.push_back(0);
        }
    }

    for (auto vec: arr) {
        for (int i=0; i < vec.size(); i++) {
            int l = i;
            int r = vec.size() - 1;
            int t = 0;

            while (l <= r) {
                int mid = (l + r) >> 1;
                if (vec[mid] - vec[i] > k) {
                    r = mid - 1;
                } else {
                    t = mid - i;
                    l = mid + 1;
                }
            }

            resp = max(resp, t);
        }
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
