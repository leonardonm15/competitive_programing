#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int R = 2e5 + 5;
int arr[R];
int pref[R];

void calc() {
    for (int i = 1; i < R; i++) {
        int num = i;
        int k = 0;
        while (num > 0) {
            num /= 3;
            k++;
        }
        arr[i] = k;
    }

    int now = 0;
    for (int i = 1; i < R; i++) {
        now += arr[i];
        pref[i] = now;
    }
}

void solve () {
    int l, r; cin >> l >> r;
    int resp = (2 * arr[l]) + (pref[r] - pref[l]);
    cout << resp << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    calc();
    int TC = 1;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
