#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    map<tuple<int, int, int, int>, int> mp; // numero, quantidade de vezes por q trio
    int n; cin >> n;
    vector<int> arr(n);

    for (int i=0; i < n; i++) cin >> arr[i];

    int resp = 0;
    int triples = 0;
    for (int i=1; i < n - 1; i++) {
        int a, b, c;
        a = arr[i - 1];
        b = arr[i];
        c = arr[i + 1];
        
        resp += map[{a, b, 0, 1}] + map[{a, c, 0, 2}] + map[{b, c, 1, 2}];

        map[{a, b, 0, 1}]++;
        map[{a, c, 0, 2}]++;
        map[{b, c, 1, 2}]++;
        triples++;
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
