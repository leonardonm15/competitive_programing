#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

const int maxn = 2e5 + 5;
vector<int> arr(maxn);

void calc() {
    arr[1] = 1;
    for (int i=2; i < maxn; i++) {
        int k = i;
        int sum = 0;
        while (k > 0) {
            sum += (k % 10);
            k /= 10;
        }
        arr[i] = arr[i - 1] + sum;
    }
}

void solve () {
    int n; cin >> n;
    cout << arr[n] << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    calc();
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
