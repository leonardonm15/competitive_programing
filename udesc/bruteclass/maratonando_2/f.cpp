#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    int qn = 0;
    int idxn = -1;
    bool flag = false;
    vector<int> arr;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        arr.push_back(num);
        if (num < 0) {
            qn++;
            idxn = i;
        } else if (num == 0) flag = true;
    }

    if (flag) {
        cout << 0 << endl;
        return;
    }

    if (!(qn&1) && qn > 0) {
        // se a quantidade de impares for par
        int c = -1e16;
        int p = 0;
        for (int i=0; i < n; i++) {
            if (arr[i] < 0 && arr[i] > c) {
                c = arr[i];
                p = i;
            }
        }

        cout << 1 << endl;
        cout << p + 1 << " " << 0 << endl;
        return;
    }

    if (qn&1) {
        cout << 0 << endl;
        return;
    }

    cout << 1 << endl;
    cout << 1 << " " << 0 << endl;
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
