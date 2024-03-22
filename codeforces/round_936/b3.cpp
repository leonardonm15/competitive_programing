#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     


const int mod = 1e9 + 7;
void solve () {
    int n, k; cin >> n >> k;

    vector<int> arr(n);
    vector<__int128> pref(n + 1);
    for (int i=0; i < n; i++) cin >> arr[i];

    __int128 z = 0;
    __int128 soma = 0;
    for (int i=1; i <= n; i++) {
        __int128 num = arr[i - 1];
        soma += num;
        pref[i] = max(pref[i - 1] + num, z);
    }

    sort(pref.rbegin(), pref.rend());
    cout << "pref -> ";
    for (auto cara: pref) cout << (long long)cara << " ";
    cout << endl;

    soma -= pref[0];

    while (k-- && pref[0] > 0) {
        pref[0] += pref[0];
    }

    cout << "soma -> ";
    cout << (long long) soma << endl;

    cout << (long long) ((soma + pref[0]) % mod) << endl;


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
