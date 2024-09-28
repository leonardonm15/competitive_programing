#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> vec(n);

    int mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> vec[i];
        mx = max(mx, vec[i]);
    }

    int l = 1;
    int r = 1e12;
    int ans = 1e18;

    for (int k = 1; k <= mx; k++) {
        vector<int> arr = vec;
        int resto = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] >= k) {
                resto += arr[i] - k;
                arr[i] = k;
            } else {
                int a = min(resto, k - arr[i]);
                arr[i] += a;
                resto -= a;
            }
        }

        if (resto > 0) arr[n - 1] += resto;
        int minimo = 1e18;
        int maximo = 0;

        for (auto c: arr) {
            minimo = min(minimo, c);
            maximo = max(maximo, c);
        }

        cout << "k - " << k << " -> " << maximo - minimo << endl;
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
