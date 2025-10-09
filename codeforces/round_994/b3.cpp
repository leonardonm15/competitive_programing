#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

int is_perm(int l, int r, vector<int>& arr) {
    vector<int> mex(arr.size() + 5);

    for (int i = l; i <= r; i++) {
        mex[arr[i]]++;
    }
    
    /* cout << "opa gangnam" << endl; */

    int lc = 0;
    for (int i = 1; i < (int) mex.size(); i++) {
        if (!mex[i]) break;
        else lc = i;
    }

    /* cout << "lc -> " << lc << endl; */

    return lc;
}

void solve () {
    int n; cin >> n;
    string s; cin >> s;

    vector<int> perm(n + 1, -1);
    int k = 1;
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 's') {
            for (int j = i; j < n; j++) {
                if (perm[j + 1] != -1) continue;
                perm[j + 1] = k++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == 'p') {
            for (int j = 0; j <= i; j++) {
                if (perm[j + 1] != -1) continue;
                perm[j + 1] = k++;
            }
        }
    }

    /* cout << "perm -> "; */
    /* for (auto c: perm) cout << c << " "; */
    /* cout << endl; */

    bool flag = false;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'p') {
            int mex = is_perm(1, i + 1, perm);
            if (mex < i + 1) flag = true;
        }

        if (s[i] == 's') {
            int mex = is_perm(i + 1, n, perm);
            if (mex < n - i) flag = true;
        }
        /* cout << "flag -> " << flag << endl; */
    }

    cout << (flag ? "NO" : "YES") << endl;
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
