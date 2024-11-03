#include <bits/stdc++.h>

using namespace std;
 
#define endl '\n' 
#define int long long
 
void solve () {
    string s; cin >> s;
    int q; cin >> q;
 
    if (s.size() < 4) {
        for (int i = 0; i < q; i++) cout << "NO" << endl;
        for (int i = 0; i < q; i++) {
            int _; cin >> _ >> _;
        }
        return;
    }

    s.push_back('6');
    s.push_back('6');
    s.push_back('6');
    s.push_back('6');
 
    vector<int> good(s.size() + 5, 1e9);
    int goodam = 0;
 
    for (int i = 0; i < s.size() - 4; i++) {
        if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0') {
            goodam++;
            good[i] = 0;
            good[i + 1] = 1;
            good[i + 2] = 2;
            good[i + 3] = 3;
        }
    }

 
    while (q--) {
        int i; cin >> i;
        char v; cin >> v;
        i--;
 
        if (good[i] != 1e9 && s[i] != v) {
            int p = i;
            goodam--;
 
            while (good[p + 1] == good[p] + 1) p++;
            
            for (int l = p; l >= p - 3; l--) {
                good[l] = 1e9;
                if (good[l] == 0) break;
            }
        }

        if (s[i] == v) {
            cout << (goodam ? "YES" : "NO") << endl;
            continue;
        }

        s[i] = v;

        if (v == '1') {
            if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '0') {
                goodam++;
                good[i] = 0;
                good[i + 1] = 1;
                good[i + 2] = 2;
                good[i + 3] = 3;
            } else if (s[i - 1] == '1' && s[i] == '1' && s[i + 1] == '0' && s[i + 2] == '0') {
                goodam++;
                good[i - 1] = 0;
                good[i] = 1;
                good[i + 1] = 2;
                good[i + 2] = 3;
            }
 
        } else {
            if (i >= 2 && s[i] == '0' && s[i + 1] == '0' && s[i - 1] == '1' && s[i - 2] == '1') {
                goodam++;
                good[i - 2] = 0;
                good[i - 1] = 1;
                good[i] = 2;
                good[i + 1] = 3;
 
            } else if (i >= 3 && s[i] == '0' && s[i - 1] == '0' && s[i - 2] == '1' && s[i - 3] == '1') {
                goodam++;
                good[i - 3] = 0;
                good[i - 2] = 1;
                good[i - 1] = 2;
                good[i] = 3;
            }
        }
 
        cout << (goodam ? "YES" : "NO") << endl;
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
