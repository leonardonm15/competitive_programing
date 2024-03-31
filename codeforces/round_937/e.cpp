#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    int x = n;
    string s; cin >> s;
    set<int> div;
    div.emplace(n);
    vector<int> freq(26);
    for (int i=2; i * i <= x; i++) {
        if (n % i == 0) {
            div.emplace(i);
            if (i * i < x) div.emplace(x/i);
        }
    }

    for (auto cara: s) freq[cara - 'a']++;

    sort(freq.rbegin(), freq.rend());
    if (freq[1] <= 1 && freq[2] == 0) {
        cout << 1 << endl;
        return;
    }

    /* cout << "div -> "; */
    /* for (auto cara: div) cout << cara << " "; */
    /* cout << endl; */
    
    for (auto r: div) {
        string ref;
        string ref2;
        for (int i=0; i < r; i++) {
            ref.push_back(s[i]);
        }

        for (int i=n - 1; i >= n - r; i--) {
            ref2.push_back(s[i]);
        }
        reverse(ref2.begin(), ref2.end());

        int err = 0;
        for (int i=r; i < n; i++) {
            int k = i % r;
            if (ref[k] != s[i]) err++;
        }

        int err2 = 0;
        for (int i=0; i < n - r; i++) {
            int k = i % r;
            if (ref2[k] != s[i]) err2++;
        }

        if (err <= 1 || err2 <= 1) {
            cout << r << endl;
            return;
        }
    }
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
