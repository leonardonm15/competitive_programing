#include <bits/stdc++.h>

using namespace std;
//#define int long long

double trap(double a, double b, double h) {
    return ( h * (a + b)) / 2;
} 

double tri(double a, double h) {
    return (a * h) / 2;
} 

void solve () {
    cout << setprecision(7) << fixed;
    double res = 0;
    double n, d, h; cin >> n >> d >> h;
    double slope = h / (d/2);
    vector<double> arr(n);
    res += tri(d, h);
    for (int i=0; i < n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    for(int i=1; i < n; i++) {
        double num = arr[i];
        double lv = arr[i-1];
        if ((lv + h) > num) {
            double nh = num - lv;
            double tb = ((d/2) - (nh / slope)) * 2;
            res += trap(d, tb, nh);
        }
        else res += tri(d, h);
    }
    cout << res << endl;
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
