#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T, typename U>
using ordered_map = tree<T, U, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define endl '\n' 
#define int long long


const int INF = 1e9;

void solve () {
    int n, x, y; cin >> n >> x >> y;
    vector<int> arr(n);
    ordered_set<pair<int, int>> sarr;
    int soma_total = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        soma_total += arr[i];
    }

    /* cout << "soma_total -> " << soma_total << endl; */

    int resp = 0;
    for (int i = 0; i < n; i++) {
        int now = arr[i];

        int mac = soma_total - (x + now); // maior cara que eu posso tirar
        int mec = soma_total - (y + now); // menor cara que eu posso tirar

        mac++;
        /* mec--; */

        auto map = sarr.order_of_key({mac, -INF});
        auto mep = sarr.order_of_key({mec, -INF}); 

        /* cout << "--------------------" << endl; */
        /* cout << "quantos caras menores que " << mac << " -> " << map << endl; */
        /* cout << "quantos caras menores que " << mec << " -> " << mep << endl; */

        resp += (map - mep);
        sarr.insert({now, i});
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
