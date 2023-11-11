#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    string s; cin >> s;
    int n = s.size();
    vector<char> arr;
    for (int i=0; i < n; i++) {
        arr.push_back(s[i]);
        while (arr.size() >= 3 && arr[arr.size() - 1] == 'C' && arr[arr.size() - 2] == 'B' && arr[arr.size() - 3] == 'A') {
            arr.pop_back(); 
            arr.pop_back();
            arr.pop_back();
        }
    }
    for (auto cara: arr) cout << cara;
    cout << endl;
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
