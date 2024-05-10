#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

int form(int r, int x) {
    return (int)sqrtl((r * r) - (x * x));
}

void solve () {
    int d; cin >> d;
    int resp = 0;
    for (int i=1; i < d + 1; i++) {
        int r1 = form(d, i);
        int r2 = form(d + 1, i);
        if ((d * d) - (i * i) == r1 * r1) {
            resp += 4;
        }

        if (((d + 1) * (d + 1) - (i * i)) == r2 * r2) resp -= 4;
        resp += (r2 - r1) * 4;
    }

    cout << resp << endl;

}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int tc; cin >> tc;
    while (tc--) solve();
    return 0;
}
