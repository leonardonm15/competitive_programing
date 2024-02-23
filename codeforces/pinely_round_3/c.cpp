#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    vector<int> l(n);
    vector<int> r(n);
    vector<int> c(n);

    for (int i=0; i < n; i++) cin >> l[i];
    for (int i=0; i < n; i++) cin >> r[i];
    for (int i=0; i < n; i++) cin >> c[i];

    sort(l.begin(), l.end());
    sort(r.begin(), r.end());
    sort(c.rbegin(), c.rend());

    int resp = 0;
    for (int i=0; i < n; i++) {
        int d = 0;
        int u = l.size();
        int m = 0;
        int k = 0;
        
        cout << "------------" << endl;
        while (d <= u) {
            int mid = (d + u) >> 1;
            cout << "mid -> " << l[mid] << endl;
            if (l[mid] > r[i]) u = mid - 1;
            else {
                k = l[mid];
                m = mid;
                d = mid + 1;
            }
        }

        /* cout << "l[mid] -> " << k << endl; */
        resp += (c[i] * (r[i] - k));
        l.erase(l.begin() + (m - 1));
        cout << "l -> ";
        for (auto cara: l) cout << cara << " ";
        cout << endl;
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
