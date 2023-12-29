#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr;
    /* map<int, int> map; */
    /* if (n&1) ppar.push_back(0); */
    int soma = 0;
    bool flag = false;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        if (i&1) {
            soma -= num;
        } else {
            soma += num;
        }
        arr.push_back(soma);
    }

    sort(arr.begin(), arr.end());
    for (int i=0; i < arr.size() - 1; i++) {
        if (arr[i] == arr[i + 1] || arr[i] == 0) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;

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
