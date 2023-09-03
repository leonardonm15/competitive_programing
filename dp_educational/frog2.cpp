#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    int arr[n];
    vector<int> arr_val(n, 2e9);
    arr_val[0] = 0;
    for (int i=0; i < n; i++) cin >> arr[i];
    for (int i=0; i <= n - 2; i++) {
        int val;
        for (int j = i + 1; j - i <= k; j++) {
            val = abs(arr[i] - arr[j]) + arr_val[i];
            arr_val[j] = min(val, arr_val[j]);
            if (j == n - 1) break;
        }
    }
    cout << arr_val[n - 1] << endl;
}
