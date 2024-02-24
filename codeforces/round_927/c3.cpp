#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

const int maxn = 2e5 + 5;
vector<int> seg(4 * maxn, neutral);
int neutral = 1;
int n, mod;

int merge(int a, int b) {
    return (a * b) % mod;
}

void build(int u, int l, int r, vector<int> &arr) {
    // vai fazendo dfs, quando l == r
    if (l == r) {
        seg[u] = arr[l];
    } else {
        int mid = (l + r) >> 1;
        build(u / 2, l, mid, arr);
        build((u / 2) + 1, mid + 1, r, arr);
        seg[u] = merge(seg[u << 1], seg[(u / 2) + 1]);
    }
}



void solve () {
    cin >> n >> mod;
    vector<int> arr(n);

    for (auto &cara: arr) cin >> cara;
    int s; cin >> s;

    for (int i=0; i <= 4 * n; i++) seg[i] = 1;

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
