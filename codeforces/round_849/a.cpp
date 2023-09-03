#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    string codeforces = "codeforces";
    while (t--) {
        char n;
        cin >> n;
        bool flag_found = false;
        for(int i=0; i < codeforces.size(); i++) {
            if (codeforces[i] == n) {
                cout << "YES" << endl;
                flag_found = true;
                break;
            }
        }
        if (flag_found == false) cout << "NO" << endl;
    }
}
