#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int h, w, x, y, a, b; cin >> h >> w >> y >> x >> b >> a;
    
    int dv = b - y;
    int dh = a - x;
    
    if (dv <= 0) {
        cout << "DRAW" << endl;
        return;
    }
    
    pair<int, int> mbd;
    pair<int, int> mbe;

    pair<int, int> mpd;
    pair<int, int> mpe;

    int j = dv / 2;

    if (dv % 2 == 1) {

        mbd.first = min(x + j + 1, w);
        mbd.second = y - (mbd.first - x);
        
        mbe.first = max(1, x - j - 1);
        mbe.second = y - (x - mbd.first);

        mpd.first = min(a + j, w);
        mpd.second = b + (mpd.first - a);

        mpe.first = max(1, a - j);
        mpe.second = b + (a - mpe.first);

        if (mpe.first >= mbe.first && mpd.first <= mbd.first) {
            cout << "ALICE" << endl;
            return;
        }
        cout << "DRAW" << endl;

    } else {
        mbd.first = min(x + j, w);
        mbd.second = y - (mbd.first - x);

        mbe.first = max(1, x - j);
        mbe.second = y - (x - mbd.first);

        mpd.first = min(a + j, w);
        mpd.second = b + (mpd.first - a);

        mpe.first = max(1, a - j);
        mpe.second = b + (a - mpe.first);

        if (mbe.first >= mpe.first && mbd.first <= mpd.first) {
            cout << "BOB" << endl;
            return;
        }
        cout << "DRAW" << endl;

    }

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
