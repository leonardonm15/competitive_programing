#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    vector<int> gcds;
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i= 1; i < n; i++) gcds.push_back(gcd(arr[i], arr[i - 1]));

    /* cout << "gcds -> "; */
    /* for (auto c: gcds) cout << c << " "; */
    /* cout << endl; */

    vector<int> points;
    for (int i = 1; i < (int)gcds.size(); i++) {
        if (gcds[i] < gcds[i - 1]) {
            points.push_back(i);
        }
    }

    /* cout << "Points.size() -> " << points.size() << endl; */
    if (!points.size()) {
        cout << "YES" << endl;
        return;
    } else if (points.size() == 1 || points.size() == 2) {
        for (auto pt: points) {
            vector<int> a1, a2, a3, g1, g2, g3;
            bool f1 = true, f2 = true, f3 = true;
            for (int i=0; i < n; i++) {
                if (i == pt - 1) {
                    a2.push_back(arr[i]);
                    a3.push_back(arr[i]);
                }
                else if (i == pt) {
                    a1.push_back(arr[i]);
                    a3.push_back(arr[i]);
                }
                else if (i == pt + 1) {
                    a1.push_back(arr[i]);
                    a2.push_back(arr[i]);
                } else {
                    a1.push_back(arr[i]);
                    a2.push_back(arr[i]);
                    a3.push_back(arr[i]);
                }
            }

            for (int i=1; i < (int)a1.size(); i++) {
                g1.push_back(gcd(a1[i], a1[i - 1]));
                g2.push_back(gcd(a2[i], a2[i - 1]));
                g3.push_back(gcd(a3[i], a3[i - 1]));
            }

            /* cout << "a1 -> "; */
            /* for (auto c: a1) cout << c << " "; */
            /* cout << endl; */

            /* cout << "g1 -> "; */
            /* for (auto c: g1) cout << c << " "; */
            /* cout << endl; */

            /* cout << "a2 -> "; */
            /* for (auto c: a2) cout << c << " "; */
            /* cout << endl; */

            /* cout << "g2 -> "; */
            /* for (auto c: g2) cout << c << " "; */
            /* cout << endl; */

            /* cout << "a3 -> "; */
            /* for (auto c: a3) cout << c << " "; */
            /* cout << endl; */

            /* cout << "g3 -> "; */
            /* for (auto c: g3) cout << c << " "; */
            /* cout << endl; */

            for (int i = 1; i < (int) g1.size(); i++) {
                if (g1[i] < g1[i - 1]) f1 = false;
                if (g2[i] < g2[i - 1]) f2 = false;
                if (g3[i] < g3[i - 1]) f3 = false;
            }

            if ((f1 | f2 | f3) == false) cout << "NO" << endl;
            else cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
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
