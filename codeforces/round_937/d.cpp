#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

const int N = 1e5 + 5;
vector<int> dp(N);

void calc() {
    int n = 1;
    while (n <= N) {
        n <<= 1;
        dp[n]++;
    }
}

void solve () {
    int n; cin >> n;
    
    for (int i=2; i * i <= n; i++) {
        if (n % i == 0 && dp[i]) {
            n /= i;
        }
    }

    cout << "n -> " << n << endl;

    cout << (n == 1 ? "YES" : "NO") << endl;

}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
