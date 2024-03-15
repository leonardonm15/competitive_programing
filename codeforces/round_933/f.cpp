#include <bits/stdc++.h>

using namespace std;

/* #define endl '\n' */ 
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

void solve () {
    int n, m, k; cin >> n >> m >> k;
    vector<int> arr(n);
    vector<int> mod(m);
    vector<int> func(k);
    vector<tuple<int, int, int>> difs;

    for (int i=0; i < n; i++) cin >> arr[i];
    for (int i=0; i < m; i++) cin >> mod[i];
    for (int i=0; i < k; i++) cin >> func[i];

    sort(arr.begin(), arr.end());
    sort(func.begin(), func.end());
    sort(mod.begin(), mod.end());

    /* if (func.size() > mod.size()) swap(func, mod); */

    for (int i=1; i < n; i++) {
        difs.push_back({arr[i] - arr[i - 1], arr[i], arr[i - 1]});
    }
    
    sort(difs.rbegin(), difs.rend());

    auto [d, r, l] = difs[0];

    /* cout << "difs -> "; */
    /* for (auto [d, _, a]: difs) cout << d << " "; */
    /* cout << endl; */

    /* debug(mod); */
    /* debug(func); */
    /* debug(d); */
    /* cout << "mid -> " << ((l + r) >> 1) << endl; */
    /* cout << "l -> " << l << endl; */
    int ans = d;
    for (int i=0; i < m; i++) {
        int tg = (l + (d / 2)) - mod[i];
        int tg2 = l + (d/2);
        if (tg < 0) tg = func[0];
        /* cout << "tg -> " << tg << endl; */
        /* cout << "tg2 -> " << tg2 << endl; */
        /* cout << "ans -> " << ans << endl; */
        auto r1 = lower_bound(func.begin(), func.end(), tg);
        auto r2 = upper_bound(func.begin(), func.end(), tg);
        auto r3 = lower_bound(mod.begin(), mod.end(), tg2);
        auto r4 = upper_bound(mod.begin(), mod.end(), tg2);
        if (r1 != func.end()) {
            int resp1 = *r1 + mod[i];
            ans = min(ans, max({r - resp1, resp1 - l}));
        }

        if (r3 != mod.end()) {
            ans = min(ans, max({r - *r3, *r3 - l}));
        }
        
        if (r2 != func.end()) {
            int resp2 = *r2 + mod[i];
            ans = min(ans, max({r - resp2, resp2 - l}));
        }

        if (r4 != mod.end()) {
            ans = min(ans, max({r - *r4, *r4 - l}));
        }

    }

    int ans2 = -1;
    if (difs.size() > 1) {
        auto [j, r2, l2] = difs[1];
        ans2 = j;
    }

    cout << max(ans, ans2) << endl;
}

signed main() {
    /* ios_base::sync_with_stdio(0);cin.tie(0); */
    int TC = 1;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
