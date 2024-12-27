#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> a, b, d;

    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        while (a.size() && num < a.back()) {
            int d = a.back();
            a.pop_back();
            b.push_back(d + 1);
        }

        a.push_back(num);

    }

    sort(b.rbegin(), b.rend());

    while (b.size()) {

        while (a.size() && b.size() && b.back() < a.back()) {
            d.push_back(a.back() + 1);
            a.pop_back();
        }

        while (a.size() && b.size() && b.back() >= a.back()) {
            a.push_back(b.back());
            b.pop_back();
        }
    }

    for (auto c: d) a.push_back(c);

    sort(a.begin(), a.end());

    for (auto c: a) cout << c << " ";
    cout << endl;
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
