#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

int rt(int a) {
    int l = 1;
    int r = a;
    int ans = 0;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if ((mid * mid) < a) {
            l = mid + 1;
        } else if (mid * mid > a){
            r = mid - 1;
        } else {
            ans = mid;
            break;
        }
    }

    return ans;
}

bool is_bound(int i, int j, int n) {
    if (i == 1 || i == n || j == 1 || j == n) return true;
    else return false;

}

void solve () {
    int n; cin >> n;
    string s; cin >> s;
    int rtn = rt(n);
    if ((rtn * rtn) == n && rtn > 0) {
        string ns;
        for (int i = 1; i <= rtn; i++) {
            for (int j = 1; j <= rtn; j++) {
                if(is_bound(i, j, rtn)) ns.push_back('1');
                else ns.push_back('0');
            }
        }

        if (ns == s) cout << "YES" << endl;
        else cout << "NO" << endl;
    } else {
        cout << "NO" << endl;
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
