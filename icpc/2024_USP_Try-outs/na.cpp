#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
#define tii tuple<int, int, int, int>

bool interssect(int l, int r, int L, int R) {
    /* cout << "l r -> " << l << " " << r << endl; */
    /* cout << "L R -> " << L << " " << R << endl; */
    if (r < L || l > R) return false;
    else return true;
}

void solve () {
    int n; cin >> n;
    vector<tii> arr(n);
    vector<tii> tp(n);

    for (int i = 0; i < n; i++) {
        int t, d, o; cin >> t >> d >> o;
        arr.push_back({t, d, o, i + 1});
    }

    sort(arr.begin(), arr.end());

    vector<int> angry_birds;

    int L = 0;
    int R = 0;
    int c = 0;
    for (auto [t, d, o, i]: arr) {
        if (o) {
            if (interssect(t, t + d - 1, L, R)) angry_birds.push_back(get<3>(arr[c - 1]));
            L = t;
            R = t + d - 1;
        } else {
            L = R + 1;
            R = L + d - 1;
        }
        c++;
    }

    cout << angry_birds.size() << endl;
    for (auto c: angry_birds) cout << c << " ";
    cout << endl;
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
