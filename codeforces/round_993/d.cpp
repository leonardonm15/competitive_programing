#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    vector<int> freq(n + 1);
    vector<int> tenho(n + 1, 0);
    int maior = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        tenho[arr[i]]++;
    }

    vector<int> b;
    vector<int> nt;

    for (int i = 1; i <= n; i++) {
        if (!tenho[i]) nt.push_back(i);
    }

    for (int i = 0; i < n; i++) {
        if (freq[arr[i]] == 0 || freq[arr[i]] < freq[maior]) {
            b.push_back(arr[i]);
            freq[arr[i]]++;
            if (freq[arr[i]] > freq[maior]) maior = arr[i];
        } else if (freq[arr[i]] == freq[maior]) {
            b.push_back(nt.back());
            nt.pop_back();
        }
    }

    for (auto c: b) cout << c << " ";
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
