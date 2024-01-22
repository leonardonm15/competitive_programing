#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     
//

int check(vector<int> &arr, int mn, int& iat) {
    int n = arr.size();
    int i = 0;
    for (i; i < n; i++) {
        if (abs(arr[i] - mn) > abs(arr[i + 1] - mn)) {
            break;
        }
    }
    iat = i;
    return i;
}

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    vector<int> sarr;

    for (int i=0; i < n; i++) cin >> arr[i];
    arr.push_back(1e9);
    sarr = arr;
    sort(sarr.begin(), sarr.end());
    if (arr == sarr) {
        cout << 0 << endl;
        return;
    }

    int l = 0;
    int r = 2 * *(max_element(arr.begin(), arr.end()));
    /* r = 1e9; */
    int resp = 0;
    int maxi = 0;
    int iat = 0;
    while (l <= r) {
        /* cout << "-------------" << endl; */
        int mid = (l + r) / 2;
        /* cout << "mid -> " << mid << endl; */
        /* cout << "maxi -> " << maxi << endl; */
        if (check(arr, mid, iat) < maxi) {
            l = mid + 1;
        } else {
            resp = mid;
            maxi = iat;
            r = mid - 1;
        }
    }
    if (resp == 0 || maxi < n - 1) cout << -1 << endl;
    else cout << resp << endl;
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
