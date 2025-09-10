#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

const int INF = 1e9 + 5;

void solve () {
	int n, m; cin >> n >> m;
    vector<int> arr(n);

    vector<int> pref;
    int soma = 0;
    pref.push_back(soma);
    for (int i = 0; i < n; i++) {
        int num; cin >> num;
        soma += num;
        pref.push_back(soma);
        arr[i] = num;
    }

    int q_pulos = INF;
    int mind = INF;
    for (int i = 1; i <= m; i++) {
        /* cout << "------------------" << endl; */
        /* cout << "i -> " << i << endl; */
        int cristiano_ronaldo = INF;
        int pulos = 0;
        bool deixou_puto = false;
        int atual = 1;
        while (atual <= n) {
            int L = atual;
            int R = n;
            int ans = -1;

            /* cout << "---------------" << endl; */
            /* cout << "L -> "  << L << endl; */
            /* cout << "R -> " << R << endl; */
            while (L <= R) {
                int mid = (L + R) >> 1;
                int valor = pref[mid] - pref[atual - 1];

                if (valor > i) {
                    R = mid - 1;
                } else {
                    L = mid + 1;
                    ans = mid;
                }
            }


            pulos++;

            /* cout << "ans -> " << ans << endl; */
            if (ans == -1) {
                atual++;
                deixou_puto = true;
            } else {
                cristiano_ronaldo = min(cristiano_ronaldo, pref[ans] - pref[atual - 1]);
                atual = ans + 1;
            }
            /* cout << "dixou_puto -> " << deixou_puto << endl; */
        }

        /* cout << "pulos -> " << pulos << endl; */

        if (deixou_puto) continue;
        cout << "cristiano_ronaldo -> " << (m - cristiano_ronaldo) << endl;
        return;

        if (pulos < q_pulos) {
            q_pulos = pulos;
            mind = i;
        }

    }


    /* cout << mind << endl; */
    /* cout << (m - mind) + 1 << endl; */
    /* cout << q_pulos << endl; */
}

signed main() {
    int TC = 1;
    if (TC){
        cin >> TC;
        while (TC--) solve();
    } else {
        solve();
    }
    return 0;
}
