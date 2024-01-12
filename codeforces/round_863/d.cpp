#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

vector<int> fib(46);

bool aob (int h, int w, int a, int b) {
    if ((a > h || a <= 0) || (b > w || b <= 0)) return true;
    else return false;
}

void build() {
    fib[0] = 1;
    fib[1] = 1;
    for (int i=2; i <= 45; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

void solve () {
    int n, y, x; cin >> n >> y >> x;
    int h, w;
    h = fib[n];
    w = fib[n + 1];
    /* cout << "fib -> "; */
    /* for (int i=0; i <= 10; i++) cout << fib[i] << " "; */
    /* cout << endl; */
    cout << "h -> " << h << endl;
    cout << "w -> " << w << endl;
    // direita cima esquerda baixo
    vector<pair<int, int>> mv = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    for (int k=0; k < 4; k++) {
        int q = k;
        int a = x;
        int b = y;
        bool flag = true;
        cout << " ---------------- " << endl;
        for (int i=1; i <= n; i++) {
            int op = q % 4;
            cout << "op -> " << op << endl;
            if (i > 1) {
                a += (mv[op].first * fib[i]) + (mv[(op + 1) % 4].first * (fib[i] - 1));
                b += (mv[op].second * fib[i]) + (mv[(op + 1) % 4].second * (fib[i] - 1));
                op++;
            } else {
                /* cout << "(mv[op].first * fib[i]) -> " << (mv[op].first * fib[i]) << endl; */
                /* cout << "(mv[op].second * fib[i]) -> " << (mv[op].second * fib[i]) << endl; */
                a += (mv[op].first * fib[i]);
                b += (mv[op].second * fib[i]);
            }
            cout << a << " - " << b << endl;
            if (aob(h, w, b, a)) {
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
    cout << " ---------- INVERSO -----------" << endl;
    for (int k=4; k > 0; k--) {
        int q = k;
        int a = x;
        int b = y;
        bool flag = true;
        cout << " ---------------- " << endl;
        for (int i=1; i <= n; i++) {
            int op = q % 4;
            cout << "op -> " << op << endl;
            a += (mv[op].first * fib[i]) + (mv[(op - 1) % 4].first * (fib[i] - 1));
            b += (mv[op].second * fib[i]) + (mv[(op - 1) % 4].second * (fib[i] - 1));
            op--;
            cout << a << " - " << b << endl;
            if (aob(h, w, b, a)) {
                flag = false;
                break;
            }
            q--;
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
