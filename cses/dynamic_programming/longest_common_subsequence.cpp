#include <bits/stdc++.h> 
 
 
using namespace std;
 
#define endl '\n'
 
const int N = 1000 + 50;
const int INF = -1;
 
int dp[N][N];
int a[N], b[N];
int n, m;
 
vector<int> resp1;
int calc(int i, int j, vector<int>& v) {
    /* cout << "----------------------" << endl; */
    /* cout << "v.size() -> " << v.size() << endl; */
    /* cout << "v -> "; */
    /* for (auto c: v) cout << c << " "; */
    /* cout << endl; */

    if (resp1.size() < v.size()) {
        resp1 = v;
    }
	if (i == 0 || j == 0) return 0;
	if (dp[i][j] != INF) return dp[i][j];
	if (a[i-1] != b[j-1]) dp[i][j] = max({dp[i][j], calc(i - 1, j, v), calc(i, j - 1, v)});
	if (a[i - 1] == b[j - 1]) {
        v.push_back(a[i - 1]);
        dp[i][j] = max(dp[i][j], calc(i - 1, j - 1, v) + 1);
        v.pop_back();
    }
 
	return dp[i][j];
}
 
/* int vis[N][N]; */
/* void dfs(int i, int j, vector<int>& resp) { */
/*     if (vis[i][j]) return; */
/*     vis[i][j]++; */
/*     if (dp[i][j] != (dp[n][m] - resp.size())) return; */
/*     if ((resp.size() == dp[n][m]) && resp1.size() == 0) { */
/*         resp1 = resp; */
/*         return; */
/*     } */

/*     /1* cout << "------------------" << endl; *1/ */
/*     /1* cout << "i -> " << i << endl; *1/ */
/*     /1* cout << "j -> " << j << endl; *1/ */
/*     /1* cout << "resp -> "; *1/ */
/*     /1* for (auto v: resp) cout << v << " "; *1/ */
/*     /1* cout << endl; *1/ */

/* 	if (a[i-1] != b[j-1]) { */
/*         dfs(i - 1, j, resp); */
/*         dfs(i, j - 1, resp); */
/*     } */

/*     if (a[i - 1] == b[j - 1]) { */
/*         resp.push_back(a[i - 1]); */
/*         dfs(i - 1, j - 1, resp); */
/*         resp.pop_back(); */
/*     } */
 
/*     return; */
/* } */
 
void solve() {
	cin >> n >> m;
 
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) dp[i][j] = INF;
	}
 
	dp[0][0] = 0;
    vector<int> c;
	calc(n, m, c);

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            cout << max(dp[i][j], 0) << " ";
        }
        cout << endl;
    }
 
	vector<int> resp;
    /* dfs(n, m, resp); */
 
    reverse(resp1.begin(), resp1.end());
 
    cout << resp1.size() << endl;
    for (auto c: resp1) cout << c << " ";
    cout << endl;
}
 
signed main() {
	solve();
}
