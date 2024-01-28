#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
/* #define int long long */

//debug
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
#ifndef ONLINE_JUDGE
#define debarr(arr, n) cerr << "arr: ["; forn(i, n) cerr << arr[i] << (i == n-1 ? "" : ", "); cerr << "]" << endl;
#else
#define debarr(x...)
#endif

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

int check(vector<int> &indx, vector<vector<int>> &a, vector<int> c) {
    int v = 0;
    for (auto id: indx) {
        for (auto cara: a[id]) {
            c[cara]--;
            if (c[cara] == 0) v++;
        }
    }
    return v;
}

void solve () {
    int n; cin >> n;
    vector<vector<int>> f(51); // indices
    vector<vector<int>> a; // perrm
    vector<int> c(51);
    set<int> set;

    for (int i=0; i < n; i++) {
        int num; cin >> num;
        vector<int> v;
        while (num--) {
            int m; cin >> m;
            f[m].push_back(i);
            v.push_back(m);
            c[m]++;
            set.emplace(m);
        }
        a.push_back(v);
    }

    int i = 0;
    int resp = 200;
    while (i < f.size()) {
        if (f[i].size() == 0) {
            i++;
            continue;
        }
        resp = min(resp, check(f[i], a, c));
        i++;
    }

    cout << set.size() - resp << endl;
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
