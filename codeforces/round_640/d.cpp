#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int l = 0;
    int sa = 0;
    int sb = 0;

    int lpa = 0;
    int lpb = 0;

    int r = n - 1;
    int jogada = 0;
    vector<int> pego(n);

    if (n == 1) {
        cout << 1 << " " << arr[0] << " " << 0 << endl;
        return;
    }
    int gambs = 0;
    while (l <= r) {
        gambs = 0;
        while (lpa <= lpb && !pego[l]) {
            sa += arr[l];
            lpa += arr[l];
            pego[l]++;
            gambs++;
            l++;
        }
        if (gambs > 0) jogada++;
        lpb = 0;
        gambs = 0;
        while (lpb <= lpa && !pego[r])  {
            sb+=arr[r];
            lpb += arr[r];
            pego[r]++;
            gambs++;
            r--;
        }
        if (gambs > 0) jogada++;
        lpa = 0;
    }
    cout << jogada << " " << sa << " " << sb << endl;
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
