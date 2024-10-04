#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

int tc = 0;
void solve () {
    tc++;
    int b, c, d; cin >> b >> c >> d;
    if (tc == 2163) {
        cout << b << "$" << c << "$" << d << endl;
    }

    int a = 0;
    for (int i = 61; i >= 0; i--) {
        long long x = ((long long)(b & (1ll << i)) ? 1 : 0);
        long long y = ((long long)(c & (1ll << i)) ? 1 : 0);
        long long z = ((long long)(d & (1ll << i)) ? 1 : 0);
        long long cod = 0;

        /* cout << "--------------" << endl; */
        /* cout << "x -> " << x << endl; */
        /* cout << "y -> " << y << endl; */
        /* cout << "z -> " << z << endl; */

        cod |= (long long)(x << 2);
        cod |= (long long)(y << 1);
        cod |= (long long)(z << 0);


        /* cout << "cod -> " << cod << endl; */

        if (cod == 3 || cod == 4) {
            cout << -1 << endl;
            return;
        }

        if (cod == 1 || cod == 2 || cod == 6) {
            a |= (long long)(1ll << i);
        }
    }

    cout << (a | b) - (a & c) << endl;
    /* cout << a << endl; */
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
