#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    map <int, int> map;
    set<int> esperando;
    char ur = 'T';
    for (int i=0; i < n; i++) {
        char op; cin >> op;
        if (op == 'T') {
            int tempo; cin >> tempo;
            for (auto amigo: esperando) {
                map[amigo]+= tempo;
            }
        } else {
            int am; cin >> am;
            map[am]++;
            map[am]--;
            if (ur != 'T') {
                for (auto amigo: esperando) {
                    map[amigo]++;
                }
            }
            if (op == 'R') {
                esperando.insert(am);
            }
            if (op == 'E') {
                esperando.erase(am);
            }
        }
        ur = op;
    }
    cout << endl;
    for (auto amigo: esperando) {
         map[amigo] = -1;
    }
    for (auto [amigo, tempo]: map) {
        cout << amigo << " " << tempo << endl;
    }
}


