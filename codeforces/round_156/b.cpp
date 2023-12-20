#include <bits/stdc++.h>

using namespace std;
/* #define int long long */
#define pii pair<int, int> 

double eps = 0.0000001;

double dist(pii a, pii b) {
    double k = abs(a.first - b.first);
    double t = abs(a.second - b.second);
    return sqrt((k * k) + (t * t));
}

bool valid(int mid, pii a, pii b, pii p, pii o) {
    if (
            (min(dist(p, b), dist(p, a)) - mid) <= eps && // dist p esta numa bola
            (min(dist(o, a), dist(o, b)) - mid) <= eps    // o esta numa bola
       )
    else return false;
}

void solve () {
    double px, py, ax, ay, bx, by;
    cin >> px >> py >> ax >> ay >> bx >> by;
    pii p = {px, py};
    pii a = {ax, ay};
    pii b = {bx, by};
    pii o = {0, 0};

    // estao dentro da area de alguma bola 
    // min(dist(p, b), dist(p, a)) <= mid
    // and
    // min(dist(o, a), dist(o, b)) <= mid;
    // and
    //
    // ( dentro da mesma bola
    // dist(a, p) && dist(a, o) <= mid
    // ou
    // dist(b, p) && dist(b, a) <= mid
    // )
    // ou
    // dist(a, b) / 2 <= mid
    
    double l = 1;
    double r = 1e9;
    double mid = (l + r) / 2;
    double answ = 0;
    while (abs(r - l) >= eps) {
        mid = (l + r) / 2;
        if (valid(mid, a, b, p, o)) {
            answ = mid;
            r = mid - eps;
        } else {
            answ = mid;
            l = mid + eps;
        }
    }

    cout << "l -> " << l << endl;
    cout << "r -> " << r << endl;
    cout << "answ -> " << answ << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    cout << fixed << setprecision(10);
    int TC = 1;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
