#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    vector<string> arr;
    vector<vector<int>> vis(2, vector<int> (n + 3));
    string s; cin >> s;
    arr.push_back(s);
    cin >> s;
    arr.push_back(s);
    int andar = 0;
    int pos = 0;
    map<char, int> mp;
    mp['<'] = -1;
    mp['>'] = +1;
    for (int i=0; i < 3 * n; i++) {
        vis[andar][pos]++;

        if (vis[1][n - 1]) {
            cout << "YES" << endl;
            return;
        }

        if (pos < n - 1 && arr[andar][pos + 1] == '<') {
            andar ^= 1;
            vis[andar][pos]++;
            pos += mp[arr[andar][pos]];
            vis[andar][pos]++;
        } else {
            pos++;
            vis[andar][pos]++;
            pos += mp[arr[andar][pos]];
            vis[andar][pos]++;
        }
    }

    cout << "NO" << endl;
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
