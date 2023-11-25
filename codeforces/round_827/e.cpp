#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    // sorta o de baixo e guarda os indices e e vai colocando a resp no array 
    //
    //
    //
    int n, q; cin >> n >> q;
    vector<int> resp(q, -1);
    vector<int> arr(n);
    vector<pair<int, int>> qs(q);

    for (int i=0; i < n; i++) cin >> arr[i];
    for (int i=0; i < q; i++) {
        cin >> qs[i].first;
        qs[i].second = i;
    }

    sort(qs.begin(), qs.end());
    int altura = 0;
    int query = 0;

    for (int i=0; i < n; i++) {
        if (qs[query].first >= arr[i] && query < q) {
            altura += arr[i];
            continue;
        } else {
            resp[qs[query].second] = altura; 
            query++;
        }
    }
    for (auto cara: resp) {
        if (cara == -1) cout << altura << " ";
        else cout << cara << " ";
    }
    cout << endl;

    // quantos cara 

    /* while (k != q) { */
    /*     while (qs[i].first >= arr[i]) { */
    /*         k++; */
    /*     } */
    /*     k++; */
    /*     resp[qs[i].second] = k; */
    /* } */
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
