#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, k; cin >> n >> k;
    vector<pair<int, int>> arr(n);
    vector<pair<int, int>> bomba;

    for (int i=0; i < n; i++) cin >> arr[i].second;

    for (int i=0; i < n; i++) {
        int num; cin >> num;
        arr[i].first = abs(num);
    }
 
    sort(arr.begin(), arr.end());

    bomba.push_back(arr[0]);
    for (int i=1; i < n; i++) {
        if (bomba[bomba.size() - 1].first == arr[i].first) bomba[bomba.size() - 1].second += arr[i].second;
        else bomba.push_back(arr[i]);
    }


    /* cout << "bomba -> " << endl; */
    /* for (auto [a, b]: bomba) cout << a << "  " << b << endl; */
    /* return; */
    
    int qa = 0;
    int lc = 0;
    for (int i=0; i < (int)bomba.size(); i++) {
        auto [pos, vida] = bomba[i];
        int diff = pos - lc;
        qa += (k * diff);
        // cout << pos << " " << vida << " " << qa << endl;
        if (vida > qa) {
            cout << "NO" << endl;
            return;
        } else qa -= vida;

        lc = pos;
    }

    cout << "YES" << endl;
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
