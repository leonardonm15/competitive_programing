#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

vector<string> arr;

bool check (int& a, int& b) {
    if (arr[a][b] == '1') return a < b;
    else return a > b;
}

void solve () {
    int n; cin >> n;
    vector<int> resp(n);
    arr.resize(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = n - 1; i >= 0; i--) {
        resp[n - i - 1] = i;
    }

    sort(resp.begin(), resp.end(), check);

    for (auto c: resp) cout << c + 1 << " ";
    cout << endl;

    arr.clear();
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
