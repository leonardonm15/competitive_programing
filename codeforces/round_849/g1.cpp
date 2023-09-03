#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n, c; cin >> n >> c;
        long long arr[n];
        for (int i=0; i < n; i++) { 
            int num; cin >> num;
            num += i + 1;
            arr[i] = num;
        }
        sort(arr, arr + n);
        // for (int i =0; i < n; i++) cout <<  " " << arr[i];
        // cout << endl;
        int i = 0;
        while (c >= arr[i]) {
            if (i == n) break;
            // cout << " " << arr[i];
            c -= arr[i];
            i++;
        }
        // cout << endl;
        cout << i << endl;
    }
}
