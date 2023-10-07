#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n; cin >> n;
    vector<pair<int, int>> arr(n + 1);
    map<int, set<int>> map;
    vector<int> resp;
    for (int i=1; i <= n; i++) {
        string s; cin >> s;
        arr[i] = {0, i};
        for (int j=0; j < n; j++) {
            if (s[j] == 'o') arr[i].first += 2;
            if (s[j] == '-') arr[i].first++;
        }
    }
    for (int i=1; i <= n; i++) {
        map[arr[i].first].emplace(arr[i].second);
    }
    set<int>::reverse_iterator rit;
    for (auto pair: map) {
        set<int> st = pair.second;
        for (rit = st.rbegin(); rit != st.rend(); rit++) {
            resp.push_back(*rit);
        }
    }
    reverse(resp.begin(), resp.end());
    for (int i=0; i < n; i++) {
        cout << resp[i] << " ";
    }
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
