#include <bits/stdc++.h>

using namespace std;
//#define int long long
//
int calc(int n, int mid) {
    set<int> s;
    /* cout << "calc -> "; */
    for (int i=n; i >= 0; i--) {
        s.emplace(mid);
        /* cout << mid << " - "; */
        mid %= i;
        if (mid == 0) {
            s.emplace(0);
            break;
        }
    }
    return s.size();
}

void solve () {
    int n, r, k; cin >> n >> r >> k;
    int r2 = r;
    int l = 0;
    int mid = (l + r) / 2;
    int resp = -1;
    
    while (l <= r) {
        mid = (l + r) / 2;
        int x = calc(n, mid);
        if (k <= x) {
            resp = x;
            r--;
        } else {
            l++;
        }
    }

    /* cout << "resp -> " << resp << endl; */
    if (r2 == 0 && k == 1) {
        cout << 1 << endl;
        return;
    }
    if (resp == -1) {
        cout << 0 << endl;
        return;
    }

    r = r2;
    l = 0;
    int answ = -1;
    while (l <= r) {
        mid = (l + r) / 2;
        int x = calc(n, mid);
        /* cout << "mid -> " << mid << endl; */
        /* cout << "calc -> " << calc(n, mid) << endl; */
        if ((k + 1) <= x) {
            answ = mid;
            r--;
        } else {
            l++;
        }
    }
    
    for (int i=0; i <= r2; i++) {
        cout << "calc - " << i << " -> " << calc(n, i) << endl;
    }

    /* cout << "answ -> " << answ << endl; */
    /* cout << "r2 -> " << r2 << endl; */
    /* if (answ == -1) { */
    /*     cout << (r2 + 1) - resp << endl; */
    /*     return; */
    /* } else { */
    /*     cout << (answ + 1) - resp << endl; */
    /*     return; */
    /* } */
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
