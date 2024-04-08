#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n, m, k; cin >> n >> m >> k;
    map<int, int> fa;
    map<int, int> fb;
    vector<int> a(n);
    vector<int> b(m);
    for (int i=0; i < n; i++) cin >> a[i];
    for (int i=0; i < m; i++) {
        cin >> b[i];
        fb[b[i]]++;
    }

    int resp = 0;
    int score = 0;
    int l = 0;
    int r = m - 1;
    for (int i=0; i < m; i++) {
        fa[a[i]]++;
        if (fb[a[i]] > 0 && fb[a[i]] >= fa[a[i]]) {// c tem mais quatros que b
            score++;
        }
    }

    while (r < n) {
        if (score >= k) resp++;
        if (r == n - 1) break;
        if (r < n - 1) {
            fa[a[l]]--;
            if (fb[a[l]] > 0 && fa[a[l]] == 0) score--;
            l++;
            r++;
            fa[a[r]]++;
            if (fb[a[r]] > 0 && fa[a[r]] <= fb[a[r]]) score++;
        }
    }

    cout << resp << endl;

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
