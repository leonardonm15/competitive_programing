#include <bits/stdc++.h>

using namespace std;
#define int long long


void dbg(multiset<int> a, multiset<int> b) {
    cout << "a -> ";
    for (auto cara: a) cout << cara << " ";
    cout << endl;

    cout << "b -> ";
    for (auto cara: b) cout << cara << " ";
    cout << endl;
}

void solve () {
    int n, m, k; cin >> n >> m >> k;
    int q = min(1000ll, k);
    multiset<int> a;
    multiset<int> b;
    
    for (int i=0; i < n; i++) {
        int num; cin >> num;
        a.emplace(num);
    }

    for (int i=0; i < m; i++) {
        int num; cin >> num;
        b.emplace(num);
    }


    int i = 0;
    while (q--) {
        i++;
        if (i&1) {
            if (*a.begin() < *b.rbegin()) {
                int x = *a.begin();
                int y = *b.rbegin();
                a.erase(a.begin());
                b.erase(--b.end());
                b.emplace(x);
                a.emplace(y);
            }
        } else {
            if (*b.begin() < *a.rbegin()) {
                int x = *b.begin();
                int y = *a.rbegin();
                b.erase(b.begin());
                a.erase(--a.end());
                a.emplace(x);
                b.emplace(y);
            }
        }
        /* dbg(a, b); */
    }

    if (k > n * m) {
        k -= n * m;
        if (k&1 && *a.begin() < *b.rbegin()) {
            int x = *a.begin();
            int y = *b.rbegin();
            a.erase(a.begin());
            b.erase(--b.end());
            b.emplace(x);
            a.emplace(y);
        }
    }

    int soma = 0;
    for (auto cara: a) soma += cara;
    cout << soma << endl;
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

