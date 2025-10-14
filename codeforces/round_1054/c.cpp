#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, k; cin >> n >> k;
    vector<int> arr(n + 5);

    int v = 0;
    int repetido_k = 0;
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        if (arr[num]) {
            if (num == k) repetido_k++;
            v++;
        }
        else arr[num]++;
    }


    int p = 0;
    int parada = -1;
    for (int i = 0; i < k; i++) {
        if (arr[i] == 0 && p < v) {
            arr[i]++;
            p++;
            if (repetido_k) repetido_k--;
        }
        if (arr[i] == 0 && p == v && parada == -1) {
            parada = i;
        }
    }


    if (parada == -1) {
        /* cout << "opa -> " << endl; */
        /* cout << "arr -> "; */
        /* for (int i = 0; i <= n; i++) cout << arr[i] << " "; */
        /* cout << endl; */
        /* cout << "p -> " << p << endl; */
        /* cout << "repetido_k -> " << repetido_k << endl; */
        cout << p + (arr[k] + repetido_k) << endl;
    } else {
        cout << "opa -> " << endl;
        int qz = 0;
        for (int i = parada; i < k; i++) {
            if (arr[i] == 0) qz++;
        }

        int qu = 0;
        qz += repetido_k + arr[k];
        for (int i = k; i <= n; i++) {
            if (arr[i]) {
                qu++;
                arr[i]--;
            }
        }

        cout << p + qz << endl;

    }

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
