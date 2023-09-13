#include <bits/stdc++.h>

using namespace std;

int main() {
    int d, a, n; cin >> d >> a >> n;
    int dias = 32 - n;
    if (n > 15) {
        cout << (d + (14 * a)) * dias << endl;
    } else {
        int k = n - 1;
        cout << (d + (k * a)) * dias << endl;
    }

}
