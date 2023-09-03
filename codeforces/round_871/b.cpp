#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int cs = 0;
        int ls = 0;
        for (int i=0; i < n; i ++) {
            int num; cin >> num;
            if (num == 0) {
                cs++;
                if (cs > ls) ls = cs;
            }
            else cs = 0;
        }
        cout << ls << endl;
    }
}
