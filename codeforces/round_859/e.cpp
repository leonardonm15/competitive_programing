#include <bits/stdc++.h>

using namespace std;

const int MAX = 2e5 + 5;
int arr_norm[MAX];

void solve(int l, int r, int arr[]) {
    cerr << "r - l" << r << " " << l << endl; // apagar
    string query = "? " + to_string((( l + r) / 2) - l + 1);
    for (int i=l; i <= (l + r) / 2; i++) {
        query += " " + to_string(i);
    }
    cout << query << endl;
    int res; // respota
    cin >> res;
    int correto = arr[(l + r) / 2] - arr[l - 1];
    if (r - (l - 1)  <= 1) {
        correto = arr_norm[l - 1];
        if (correto == res) cout << "! " << r << endl;
        else cout << "! " << l << endl;
        return;
    }
    if (res == correto) solve( 1 + (l + r) / 2, r, arr);
    else solve(l, (l + r) / 2 , arr);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n; // number of piles 
        cin >> n;
        int sumn[n + 1];
        sumn[0] = 0;
        int soma = 0;
        for (int i=0; i < n; i++) {
            int np; // numero de pedras na pilha n
            cin >> np;
            arr_norm[i] = np;
            soma += np;
            sumn[i + 1] = soma;
        }	
        solve(1, n, sumn);
    }
}
