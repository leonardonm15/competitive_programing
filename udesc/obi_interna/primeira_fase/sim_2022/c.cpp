#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    pair<int, int> c;
    int resp;
    int soma_row = 0;
    for (int i=0; i < n; i++) {
        int aux2 = 0;
        for (int j=0; j < n; j++) {
            int num; cin >> num;
            aux2 += num;
            if (num == 0) {
                c.first = i + 1;
                c.second = j + 1;
            }
        }
        if (i == 0) {
            soma_row = aux2;
        }
        else if (aux2 > soma_row && i != 0) { 
            resp = aux2 - soma_row;
        } 
        else if (aux2 < soma_row && i != 0) {
            resp = soma_row - aux2;
        } 
    }
    cout << resp << endl;
    cout << c.first<< endl;
    cout << c.second<< endl;
}
