#include <bits/stdc++.h>

using namespace std;

const int N = 500 + 5;
const int M = 60 * 1e3;
vector<int> adj[N];
vector<int> age(N);
vector<int> trade(N);

int c = 0;
void dfs(int u, int p, int &resp) {
    /* cout << "u -> " << u << endl; */
    /* cout << "age[u] -> " << age[u] << endl; */
	for (auto cara: adj[u]) {
		if (trade[cara] != p) {
			resp = min(resp, age[trade[cara]]);
			dfs(trade[cara], u, resp);
		}
	}
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
	// employees, number of direct manage relation, number of instructions
	int n, m, q; cin >> n >> m >> q;
	for (int i=0; i <= n; i++) trade[i] = i;
	for (int i=1; i <= n; i++) cin >> age[i];
	for (int i=0; i < m; i++) {
		int a, b; cin >> a >> b;
		adj[b].push_back(a);
	}

	while(q--) {
		char t; cin >> t;
		if (t == 'T') {
			int a, b; cin >> a >> b;
			swap(trade[a], trade[b]);
            /* swap(adj[a], adj[b]); */
		} else {
			int k; cin >> k;
            cout << endl;
			/* cout << "K -> " << k << endl; */
			int resp = 1e9 + 5;
			dfs(k, -1, resp);
			if (resp == 1e9 + 5) {
                cout << "*" << endl;
            } else {
                cout << "resp -> ";
                cout << resp << endl;
            }
		}
        cout << "-----------" << endl;
        /* for (int i=1; i <= n; i++) { */
        /*     cout << trade[i] << " "; */
        /* } */
        /* cout << endl; */
        for (int i=1; i <= n; i++) {
            for (auto cara: adj[trade[i]]) {
                cout << trade[i] << " " << trade[cara] << endl;
            }
        }
	}
}
