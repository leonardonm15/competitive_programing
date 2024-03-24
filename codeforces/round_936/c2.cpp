#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

const int N = 1e5 + 5;

vector<int> adj[N];
vector<int> sub(N, 1);
int resp = -1;
int tg;
int k;
int tic = 1;

int dfs1(int u, int p, int& ans) {
    sub[u] = 1;
    /* vis[u]++; */
    vector<pair<int, int>> r;
    for (auto cara: adj[u]) {
        if (cara != p) {
            int cc = dfs1(cara, u, ans);
            r.push_back({cc, cara});
        }
    }
    sort(r.begin(), r.end());
    for (auto [cc, i]: r) {
        if (sub[u] + cc <= tg || tic > k) {
            sub[u] += cc;
            /* resp = min({resp, cc}); */
            /* sub[i] = 0; */
        } else {
            tic++;
            /* cout << "tic -> " << tic << endl; */
            /* /1* cout << "================" << endl; *1/ */
            /* cout << "000000000000000" << endl; */
            /* cout << "u -> " << u << endl; */
            /* cout << "cc -> " << cc << endl; */
            /* cout << "tic -> " << tic << endl; */
            /* cout << "sub[u] -> " << sub[u] << endl; */
            /* cout << "resp -> " << resp << endl; */
            ans = min({ans, cc});
            /* cout << "resp -> " << resp << endl; */
        }
    }
    /* cout << "sub -> " << sub[u] << endl; */

    return sub[u];
}

int tc = 0;
void solve () {
    tc++;
    int n; cin >> n >> k;
    vector<int> re;
    for (int i=0; i < n - 1; i++) {
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        re.push_back(a);
        re.push_back(b);
    }

    /* if (tc == 420) { */
    /*     cout << n << "#" << k << "#"; */
    /*     for (auto cara: re) { */
    /*         cout << cara << "#"; */
    /*     } */
    /*     cout << endl; */
    /* } */

    int l = 1;
    int r = n;
    while (l <= r) {
        int mid = (l + r) >> 1;
        /* cout << "-------------" << endl; */
        tg = mid;
        int rsp = 1e9 + 5;
        tic = 1;
        dfs1(1, -1, rsp);
        rsp = min(rsp, sub[1]);
        /* cout << "---" << endl; */
        /* cout << "mid --> " << mid << endl; */
        /* cout << "sub[1] -> " << sub[1] << endl; */
        /* cout << "rsp -> " << rsp << endl; */
        /* cout << "tic -> " << tic << endl; */
        /* cout << "K -> " << k << endl; */
        /* cout << "resp -> " << resp << endl; */
        if (rsp > resp && tic > k) {
            resp = rsp;
            /* cout << "deu certo" << endl; */
            l = mid + 1;
        } else {
            /* cout << "deu errado" << endl; */
            r = mid - 1;
        }
    }

    cout << resp << endl;

    for (int i=0; i <= n; i++) {
        adj[i].clear();
        sub[i] = 1;
    }
    tic = 1;
    resp = -1;
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
