#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long


int check(vector<pair<int, int>> &v, vector<int> &arr) {
    int n = arr.size();
    vector<int> mex(n + 2);

    for (auto [l, r]: v) {
        vector<int> mx(n + 2);
        for (int i = l; i <= r; i++) {
            mx[arr[i]]++;
        }

        int mexi = 0;
        for (int i = 0; i <= n + 1; i++) {
            if (mx[i] == 0) {
                mexi = i;
                break;
            }
        }

        mex[mexi]++;
    }

    for (int i = 0; i <= n + 1; i++) {
        if (mex[i] == 0) {
            return i;
        }
    }
}

void solve () {
    int n, m; cin >> n >> m;

    vector<pair<int, int>> am(n);
    vector<pair<int, int>> qs;
    vector<int> plus(n + 1);
    vector<int> minus(n + 1);

    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        l--; r--;

        qs.push_back({l, r});

        plus[l]++;
        minus[r + 1]++;
    }

    int now = 0;
    for (int i = 0; i < n; i++) {
        now -= minus[i];
        now += plus[i];
        am[i] = {now, i};
    }

    vector<int> resp(n);
    sort(am.rbegin(), am.rend());


    /* cout << "am.size() -> " << am.size() << endl; */
    /* swap(am[1], am[n - 1]); */
    cout << "-----------------" << endl;
    for (auto [f, s]: am) cout << "[" << f << " - " << s << "] " << endl;

    for (int i = 0; i < n; i++) {
        resp[am[i].second] = i;
    }

    cout << "check -> " << check(qs, resp) << endl;

    for (auto v: resp) cout << v << " ";
    cout << endl;
}

signed main() {
    /* ios_base::sync_with_stdio(0);cin.tie(0); */
    int TC = 1;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
