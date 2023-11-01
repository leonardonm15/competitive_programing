#include <bits/stdc++.h>

using namespace std;
#define int long long

void solve () {
    int n; cin >> n;
    multiset<int> maiores;
    multiset<int> menores;
    for (int i=0; i < n; i++) {
        int k; cin >> k;
        multiset<int> arr;
        if (k == 1) {
            int num; cin >> num;
            menores.emplace(num);
            continue;
        }
        for (int j=0; j < k; j++) {
            int num; cin >> num;
            arr.emplace(num);
        }
        int num = *arr.begin();
        menores.emplace(num);
        num = *(next(arr.begin()));
        maiores.emplace(num);
    }
    int i = 0;
    int resp = *menores.begin();
    /* cout << "maiores size -> " << maiores.size() << endl; */
    /* cout << "menor cara -> " << resp << endl; */
    multiset<int>::reverse_iterator it;
    for (it = maiores.rbegin(); it != maiores.rend(); ++it) {
        if (it == maiores.rend()) break;
        /* cout << "cara sendo somado -> " << *it << endl; */
        resp += *it;
    }
    resp -= *maiores.begin();
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
