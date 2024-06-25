#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const double EPS = 1e-9;
const int G = 5e5;

void solve () {
    int n; cin >> n;
    vector<pair<double, int>> arr(n);

    for (int i = 0; i < n; i++) {
        double num; cin >> num;
        arr[i] = {num, i};
    }

    vector<int> resp(n);
    sort(arr.rbegin(), arr.rend());

    resp[arr[0].second] = G;
    int cumm1 = G * arr[0].first;
    int cumm2 = n * G;

    int t1 = 1;
    int t2 = 1;
    for (int i = 1; i < n; i++) {
        t1 *= arr[0].first * G + 2;
        t2 *= arr[i].first;
    }

    cout << "t1 / t2 -> " << t1 / t2 << endl;

    for (int i = 1; i < n; i++) {
        long double k = ((long double)(arr[0].first / arr[i].first) * G) + 2;
        resp[arr[i].second] = k;
        cumm1 += (k * arr[i].first);
        cumm2 += n * k;
    }

    cout << "cumm1 -> " << cumm1 << endl;
    cout << "cumm2 -> " << cumm2 << endl;
    return;

    if (cumm1 > cumm2) {
        for (auto c: resp) cout << c << " ";
        cout << endl;
    } else cout << -1 << endl;
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
