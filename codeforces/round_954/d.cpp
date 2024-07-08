#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    string s; cin >> s;

    if (s.size() <= 2) {
        cout << stoll(s) << endl;
        return;
    }

    if (s.size() == 3) {
        string n1;
        n1 += s[0];
        n1 += s[1];
        int k1 = stoll(n1);
        /* cout << "k1 -> " << k1 << endl; */
        /* cout << "s[2] -> "<< s[2] - '0' << endl; */
        if (s[2] == '1' || s[2] == '0' || k1 == 1 || k1 == 0) k1 *= (s[2] - '0');
        else k1 += (s[2] - '0');

        string n2;
        n2 += s[1];
        n2 += s[2];
        int k2 = stoll(n2);
        if (s[0] == '1' || s[0] == '0' || k2 == 1 || k2 == 0) k2 *= (s[0] - '0');
        else k2 += (s[0] - '0');

        /* cout << "k1 -> " << k1 << endl; */
        /* cout << "k2 -> " << k2 << endl; */
        cout << min(k1, k2) << endl;
        return;
    }
    
    int resp = 1e18;
    for (int a = 1; a < n; a++) {
        string num;
        num += s[a - 1];
        num += s[a];
        int k = stoll(num);
        bool flag = false;

        for (int i = 0; i < n; i++) {
            if (s[i] == '0') flag = true;
            if (i == a || i == a - 1 || s[i] == '1') continue;
            else k += (s[i] - '0');
        }

        if (flag) k = 0;
        /* cout << "a -> " << a << endl; */
        /* cout << "k -> " << k << endl; */
        resp = min(resp, k);
    }


    cout << resp << endl;

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
