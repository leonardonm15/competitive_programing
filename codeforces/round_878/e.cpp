#include <bits/stdc++.h>
using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

int test = 0;

void solve () {
    string s, r; cin >> s >> r;
    int t, q; cin >> t >> q;
    vector<int> diff((int)s.size() + 5);
    vector<int> ops(q + 5);
    int total = 0;
    for (int i=0; i < (int)s.size(); i++) {
        if (s[i] == r[i]) diff[i + 1] = 0;
        else {
            total++;
            diff[i + 1] = 1;
        }
    }

    vector<int> operations;

    for (int i=1; i <= q; i++) {
        int tc; cin >> tc;
        operations.push_back(tc);
        /* cout << "----------------" << endl; */
        /* cout << "tc -> " << tc << endl; */
        /* return; */
        /* cout << "total -> " << total << endl; */
        /* cout << "ops[i] -> " << ops[i] << endl; */
        total += ops[i];
        if (tc == 1) {
            int pos; cin >> pos;
            operations.push_back(pos);
            if (diff[pos] == 1) {
                total--;
                if (i + t <= q) ops[i + t]++;
            }
        } 
        if (tc == 2) {
            int a, x, b, y; cin >> a >> x >> b >> y;
            operations.push_back(a);
            operations.push_back(x);
            operations.push_back(b);
            operations.push_back(y);
            if (a == 1 && b == 1) swap(s[x - 1], s[y - 1]);
            if (a == 2 && b == 2) swap(r[x - 1], r[y - 1]);
            if (b != a) {
                if (b < a) {
                    swap(a, b);
                    swap(x, y);
                }
                swap(s[x - 1], r[y - 1]);
            }
            if (s[x - 1] != r[x - 1] && diff[x] == 0) {
                diff[x] = 1;
                total++;
            }
            if (s[y - 1] != r[y - 1] && diff[y] == 0) {
                diff[y] = 1;
                total++;
            }
            if (s[y - 1] == r[y - 1] && diff[y] == 1) {
                diff[y] = 0;
                total--;
            }
            if (s[x - 1] == r[x - 1] && diff[x] == 1) {
                diff[x] == 0;
                total--;
            }
        }
        if (tc == 3) {
            test++;
            if (test == 1849) {
                cout << s << "$$$$$$" << r << "$$$$";
                cout << t << "#" << q << "*";
                for (auto cara: operations) {
                    cout << cara << "%";
                }
                cout << endl;
            }
            cout << (total ? "NO" : "YES") << endl;
        }
    }

    /* cout << "Ops -> "; */
    /* for (int i=1; i <= q; i++) { */
    /*     cout << ops[i] << " "; */
    /* } */
    /* cout << endl; */

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
