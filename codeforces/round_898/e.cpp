#include <bits/stdc++.h>

using namespace std;
# define int long long

void solve () {
    int n, h; cin >> n >> h;
    vector<int> arr;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());
    int qq = 0;
    int q0 = 0;
    int nw = 0;
    for (int i=0; i < n; i++) {
        cout << i << endl;
        cout << "n  -> " << n << endl;
        int j = i + 1;
        while (arr[i] == arr[j] && j < n) j++;
        j -= i;
        if (i == 0) {
            nw = arr[0];
            q0 = j + i;
            arr[0] = 0;
            if (j > 1) i += j;
            continue;
        }
        /* cout << "i -----> " << i << endl; */
        /* cout << "j -----> " << j << endl; */
        /* cout << "q0 -----> " << q0 << endl; */
        int diff = max(1ll, arr[i] - nw);
        /* cout << "diff -----> " << diff << endl; */
        int nr = diff * q0 * j;
        /* cout << " new resp -> " << nr << endl; */
        if (qq + nr > h) {
            cout << "--------> " <<  nw << endl;
            return;
        } else {
            qq += nr;
            nw += diff;
            q0 += j;
        }
        if (j > 1) i += j;
    }
    while (qq < h) {
        if ((qq + n) <= h) qq += n;
    }
    cout << "qq ----------> " << qq << endl;
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

