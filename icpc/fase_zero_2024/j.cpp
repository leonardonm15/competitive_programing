#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define debug(...)
#endif

#define endl "\n"
typedef long long ll;


const int maxn = 505;
ll n, m; 
vector<string> grid(maxn);

ll k, l; 

map<pair<int, int>, bool> vis;
bool check(ll i, ll j){
    if ((i >= n || j >= m) || (i < 0 || j < 0) || (vis[{i,j}])) return false;
    vis[{i,j}] = true;
    return true;
}

ll count(ll i, ll j){
    ll res = 0;
    if (check(i+k, j+l)) if (grid[i+k][j+l] == '*') res++;
    if (check(i+k, j-l)) if (grid[i+k][j-l] == '*') res++;
    if (check(i-k, j+l)) if (grid[i-k][j+l] == '*') res++;
    if (check(i-k, j-l)) if (grid[i-k][j-l] == '*') res++;

    if (check(i+l, j+k)) if (grid[i+l][j+k] == '*') res++;
    if (check(i+l, j-k)) if (grid[i+l][j-k] == '*') res++;
    if (check(i-l, j+k)) if (grid[i-l][j+k] == '*') res++;
    if (check(i-l, j-k)) if (grid[i-l][j-k] == '*') res++;
    
    vis.clear();
    return res;
}

signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n >> m;
    cin >> k >> l; k--; l--;

    for (ll i = 0; i < n; i++) cin >> grid[i];
    ll sm = -1;
    ll x = 0, y = 0;
    for (ll i = 0; i < n; i++){
        for (ll j = 0; j < m; j++){
            if (grid[i][j] != '*'){
                /* debug(grid[i][j]); */
                if (count(i,j) > sm){
                    sm = max(count(i,j), sm);
                    /* debug(i,j); */
                    x = i;
                    y = j;
                }
            }
        }
    }
    /* debug(sm); */
    cout << x+1 << " " << y+1 << endl;
    return 0;
}

