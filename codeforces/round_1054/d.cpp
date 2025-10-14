#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    string s; cin >> s;

    vector<int> prefa;
    prefa.push_back(0);
    int qb = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') prefa.push_back(prefa.back() + qb);
        if (s[i] == 'b') {
            prefa.push_back(prefa.back());
            qb++;
        }
    }

    qb = 0;
    vector<int> sufa;
    sufa.push_back(0);
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'a') sufa.push_back(qb + sufa.back());
        if (s[i] == 'b') {
            sufa.push_back(sufa.back());
            qb++;
        }
    }

    reverse(sufa.begin(), sufa.end());

    vector<int> prefb;
    prefb.push_back(0);
    int qa = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a') {
            qa++;
            prefb.push_back(prefb.back());
        }
        if (s[i] == 'b') {
            prefb.push_back(prefb.back() + qa);
        }
    }

    qa = 0;
    vector<int> sufb;
    sufb.push_back(0);
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'a') {
            sufb.push_back(sufb.back());
            qa++;
        }
        if (s[i] == 'b') {
            sufb.push_back(sufa.back() + qa);
        }
    }

    reverse(sufb.begin(), sufb.end());

    int resp = 1e18;
    for (int i = 0; i <= n; i++) {
        resp = min(resp, sufa[i] + prefa[i]);
        resp = min(resp, sufb[i] + prefb[i]);
    }

    //resp = min({sufb[0], sufb[n], prefa[0], prefa[n]});

    /* cout << "prefb -> "; */
    /* for (auto v: prefb) cout << v << " "; */
    /* cout << endl; */

    /* cout << "sufb  -> "; */
    /* for (auto v: sufb) cout << v << " "; */
    /* cout << endl; */

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
