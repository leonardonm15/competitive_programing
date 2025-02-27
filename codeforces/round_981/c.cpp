#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];


    int l = 1;
    int r = n - 2;


/*     if (arr[l + 1] == arr[l] && arr[r] != arr[l] && arr[r - 1] != arr[l + 1]) swap(arr[l], arr[r]); */
/*     l++; */
/*     r--; */

    while (l < r) {

        if (arr[l] == arr[l - 1]) swap(arr[l], arr[r]);
        if (arr[r] == arr[r + 1]) swap(arr[l], arr[r]);

        l++, r--;
    }


    int k = 0;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1]) k++;
    }

    cout << k << endl;
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

