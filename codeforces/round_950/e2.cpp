#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
#define mat vector<vector<int>> 

void solve () {
    int n, m; cin >> n >> m;
    mat a(n), b(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int num; cin >> num;
            a[i].push_back(num);
        }
        sort(a[i].begin(), a[i].end());
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int num; cin >> num;
            b[i].push_back(num);
        }
        sort(b[i].begin(), b[i].end());
    }
    
    cout << "--------------------- a" << endl;
    for (auto c: a) {
        for (auto cara: c) cout << cara << " ";
        cout << endl;
    }
    cout << "------------------- b" << endl;
    for (auto c: b) {
        for (auto cara: c) cout << cara << " ";
        cout << endl;
    }
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
