#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, f, k; cin >> n >> f >> k;
    int inicial = -1;
    int fi = -1;
    int valor = 0;
    f--;
    vector<pair<int, int>> arr(n);
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        arr[i] = {num, i};
        if (i == f) {
            valor = num;
        }
    }

    sort(arr.rbegin(), arr.rend());

    for (int i=0; i < n; i++) {
    }

    for (int i=0; i < n - 1; i++) {
        if (arr[i].first == valor && inicial == -1) {
            inicial = i;
        }

        if (arr[i + 1].first != arr[i].first && arr[i].first == valor) {
            fi = i;
        }
    }

    if (fi == -1) fi = n - 1;
    if (inicial == -1) inicial = n - 1;

    k--;
    /* cout << "inicial -> " << inicial << endl; */
    /* cout << "fi -> " << fi << endl; */
    if (k >= fi) cout << "YES" << endl;
    else if (k < inicial) cout << "NO" << endl;
    else cout << "MAYBE" << endl;
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
