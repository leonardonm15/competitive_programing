#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int MOD = 1e9 + 7;
const int N = 2e5 + 5;
int fact[N];

void calc() {
    fact[1] = 1;
    fact[0] = 1;
    for (int i = 2; i < N; i++) fact[i] = (i * fact[i - 1]) % MOD;
}

int bpow(int a, int b) {
    int resp = 1;
    while (b > 0) {
        if (b&1) {
            resp *= a;
            resp %= MOD;
        }
        a *= a;
        a %= MOD;
        b >>= 1;
    }

    return resp;
}

int count(int n, int k) {
    /* if (n == k) return 1; */
    return fact[n] * bpow(((fact[k] * fact[n - k]) % MOD), MOD - 2) % MOD;
}

void solve () {
    int n, k; cin >> n >> k;
    vector<int> c(2);

    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        c[num]++;
    }

    int resp = 0;
    for (int i = (k + 1) / 2; i <= k; i++) {
        int b = k - i; // quantidade de zeros;
        if (c[1] < i || c[0] < b) continue;
        resp += (count(c[1], i) * count(c[0], b)) % MOD;
        resp %= MOD;
    }

    cout << resp << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    calc();
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
