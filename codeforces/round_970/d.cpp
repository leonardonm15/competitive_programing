#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];
    string s; cin >> s;

    vector<int> resp;
    vector<int> group(n);

    int ga = 1;
    for (int i = 0; i < n; i++) {
        if (!group[i]) {
            int k = i;
            int bc = 0;
            while (!group[k]) {
                group[k] = ga;
                if (s[k] == '0') bc++;
                k = arr[k] - 1;
            }
            ga++;
            resp.push_back(bc);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << resp[group[i] - 1] << " ";
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
