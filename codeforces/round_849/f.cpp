#include <bits/stdc++.h>

using namespace std;

int get_sum(int numero) {
    int s = numero;
    int s2 = numero;
    int soma = 0;
    while (s2 > 0) {
        s = s2 % 10;
        soma = soma + s;
        s2 = s2/10;
    }
    return soma;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> arr(n);
        set<int> igt;
        for (int i=0; i < n; i++) {
            int inp; cin >> inp;
            arr[i] = inp;
            igt.insert(i);
        }
        while (q--) {
            int tp; cin >> tp;
            if (tp == 1) {
                int l, r; cin >> l >> r;
                for (auto i=igt.lower_bound(l - 1); i != igt.end() && *i <= r - 1;){
                    arr[*i] = get_sum(arr[*i]);
                    if (arr[*i] <= 9) {
                        i = igt.erase(i);
                    } else {
                        i++;
                    }

                }
            } else {
                int ind; cin >> ind;
                ind--;
                int numero = arr[ind];
                cout << numero << endl;
            }            
        }
    }
}
