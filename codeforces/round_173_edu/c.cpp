#include <bits/stdc++.h>

using namespace std;

#define endl '\n' 
#define int long long

void solve () {
    int n; cin >> n;
    vector<int> arr(n);
    set<int> resp;
    resp.emplace(0ll);

    for (int i = 0; i < n; i++) cin >> arr[i];
    
    int v = 0;
    int special = 0;
    for (int i = 0; i < n; i++) {
        resp.emplace(arr[i]);
        cout << "-------------" << endl;
        cout << "v1 -> " << v << endl;
        if (v > 0 && arr[i] == -1) {
            v = arr[i];
        } else if (v < 0 && arr[i] == -1) {
            v += arr[i];
        } else if (v > 0 && arr[i] == 1) {
            v += arr[i];
        } else if (v < 0 && arr[i] == 1) {
            v = arr[i];
        } else if (arr[i] > 1) {
            special = i;
            v += arr[i];
        } else if (v == 0) {
             v = arr[i];
        }
        resp.emplace(v);

        cout << "v2 -> " << v << endl;
        cout << "I -> " << i << endl;
        cout << "resp -> ";
        for (auto c: resp) cout << c << " ";
        cout << endl;
    }

    int soma = 0;
    for (int i = special; i < n; i++) {
        soma += arr[i];
        resp.emplace(soma);
    }

    soma = 0;
    for (int i = special; i >= 0; i--) {
        soma += arr[i];
        resp.emplace(soma);
    }

    soma = 0;
    for (int i = n - 1; i >= 0; i--) {
        soma += arr[i];
        resp.emplace(soma);
    }

    soma = 0;
    for (int i = 0; i < n; i++) {
        soma += arr[i];
        resp.emplace(soma);
    }

    cout << resp.size() << endl;
    for (auto c: resp) cout << c << " ";
    cout << endl;

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
