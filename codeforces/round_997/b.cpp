#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

vector<string> arr;

bool check(int& a, int& b) {
    if (arr[a][b] == '1' && a > b) return true;
    else return false;
}

void solve () {
    int n; cin >> n;
    vector<int> resp(n);

    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        arr.push_back(s);
    }


    for (int i = 0; i < n; i++) resp[i] = i;

    sort(resp.begin(), resp.end(), check);
    reverse(resp.begin(), resp.end());

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
