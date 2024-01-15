#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     


void dfs(int i, int k, string &v, string& s, vector<int> &vis) {
    int n = s.size();
    bool flag = false;
    vis[i]++;
    v.push_back(s[i]);
    if (i + k < n && !vis[i + k]) {
        dfs(i + k, k, v, s, vis);
        flag = true;
    }
    if (i + k + 1 < n && !vis[i + k + 1]) {
        dfs(i + k + 1, k, v, s, vis);
        flag = true;
    }
    if (i - k >= 0 && !vis[i - k]) {
        dfs(i - k, k, v, s, vis);
        flag = true;
    }
    if (i - k - 1 >= 0 && !vis[i - k - 1]) {
        dfs(i - k - 1, k, v, s, vis);
        flag = true;
    }

    if (!flag) vis[i]++;
}

/* int testcase = 0; */
void solve () {
    /* testcase++; */
    int n, k; cin >> n >> k;

    vector<int> viss(n + 1);
    vector<int> vist(n + 1);
    string s; cin >> s;
    string t; cin >> t;
    /* if (testcase == 46) cout << n << "#" << k << "#" << s << "#" << t; */
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
            dfs(i, k, v, s, viss);
            sarr.push_back(v);
        }
        if (!vist[i]) {
            dfs(i, k, c, t, vist);
            tarr.push_back(c);
        }
    }

    for (auto &cara: sarr) sort(cara.begin(), cara.end());
    for (auto &cara: tarr) sort(cara.begin(), cara.end());
    sort(sarr.begin(), sarr.end());
    sort(tarr.begin(), tarr.end());

    cout << "sarr -> ";
    for (auto cara: sarr) cout << cara << " ";
    cout << endl;

    cout << "tarr -> ";
    for (auto cara: tarr) cout << cara << " ";
    cout << endl;
    
    // verificar posição dos caras ilhados
    for (int i=0; i < sarr.size(); i++) {
        if (sarr[i] != tarr[i]) {
            cout << "NO" << endl;
            return;
        }
    }

    for (int i=0; i < n; i++) {
        if ((viss[i] > 1 || vist[i] > 1) && (s[i] != t[i])) {
            cout << "i -> " << i << endl;
            cout << "NO" << endl;
            return;
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
