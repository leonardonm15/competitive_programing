#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

const int maxn = 1001;
vector<int> arr(maxn);

void build () {
    int num = 1;
    for (int i=1; i < 1001;){
        if (num % 10 != 3 && num % 3 != 0){
            arr[i] = num;
            i++;
        }
        num++;
    }
}

void solve () {
    int n; cin >> n;
    cout << arr[n] << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    build();
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
