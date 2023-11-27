
#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    // sorta o de baixo e guarda os indices e e vai colocando a resp no array 
    int n, q; cin >> n >> q;
    int cum = 0;
    vector<int> pref(n + 1);
    pref[0] = 0;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        cum += num;
        pref[i + 1] = cum;
    }
    for (auto cara: pref) cout << cara << " - ";
    cout << endl;
    for (int i=0; i < q; i++) {
        int num; cin >> num;
        /* int l = 0; */
        /* int r = n - 1; */
        /* int ans = -1; */
        int resp = upper_bound(pref.begin(), pref.end(), num) - pref.begin();
        /* cout << resp << " "; */
        cout << pref[resp] << " ";

        /* while (l <= r) { */
        /*     int mid = (l + r) / 2; */
        /*     /1* cout << "mid -> " << mid << endl; *1/ */
        /*     if (pref[mid] > num) { */
        /*         ans = mid; */
        /*         r = mid - 1; */
        /*     } else { */
        /*         l = mid + 1; */
        /*     } */
        /* } */
        /* if (ans == -1) cout << 0 << endl; */
    }
    cout << endl;
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
