#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    vector<int> rarr;
    vector<int> resp;
    for (int i=0; i < n; i++) cin >> arr[i];

    if (n == 1) {
        if (arr[0] > 1) cout << "NO" << endl;
        else cout << "YES" << endl;
        return;
    }
    // constroi de tras pra frente
    // primeiro cara = proximo cara k++;
    // quando for diferente append n caras
    //
    // primeiro piso sempre é 1
    int k = 1;
    rarr = arr;
    reverse(rarr.begin(), rarr.end());
    resp.push_back(1);
    for (int i=0; i < n - 1; i++) {
        k += (rarr[i + 1] - k);
        resp.push_back(k);
    }

    reverse(resp.begin(), resp.end());

    /* for (auto cara: arr) cout << cara << " "; */
    /* cout << endl; */

    for (auto cara: resp) cout << cara << " ";
    cout << endl;

    cout << (arr == resp? "YES" : "NO") << endl;
    

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

