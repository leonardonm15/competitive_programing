#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

vector<bool> sv;
vector<int> primo;

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
    int n, m; cin >> n >> m;
    
    cout << "primos -> ";
    for (int i=0; i <= 20; i++) cout << primo[i] << " ";
    cout << endl;
    cout << "primo.size() -> " << primo.size() << endl;

    int resp = 0;
    for (int i=1; i < primo.size() - 1; i++) {
        if (primo[i] > n) break;
        for (int j = 1; i < primo.size(); j++) {
            if (primo[j] > m) break;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    sv = sieve(2e6 + 5);
    for (int i=1; i <= 2e6; i++) if (sv[i]) primo.push_back(i);
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
