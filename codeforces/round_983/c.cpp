#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n, k; cin >> n >> k;
    int d = n;

    vector<int> divisors;
    for (int i = 3; i * i <= d; i += 2) {
        if (d % i == 0) {
            divisors.push_back(i);
            if (d % (d/i) == 0) divisors.push_back(n/i);
        }

        if (d&1 && d > 1) {
            divisors.push_back(d);
        }
    }


    /* cout << "divisors -> "; */
    /* for (auto c: divisors) cout << c << " "; */
    /* cout << endl; */

    /* if ((1 + n) / 2 == k) { */
    /*     cout << n << endl; */
    /*     for (int i = 1; i <= n; i++) cout << i << " "; */
    /*     cout << endl; */
    /*     return; */
    /* } */

    for (auto jump: divisors) {
        if (jump % 2 == 0) continue;
        vector<int> resp;
        vector<int> median;
        for (int i = 1; i <= n; i += jump) {
            resp.push_back(i);
            /* cout << "(i + jump / 2) -> " << (i + (i + jump)) / 2 << endl; */
            median.push_back((2 * i + jump) / 2);
        }

        /* cout << "------------" << endl; */
        /* cout << "median -> "; */
        /* for (auto c: median) cout << c << " "; */
        /* cout << endl; */

        /* cout << "Median median -> " << median[(n / jump) / 2] << endl; */

        if (median[(n / jump) / 2] == k && median.size()&1) {
            cout << (int) resp.size() << endl;
            /* for (auto m: median) cout << m << " "; */
            /* cout << endl; */

            for (auto c: resp) cout << c << " ";
            cout << endl;
            return;
        }
    }

    cout << -1 << endl;
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
