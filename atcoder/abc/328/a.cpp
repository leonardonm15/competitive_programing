#include <bits/stdc++.h>

using namespace std;
#define int long long

signed main() {
    int n, k; cin >> n >> k;
    int resp = 0;
    vector<int> arr(n);
    for (int i=0; i < n; i++) cin >> arr[i];

    for (int i=0; i < n; i++){
        if (arr[i] <= k) resp += arr[i];
    }
    cout << resp << endl;
}
