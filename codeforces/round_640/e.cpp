#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> pref(n + 1);
    vector<int> freq(n + 1);
    vector<int> arr;

    int soma = 0;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        freq[num]++;
        arr.push_back(num);
        soma += num;
        pref[i + 1] = soma;
    }

    int p = 0;
    for (int i=1; i <= n; i++) {
        for (int j=2; (i - j) >= 0; j++) {
            int x = pref[i];
            int m = pref[(i - j)];
            if (x - m <= n && freq[x - m]) {
                p += freq[x - m];
                freq[x - m] = 0;
            }
            
        }
    }
    cout << p << endl;
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
