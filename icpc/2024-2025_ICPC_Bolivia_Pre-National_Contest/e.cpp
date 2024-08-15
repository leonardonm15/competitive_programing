#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

void solve() {
    int n; cin >> n;
    int N = n;
    vector<int> arr;

    for (int i = 2; i <= N; i++) {
        while (n % i == 0) {
            arr.push_back(i);
            n /= i;
        }
    }

    if (arr.size() == 0) {
        cout << n << endl;
        return;
    }

    string resp;
    for (auto c: arr) {
        string k = to_string(c);
        resp += k;
        resp.push_back('x');
    }
    resp.pop_back();
    cout << resp << endl;

}

signed main() {
    solve();
}
