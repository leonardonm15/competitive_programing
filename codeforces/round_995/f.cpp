#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long

void solve() {
    int n, m, q; cin >> n >> m >> q;
    vector<pair<int, int>> ranges(4);
    ranges[0] = {m, m};
    int am_ranges = 1;

    bool has_1 = false;
    bool has_n = false;
    while (q--) {
        int cut; cin >> cut;
        int rg = am_ranges;

        if (cut == m && am_ranges == 1 && ranges[0].first == m && ranges[0].second == m) {
            ranges[0] = {1, 1};
            ranges[1] = {n, n};
            has_1 = true;
            has_n = true;
            am_ranges = 2;
        } else {
            for (int i = 0; i < rg; i++) {
                int &l = ranges[i].first;  // Use referência ao invés de ponteiro
                int &r = ranges[i].second;

                if (cut < l) {
                    l = max(1LL, l - 1); // Atualiza diretamente o valor de `l`
                } else if (cut > r) {
                    r = min(n, r + 1); // Atualiza diretamente o valor de `r`
                } else {
                    if (!has_1) ranges[am_ranges++] = {1, 1};
                    if (!has_n) ranges[am_ranges++] = {n, n};
                    has_1 = true;
                    has_n = true;
                }

                if (l == 1) has_1 = true;
                if (r == n) has_n = true;

            }
        }

        int pr = 0;
        int resp = 0;
        sort(ranges.begin(), ranges.begin() + am_ranges);
        for (int i = 0; i < am_ranges; i++) {
            int l = ranges[i].first;
            int r = ranges[i].second;
            int k = 0;
            if (l > pr) {
                k += r - l + 1;
                pr = r;
            }

            if (l <= pr) {
                l = pr + 1;
                k += max(0LL, r - l + 1);
                pr = max(pr, r);
            }

            resp += k;
        }

        cout << resp << " ";
    }
    cout << endl;

}

signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int TC = 1;
    if (TC) {
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
