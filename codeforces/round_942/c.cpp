#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

int check(int mid, vector<int>& arr) {
    int n = arr.size();
    int c = 0;
    for (int i=0; i < n; i++) {
        c += max(0ll, mid - arr[i]); // tem que concertar isso; 9 - 10
    }

    return c; // quanto que eu vou somar no final
}

void solve () {
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    for (int i=0; i < n; i++) cin >> arr[i];

    int l = 0;
    int r = 1e12 + 5;
    int ans = 0; // quantos ks eu consumi na rodada optima
    int quantidade_max = 0; // vezes que repete a sequencia
    while (l <= r) {
        int mid = (l + r) >> 1;
        int c = check(mid, arr);
        if (c > k) {
            r = mid - 1;
        } else {
            ans = c;
            quantidade_max = mid;
            l = mid + 1;
        }
    }

    k -= ans;
    int add = k;

    /* cout << "arr[i] -> "; */
    for (int i=0; i < n; i++) {
        arr[i] = max(0ll, arr[i] - quantidade_max);
        if (arr[i] > 0) add++;
        /* cout << arr[i] << " "; */
    }
    /* cout << endl; */

    /* cout << "k -> " << k << endl; */
    /* cout << "quantidade vezes repet -> " << quantidade_max << endl; */
    /* cout << "add -> " << add << endl; */

    cout << ((quantidade_max - 1) * n) + 1 + add << endl;
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
