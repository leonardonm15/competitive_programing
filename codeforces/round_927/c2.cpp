#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

const int maxn = 2e5 + 5;
const int neutral = 1;
int n, mod;
vector<int> seg(2 * maxn);

int merge(int a, int b) {
    return (a * b) % mod;
}

void build(vector<int> &arr) {
    for (int i=1; i <= 2 * n; i++) seg[i] = neutral;

    for (int i=0; i < n; i++) seg[i + n] = arr[i];

    for (int i= n - 1; i >= 1; i--) seg[i] = merge(seg[(i * 2) + 1], seg[i * 2]);
}

void update(int i) {
    i += n;
    seg[i] = 1;
    while (i > 1) {
        i >>= 1;
        seg[i] = merge(seg[i * 2], seg[(i * 2) + 1]);
    }
}

int query(int l, int r) {
    int ans = neutral;
    l += n;
    r += n;
    while (l <= r) {
        if (l&1) ans = merge(ans, seg[l++]);
        if (!(r&1)) ans = merge(ans, seg[r--]);
        l >>= 1;
        r >>= 1;
    }

    return ans;
}

void solve () {
    cin >> n >> mod;
    vector<int> arr(n);

    for (int i=0; i < n; i++) {
        int num; cin >> num;
        arr[i] = num % mod;
    }

    build(arr);

    string s; cin >> s;
    
    int l = 0;
    int r = n - 1;
    for (auto c: s) {
        cout << query(0, n - 1) << " ";
        if (c == 'L') update(l++);
        else update(r--);
    }
    cout << endl;
    
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
