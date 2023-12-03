#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    vector<int> rarr;

    for (int i=0; i < n; i++) cin >> arr[i];

    if (n == 1) {
        if (arr[0] > 1) cout << "NO" << endl;
        else cout << "YES" << endl;
        return;
    }

    int k = n;
    int l = n - 1;
    int r = n - 1;
    // começa com 5
    // vai descendo com base nos numeros repetidos, se tiver repetido espera pra
    // printar vindo com o r
    //
    // colocar 5 * quantidade de vezes que o primeiro cara aprece repetido

    while (arr[l] == arr[n - 1]) {
        l--;
        rarr.push_back(n);
    }
    r = l;
    while (l != 0 && r != 0) {
        while (l > 0 && arr[l] == arr[r]) {
            l--;
            k--;
        }
        while (l != r) {
            rarr.push_back(k);
            r--;
        }
        /* cout << "l -> " << l << endl; */
        /* cout << "r -> " << r << endl; */
    }

    for (auto cara: arr) cout << cara << " ";
    cout << endl;

    for (auto cara: rarr) cout << cara << " ";
    cout << endl;
    
    cout << (arr == rarr ? "YES" : "NO") << endl;
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
