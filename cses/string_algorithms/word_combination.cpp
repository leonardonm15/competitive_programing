#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int N = 1e6 + 5;
const int MOD = 1e9 + 7;

vector<vector<int>> trie(N, vector<int>(26, 0));
struct tr {
    int value[N];
    int n_nodes = 0;

    void insert(string &s, int v) {
        int id = 0;
        for (char b : s) {
            int c = b - 'a';
            if (!trie[id][c]) trie[id][c] = ++n_nodes;
            id = trie[id][c];
        }
        /* cout << "id -> " << id << endl; */
        value[id] = v;
    }
    int get_value(string &s) {
        int id = 0;
        for (char b : s) {
            int c = b - 'a';
            if (!trie[id][c]) return -1;
            id = trie[id][c];
        }
        return value[id];
    }

    int get_new_id(int id, char new_letter) {
        /* cout << "----------------" << endl; */
        /* cout << "new_letter -> " << new_letter << endl; */
        /* cout << "trie -> " << trie[id][new_letter - 'a'] << endl; */
        /* cout << "----------------" << endl; */
        if (!trie[id][new_letter - 'a']) return -1;
        return trie[id][new_letter - 'a'];
    }

    int get_value_from_id(int id) {
        return value[id];
    }
};

vector<int> adj[N];
void build_adj(string& s, tr& t) {
    int n = s.size();
    for (int i = 0; i < n; i++) {
        int id = 0;
        for (int j = i; j < n; j++) { 
            id = t.get_new_id(id, s[j]);
            /* cout << "id -> " << id << endl; */
            if (id == -1) break;
            if (t.get_value_from_id(id)) adj[i].push_back(j);
        }
    }
}

int dp[N];
int calc(int i, int k) {
    if (i == k) return 1;
    if (dp[i] != -1) return dp[i];

    dp[i] = 0;
    for (auto v: adj[i]) {
        dp[i] += calc(v + 1, k);
        dp[i] %= MOD;
    }

    return dp[i];
}

void cout_adj(string& s) {
    for (int i = 0; i < s.size(); i++) {
        cout << "v -> ";
        for (auto c: adj[i]) {
            cout << c << " ";
        }
        cout << endl;
    }
}



void solve () {
    string s; cin >> s;
    int k; cin >> k;
    int n = s.size();
    tr t;
    for (int i = 0; i < k; i++) {
        string r; cin >> r;
        t.insert(r, 1);
    }

    /* cout << "trie -> "; */
    /* for (int i = 0; i < 26; i++) { */
    /*     cout << trie[0][i] << " "; */
    /* } */
    /* cout << endl; */

    for (int i = 0; i < N; i++) dp[i] = -1;

    build_adj(s, t);
    /* cout_adj(s); */
    cout << calc(0, n) << endl;
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
