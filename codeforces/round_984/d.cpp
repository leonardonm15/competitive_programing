#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, m; cin >> n >> m;

    vector<vector<int>> arr(n);

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (auto c: s) arr[i].push_back(c - '0');
    }

    int l = 0;
    int r = m - 1;
    int up = 0;
    int down = n - 1;

    int resp = 0;
    while (l < r && up < down) {
        vector<int> vec;
        /* cout << "----------------" << endl; */
        /* cout << "l ->  " << l << endl; */
        /* cout << "r -> " << r << endl; */
        /* cout << "Up -> " << up << endl; */
        /* cout << "down -> " << down << endl; */

        for (int i = l; i <= r; i++) {
            vec.push_back(arr[up][i]);
        }
        
        for (int i = up + 1; i <= down; i++) {
            vec.push_back(arr[i][r]);
        }


        for (int i = r - 1; i >= l; i--) {
            vec.push_back(arr[down][i]);
        }


        for (int i = down - 1; i > up; i--) {
            vec.push_back(arr[i][l]);
        }

        vec.push_back(vec[0]);
        vec.push_back(vec[1]);
        vec.push_back(vec[2]);
        vec.push_back(vec[3]);

        /* cout << "vec -> "; */
        /* for (auto c: vec) cout << c << " "; */
        /* cout << endl; */

        for (int i = 3; i < vec.size() - 1; i++) {
            string k;
            k.push_back('0' + vec[i]);
            k.push_back('0' + vec[i - 1]);
            k.push_back('0' + vec[i - 2]);
            k.push_back('0' + vec[i - 3]);

            if (k == "3451") resp++;
        }

        l++; r--;
        up++; down--;
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
