#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

int check(int p, vector<int>& v) {
    int s = 0;
    for (auto c: v) {
        s += abs(c - p);
    }
    return s;
}

void solve() {
    int n; cin >> n;
    map<int, vector<int>> map;

    for (int i = 0; i < n; i++) {
        int c, num; cin >> c >> num;

        map[c].push_back(num);
    }

    int resp = 0;
    for (auto &[c, vec]: map) {
        sort(vec.begin(), vec.end());

        /* int k = 200; */
        /* int l = vec[0]; */
        /* int r = vec[vec.size() - 1]; */

        /* while (k--) { */
        /*     int step = (l + r) / 5; */
        /*     int m1 = l + step; */
        /*     int m2 = r - step; */

        /*     if (check(m1, vec) <= check(m2, vec)) r = m2; */
        /*     else l = m1; */
        /* } */

        int parada = vec[(vec.size() - 1) / 2];
        for (auto a: vec) {
            resp += abs(a - parada);
        }
    }

    cout << resp << endl;
}

signed main() {
    solve();
    return 0;
}
