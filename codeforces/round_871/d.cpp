#include <bits/stdc++.h>

using namespace std;

int db3(int n, int m) {
    if (n == m) return true;
    else if (n % 3 != 0) return false;
    else {
        return (db3(2 * n / 3, m) || db3(n / 3, m));
    }
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n, gn; cin >> n >> gn;
        if (db3(n, gn) == true) cout << "YES" << endl;
        else cout << "NO" << endl;

    }
}
