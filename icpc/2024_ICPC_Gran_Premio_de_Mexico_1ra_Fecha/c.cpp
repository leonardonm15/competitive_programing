#include <bits/stdc++.h>
#define int long long

using namespace std;

int L, W, H;

int calc(int l, int w, int h) {
    int r = 1;
    r *= L/l;
    r *= W/w;
    r *= H/h;
    return r;
}

void solve() {
    cin >> L >> W >> H;
    int a, b, c; cin >> a >> b >> c;

    int resp = 0;
    resp = max(resp, calc(a, b, c));
    resp = max(resp, calc(a, c, b));
    resp = max(resp, calc(b, a, c));
    resp = max(resp, calc(b, c, a));
    resp = max(resp, calc(c, a, b));
    resp = max(resp, calc(c, b, a));
    cout << resp << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
}
