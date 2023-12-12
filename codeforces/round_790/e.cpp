#include <bits/stdc++.h>

using namespace std;
//#define int long long

void solve () {
    int n, q; cin >> n >> q;
    int soma = 0;
    vector<int> p(n);
    vector<int> arr(n);

    for (int i=0; i < n; i++) {
        int num; cin >> num;
        p[i] = num;
    }

    sort(p.rbegin(), p.rend());

    for (int i=0; i < n; i++) {
        soma += p[i];
        arr[i] = soma;
    }

    cout << endl;
    cout << "caras - > ";
    for (auto cara: arr) cout << cara << " ";
    cout << endl;

    while (q--) {
        int num; cin >> num;
        int anw = 0;
        int l = 0;
        int r = n - 1;
        int mid = (l + r) / 2;
        while (l <= r) {
            mid = (l + r) / 2;
            if (arr[mid] >= num) {
                anw = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        cout << "arr[mid] -> " << arr[mid] << " - num -> " << num << endl;
        if (arr[mid] < num) cout << -1 << endl;
        else cout << mid + 1 << endl;
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
