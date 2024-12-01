#include <bits/stdc++.h>

using namespace std;

#define int long long
#define endl '\n'

const int INF = 1e18;

void solve() {
    int n, m, v; cin >> n >> m >> v;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<int> pref;
    int monstros_prefixo = 0;
    int a = 0;
    pref.push_back(monstros_prefixo);
    for (int i = 0; i < n; i++) {
        monstros_prefixo += arr[i];
        if (monstros_prefixo >= v) {
            pref.push_back(++a);
            monstros_prefixo = 0;
        } else {
            pref.push_back(a);
        }
    }


    vector<int> suf(n + 1);
    int monstros_sufixo = 0;
    a = 0;
    for (int i = n - 1; i >= 0; i--) {
        monstros_sufixo += arr[i];
        if (monstros_sufixo >= v) {
            suf[i] = ++a;
            monstros_sufixo = 0;
        } else {
            suf[i] = a;
        }
    }

    vector<int> prefixo_soma;
    int soma = 0;
    prefixo_soma.push_back(soma);

    for (int i = 0; i < n; i++) {
        soma += arr[i];
        prefixo_soma.push_back(soma);
    }

    cout << "Pref -> ";
    for (auto v: pref) cout << v << " ";
    cout << endl;

    cout << "suf  -> ";
    for (auto c: suf) cout << c << " ";
    cout << endl;

    cout << "prefixo_soma -> ";
    for (auto c: prefixo_soma) cout << c << " ";
    cout << endl;

    if (pref.back() - m < 0) {
        cout << -1 << endl;
        return;
    }

    for (int i = 1; i <= n; i++) {

    }


    for (auto [L, R]: ranges) {
        cout << "---------------" << endl;
        cout << "l -> " << L << endl;
        cout << "R -> " << R << endl;

        resp = max(resp, prefixo_soma[R] - pref[L - 1]);
    }

    cout << resp << endl;


}

signed main() {
    // cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
}
