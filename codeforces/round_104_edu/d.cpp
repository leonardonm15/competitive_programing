#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int N = 1e6;
int memo[N];

void calc() {
    for (int a=2; (int)(a * a) <= N; a++) {

        // obrigatorios 
        int aa = a * a;
        int b = (aa - 1) / 2;
        int c = b + 1;
        c *= c;

        // formula errada
        int cerr = aa - b;
        cerr *= cerr;

        // formula certa
        int ccer = aa + (b * b);

        /* cout << "---------------" << endl; */
        /* cout << "c -> " << c << endl; */
        /* cout << "cerr -> " << cerr << endl; */
        /* cout << "ccerr -> " << ccer << endl; */

        if (cerr == ccer && cerr == c) memo[a] = memo[a - 1] + 1;
        else memo[a] = memo[a - 1];

    }

}

void solve () {
    int n; cin >> n;
    int a = 1;
    while ((a * a) <= n) a++;
    cout << memo[a] << endl;

}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    calc();
    int TC = 1;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
