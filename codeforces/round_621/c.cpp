#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    string s; cin >> s;
    int n = (int)s.size();
    int freq[26];
    for (int i=0; i < 26; i++) freq[i] = 0;
    map<string, int> map;
    for (int i=0; i < n; i++) {
        freq[s[i] - 'a']++;
        string k;
        k += s[i];
        map[k]++;
    }
    for (auto c: s) {
       for (int i=0; i < 26; i++) {
           string r;
           r += c;
           r += (char)('a' + i);
           map[r] += (freq[i] - ('a' + i == c));
       }
       freq[c - 'a']--;
    }

    int resp = 1;
    for (auto [t, v]: map) resp = max(resp, v);

    cout << resp << endl;
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
