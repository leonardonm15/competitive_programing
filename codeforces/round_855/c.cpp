#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
//#define int long long

// ----------    GRIND MENTALITY    ---------     
// /* ESCREVE TODAS AS SUAS IDEIAS E TESTA */
// ----------    GRIND MENTALITY    ---------     

void solve () {
    int n; cin >> n;
    multiset<int> s;
    long long resp = 0;
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        if (s.size() > 0 && num == 0) {
            /* cout << "set -> "; */
            /* for (auto c: s) cout << c << " "; */
            /* cout << endl; */
            /* return; */
            int k = *s.rbegin();
            /* cout << "k -> " << k << endl; */
            resp += k;
            auto lastElement = s.rbegin();  // Obtém o iterador reverso para o primeiro elemento
            s.erase(std::next(lastElement).base()); 
        } else if (num > 0) {
            s.insert(num);
        }
    }
    cout << resp << endl;
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
