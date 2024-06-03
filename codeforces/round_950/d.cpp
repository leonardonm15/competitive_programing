#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    vector<int> gcds;
    for (int i=0; i < n; i++) cin >> arr[i];

    for (int i= 1; i < n; i++) {
        gcds.push_back(gcd(arr[i], arr[i - 1]));
    }
    
    vector<int> points;
    for (int i = 1; i < n; i++) {
        if (gcds[i] < gcds[i - 1]) {
            points.push_back(i);
        }
    }

    int mud = 0;
    for (int i=1; i < n - 2; i++) {
        if (gcds[i] < gcds[i - 1]) {
            /* cout << "gcds[i] -> " << gcds[i] << endl; */
            /* cout << "gcds[i - 1] -> " << gcds[i - 1] << endl; */
            /* cout << "arr[i] -> " << arr[i] << endl; */
            /* cout << "arr[i - 1] -> " << arr[i - 1] << endl; */
            int num = gcd(arr[i], arr[i + 2]);
            /* cout << "num -> " << num << endl; */
            if (num > gcds[i]) {
                gcds[i] = num;
                gcds[i + 1] = num;
                mud++;
            }
        }
    }

    cout << "gcds -> ";
    for (auto c: gcds) cout << c << " ";
    cout << endl;
    

    if (mud == 0 && points.size() > 0) {
        bool flag = false;
        for (int i=1; i < gcds.size() - 1; i++) {
            if (gcds[i] < gcds[i - 1]) {
                flag = true;
            }
        }

        if (!flag) {
            cout << "YES" << endl;
            return;
        }
        flag = true;

        for (int i=2; i < gcds.size(); i++) {
            if (gcds[i] < gcds[i - 1]) 
        }
        if (!flag) {
            cout << "YES" << endl;
            return;
        }
    }
    if (mud > 2) cout << "NO" << endl;
    else cout << "MAYBE" << endl;
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
