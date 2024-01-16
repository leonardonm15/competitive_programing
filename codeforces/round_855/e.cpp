#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n' 
//#define int long long
 
// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     
 
 
void dfs(int i, int k, string &v, string& c, string& s, string& t, vector<int> &vis) {
    int n = s.size();
    vis[i]++;
    v.push_back(s[i]);
    c.push_back(t[i]);
    if (i + k < n && !vis[i + k]) dfs(i + k, k, v, c, s, t, vis);
    if (i + k + 1 < n && !vis[i + k + 1]) dfs(i + k + 1, k, v, c, s, t, vis);
    if (i - k >= 0 && !vis[i - k]) dfs(i - k, k, v, c, s, t, vis);
    if (i - k - 1 >= 0 && !vis[i - k - 1]) dfs(i - k - 1, k, v, c, s, t, vis);
}
 
void solve () {
    int n, k; cin >> n >> k;
    /* k--; */
    vector<int> viss(n + 1);

    string s; cin >> s;
    string t; cin >> t;
    vector<string> sarr;
    vector<string> tarr;
 
    if (k >= n && s != t) {
        cout << "NO" << endl;
        return;
    }
 
    for (int i=0; i < n; i++) {
        string v;
        string c;
        if (!viss[i]) {
            dfs(i, k, v, c, s, t, viss);
            sort(v.begin(), v.end());
            sort(c.begin(), c.end());
            /* cout << "c -> " << c << endl; */
            /* cout << "v -> " << v << endl; */
            if (c != v) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
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
