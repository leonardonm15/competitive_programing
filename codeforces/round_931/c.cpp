#include <bits/stdc++.h>

using namespace std;

/* #define endl '\n' */ 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

int ask (int a, int b) {
    cout << "? " << a << " " << b << endl;
    int num; cin >> num;
    return num;
}

void answ (int a, int b) {
    cout << "! " << a << " " << b << endl;
    return;
}

void solve () {
    int n, m; cin >> n >> m; // 4 x 3
    int r1 = ask(1, 1);
    if (r1 == 0) {
        answ(1, 1);
        return;
    }

    int r2 = ask(n, 1);
    if (r2 == 0) {
        answ(n, 1);
        return;
    }
    
    int r3 = ask(1, m);
    if (r3 == 0) {
        answ(1, m);
        return;
    }

    int x1 = (r1 - r2 + n + 1) / 2;
    int y1 = (r1 + r2 - n + 3) / 2;

    int x2 = (r1 + r3 - m + 3) / 2;
    int y2 = (r1 - r3 + m + 1) / 2;

    if (1 <= x1 && x1 <= n && 1 <= y1 && y1 <= m && ask(x1, y1) == 0) answ(x1, y1);
    else answ(x2, y2);
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
