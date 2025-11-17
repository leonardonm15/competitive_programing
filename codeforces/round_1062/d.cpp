#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int L = 1e5 + 1;
const int P = 2e5 + 100;


namespace Sieve {
    vector<bool> is_prime(P, true);
    void build() {
        is_prime[0] = is_prime[1] = 0;
        for (int i = 2; i < P; i++) {
            if (is_prime[i])
                for (int j = i + i; j < P; j += i) is_prime[j] = 0;
        }
    }
}

vector<int> primes;
void build_primes() {
    for (int i = 2; i < P; i++) {
        if (Sieve::is_prime[i]) primes.push_back(i);
    }
}

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int k = arr[0];
    for (int i = 1; i < n; i++) {
        k = gcd(arr[i], k);
    }

    for (auto v: primes) {
            if (k % v != 0) {
                    cout << v << endl;
                    return;
            }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    Sieve::build();
    build_primes();
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
