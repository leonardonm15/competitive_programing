#include <bits/stdc++.h>

using namespace std;

int main() {
    int r; cin >> r;
    double k, d; cin >> k >> d;
    double kr = r * k;
    double coroa = ((acos(-1) * r * r) - (acos(-1) * kr  * kr)) * 0.5;
    double base_tri = sqrt(3) * kr/2.0;
    double h_tri = sqrt((base_tri * base_tri) - ((base_tri / 2) * (base_tri / 2)));
    double vol_tri = (base_tri * h_tri) / 2;
    vol_tri = vol_tri * 3 * 0.5;
    double peso = (vol_tri + coroa) * d;
    cout << setprecision(10) << fixed;
    cout << peso << endl;
}
