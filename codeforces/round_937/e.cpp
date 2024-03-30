#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

int tc = 0;
void solve () {
    tc++;
    int n; cin >> n;
    int x = n;
    string s; cin >> s;
    if (tc == 75) {
        cout << n << "$";
        cout << s << endl;
    }
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
        for (int i=0; i < r; i++) {
            ref.push_back(s[i]);
        }

        int err = 0;
        bool flag = false;
        int same_word = 0;
        for (int i=r; i < n; i++) {
            int k = i % r;

            if (ref[k] != s[i]) err++;
        }

        if (err <= 1 || err == (n / r) - 1) {
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
