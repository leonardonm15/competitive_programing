#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

vector<vector<int>> gcds(1e3 + 5, vector<int>(1e3 + 5, 0));

void calc() {
    for (int i=1; i <= 1e3 + 2; i++) {
        for (int j=1; j <= 1e3 + 2; j++) {
            gcds[i][j] = gcd(i, j);
        }
    }
}


void solve () {
    int n; cin >> n; 
    vector<int> arr(n);
    vector<int> freq(1e4, -1);

    for (int i=0; i < n; i++) {
        int num; cin >> num;
        arr[i] = num;
        freq[num] = i;
    }

    int resp = -1;
    for (int i=0; i < n; i++) {
        for (int j=1; j < 1e3 + 2; j++) {
            if (freq[j] > -1 && gcds[arr[i]][j] == 1) {
                resp = max(resp, i + freq[j] + 2);
            }
        }
    }

    cout << resp << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    calc();
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
