#include <bits/stdc++.h>

using namespace std;

int main() {
    string cd = "codeforces";
    int t; cin >> t;
    while (t--) {
        string n; cin >> n;
        int df = 0;
        for (int i = 0; i < 10; i++) {
            if (n[i] != cd[i]) df++;
        }
        cout << df << endl;
    }
}
