#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    vector<int> freq(64);
    while (n--) {
        int q; cin >> q;
        if (q == 1) {
            int num; cin >> num;
            freq[num]++;
        } else {
            int num; cin >> num;
            for (int i=29; i >= 0; i--) {
                /* cout << " ---------------" << endl; */
                /* cut << "num -> " << num << endl; */
                /* cout << "i -> " << i << endl; */
                /* cout << "freq[i] -> " << freq[i] << endl; */
                if (freq[i] > 0 && (1 << i) <= num) {
                    /* cout << "num -> " << num << endl; */
                    /* cout << (1 << i) << endl; */
                    /* cout << "num % (1 << i) -> " << num / (1 << i) << endl; */
                    int q = min(num / (1 << i), freq[i]);
                    /* cout << "q -> " << q << endl; */
                    num -= q * (1 << i);
                }
            }
            if (num == 0) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
