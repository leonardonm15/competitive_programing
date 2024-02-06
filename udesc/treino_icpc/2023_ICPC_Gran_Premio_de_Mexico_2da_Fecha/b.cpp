#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

int mod = 1e9 + 7;
const int joao = 1e6 + 5;

int f[joao];

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

int inv(int q) {
    int k = mod - 2;
    int c = 1;
    while (k > 0) {
        if (k&1) {
            c *= q;
            c %= mod;
        }
        q *= q;
        q %= mod;
        k >>= 1;
    }
    return c;
}   

int divi(int a, int b) {
    return (a * inv(b)) % mod;
}

void fat() {
    int k = 1;
    for (int i=1; i <= 1e6 + 2; i++) {
        k *= i;
        k %= mod;
        f[i] = k;
    }
}

void solve () {
    int n, q; cin >> n >> q;
    vector<int> arr(n);
    map<int, int> map;
    set<int> set;

    for (int i=0; i < n; i++) {
        cin >> arr[i];
        map[arr[i]]++;
        if (map[arr[i]] > 1) set.emplace(arr[i]);
    }

    int c = 1;
    for (auto cara: set) {
        c *= f[map[cara]];
        c %= mod;
    }

    cout << divi(1ll, divi(f[n], c)) << endl;

    while (q--) {
        int i, k; cin >> i >> k;
        i--;
        int c = 1;

        map[arr[i]]--;
        if (map[arr[i]] == 1) {
            set.erase(arr[i]);
            c = 
        }
        arr[i] = k;

        map[k]++;
        if (map[k] > 1) set.emplace(arr[i]);
        
        int c = 1;
        for (auto cara: set) {
            c *= f[map[cara]];
            c %= mod;
        }

        cout << divi(1ll, divi(f[n], c)) << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    fat();
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
