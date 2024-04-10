#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

const int maxn = 1e6 + 5;
vector<int> freq(maxn);
vector<int> adj[maxn];
vector<int> gp(maxn);
vector<int> resp(maxn);

void dfs(int i, int maxgp, int dg) {
    freq[gp[i]]++;
    if (freq[gp[i]] == 1) dg++;
    resp[i] = dg;
    for (auto cara: adj[i]) dfs(cara, maxgp, dg);
    freq[gp[i]]--;
    if (freq[gp[i]] == 0) dg--;
}

void solve () {
    int n; cin >> n;

    int rot = 0;
    for (int i=1; i <= n; i++) {
        int num; cin >> num;
        if (num == 0) rot = i;
        else adj[num].push_back(i);
    }

    int maxgp = 0;
    for (int i=1; i <= n; i++) {
        cin >> gp[i];
        maxgp = max(maxgp, gp[i]);
    }

    dfs(rot, n, 0);

    for (int i=1; i <= n; i++) cout << resp[i] << " ";
    cout << endl;
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
