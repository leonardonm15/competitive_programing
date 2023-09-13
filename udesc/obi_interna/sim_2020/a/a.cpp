#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    t -= 4;
    t %= 8;
    if (t == 2) cout << 1 << endl;
    if (t == 3) cout << 2 << endl;
    if (t == 4) cout << 3 << endl;
}
