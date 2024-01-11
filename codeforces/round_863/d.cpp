#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

vector<int> fib(46);

bool aob (int h, int w, int a, int b) {
    if ((a > h || a <= 0) || (b < w || b <= 0)) return false;
    else return true;
}

void build() {
    fib[0] = 1;
    fib[1] = 1;
    for (int i=2; i <= 45; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

void solve () {
    int n, x, y; cin >> n >> x >> y;
    int h, w;
    h = fib[n];
    w = fib[n + 1];
    cout << "h -> " << h << endl;
    cout << "w -> " << w << endl;
    vector<pair<int, int>> mv = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    for (int k=0; k < 4; k++) {
        int q = k;
        int a = x;
        int b = y;
        bool flag = true;
        cout << " ---------------- " << endl;
        for (int i=1; i <= n + 1; i++) {
            int op = q % 4;
            int z = 0;
            if (i == n) z = -1;
            /* cout << (mv[op].first * fib[i + z]) << endl; */
            /* cout << (mv[op].second * fib[i + z]) << endl; */
            a += (mv[op].first * fib[i + z]);
            b += (mv[op].second * fib[i + z]);
            cout << a << " - " << b << endl;
            if (aob(h, w, a, b)) {
                flag = false;
                break;
            }
            q++;
        }
        if (flag) {
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;

}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if (TC){
        build();
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
