#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string number;
        cin >> number;
        int l = 0;
        int r = n - 1;
        bool wtflag = false;
        while (l <= r) {
            if (n == 1) break;
            if (number[l] == number[r]) {
               cout << r - l + 1 << endl;
               wtflag = true;
               break;
            } else {
                l++;
                r--;
            }
        }
        if (l >= r && n % 2 == 0 && wtflag == false) cout << 0 << endl;
        if (l >= r && n % 2 != 0 && wtflag == false) cout << 1 << endl;
    }
}
