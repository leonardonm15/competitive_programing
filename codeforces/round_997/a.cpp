#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, l; cin >> n >> l;

    pair<int, int> atual = {1, 1};
    pair<int, int> last = {-1000, -1000};

    int p = 0;
    for (int i = 0; i < n; i++) {
        pair<int, int> cut;
        cin >> cut.first >> cut.second;
        atual.first += cut.first;
        atual.second += cut.second;

        if (last.first + l < atual.first && atual.second > last.second + l) p += l * 4;
        else {
            p += l * 4;
            int dx = last.first + l - atual.first;
            int dy = last.second + l - atual.second;
            if (dx > 0) {
                p -= 2 * dx;
            }

            if (dy > 0) {
                p -= 2 * dy;
            }
        }

        /* cout << "p -> " << p << endl; */
        last = atual;
    }

    cout << p << endl;
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
