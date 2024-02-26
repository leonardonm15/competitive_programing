#include <bits/stdc++.h>
 
using namespace std;
map<int, int> plts;

int main() {
    int t; cin >> t;
    for(int i=0; i < t; i++) {
        plts.clear();
        int n = 0, c = 0, plt = 0, out = 0; cin >> n >> c;
        while (n --) {
            cin >> plt;
            plts[plt]++;
        }
        for (auto [x, y]:plts) {
            if (y > c) {
                out+= c;
            } else if (y <= c) {
                out += y;
            }
        }
        cout << out << endl;
    }
}
