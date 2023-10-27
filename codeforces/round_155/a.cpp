#include <bits/stdc++.h>
 
using namespace std;
#define int long long
#define endl "\n"
 
signed main() {
    int t; cin >> t;
    while (t--) {
        int n, a, b; cin >> n >> a >> b;
        int x, y;
        for (int i=1; i < n; i++) {
            cin >> x >> y;
            if (x >= a && y >= b) {
                a = -1;
            }
        }
        cout << a << endl;
    }
}
