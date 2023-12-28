#include <bits/stdc++.h>

using namespace std;
//#define int long long

// 1, 3, 5

void solve () {
    int a1, a2, a3; cin >> a1 >> a2 >> a3;
    string s;
    if (a3 > 0) for (int i=0; i < a3 + 1; i++) s.push_back('1');

    // maybe 0 a esquerda
    int k = 0;
    if (a3 == 0) k = 1;
    if (a2 > 0) {
        for (int i=0; i < a2 + 1; i++) {
            if ((i + k)&1) s.push_back('1');
            else s.push_back('0');
        }
    }
    
    // caso em que o a2 termina em 1 e 0
    /* cout << "a3 -> " << a3 << endl; */
    if (a3 > 0 && a2 > 0) {
        s.pop_back();
    }
    
    if (a1 > 0) {
        if (s[s.size() - 1] == '0') {
            for (int i=0; i < a1; i++) s.push_back('0');
        } else {
            for (int i=0; i < a1 + 1; i++) s.push_back('0');
        }
    }

    cout << s << endl;
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
