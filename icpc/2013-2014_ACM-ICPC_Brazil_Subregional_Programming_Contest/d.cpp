#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

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

vector<int> dobra(vector<int> arr, int pos) {
    vector<int> v;
    int n = arr.size();
    int r = pos + 1;
    int l = pos;
    while (r <= n - 1 || l >= 0) {
        if (l >= 0 && r <= n - 1) {
            v.push_back(arr[r] + arr[l]);
            r++; l--;
        }
        else if (l >= 0 && r > n - 1) {
            v.push_back(arr[l]);
            l--;
        }
        else if (l < 0 && r <= n - 1) {
            v.push_back(arr[r]);
            r++;
        }
    }
    reverse(v.begin(), v.end());
    return v;
}

bool brute(vector<int> arr, vector<int> &ref) {
    /* debug(arr); */
    if (arr == ref) return true;
    reverse(arr.begin(), arr.end());
    if (arr == ref) return true;
    reverse(arr.begin(), arr.end());
    
    for (int i=0; i < arr.size() - 1; i++) {
        if (brute(dobra(arr, i), ref)) return true;
    }
    return false;
}

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &cara: arr) cin >> cara;
    int k; cin >> k;
    vector<int> ref(k);
    for (auto &cara: ref) cin >> cara;

    cout << (brute(arr, ref) ? 'S' : 'N') << endl;
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
