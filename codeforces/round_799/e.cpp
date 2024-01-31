#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, k; cin >> n >> k;
    int s = 0;
    vector<int> v(n);
    vector<int> p(n);

    for (int i=0; i < n; i++) {
        int num; cin >> num;
        s += num;
        v[i] = num;
        p[i] = s;
    }

    if (k > s) {
        cout << -1 << endl;
        return;
    }

    if (s == k) {
        cout << 0 << endl;
        return;
    }

    reverse(v.begin(), v.end());

    /* cout << "s -> " << s << endl; */

    int c = 0;
    int resp = 1e9;
    int flag = false;
    for (int i=0; i < n; i++) {
        int q = s - k; // soma total menos quanto eu quero
        /* cout << "q -> " << q << endl; */
        auto it = lower_bound(p.begin(), p.end(), q);
        if (q == 0) resp = min(resp, c);
        else if (it != p.end() && *it == q) {
            int b = it - p.begin();
            b++;
            /* cout << "b -> " << b << endl; */
            /* cout << "b + c -> " << b + c << endl; */
            resp = min(resp, b + c);
            flag = true;
        }
        s -= v[i];
        c++;
    }

    if (flag) cout << resp << endl;
    else cout << -1 << endl;
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
