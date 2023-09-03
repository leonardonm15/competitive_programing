#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    int n, m, h; cin >> n >> m >> h;
    pair<int, int> best = {-1, h+1};
    int change_counter = 1;
    for (int i=1; i <= n; i++) {
        vector<int> arr;
        for (int j=0; j < m; j++){ 
            int num; cin >> num;
            arr.push_back(num);
        }
        sort(arr.begin(), arr.end());
        int c = 0;
        int idx = 0;
        int aux = h;
        int pen = 0;
        while (aux >= arr[idx]) {
            aux -= arr[idx];
            pen += pen + arr[idx];
            c++;
            idx++;
            if (idx == m) break;
        }
        pair<int, int> res = {c, pen};
        if (res.first > best.first){
            if (i == 1) {
                best = res;
            } else change_counter++;
        } 
        else if (res.first == best.first) {
            bool d = best.second > res.second;
            if (d) change_counter++;
        }
    }
    cout << change_counter << endl; 
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
