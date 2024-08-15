#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

pair<int, int> mvs[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

vector<vector<vector<int>>> arr = { { {}, {}, {}, {} },
                                    { {}, {}, {}, {} },
                                    { {}, {}, {}, {} },
                                    { {}, {}, {}, {} }
                                  };
int vis[4][4];

void dfs(int a, int b, int ta, int tb) {
    vis[a][b]++;
    for (auto c: arr[a][b]) {
    
    }

}

void solve () {
    int n, q; cin >> n >> q;
    vector<string> vec;

    vector<int> f(26);
    f['B' - 'A'] = 0;
    f['G' - 'A'] = 1;
    f['R' - 'A'] = 2;
    f['Y' - 'A'] = 3;


    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        if (f[s[1] - 'A'] < f[s[0] - 'A']) swap(s[0], s[1]);
        vec.push_back(s);
        arr[f[s[0] - 'A']][f[s[1] - 'A']].push_back(i + 1);
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << i << j << " -> ";
            for (auto c: arr[i][j]) cout << c << " ";
            cout << endl;
        }
    }

    while (q--) {
        int u, v; cin >> u >> v;
        u--; v--;
        string su = vec[u];
        string sv = vec[v];

        dfs(f[su[0] - 'A'], f[su[1] - 'A'], f[sv[0] - 'A'], f[sv[1] - 'A']);
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                vis[i][j] = 4;
            }
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
