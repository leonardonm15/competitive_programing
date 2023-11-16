#include <bits/stdc++.h>

using namespace std;
#define int long long

map<int, int> m;
int l; int r; int size_jump; int f;
const int INF = 1e10;

int jumps(int start, int looking, int current_jumps) {
    if (m[start]) return INF;
    m[start]++;
    if (looking > r || looking < l) return INF;
    if (start + size_jump <= f || start - size_jump >= f) return current_jumps;
    else return min(jumps(start, looking + size_jump, current_jumps + 1), jumps(start, looking - size_jump, current_jumps + 1));
}

void solve () {
    cin >> l >> r >> size_jump;
    int c; cin >> c >> f;
    int resp = 0;
    int o = c; // onde eu to
    int tg = f; // target
    if (c == f) {
        cout << 0 << endl;
        return;
    }
    resp = min(jumps(c, f - size_jump, 0), jumps(c, f + size_jump, 0));
    cout << resp << endl;
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
