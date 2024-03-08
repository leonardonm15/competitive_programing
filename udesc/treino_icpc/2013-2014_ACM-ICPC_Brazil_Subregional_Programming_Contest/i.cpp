#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

const int C = 1e6;
int n, c, p1, p2;
vector<int> arr;

int calc(int i, int inicial, int af) {
    // to num cara, chamo ele + p1, ele + p2 pra cada
    if (inicial - i >= n) return af;
    auto jp1 = max(upper_bound(arr.begin() + incial, arr.end(), arr[i] + p1) - arr.begin(), 1);
    auto jp2 = max(upper_bound(arr.begin(), arr.end(), arr[i] + p2) - arr.begin(), 1);
    int a = 1e9 + 5;
    int b = 1e9 + 5;
    
    a = calc(i + jp1, inicial, af + p1);
    b = calc(i + jp2, inicial, af + p2);

    return min(a, b);
}

void solve () {
    cin >> n >> c >> p1 >> p2;
    arr.resize(n);
    for (int i=0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i=0; i < n; i++) {
        arr.push_back(arr[i] + c);
    }

    int resp = 1e9 + 5;
    for (int i=0; i < n; i++) {
        resp = min(resp, calc(i, i, 0));
    }

    cout << resp << endl;

}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
