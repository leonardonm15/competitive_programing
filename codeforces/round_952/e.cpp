#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int h, n; cin >> h >> n;
    map<int, int> damage;
    vector<int> a(n);
    vector<int> c(n);
    map<int, int> life;
    int mxci = 0; // max c de i

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        damage[c[i]] += a[i];
        mxci = max(mxci, c[i]);
    }

    int dm = 0;
    for (auto [time, dam]: damage) {
        cout << time << " " << dam << endl;
        cout << "dm -> " << dm << endl;
        dm += (mxci / time) * dam;
    }

    cout << "dm -> " << dm << endl;

    int initial_time = 1;
    if (h >= dm) {
        initial_time = (h / dm) * mxci;
        h -= (h / dm) * dm;
    }

    for (auto [time, dam]: damage) {
        int sum = 0;
        int i = (initial_time / time) + time;
        while (sum < h) {
            life[i] += dam;
            sum += dam;
            i += time;
        }
    }

    int sum = 0;
    int resp = 0;
    for (auto [mom, dam]: life) {
        sum += dam;
        if (sum >= h) {
            resp = mom;
            break;
        }
    }

    cout << resp + 1 << endl;
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
