#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    int n; string s; cin >> n >> s;
    sort(s.rbegin(), s.rend());
    int cap = stol(s);
    int ans = 0;
    for (int i=0; i * i <= cap; i++) {
        // pega o sqr 
        int sqr = i * i; string q;
        // itera nos numeros do sqr pra pegar o array dos numeros
        while (sqr > 0) {
            char num = char((sqr % 10)) + '0';
            sqr /= 10;
            q.push_back(num);
        }
        // pega completa os 0 que nao apareceram por causa do 0 a esquerda
        while (q.size() < s.size()) q.push_back('0');
        // sorta e compara pra ver se é igual, se for ans++
        sort(q.rbegin(), q.rend());
        if (q == s) ans++;
    }
    cout << ans << endl;
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
