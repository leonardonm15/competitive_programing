#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

#define endl '\n' 
#define int long long


using namespace __gnu_pbds;

template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    ordered_set<int> resp;
    int k = 0;
    for (int i=0; i < n; i++) cin >> arr[i];
    for (int i=0; i < n; i++) {
        if (arr[i] < (i + 1)) {
            int c = resp.order_of_key(arr[i]);
            /* cout << "c -> " << c << endl; */
            k += c;
            resp.insert(i + 1);
        }

        /* if (i > 0 && arr[i - 1] < i) resp.insert(i + 1); */
    }

    cout << k << endl;
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
