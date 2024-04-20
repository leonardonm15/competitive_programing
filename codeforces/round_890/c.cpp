#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long


int dp() {
    // cada cara pode se maximizar direto ou maximizar o proximo cara e dps se maximizar
}

void solve () {
    // recebe o array, sorta os caras
    // dps de sortar, pra cada maior cara eu chamo a função da dp
    // tem que resetar o array chama recursivo e vai diminuindo o k
    int n, k; cin >> n >> k;
    for (int i=0; i < n; i++) cin >> arr[i];

    for (int i=1; i < n - 1; i++) {

    }
    vector<int> aux = arr;

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
