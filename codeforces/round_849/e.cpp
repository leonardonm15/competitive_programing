#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        int min;
        long long soma = 0;
        for(int i=0; i < n; i++) {
            cin >> arr[i];
            if (i==0) {
                min = arr[i];
            }
            if (arr[i] < min) min = arr[i];
            if (arr[n - 1] > min && arr[n - 1] < 0) {
                arr[n - 1] = arr[n - 1] * -1;
                arr[n - 2] = arr[n - 2] * -1;
            }
        }
        for(int i=0; i < n - 1; i++) {
            int b = 0;
            int a = 0;
            a = arr[i];
            b = arr[i+1];
            int soma1 = a + b;
            int soma2 = -b + -a;
            if (soma2 > soma1) {
                arr[i] = -a;
                arr[i+1] = -b;
                soma += -a;
            } else {
                soma += a;
            }
        }
        soma += arr[n - 1];
        cout << soma << endl;
    }
}

