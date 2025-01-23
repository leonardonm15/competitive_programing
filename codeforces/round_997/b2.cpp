#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    vector<string> arr(n);
    vector<int> resp(n);

    for (int i = 0; i < n; i++) cin >> arr[i];


    for (int i = 0; i < n; i++) {
        // quantos caras menores doq i tem atras dele
        int menoresqi = 0;

        // quantos caras maiore doq i tem atras dele
        int maioresqiatras = 0;
        
        for (int j = 0; j < i; j++) {
            if (arr[j][i] == '1') menoresqi++;
        }

        for (int j = i + 1; j < n; j++) {
            if (arr[i][j] == '0') maioresqiatras++;
        }

        resp[menoresqi + maioresqiatras] = i + 1; 
    }

    for (auto c: resp) cout << c << " ";
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
