#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 

vector<bool> sieve(int n) {
    vector<bool> is_prime(n + 5, true);
    is_prime[0] = false;
    is_prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j < n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

void solve () {
    int q; cin >> q;
    while (q--) {
        int n; cin >> n;
        int div = 0;
        for (int i=1; i * i <= n; i++) {
            if (n % i == 0)  {
                if (n % (n / i) == 0 && n/i != i) div++;
                div++;
            }
        }

        cout << div << endl;
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
