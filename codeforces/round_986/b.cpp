#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int INF = 1e18;

void solve () {
    int n, b, c; cin >> n >> b >> c;
    vector<string> d = {"laranja", "preto", "azul", "amarelo", "vermelho", "roxo"};
    sort(d.begin(), d.end());

    cout << "d -> ";
    for (auto c: d) cout << c << " ";
    cout << endl;
    return;
    
    if (b == 0 && c + 2 >= n) {
        if (c >= n) cout << n << endl;
        else cout << n - 1 << endl;
        return;
    }

    if (b == 0 && c + 2 < n) {
        cout << -1 << endl;
        return;
    }

    int R = n;
    int l = 0;
    int r = n;
    int ans = -1;

    /* if (b > 0) ans = -1; */

    while (l <= r) {
        int i = (l + r) >> 1;
        
        if ((i - 1) >= INF / b) {
            r = i - 1;
            /* if (ans == r) break; */
            continue;
        }

        int ge = b * (i - 1) + c; // greatest element
        int rs = R - i; // right side
        int elements = ge / b;
        int misses = ge - elements + 1;

        if (i == 0) {
            ge = 0;
            rs = n;
            misses = 0;
        }

/*         cout << "------------------" << endl; */
/*         cout << "i -> " << i << endl; */
/*         cout << "greatest_element -> " << ge << endl; */
/*         cout << "rigt side -> " << rs << endl; */
/*         cout << "elements -> " << elements << endl; */
/*         cout << "Misses -> " << misses << endl; */
/*         cout << "r -> " << r << endl; */

        if (misses > rs) {
            r = i - 1;
            /* if (ans == r) break; */
        } else if (misses < rs) {
            /* cout << "opa -> " << endl; */
            l = i + 1;
            ans = i;
        } else {
            ans = i;
            break;
        }
    }

    cout << "foi até qual cara -> " << ans << endl;
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
