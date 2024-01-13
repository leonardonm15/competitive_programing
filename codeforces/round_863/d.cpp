#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

vector<int> fib(46);

void build() {
    fib[0] = 1;
    fib[1] = 1;
    for (int i=2; i <= 45; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

bool inside(int n, int x, int y) {
    if (n == 1) return true; // chegou na coordenada final
    // maior que o quadradão e menor que o retangulo
    if (fib[n - 1] <= y && y < fib[n]) return false; 
    if (fib[n] <= y) y -= fib[n]; // caso esteja na outra metade
    return inside(n - 1, y, x); // fecha o quadrado verticalmente e horizontalmente
}

void solve () {
    int n, x, y; cin >> n >> x >> y;
    x--, y--;
    cout << (inside(n, x, y) ? "YES" : "NO") << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    build();
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
