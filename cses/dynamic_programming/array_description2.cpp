
#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int MOD = 1e9 + 7;
int n, m;

vector<int> arr;

int calc(int u, int i, int n) {

    cout << "----------------------" << endl;
    cout << "u -> " << u << endl;
    cout << "i -> " << i << endl;

    // ultimo cara é 0 ou é outro numero
    if (i == n - 1) {
        if (arr[i] != 0) {
            if (u == arr[i]) return 1;
            else return 0;
        } else return 1;
    }

    int resp = 0;
    for (int k = -1; k <= 1; i++) {
        cout << "----------------------" << endl;
        cout << "u -> " << u << endl;
        cout << "i -> " << i << endl;
        if (u + k > 0 && u + k <= m) {
            resp += calc(u + k, i + 1, n);
            resp %= MOD;
        }
    }

    return resp;
}

void solve () {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        arr.push_back(num);
    }

    int resp = 0;
    for (int u = 1; u <= m; u++) {
        resp += calc(u, 0, n);
        resp %= MOD;
    }

    cout << resp << endl;
}

signed main() {
    /* ios_base::sync_with_stdio(0);cin.tie(0); */
    int TC = 0;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
