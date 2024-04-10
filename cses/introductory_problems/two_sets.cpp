#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    int n; cin >> n;
    int soma = (n * (1 + n)) / 2;
    vector<int> arr;
    vector<int> resp;
    if (soma % 2 == 1) {
        cout << "NO" << endl;
        return;
    }
    soma /= 2;
    for (int i=n; i >= 1; i--) {
        if (i <= soma){
            soma -= i;
            arr.push_back(i);
        } 
        else resp.push_back(i);
    }
    cout << "YES" << endl;
    cout << arr.size() << endl;
    for (int i=0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << resp.size() << endl;
    for (int i=0; i < resp.size(); i++) {
        cout << resp[i] << " ";
    }
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
