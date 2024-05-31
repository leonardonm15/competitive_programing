#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
  int n, k, q;
  cin >> n >> k >> q;
  vector<int> a(k+1), b(k+1);
  for (int i = 1; i <= k; ++i) cin >> a[i];
  for (int i = 1; i <= k; ++i) cin >> b[i];
  while (q--) {
    int d;
    cin >> d;
    if (d == 0) {
      cout << 0 << ' ';
      continue;
    }
    int r = lower_bound(a.begin(), a.end(), d) - a.begin(),
        l = r-1;
    cout << b[l] + (((d-a[l])*(b[r]-b[l]))/(a[r]-a[l])) << ' ';
  }
  cout << '\n';
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
