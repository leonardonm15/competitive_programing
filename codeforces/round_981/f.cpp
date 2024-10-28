#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int MOD = 1e9 + 7;

void solve () {
    int n, k; cin >> n >> k;

    int a = 1 % k;
    int b = a;
    int c = -1;
    int d = 0;


    if (a == 0)  d = 1;
    else if (b == 0) d = 2;
    else {
        int i = 3;
        while (true) {
            c = (a + b) % k;
            if (!c) {
                d = i;
                break;
                } else {
                a = b;
                b = c;
                c = -1;
            }

            i++;
        }
    }

    cout << ((n % MOD) * d) % MOD << endl;
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
