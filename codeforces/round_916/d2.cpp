#include <bits/stdc++.h>

using namespace std;
#define int long long
#define pll pair<long long, long long>

void solve () {
    int n; cin >> n;
    vector<pll> a;
    vector<pll> b;
    vector<pll> c;

    for (int i=0; i < n; i++) {
        int num; cin >> num;
        a.push_back({num, i});
    }


    for (int i=0; i < n; i++) {
        int num; cin >> num;
        b.push_back({num, i});
    }


    for (int i=0; i < n; i++) {
        int num; cin >> num;
        c.push_back({num, i});
    }

    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    sort(c.rbegin(), c.rend());
    
    int answ = 0;
    for (int k=0; k < 3; k++) {
        for (int i=0; i < 3; i++) {
            for (int j=0; j < 3; j++) {
                if (a[k].second != b[i].second && b[i].second != c[j].second && c[j].second != a[k].second) {
                    answ = max(answ, a[k].first + b[i].first + c[j].first);
                }
            }
        }
    }

    cout << answ << endl;

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
