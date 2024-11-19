#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

bool valid(int i, int s) {
    if (i < 0 || i >= s) return false;
    return true;
}

void solve () {
    vector<string> d = {"laranja", "preto", "azul", "amarelo", "vermelho", "rosa"};
    sort(d.begin(), d.end());

    cout << "d -> ";
    for (auto c: d) cout << c << " ";
    cout << endl;

    /* 2 3 4 5 1 6 */
    /* 2 3 5 4 1 6 */

    string s = "MHEALCRNPOEIBHD";
    /* vector<int> seq = {2, 3, -5, -4, 1, 6}; */
    vector<int> seq = {4, 4, -4, -4, 4, 4};

    vector<string> resps;
    for (int i = 0; i < s.size(); i++) {
        int k = i;
        string r;
        bool flag = true;
        r.push_back(s[k]);

        for (auto c: seq) {
            k += c;
            k %= s.size();
            if (valid(k, (int)s.size())) {
                r.push_back(s[k]);
            }

            flag &= valid(k, (int)s.size());
        }

        if (flag) {
            resps.push_back(r);
        }
    }

    cout << "resps -> ";
    for (auto v: resps) cout << v << endl;
}


signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
