#include <bits/stdc++.h>

#define int long long
#define endl '\n'
using namespace std;

void solve() {
    int n; cin >> n;
    vector<int> arr;
    arr.push_back(0);
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());

    for (int i=1; i < arr.size(); i++) {
        int x = arr[i] - arr[i - 1];
        if (x > 1) {
            cout << (i&1 ? "Alicius" : "Bobius") << endl;
            return;
        }
    }

    cout << (arr.size()&1 ? "Alicius" : "Bobius") << endl;
}

signed main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}
