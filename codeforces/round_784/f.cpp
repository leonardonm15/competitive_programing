#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int arr[n];
        for (int i=0; i < n; i++) cin >> arr[i];
        int doces = 0;
        int l=0, r = n - 1;
        int somal = 0, somar = 0;
        somal += arr[l];
        somar += arr[r];
        while (l < r) {
            if (somal == somar) {
                /* cout << " " << somar << " " << somal << endl; */
                /* cout << " " << l << " " << r << endl; */
                /* cout << "nova quantidade de doces -> " << (l+1) + (n - r) << endl; */
                doces = max(doces, (l+1) + (n - r));
                l++;
                r--;
                somar += arr[r];
                somal += arr[l];
                continue;
            }
            if (somal > somar) {
                r--;
                somar += arr[r];
                continue;
            }
            if (somar > somal) {
                l++;
                somal += arr[l];
                continue;
            }
        }
        cout << doces << endl;
    }
}
