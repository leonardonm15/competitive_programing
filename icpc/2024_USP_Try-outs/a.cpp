#include <bits/stdc++.h>

using namespacestd;

#define endl '\n'
// #define int long long
#define pii pair<int, int>

bool interssect_check(int l, int r, int L, int R) { //zeros uns
    if (l >= L && r <= R) return true;
    else return false;
}   

void solve() {
    int n; cin >> n;
    
    vector<pair<int, int>> zeros;
    vector<pair<int, int>> uns;

    for (int i = 0; i < n; i++) {
        int inicial, fin, cortou; cin >> inicial >> fin >> cortou;
        if (cortou) uns.push_back({incial, fin});
        else zeros.push_back({incial, fin});
    }

    sort(zeros.rbegin(), zeros.rend());
    sort(uns.rbegin(), uns.rend());
    
    while (uns.back().second < zeros.back().first) uns.pop_back();

    int t = 0;
    while (uns.size() != 0) { 
        auto [L, R] = uns.back();
        // ver quando o um cancela o um
        // equanto u incial for > que u z inicial ou z final  && u final > z final
        while (zeros.size() && zeros.back().second < L) { //  enquanto r < L
            t = zeros.back().second;
            zeros.pop_back();
        }

        if (zeros.size()) {
            
        }
    }
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
