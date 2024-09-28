#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int INF = 1e18;

int check(int mid, vector<int> arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > mid) {
            int k = arr[i] - mid;
            arr[i + 1] += k;
            arr[i] -= k;
        }
    }


    if (arr[n - 1] > mid) return -INF;

    int resto = 0; 
    int minimo = arr[0];
    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += arr[i];
        if (arr[i] >= minimo) {
            int k = arr[i] - minimo;
            arr[i] -= k;
            resto += k;
        } else if (arr[i] + resto >= minimo) {
            int k = (arr[i] + resto) - minimo; // quanto essa porra + resto > minimo
            arr[i] = minimo;
            resto -= k;
        } else {
            int k = sum / (i + 1);
            resto = sum % (i + 1);
            minimo = k;
        }
    }


    /* if (arr[n - 1]> mid) return -INF; */
    /* sort(arr.begin(), arr.end()); */

    cout << "resto -> " << resto << endl;
    cout << "arr -> ";
    for (auto c: arr) cout << c << " ";
    cout << endl;

    if (resto > mid) return -INF;
    return arr[n - 1] - minimo;
}

void solve() {
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    if (arr[0] > arr[n - 1]) {
        int k = ((arr[0] + arr[n - 1]) + 1);
        arr[0] = (arr[0] + arr[n - 1]) - (k / 2);
        arr[n - 1] = k / 2;
    }

    int l = 0;
    int r = 1e12;
    int ans = 1e18;

    while (l <= r) {
        int mid = (l + r) >> 1;
        cout << "--------------------" << endl;
        cout << "mid -> " << mid << endl;
        int k = check(mid, arr);
        if (k > -INF) {
            cout << "k -> " << k << endl;
            ans = min(ans, k);
            r = mid - 1;
        } else {
            l = mid + 1;
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
