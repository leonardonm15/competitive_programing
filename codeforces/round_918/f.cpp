#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;


void solve () {
    int n; cin >> n;
    vector<pair<int, int>> arr;
    ordered_set s;
    for (int i=0; i < n; i++) {
        int a, b; cin >> a >> b;
        arr.push_back({b, a});
    }

    sort(arr.begin(), arr.end());

    long long resp = 0;
    for (auto [b, a]: arr) {
        resp += s.size() - s.order_of_key(a);
        s.insert(a);
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
