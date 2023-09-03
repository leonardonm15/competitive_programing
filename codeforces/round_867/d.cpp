#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n == 1) {
            cout << "1" << endl;
            continue;
        }
        if (n % 2 == 1) cout << -1 << endl;
        else {
            for (int i=0; i < n; i++) {
                if (i % 2 == 0) cout << " " << n - i;
                else cout << " " << i;
            }
            cout << endl;
        }
    }
}
