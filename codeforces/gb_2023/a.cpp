#include <bits/stdc++.h>

using namespace std;
//#define int long long

vector<bool> primo(2024, true);

void set_crivo() {
    for (int p = 2; p * p <= primo.size(); p++) { 
        if (primo[p] == true) { 
            for (int i = p * p; i <= primo.size(); i += p) 
                primo[i] = false; 
        } 
    }
}

void solve () {
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    vector<int> mul(2024);
    bool flag = false;

    for (int i=0; i < n; i++) {
        int num; cin >> num;
        if (num == 1) continue;
        for (int i=2; i < primo.size(); i++) {
            while ((num % i == 0) && primo[i] && num > 0) {
                mul[i]++;
                num /= i;
                if (i != 7 && i != 17) {
                    /* cout << "i -> " << i << endl; */
                    flag = true;
                }
            }
        }
    }
    /* cout << "mul[7] -> " << mul[7] << endl; */
    /* cout << "mul[17] -> " << mul[17] << endl; */
    bool q = (mul[7] <= 1 && mul[17] <= 2);
    if (flag == true || q == false) cout << "NO" << endl;
    else {
        int v = max(1, 7 * (1 - mul[7]));
        int c = max(1, (int) pow(17, (2 - mul[17])));
        cout << "YES" << endl;
        /* cout << "c -> " << c << endl; */
        /* cout << "v -> " << v << endl; */
        cout << c * v << " ";
        k--;
        while (k--) {
            cout << 1 << " ";
        }
        cout << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    set_crivo();
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
