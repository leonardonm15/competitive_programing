#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, m, k; cin >> n >> m >> k;
    vector<int> arr(n);
    vector<int> mod(m);
    vector<int> func(k);
    vector<tuple<int, int, int>> difs;

    for (int i=0; i < n; i++) cin >> arr[i];
    for (int i=0; i < m; i++) cin >> mod[i];
    for (int i=0; i < k; i++) cin >> func[i];

    for (int i=1; i < n; i++) {
        difs.push_back({arr[i] - arr[i - 1], arr[i], arr[i - 1]});
    }

    sort(difs.rbegin(), difs.rend());

    auto [d, r, l] = difs[0];
    cout << "d -> " << d << endl;
    cout << "r -> " << r << endl;
    cout << "l -> " << l << endl;
    int ans = 1e9 + 5;
    for (int i=0; i < m; i++) {
        int tg = (d / 2) - mod[i];
        if (tg <= 0) tg = func[0];
        cout << "tg -> " << tg << endl;
        auto r1 = lower_bound(func.begin(), func.end(), tg);
        auto r2 = upper_bound(func.begin(), func.end(), tg);
        if (r1 != func.end()) {
            int resp1 = *r1;
            resp1 += mod[i];
            ans = min(ans, max({r - resp1, resp1 - l}));
        }
        if (r2 != func.end()) {
            int resp2 = *r2;
            resp2 += mod[i];
            ans = max(ans, min({r - resp2, resp2 - l}));
        }
    }

    auto [ans2, r2, l2] = difs[1];
    cout << max(ans, ans2) << endl;
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
