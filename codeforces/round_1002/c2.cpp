#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 

const int INF = 305;

int mex(vector<pair<int, int>>& arr) {
    vector<int> mex(INF);

    for (auto [f, s]: arr) {
        mex[min(f, INF)]++;
    }

    for (int i = 0; i < INF; i++) {
        if (!mex[i]) return i;
    }

    return INF;
}

void solve () {
    int n; cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> arr[i][j];

    //  [ [1, 2, 3], [], [], [] ]
    //  [ [1, 2, 3], [], [], [] ]

    vector<pair<int, int>> vec(n);

    int resp = 0;
    for (int i = 0; i < n; i++) vec[i].second = i;
    for (int i = 0; i < n; i++) {
        for (auto& [f, s]: vec) {
            f += arr[i][s];
        }

        sort(vec.begin(), vec.end());

        cout << "vec -> ";
        for (auto [f, s]: vec) cout << f << " ";
        cout << endl;

        vec[n - 1].first = 0;
        resp = max(resp, mex(vec));
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
