#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        pair<int, int> pos(0,0);
        bool flag_yes = false;
        for (int i=0; i<n; i++) {
            char op = s[i];
            if (op == 'R') pos.first++;
            if (op == 'L') pos.first--;
            if (op == 'U') pos.second++;
            if (op == 'D') pos.second--;
            if (pos.first == 1 && pos.second == 1) {
                cout << "YES" << endl;
                flag_yes = true;
                break;
            }
        }
        if (flag_yes == false) cout << "NO" << endl;
    }
}
