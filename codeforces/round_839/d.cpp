#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     
//

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    vector<int> sarr;

    for (int i=0; i < n; i++) cin >> arr[i];
    sarr = arr;
    sort(sarr.begin(), sarr.end());
    if (arr == sarr) {
        cout << 0 << endl;
        return;
    }

    int l = *(min_element(arr.begin(), arr.end()));
    int r = *(max_element(arr.begin(), arr.end()));
    while (l <= r) {
        /* cout << "-------------" << endl; */
        int mid = (l + r) / 2;
        bool hi; bool low; bool answ = true;
        for (int i = 1; i < n; i++) {
            if (abs(arr[i] - mid) < abs(arr[i - 1] - mid)) {
                answ = false;
                hi = arr[i] > arr[i - 1];
                break;
            }
        }

        if (answ) {
            cout << mid << endl;
            return;
        }

        if (hi) r = mid - 1;
        else l = mid + 1;
    }
    cout << -1 << endl;
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
