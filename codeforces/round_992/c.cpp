#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, k; cin >> n >> k;

    vector<int> is;
    vector<int> arr(n);
    for (int i = 1; i <= n; i++) arr[i - 1] = i;

    int i = 1;
    int first = 0;
    do {
        int resp = 0;
        for (int i = 0; i < n; i++) {
            int soma = 0;
            int minimo = arr[i];
            for (int j = i; j < n; j++) {
                minimo = min(minimo, arr[j]);
                soma += minimo;
            }
            resp += soma;
        }
        if (i == 1) first = resp;
        if (resp == first) {
            is.push_back(i);
            cout << "------------" << endl;
            cout << "I -> " << i << endl;

            cout << "arr -> ";
            for (auto c: arr) cout << c << " ";
            cout << endl;
        }


        /* cout << "resp -> " << resp << endl; */
        i++;

    } while (next_permutation(arr.begin(), arr.end()));


    /* cout << "Is -> "; */
    /* for (auto c: is) cout << c << " "; */
    /* cout << endl; */

    /* cout << "dif -> "; */
    /* for (int i = 1; i < (int) is.size(); i++) { */
    /*     cout << is[i] - is[i - 1] << " "; */
    /* } */
    /* cout << endl; */

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
