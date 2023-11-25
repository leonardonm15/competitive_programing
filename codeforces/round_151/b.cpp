#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int ax, ay, bx, by, cx, cy; cin >> ax >> ay >> bx >> by >> cx >> cy;

    int acx = abs(cx - ax); // dist a pra c no eixo x
    int acy = abs(cy - ay); // dist a pra c no eixo y

    int abx = abs(bx - ax);  // dist a pra b no eixo x
    int aby = abs(by - ay);  // dist a pra b no eixo y

    

    int resp = 1;

    /* cout << "ax -> " << ax << endl; */
    /* cout << "bx -> " << bx << endl; */
    /* cout << "cy -> " << cy << endl; */
    /* cout << "--------------------" << endl; */
    /* cout << "abx -> " << abx << endl; */
    /* cout << "cbx -> " << cbx << endl; */
    /* cout << "aby -> " << aby << endl; */
    /* cout << "cby -> " << cby << endl; */
    
    // se eles estao do mesmo lado do eixo so 
    if (((bx - ax) > 0 && (cx - ax) > 0) || ((bx - ax) < 0 && (cx - ax) < 0)) {
        resp += abs(acx - abx) - 1;
    } 
    cout << resp << endl;
    if (((by - ay) > 0 && (cy - ay) > 0) || ((by - ay) < 0 && (cy - ay) < 0)){
        resp += abs(acy - aby) - 1;
    }

    /* if ((abx + cbx + cby + abx) == 0) cout << 0 << endl; */
    cout << resp << endl;
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
