#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int L, R; cin >> L >> R;
    int l, r; cin >> l >> r;


    if ((R - L) < (r - l)) {
        swap(l, L);
        swap(R, r);
    }


    
    // totalmente contido
    if (r <= R && l >= L) {
        int k = 0;
        if (l == L) k++;
        if (r == R) k++;

        cout << (2 - k) + (r - l) << endl;
        return;
    }


    vector<int> arr(200);

    for (int i = L; i <= R; i++) arr[i]++;

    int r2 = 0;
    for (int i = l; i <= r; i++) {
        if (arr[i] == 1) {
            if (i > 1 && i == l) r2++;
            r2++;
        }
    }

    if (arr[r + 1] == 1) r2++;

    // totalmente fora
    if (r2 == 0) {
        cout << 1 << endl;
    } else { // parcialmente contido
        cout << r2 << endl;
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
