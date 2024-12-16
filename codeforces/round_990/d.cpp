#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    vector<pair<int, int>> p(n);
    
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        p[i].first = arr[i];
    }

    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    
    for (int i = 0; i < (int) p.size(); i++) {
        p[i].second = i;
    }

    vector<int> narr(n);

    for (int i = 0; i < n; i++) {
        int l = 0;
        int r = p.size() - 1;

        while (l <= r) {
            int mid = (l + r) >> 1;
            if (arr[i] > p[mid].first) {
                l = mid + 1;
            } else if (arr[i] < p[mid].first) {
                r = mid - 1;
            } else {
                narr[i] = p[mid].second;
            }
        }
    }

    vector<int> f(2 * p.size() + 1);

    for (int i = 0; i < n; i++) {
        f[narr[i]]++;
    }

    cout << "narr -> ";
    for (auto c: narr) cout << c << " ";
    cout << endl;
    return;

    /* int atual = 0; */
    /* for (int i = 0; i < n; i++) { */
    /*     if (f[narr[i]] < */ 
    /* } */

    /* cout << "p -> "; */
    /* for (auto [f, s]: p) cout << f << " "; */
    /* cout << endl; */

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
