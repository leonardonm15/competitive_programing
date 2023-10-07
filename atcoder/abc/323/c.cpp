#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    int n, m; cin >> n >> m;
    vector<int> arr;
    vector<pair<int, int>> sarr;
    vector<string> inps; 
    vector<vector<int>> err(n, vector<int>(m));
    vector<int> resps(n);
    for (int i=0;i < m; i++) {
        int num; cin >> num;
        arr.push_back(num);
        sarr.push_back({num, i});
    }
    sort(sarr.begin(), sarr.end(), greater<pair<int, int>>());
    int maxp = n;
    for (int i=0; i < n; i++) {
        string s; cin >> s;
        inps.push_back(s);
        /* cout << " s -> " << s << endl; */
        int resp = i + 1;
        /* cout << " i -> " << i << endl; */
        for (int j=0; j < m; j++) {
            if (s[j] == 'o') {
                /* cout << "  " << i << " - " << j << endl; */
                resp += arr[j];
            } else err[i][j]++;
        }
        resps[i] = resp;
        /* cout << "resp -> " << resp << endl; */
        maxp = max(maxp, resp);
    }
    /* cout << "maxp -> " << maxp << endl; */
    for (int i=0; i < n; i++) {
        /* cout << "------- i ------- " << i << " --------------- " << endl; */
        string s = inps[i];
        int r = resps[i];
        int resp = 0;
        while (r < maxp) {
            for (auto pair: sarr) {
                if (r > maxp) break;
                /* cout << "r -> " << r << endl; */
                if (err[i][pair.second]) {
                    r += pair.first;
                    /* cout << "pair.first -> " << pair.first << endl; */
                    resp++;
                }
            }
        }
        cout << resp << endl;
    }
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
