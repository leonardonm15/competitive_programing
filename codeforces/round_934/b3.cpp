#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, k; cin >> n >> k;
    vector<int> l(n + 2);
    vector<int> r(n + 2);
    vector<int> ansl;
    vector<int> ansr;

    for (int i=0; i < n; i++) {
        int num; cin >> num;
        /* cout << "Num -> " << num << endl; */
        l[num]++;
    }

    for (int i=0; i < n; i++) {
        int num; cin >> num;
        /* cout << "num -> " << num << endl; */
        r[num]++;
    }


    for (int i=0; i <= n; i++) {
        if (l[i]&1) {
            /* cout << "l[i] -> " << l[i] << endl; */
            ansl.push_back(i);
            ansr.push_back(i);
            l[i]--;
            r[i]--;
        }
    }

    while (ansl.size() > 2 * k) {
        ansl.pop_back();
        ansr.pop_back();
    }

    if ((int)ansl.size()&1) {
        ansl.pop_back();
        ansr.pop_back();
    }

    for (int i=0; i <= n; i++) {
        if (l[i] > 0 && !(l[i]&1) && (int) ansl.size() < 2 * k) {
            ansl.push_back(i);
            ansl.push_back(i);
        }
        if (r[i] > 0 && !(r[i]&1) && (int) ansr.size() < 2 * k) {
            ansr.push_back(i);
            ansr.push_back(i);
        }
        /* cout << "ansl -> "; */
        /* for (auto cara: ansl) cout << cara << " "; */
        /* cout << endl; */
    }

    for (auto cara: ansl) cout << cara << " ";
    cout << endl;
    for (auto cara: ansr) cout << cara << " ";
    cout << endl;
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
