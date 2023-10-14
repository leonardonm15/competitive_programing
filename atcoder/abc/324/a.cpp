#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n; cin >> n;
    set<int> st;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        st.emplace(num);
    }
    if (st.size() > 1) cout << "No" << endl;
    else cout << "Yes" << endl;
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
