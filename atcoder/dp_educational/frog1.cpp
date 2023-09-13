#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int arr[n];
    vector<int> arr_val(n, 2e9);
    arr_val[0] = 0;
    int soma = 0;
    for (int i=0; i < n; i++) cin >> arr[i];
    int val1, val2;
    for (int i=0; i < n - 1; i++) {
        val1 = abs(arr[i] - arr[i + 1]) + arr_val[i];
        if (i < n - 2) val2 = abs(arr[i] - arr[i + 2]) + arr_val[i];
        arr_val[i + 1] = min(arr_val[i + 1], val1);
        if (i < n - 2) arr_val[i + 2] = min(arr_val[i + 2], val2);
    }
    cout << arr_val[n - 1] << endl;
}

