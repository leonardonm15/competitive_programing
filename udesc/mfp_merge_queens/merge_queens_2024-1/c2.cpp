#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    multiset<int> st;

    while (n > 1) {
        for (int i=2; i <= n; i++) {
            if (n % i == 0) {
                n /= i;
                st.emplace(i);
                break;
            }
        }
    }

    if (st.size() == 2 && *st.begin() == *st.rbegin()) cout << "SIM" << endl;
    else cout << "NAO" << endl;
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
