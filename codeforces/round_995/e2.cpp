#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

int check(int mid, vector<int>& a, vector<int>& b, int kmax) {
    int k = 0;
    int soma = 0;
    for (int i = 0; i < (int) a.size(); i++) {
        if (mid <= a[i]) soma += mid;
        else if (mid <= b[i]) {
            soma += mid;
            k++;
        }
    }

    if (k <= kmax) return soma;
    else return -1;
}

void solve () {
    int n, k; cin >> n >> k;

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int l = 1;
    int r = 1e18;
    int ans = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;

        int v = check(mid, a, b, k);

        cout << "--------------" << endl;
        cout << "Mid -> " << mid << endl;
        cout << "v ->"  << v << endl;

        if (v != -1) {
            ans = v;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << endl;

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
