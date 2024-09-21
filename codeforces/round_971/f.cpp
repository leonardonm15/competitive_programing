#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

int sum_shift(int l, int n, vector<int>& pref, bool flag = false) {
        int shift = l / n;
        int steps = l % n;
        int start_point = (shift + steps) % n;
        int falta_shift = (n - steps - 1); // quantos caras faltam no shift
        /* int falta_not_shift = n - 1 - start_point; */
        int q1 = 0;
        
        if (start_point + falta_shift >= n) {
            q1 += pref[n] - pref[start_point];
            int ja_fiz = n - start_point - 1;
            q1 += pref[falta_shift - ja_fiz];
        }

        if (start_point + falta_shift < n) {
            q1 += pref[start_point + falta_shift + 1] - pref[start_point];
        }

        return q1 - (flag ? pref[start_point + 1] - pref[start_point] : 0);
}

void solve () {
    int n, q; cin >> n >> q;
    vector<int> arr(n);

    int sum = 0;
    vector<int> pref;

    pref.push_back(sum);
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        sum += num;
        pref.push_back(sum);
        arr[i] = num;
    }

    while (q--) {
        int l, r; cin >> l >> r;
        l--; r--;
        if ((l / n) != (r / n)) {
            int r1 = sum_shift(l, n, pref);

            int k1 = (r + 1) / n - ((r + 1) % n ? 0 : 1);
            int k2 = ((l + 1) / n) + ((l + 1) % n ? 1 : 0);
            int mid = max(0ll, k1 - k2);
            mid *= sum;

            int r2 = sum - sum_shift(r, n, pref, true);
            cout << r1 + mid + r2 << endl;
        } else {
            cout << sum_shift(l, n, pref) - sum_shift(r, n, pref, true) << endl;
        }
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
