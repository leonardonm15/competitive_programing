#include <bits/stdc++.h>
 
using namespace std;
#define int long long
 
void solve () {
    int n, m; cin >> n >> m;
    int c = n;
    int k = 1;
    vector<int> arr(2);
    while (n % 2 == 0 || n % 5 == 0) {
        if (n % 2 == 0) {
            n /= 2;
            arr[0]++;
        }
        if (n % 5 == 0) {
            n /= 5;
            arr[1]++;
        }
    }

    while (arr[1] != arr[0]) {
        if (arr[1] > arr[0]) {
            if (k * 2 > m) break;
            k *= 2;
            arr[0]++;
        } else if (arr[0] > arr[1]) {
            if (k * 5 > m) break;
            k *= 5;
            arr[1]++;
        }
    }
 
    while (k * 10 < m) {
        arr[0]++;
        arr[1]++;
        k *= 10;
    }

    if (m / k > 0) cout << k * c * (m / k) << endl;
    else cout << c * n << endl;
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
