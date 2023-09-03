#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int ttl_bl = 0;
        map<char, int> solved;
        string bloons;
        cin >> bloons;
        for (int i=0; i < n; i++) {
            char balao = bloons[i];
            solved[balao]++;
        }
        for (auto pair: solved) {
            ttl_bl += pair.second + 1;
        }
        cout << ttl_bl << endl;
    }
}
