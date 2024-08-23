#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
// #define int long long

void solve(){
    int n; cin >> n;
    vector<int> cria(n, 1e9);
    int soma = 0;
    for (int i = 0; i < n - 1; i++) {
        int num; cin >> num;
        soma += num;
        soma %= n;
    }

    for (int i = 0; i <= 20; i++) {
        cria[(soma + i) % n] = min(cria[(soma + i) % n], i);
    }

    for (int i = 0; i < n; i++) {
        if (cria[i] == 1e9) cout << -1 << endl;
        else cout << cria[i] << endl;
    }

}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
