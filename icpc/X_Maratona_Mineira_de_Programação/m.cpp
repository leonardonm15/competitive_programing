#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long
#define double long double

const double PI = acos(-1);

void solve () {
    int r; cin >> r;

    double B = 2 * r;
    double A = (B/4) * 3;
    double H = (B/4) * 5;

    double area_circle = PI * r * r;

    double teta = asin(A/H);

    double alpha = PI - (2 * teta);

    double area_tri = ((r * r * sin(alpha)) * PI);

    double area_semi_circle = (2 * teta * area_circle);

    cout << (area_semi_circle + area_tri) / (2 * PI) << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout << std::setprecision(7);
    int TC = 0;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
 
