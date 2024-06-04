#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    vector<int> gcds;
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i= 1; i < n; i++) gcds.push_back(gcd(arr[i], arr[i - 1]));

    cout << "gcds -> ";
    for (auto c: gcds) cout << c << " ";
    cout << endl;

    
    vector<int> points;
    for (int i = 1; i < (int)gcds.size(); i++) {
        if (gcds[i] < gcds[i - 1]) {
            points.push_back(i);
        }
    }

    bool flag = false;
    for (int i = 1; i < (int)gcds.size() - 1; i++) {
        if (gcds[i] < gcds[i - 1]) {
            flag = true;
        }
    }

    if (!flag) {
        cout << "YES" << endl;
        return;
    }

    flag = false;
    for (int i = 2; i < (int)gcds.size(); i++) {
        if (gcds[i] < gcds[i - 1]) flag = true;
    }

    if (!flag) {
        /* cout << "opa 2 -> " << endl; */
        cout << "YES" << endl;
        return;
    }

    int mud = 0;
    cout << "bomba -> ";
    for (int i = 1; i < n - 2; i++) {
        if (gcds[i] < gcds[i - 1]) {
            int num = gcd(arr[i], arr[i + 2]);
            gcds[i] = num;
            gcds[i + 1] = num;
            mud++;
        }
        cout << gcds[i] << " ";
    }
    cout << endl;

    if (mud > 1) cout << "NO" << endl;
    else {
        for (int i = 1; i < (int)gcds.size(); i++) {
            if (gcds[i] < gcds[i - 1]) {
                cout << "NO" << endl;
                return;
            }
        }
        cout << "YES" << endl;
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
