#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; cin >> n;
        int arr[n];
        int min;
        int neg = 0;
        long long soma = 0;
        bool have_zero = false;
        for (int i=0; i < n; i++) {
            cin >> arr[i];
            if (arr[i] == 0) have_zero = true;
            if (arr[i] < 0) neg++;
            soma += abs(arr[i]);
            if (i==0) min = abs(arr[i]);
            if (abs(arr[i]) < min) min = abs(arr[i]);
        }
        if (neg % 2 != 0 && have_zero == false) {
            cout << soma - abs(min) * 2 << endl;
        } else cout << soma << endl;
    }
}
